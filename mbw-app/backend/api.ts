import express from 'express'
import mongodb from 'mongodb'

const router = express.Router();

const uri = "mongodb+srv://admin:mbwscss1234@mbw.qp4qg.mongodb.net/myFirstDatabase?retryWrites=true&w=majority";

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

    return client.db('mbw-scss').collection('devices');
}

module.exports = router