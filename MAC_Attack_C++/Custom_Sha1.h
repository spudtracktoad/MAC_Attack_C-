#pragma once
#include <string>

static const size_t BLOCKSIZE = 16;  // 32 bits
static const size_t BLOCKBITS = BLOCKSIZE * 4;
static const size_t WORSDIZE = 16; // 32 bits

using namespace std;

class Custom_Sha1
{
public:
    Custom_Sha1();
    Custom_Sha1(string prevousHash, string newMessage);
    uint32_t digest[5];
    string buffer;


private:
	uint32_t ROTL(uint32_t input, size_t bits);
    uint32_t ROTR(uint32_t input, size_t bits);
    uint32_t Ch(uint32_t x, uint32_t y, uint32_t z);
    uint32_t Parity(uint32_t x, uint32_t y, uint32_t z);
    uint32_t Maj(uint32_t x, uint32_t y, uint32_t z);
    uint32_t SHR(uint32_t input, size_t bits);
    void reset(uint32_t digest[], std::string& buffer)

};
