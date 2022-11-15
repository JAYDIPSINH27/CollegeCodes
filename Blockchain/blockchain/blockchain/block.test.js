const Block = require("./block");
describe('Block',()=>{
  let data,lastHash,block;
  beforeEach(()=>{
    data = "abchjdg";
    lastHash = Block.genesis();
    block = Block.mineBlock(lastHash,data);
  });
  it('sets the `data` to match the input', ()=> {
    expect(block.data).toEqual(data);
  });
  it('sets the `lastHash` to match the hash of the previous block',()=>{
    expect(block.lastHash).toEqual(lastHash.hash);
  });

});
