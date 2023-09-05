using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;
using db;
using MongoDB.Bson;
using MongoDB.Driver;

namespace Chat
{
    public partial class CChat : Form
    {
        private MongoDBConnection mongoDBConnection;
        private int numMessages = 0;
        private int numMessagesStart = 0;
        private int numChanges = 0;
        private const int maxNumMessages = 14;
        public CChat()
        {
            mongoDBConnection = new MongoDBConnection(this);
            string res = mongoDBConnection.ConnectToDatabase();
            var result = mongoDBConnection.GetRecentMessages(maxNumMessages);
            InitializeComponent();
            changeChat(result,true);
            connectionInfo.Text = res;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Task.Run(() => mongoDBConnection.StartChangeStream());
        }

        private void label1_Click_1(object sender, EventArgs e)
        {

        }
        //send
        private void button1_Click(object sender, EventArgs e)
        {
            var messageDocument = new BsonDocument
            {
                { "text", sendTextField.Text },
                { "timestamp", DateTime.UtcNow }
            };
            try
            {
                mongoDBConnection.InsertMessage(messageDocument);
                numMessages++;
                connectionInfo.Text = string.Format("Changes{0}", numChanges);
            }
            catch (Exception ex)
            {
                connectionInfo.Text = ex.ToString();
            }
        }
        public void changeChat(List<BsonDocument> bson,bool start=false)
        {
            if (bson.Count() > 0)
            {
                foreach (var element in bson)
                {
                    if (element["text"].ToString().Length == 0) element["text"] = "No Message";
                    textboxLabel.Text += "Date:" + element["timestamp"] + "\n" + element["text"]+"\n";
                    if (start) numMessagesStart++;
                }
                if (start) textboxLabel.Text += string.Format("----------------{0}-Prev----------------\n\n", numMessagesStart);

                connectionInfo.Text = string.Format("Changes: {0}", numChanges++);
            }
            while (numMessages + numMessagesStart > maxNumMessages)
            {
                numMessages--;
                int indexOfNewline = textboxLabel.Text.IndexOf("\n");

                if (indexOfNewline != -1)
                {
                    textboxLabel.Text= textboxLabel.Text.Substring(indexOfNewline + 1);
                    indexOfNewline = textboxLabel.Text.IndexOf("\n");
                    textboxLabel.Text= textboxLabel.Text.Substring(indexOfNewline + 1);

                }
                connectionInfo.Text = string.Format("replacing: {0}", numChanges);


            }
        }

        private void incommingMessagesBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void textboxLabel_Click(object sender, EventArgs e)
        {

        }
    }
}
