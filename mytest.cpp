#include <iostream>
#include <math.h>
#include <cinttypes>
#include <string>
#include <vector>
#include <bitset>
#include "lfsr.h"

std::vector<int> getQueue(std::bitset<32> current, std::bitset<32> next){
    std::vector<int> queue;
    for(int i=0; i<32; ++i){
        int dir = int(next[i]) - int(current[i]);
        queue.push_back(dir);
    }
    return queue;
}


int main(){

    uint32_t start= 0b00000000000000000000000000000001;

    std::bitset<32> seed = std::bitset<32>(start);

    for(int i=0; i<50; ++i){


        std::bitset<32> current = seed;
        std::bitset<32> next = step(current);
        std::vector<int> q = getQueue(current, next);

        std::cout << "c: ";
        for(int i=0; i<32; ++i){
            std::cout << current[i];
        }
        std::cout << '\n';

        std::cout << "n: ";
        for(int i=0; i<32; ++i){
            std::cout << next[i];
        }
        std::cout << '\n';

        std::cout << "q: ";
        for(int i=0; i<32; ++i){
            std::cout << q[i];
        }
        std::cout << '\n';
        std::cout << '\n';

        seed = next;
    
    }

    return 0;
}
    