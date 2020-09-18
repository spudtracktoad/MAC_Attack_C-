#pragma once
#include <string>
#include <sstream>

static const size_t BLOCKSIZE = 16;  // 32 bits
static const size_t BLOCKBITS = BLOCKSIZE * 4;
static const size_t WORSDIZE = 16; // 32 bits
static const uint32_t K[4] = { 0x5a82799, 0x6ed9eba1, 0x8f1bbcdc, 0xca62c1d6 };

using namespace std;

class Custom_Sha1
{
public:
    Custom_Sha1();
    Custom_Sha1(string prevousHash, string newMessage);
    uint32_t digest[5];
    string buffer;
    void Hash(string message);
    string getHash();


private:
    uint32_t MessageSchedule[80];
    uint32_t block[BLOCKSIZE];
    uint32_t a, b, c, d, e;
	uint32_t ROTL(uint32_t input, size_t bits);
    uint32_t ROTR(uint32_t input, size_t bits);
    uint32_t Ch(uint32_t x, uint32_t y, uint32_t z);
    uint32_t Parity(uint32_t x, uint32_t y, uint32_t z);
    uint32_t Maj(uint32_t x, uint32_t y, uint32_t z);
    uint32_t SHR(uint32_t input, size_t bits);
    void reset(uint32_t digest[], string& buffer);
    void BuildBlock(const string& buffer);
    void BuildMessageSchedule();
    void InitWorkVars();
    uint32_t Function(uint32_t x, uint32_t y, uint32_t z, uint32_t index);
    uint32_t GetConstantK(uint32_t index);
    void SetDigest();

};
