#include <iostream>
#include <math.h>
#include <cinttypes>
#include <string>
#include <vector>
#include <bitset>
#include "lfsr.h"


int main(){

    uint32_t start= 0b00000000000000000000000000000001;

    std::bitset<32> seed = std::bitset<32>(start);

    for(int i=0; i<10; ++i){
        seed = step(seed);
        std::cout << i << ": " << seed << '\n';
    }

    return 0;
}
    