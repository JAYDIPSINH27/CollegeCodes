const Block = require('./blockchain/block');
const block = new Block('foo', 'bar', 'zoo', 'baz');
console.log(block.toString());

//testing genesis step 2
console.log(Block.genesis().toString());

//testing the mine block
const fooBlock = Block.mineBlock(Block.genesis(), 'foo');
console.log(fooBlock.toString());
