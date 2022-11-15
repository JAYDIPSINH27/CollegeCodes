// SPDX-License-Identifier: MIT
pragma solidity >=0.6.0 <0.9.0;

contract storageMemoryDemo{

    string [] public student=['Mrugendra','Martin','Nirav','Nikita'];

    function fMemory() public view{
        string [] memory s1=student;
        s1[0]='Bimal';

    }
    function fStorage() public {
        string [] storage s1=student;
        s1[0]='Bimal';
    }
}