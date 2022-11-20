#include <iostream>
#include <math.h>
#include <cinttypes>
#include <string>
#include <typeinfo>
#include <vector>
// #include <chrono>
// #include <thread>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

uint32_t step(uint32_t lfsr, vector<int>& taps){
    uint32_t prev = lfsr;
    uint32_t lastBit = bitset<32>(prev)[31];
    uint32_t current=0;

    for(int c=0; c<32; ++c){
        uint32_t bit = bitset<32>(prev)[c];
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
    bitset<32> cb(current);
    cb[0] = lastBit;
    return (uint32_t)cb.to_ulong();
}
int main(){
    uint32_t seed=0b00000000000000000000000000000001;
    uint32_t initial = seed;
    uint32_t all_zero = 0b00000000000000000000000000000000;
    uint32_t all_one = 0b11111111111111111111111111111111;
    vector<int> taps;
    taps.push_back(1);
    taps.push_back(5);
    taps.push_back(6);
    taps.push_back(31);


    uint64_t period = 0;
    seed = step(seed, taps);
    while((seed!=initial)&&(seed!=all_zero)&&(seed!=all_one)){
        // cout << "seed: " << bitset<32>(seed) << '\n';
        seed = step(seed, taps);

        // cout << "ciph: " << ciphers << '\n';
        // cout << "next: " << bitset<32>(seed) << '\n' << '\n';
        period += 1;
        cout << period << '\n';

        // sleep_for(nanoseconds(10));
        // sleep_until(system_clock::now() + milliseconds(500));
   } 
   cout << "seed: " << bitset<32>(seed) << '\n';
}
