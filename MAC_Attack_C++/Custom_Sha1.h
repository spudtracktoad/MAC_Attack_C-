#pragma once
/*
    sha1.hpp - source code of

    ============
    SHA-1 in C++
    ============

    100% Public Domain.

    Original C Code
        -- Steve Reid <steve@edmweb.com>
    Small changes to fit into bglibs
        -- Bruce Guenter <bruce@untroubled.org>
    Translation to simpler C++ Code
        -- Volker Diels-Grabsch <v@njh.eu>
    Safety fixes
        -- Eugene Hopkinson <slowriot at voxelstorm dot com>
    Header-only library
        -- Zlatko Michailov <zlatko@michailov.org>


    Modified By: Jared Smith, jsmit210 Set2020
*/

#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

static const size_t BLOCK_INTS = 16;  /* number of 32bit integers per SHA1 block */
static const size_t BLOCK_BYTES = BLOCK_INTS * 4;

using namespace std;

class Custom_Sha1
{
public:
    Custom_Sha1();
    void update(const std::string& s, uint32_t* newDigest, uint32_t oldMessageLength);
    void update(const std::string& s);
    void update(std::istream& is);
    std::string final();
    static std::string from_file(const std::string& filename);

private:
    uint32_t oldLength;
    uint32_t digest[5];
    std::string buffer;
    uint64_t transforms;
    void reset(uint32_t digest[], std::string& buffer, uint64_t& transforms);
    uint32_t rol(const uint32_t value, const size_t bits);
    uint32_t blk(const uint32_t block[BLOCK_INTS], const size_t i);
    void R0(const uint32_t block[BLOCK_INTS], const uint32_t v, uint32_t& w, const uint32_t x, const uint32_t y, uint32_t& z, const size_t i);
    void R1(uint32_t block[BLOCK_INTS], const uint32_t v, uint32_t& w, const uint32_t x, const uint32_t y, uint32_t& z, const size_t i);
    void R2(uint32_t block[BLOCK_INTS], const uint32_t v, uint32_t& w, const uint32_t x, const uint32_t y, uint32_t& z, const size_t i);
    void R3(uint32_t block[BLOCK_INTS], const uint32_t v, uint32_t& w, const uint32_t x, const uint32_t y, uint32_t& z, const size_t i);
    void R4(uint32_t block[BLOCK_INTS], const uint32_t v, uint32_t& w, const uint32_t x, const uint32_t y, uint32_t& z, const size_t i);
    void transform(uint32_t digest[], uint32_t block[BLOCK_INTS], uint64_t& transforms);
    void buffer_to_block(const std::string& buffer, uint32_t block[BLOCK_INTS]);
};
