const Blockchain = require('./index');

const Block = require('./block');


describe('Blockchain', () =>
{
  let bc,bc2;

beforeEach(() => {
    bc = new Blockchain();
    //adding a new instance for chain blockchainvalidation

  bc2 = new Blockchain();

  });


  it('starts with the genesis block', () => {
	  expect(bc.chain[0]).toEqual(Block.genesis());
  });

//new block adding test case in the blockchain
  it('adds a new block', () => {
    const data = 'foo';
    bc.addBlock(data);

    expect(bc.chain[bc.chain.length-1].data).toEqual(data);
  });
//validation of blockchain test cases
  it('validates a valid chain', () => {

bc2.addBlock('foo');

expect(bc.isValidChain(bc2.chain)).toBe(true);
});

it('invalidates a chain with a corrupt genesis block', () =>
{
	bc2.chain[0].data = 'Bad data';

expect(bc.isValidChain(bc2.chain)).toBe(false);
});


it('invalidates a corrupt chain', () =>
{
  bc2.addBlock('foo');
  bc2.chain[1].data = 'Not foo';

 expect(bc.isValidChain(bc2.chain)).toBe(false);
});

// checking the replace chain functionality

it('replaces the chain with a valid chain', () =>
{
	bc2.addBlock('goo');

 bc.replaceChain(bc2.chain);

 expect(bc.chain).toEqual(bc2.chain);
});


it('does not replace the chain with one of less than or equal length',
() => {
	bc.addBlock('foo');

bc.replaceChain(bc2.chain);

expect(bc.chain).not.toEqual(bc2.chain);
});

});
