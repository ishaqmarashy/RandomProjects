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
        private int numChanges = 0;
        public CChat()
        {
            mongoDBConnection = new MongoDBConnection(this);
            string res = mongoDBConnection.ConnectToDatabase();
            var result = mongoDBConnection.GetRecentMessages(50);
            InitializeComponent();
            changeChat(result);
            connectionInfo.Text = res;
            Task.Run(() => mongoDBConnection.StartChangeStream());
        }

        private void Form1_Load(object sender, EventArgs e)
        {
        }

        private void vScrollBar1_Scroll(object sender, ScrollEventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void flowLayoutPanel2_Paint(object sender, PaintEventArgs e)
        {

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
                connectionInfo.Text = string.Format("Sent:{0}\nChanges{1}", numMessages, numChanges);
            }
            catch (Exception ex)
            {
                connectionInfo.Text = ex.ToString();
            }
        }
        public void changeChat(List<BsonDocument> bson)
        {
            numChanges++;
              foreach (var element in bson)
            {
                textboxLabel.Text += "Date:"+element["timestamp"] + "\n" + element["text"] + "\n";
                connectionInfo.Text = string.Format("Sent:{0}\nChanges{1}", numMessages,numChanges);
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
