#include "Custom_Sha1.h"

Custom_Sha1::Custom_Sha1()
{
    reset(digest, buffer);
}

uint32_t Custom_Sha1::ROTL(const uint32_t value, const size_t bits)
{
    return (value << bits) | (value >> (32 - bits));
}

uint32_t Custom_Sha1::ROTR(const uint32_t value, const size_t bits)
{
    return (value >> bits) | (value << (32 - bits));
}

uint32_t Custom_Sha1::Ch(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & y) ^ (~x & z);
}

uint32_t Custom_Sha1::Parity(uint32_t x, uint32_t y, uint32_t z)
{
    return (x ^ y ^ z);
}

uint32_t Custom_Sha1::Maj(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & y) ^ (x & z) ^ (y & z);
}

uint32_t Custom_Sha1::SHR(uint32_t input, size_t bits)
{
    return uint32_t();
}

void Custom_Sha1::reset(uint32_t digest[], std::string& buffer)
{
    /* SHA1 initialization constants */
    digest[0] = 0x67452301;
    digest[1] = 0xefcdab89;
    digest[2] = 0x98badcfe;
    digest[3] = 0x10325476;
    digest[4] = 0xc3d2e1f0;

    /* Reset counters */
    buffer = "";
}
