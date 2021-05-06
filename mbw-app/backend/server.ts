import express from 'express'
import cors from 'cors'
import bodyParser from 'body-parser'

const app = express();

app.use(bodyParser.json());
app.use(cors());

const devices = require('./api');

app.use('/api/devices',devices);


if(process.env.NODE_ENV === 'production')
{
    app.use(express.static(__dirname + '/publicDeploy'));

    app.get(/.*/, (req,res) => res.sendFile(__dirname+'/publicDeploy/index.html'));
}

const port = process.env.PORT || 8000;

app.listen(port, () => console.log("Server up & running"));