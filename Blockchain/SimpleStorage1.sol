pragma solidity >=0.6.0 <0.9.0;

contract SimpleStorage {

    uint256 favoriteNumber;

    // This is a comment!
    struct People {
        uint256 favoriteNumber;
        string name;
    }

    //People public person=People({favoriteNumber:2,name:"Mrugendra"})
    People[] public people;
    mapping(string => uint256) public nameToFavoriteNumber;

    function store(uint256 _favoriteNumber) public {
        favoriteNumber = _favoriteNumber;
    }
    
    function retrieve() public view returns (uint256){
        //favoriteNumber+favoriteNumber;
        return favoriteNumber;
    }

    // Memory store value during execution time while storage datatype store value efter execution
    function addPerson(string memory _name, uint256 _favoriteNumber) public {
        people.push(People(_favoriteNumber, _name));
        nameToFavoriteNumber[_name] = _favoriteNumber;
    }
}
