
import express from 'express'
import mongodb from 'mongodb'

const router = express.Router();

const uri ="mongodb+srv://cristiana25:1qazse4rfvgy7@mbw.jttju.mongodb.net/mbw?retryWrites=true&w=majority";

router.get('/', async (req,res) =>{
    const devices = await loadDevices();
    res.send(await devices.find({}).toArray());
})


async function loadDevices() {
    const client = await mongodb.MongoClient.connect(
        uri,
        {
            useUnifiedTopology: true
        }
    );

    return client.db('mbw').collection('pi');
}

module.exports = router