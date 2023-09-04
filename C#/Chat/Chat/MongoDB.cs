using Chat;
using MongoDB.Bson;
using MongoDB.Driver;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace db
{
    internal class MongoDBConnection
    {

        private IMongoCollection<BsonDocument> messagesCollection;
        private readonly CChat linkedChat;

        public MongoDBConnection(CChat linkedChat)
        {
            this.linkedChat = linkedChat;
        }

        public string ConnectToDatabase()
        {
            string connectionUri = "mongodb+srv://m001-student:pass@test-server.dduiwsv.mongodb.net/?retryWrites=true&w=majority";
            var client = new MongoClient(connectionUri);
            var database = client.GetDatabase("Messagedb"); // Replace with your actual database name
            messagesCollection = database.GetCollection<BsonDocument>("messages"); // Replace with your collection name
            // Send a ping to confirm a successful connection
            try
            {
                var result = client.GetDatabase("admin").RunCommand<BsonDocument>(new BsonDocument("ping", 1));
                return "Connection Success";
            }
            catch (Exception ex)
            {
                return ex.ToString();
            }
        }
        public async Task StartChangeStream()
        {
            var pipeline = new EmptyPipelineDefinition<ChangeStreamDocument<BsonDocument>>()
                .Match(new BsonDocument("operationType", "insert"));

            var options = new ChangeStreamOptions
            {
                FullDocument = ChangeStreamFullDocumentOption.UpdateLookup
            };

            using (var cursor = await messagesCollection.WatchAsync(pipeline, options))
            {
                while (await cursor.MoveNextAsync())
                {
                    var batch = cursor.Current;

                    if (batch != null)
                    {
                        // Extract the documents from the batch
                        List<BsonDocument> changes = batch.Select(change => change.FullDocument).ToList();

                        // Update the UI on the main UI thread
                        linkedChat.Invoke((MethodInvoker)delegate
                        {
                            linkedChat.changeChat(changes);
                        });
                    }
                }
            }
        }

        public List<BsonDocument> GetRecentMessages(int count)
        {
            var sort = Builders<BsonDocument>.Sort.Descending("timestamp");
            var limit = count;
            var skip = 0;

            return messagesCollection.Find(new BsonDocument())
                .Sort(sort)
                .Skip(skip)
                .Limit(limit)
                .ToList();
        }

        public string InsertMessage(BsonDocument userDocument)
        {
            try
            {
                messagesCollection.InsertOne(userDocument);
                return "Message sent successfully.";
            }
            catch (Exception ex)
            {
                return ex.ToString();
            }
        }
    }
}
