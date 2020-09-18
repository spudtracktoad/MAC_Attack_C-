#include "Custom_Sha1.h"

Custom_Sha1::Custom_Sha1()
{
    reset(digest, buffer);
}

void Custom_Sha1::Hash(string message)
{
    
    istringstream messageStream(PaddMessage(message));
    while (true)
    {
        char sbuf[BLOCKBITS];
        messageStream.read(sbuf, BLOCKBITS - buffer.size());
        buffer.append(sbuf, (std::size_t)messageStream.gcount());
        if (buffer.size() != BLOCKBITS)
        {
            return;
        }
        InitDigest();
        BuildBlock(buffer);
        BuildMessageSchedule();
        InitWorkVars();
        for (size_t i = 0; i < 80; i++)
        {
            uint32_t tmp = ROTL((a + Function(b, c, d, i) + c + GetConstantK(i) + MessageSchedule[i]), 5);
        }
        SetDigest();
        buffer.clear();
    }
}

string Custom_Sha1::getHash()
{
    return string();
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
    digest[0] = 0x67452301;
    digest[1] = 0xefcdab89;
    digest[2] = 0x98badcfe;
    digest[3] = 0x10325476;
    digest[4] = 0xc3d2e1f0;

    buffer = "";
}

void Custom_Sha1::BuildBlock(const std::string& buffer)
{
    /* Convert the std::string (byte buffer) to a uint32_t array (MSB) */
    for (size_t i = 0; i < BLOCKSIZE; i++)
    {
        block[i] = (buffer[4 * i + 3] & 0xff)
            | (buffer[4 * i + 2] & 0xff) << 8
            | (buffer[4 * i + 1] & 0xff) << 16
            | (buffer[4 * i + 0] & 0xff) << 24;
    }
}

void Custom_Sha1::BuildMessageSchedule()
{
    for (size_t i = 0; i < 80; i++)
    {
        if (i < 16)
        {
            MessageSchedule[i] = block[i];
        }
        else
        {
            ROTL((MessageSchedule[i-3] ^ MessageSchedule[i-8] ^ MessageSchedule[i-14] ^ MessageSchedule[i-16]), 1);
        }
    }
}

void Custom_Sha1::InitWorkVars()
{
    a = digest[0];
    b = digest[1];
    c = digest[2];
    d = digest[3];
    e = digest[4];
}

uint32_t Custom_Sha1::Function(uint32_t x, uint32_t y, uint32_t z, uint32_t index)
{
    if (0 <= index <= 19)
        return Ch(x, y, z);
    if (20 <= index <= 39)
        return Parity(x, y, z);
    if (40 <= index <= 59)
        return Maj(x, y, z);
    if (60 <= index <= 79)
        return Parity(x, y, z);
}

uint32_t Custom_Sha1::GetConstantK(uint32_t index)
{
    if (0 <= index <= 19)
        return K[0];
    if (20 <= index <= 39)
        return K[1];
    if (40 <= index <= 59)
        return K[2];
    if (60 <= index <= 79)
        return K[3];

}

void Custom_Sha1::SetDigest()
{
    digest[0] = a ^ digest[0];
    digest[1] = b ^ digest[1];
    digest[2] = c ^ digest[2];
    digest[3] = d ^ digest[3];
    digest[4] = e ^ digest[4];
}

void Custom_Sha1::InitDigest()
{
    digest[0] = 0x67452301;
    digest[1] = 0xefcdab89;
    digest[2] = 0x98badcfe;
    digest[3] = 0x10325476;
    digest[4] = 0xc3d2e1f0;
}

string Custom_Sha1::PaddMessage(string message)
{
    return string();
}
