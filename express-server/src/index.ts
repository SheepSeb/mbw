import express from 'express'


const app = express();
const port = 8000;
const router = express.Router();

router.get('/', (req,res) => {
    res.send({type:'GET'})
});

router.post('/',(req,res) =>{
    console.log(req.body)
    res.json(req.body)
});

router.put('/test/:id',(req,res) =>{
    res.send({type:"PUT"});
});

router.delete('/test/:id',(req,res) =>{
    res.send({type:"DELETE"});
});


app.use(express.json()); //parsing data as json
app.use('/',router);

app.listen(port, () => {
    console.log("It works")
})