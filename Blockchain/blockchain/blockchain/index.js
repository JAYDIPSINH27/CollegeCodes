const Block = require('./block');
class Blockchain{
  constructor()
  {
    this.chain = [Block.genesis()];
  }

  addBlock(data){
    const lastblock = this.chain[this.chain.length-1];
    const block = Block.mineBlock(this.chain[this.chain.length-1], data);
    this.chain.push(block);
    return block;
  }
  isValidChain(chain){
    if(JSON.stringify(chain[0]) !== JSON.stringify(Block.genesis()))
    return false;
  for(let i=1; i<chain.length; i++){

      const block = chain[i];
      const lastblock = chain[i-1];
        if(block.lastHash !== lastblock.hash || block.hash !== Block.blockHash(block)){
         return false;
         }
       }
       return true;
     }

     replaceChain(newchain){
     if(newchain.length <= this.chain.length){
         console.log('Received chain is not longer than the current chain.');
         return;
     }
     else if (!this.isValidChain(newchain)){
         console.log('new chain is not valid chain');
         return;
    }
    console.log('replacing the new chain with existing one');
    this.chain = newchain;
  }

  
}

module.exports = Blockchain;
