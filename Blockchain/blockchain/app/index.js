const express = require('express');
const bodyParser = require('body-parser');
const Blockchain = require('../blockchain');

const HTTP_PORT = process.env.HTTP_PORT || 5000;
// set HTTP_PORT = 3002 , HERE THE ENVIRONMENT VARIABLE IS PASSED I.E IN PROCESS.ENV.HTTP_PORT
const app = express();
const bc = new Blockchain();

// using middeleware function bodyParser to pass Json format data
app.use(bodyParser.json());
//to view the blockchain on localhost
app.get('/block',(req,res) => {
    res.json(bc.chain);
});
//mine functionality added and redirecting to chains , see the output in postman
app.post('/mine',(req,res) => {
    const block = bc.addBlock(req.body.data);
    console.log(`New block added : ${block.toString()}`);
    //p2pServer.syncChains();
    res.redirect('/block');
});

app.listen(HTTP_PORT, () => console.log(`Listening on port ${HTTP_PORT}`));
