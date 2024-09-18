// add your imports here
#include <cstdint>
#include <fstream>
#include <iostream>
#include <istream>
#include <map>
#include <random>
#include <unordered_map>
#include <unordered_set>
const std::string TEST_FOLDER = "\\tests\\";
unsigned int xorShift(unsigned int seed, int r1, int r2);
unsigned int seed, N, min, max;
std::unordered_set<int> set;
std::mt19937 mt{};
struct State {
   int a, b;

  bool operator==(const State& other) const {
    return a == other.a && b == other.b;
  }
};

namespace std {
  template <>
  struct hash<State> {
    std::size_t operator()(const State& p) const {
      // Combine hashes of individual members
      // you can improve this by using a better hash functions
      // I am just using xor for simplicity
      return p.a ^ p.b;
    }
  };
}

int main(){
  // code here
  int count = 0;
  std::unordered_set<State> states;
  std::uniform_int_distribution<int> rand(min, max);
  std::cin >> seed >> N >> min >> max;
  mt.seed(seed);
  int i;
  for(i = 0; i < N; i++)
  {
    //Run xor shift
    //seed = xorShift(seed, min, max);
    int a = rand(mt);
    states.insert(a,i); //I give up. Hashing is way too complicated. These errors don't tell me anything.
    if(set.find(states.end()->a) != set.end())
      {
            count++;
      std::cout << states.end()->a << " " << count <<  std:: endl;
    }
    set.insert(states.end()->a);
    //For someone who was new to PRNG. This assignment was ROUGH. Way too complicated for people who are learning.
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

