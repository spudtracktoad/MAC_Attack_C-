// MAC_Attack_C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Custom_Sha1.h"
//#include "sha1.h"

int main()
{
    std::cout << "Hello World!\n";
    /*const string orgMessage = "No one has completed Project #3 so give them all /*a 0";
    uint32_t orgHash[5] = { 0xac94e7cf, 0x99456fbf, 0xe5e7aa79, 0xe94d8905, 0x7889b67e };
    string addMessage = "P.S. Except for jsmit210, go ahead and give him the full points.";*/

    string orgMessage = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    string testMessage = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    uint32_t testHash[5] = { 0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476, 0xc3d2e1f0 };
    uint32_t orgHash[5] = { 0xA9993E36, 0x4706816A, 0xBA3E2571, 0x7850C26C, 0x9CD0D89D };
    string addMessage = "d"; 
  
    Custom_Sha1 corSha1;
    corSha1.update(testMessage);
    string corHash = corSha1.final();
    cout << "The SHA-1 of \"" << testMessage << "\" is: " << corHash << endl;

    //Custom_Sha1 mySha;
    //mySha.update(orgMessage);
    //string myHash = mySha.final();
    Custom_Sha1 checksum;
    checksum.update(orgMessage, testHash, 0);
    string hash = checksum.final();

    //cout << "The SHA-1 of \"" << orgMessage << "\" is: " << myHash << endl;
    cout << "The Mal SHA-1 of \"" << orgMessage << "\" is: " << hash << endl;

    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
