// add your imports here
#include <cstdint>
#include <fstream>
#include <iostream>
#include <istream>
#include <unordered_set>
#include<random>
const std::string TEST_FOLDER = "\\tests\\";
unsigned int xorShift(unsigned int seed, int r1, int r2);
unsigned int mersenneTwister(unsigned int seed, int r1, int r2);
unsigned int seed, N, min, max;
int main(){
  // code here

  std::cin >> seed >> N >> min >> max;
  unsigned int i;
  for(i = N; i >= 1; i--)
  {
    //Run xor shift
    seed = xorShift(seed, min, max);
    seed = mersenneTwister(seed, min, max);
  }
}
//The purpose of this function is to take the number and xor shift it to output a pseudo-random number
    unsigned int xorShift(unsigned int seed, int r1, int r2)
{
  seed = seed xor (seed << 13);
  seed = seed xor (seed >> 17);
  seed = seed xor (seed << 5);
  int value = r1 + (seed % (r2 - r1 + 1)); //clamps the value to between r1 and r2
          //output the new values
          std::cout << value << std::endl;
  return seed;
}

unsigned int mersenneTwister(unsigned int seed,int r1, int r2) {
  seed ^=  (seed << 11);
  seed ^= (seed >> 7) & 0x9d2c5680UL;
  seed ^= (seed << 15) & 0xefc60000UL;
  unsigned int newSeed = seed ^ (seed >> 18);
  int value = r1 + (newSeed % (r2 - r1 + 1)); //clamps the value to between r1 and r2
  //output the new values
  std::cout << value << std::endl;
  return newSeed;
}
