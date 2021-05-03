import express from 'express'
import rethinkdb from 'rethinkdb'

const app = express();
const router = express.Router();

let connection:any = null;
export let readData:any = null;
const host = null;
const port = 8081;
const portDB = null;

export interface Data{
    type?: string,
    dataRead? :string
}

rethinkdb.connect(
    {
        host:'localhost',
        port:28015
    },function(err,conn){
        if (err) throw err;
        connection = conn;
    }
)

router.get('/', (req,res) => {
    
    rethinkdb.db('mbw').table('id_microbit').run(
        connection,
        function(err,cursor){
            if (err) throw err;
            cursor.toArray(function(err,result){
                if(err) throw err;
                readData  = result;
            });
        }
    )
    let newData = {
        type:'GET',
        dataRead : readData
    }
    res.send(newData)
});

app.use(express.json()); //parsing data as json
app.use('/',router);

app.listen(port, () => {
    console.log("It works")
})