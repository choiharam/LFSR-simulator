#include <iostream>
#include <math.h>
#include <cinttypes>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>


std::bitset<32> step(std::bitset<32> lfsr){
    std::bitset<32> prev = lfsr;
    uint32_t lastBit = prev[31];
    uint32_t current=0;
    std::vector<int> taps = {1, 5, 6, 31};


    for(int c=0; c<32; ++c){
        uint32_t bit = prev[c];
        
        if(std::find(taps.begin(), taps.end(), c)!=taps.end()){
            bit = bit^lastBit;
            bit <<= 1;
            bit <<= c;
            current += bit;
        }else{
            bit <<= 1;
            bit <<= c;
            current += bit;
        }
        
    }
    std::bitset<32> cb(current);
    cb[0] = lastBit;
    return cb;
}