const SHA256 = require('crypto-js/sha256');
class Block {
    constructor(timestamp, lastHash, hash, data) {
        this.timestamp = timestamp;
      this.lastHash = lastHash;
      this.hash = hash;
      this.data = data;
    }

    toString(){
      return `Block-
      timestanp = ${this.timestamp}
      lasthash = ${this.lastHash}
      hash = ${this.hash}
      data = ${this.data}
      `;
    }

    // step 2 create genesis block
    static genesis() {
    return new this('Genesis time', '-----', 'f1r57-h45h', []);
  }
//step 3 create mine block function
  static mineBlock(lastBlock, data) {
      const timestamp = Date.now();
      const lastHash = lastBlock.hash;
      //const hash = 'todo-hash'
      const hash = Block.hash(timestamp,lastHash,data);
      return new this(timestamp, lastHash, hash, data);
    }
//step 4 adding hash function
static hash(timestamp, lastHash, data) {
      return SHA256(`${timestamp}${lastHash}${data}`).toString();
  }

//after creating blockvalidation now we need blockhash function
static blockHash(block){
    const{ timestamp, lastHash, data} = block;
    return Block.hash(timestamp, lastHash, data);
  }

}
module.exports = Block;
