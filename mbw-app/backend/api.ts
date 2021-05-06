import { MongoClient } from "mongodb";
import express from 'express'

const appRouter = express.Router();
const uri ="mongodb+srv://cristiana25:1qazse4rfvgy7@mbw.jttju.mongodb.net/mbw?retryWrites=true&w=majority";

const client = new MongoClient(uri, {
  useUnifiedTopology: true,
});

appRouter.get('/', async  (req, res) => {
    const devices = await getDevices();
    res.send(devices);
  })

async function getDevices() {
    
    await client.connect();
    const database = client.db('mbw');
    const pi = database.collection('pi');
    const devices =  pi.find({}).toArray();
  
    return devices;
    
  }
  module.exports = appRouter;