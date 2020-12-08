#include <cstdlib>
#include <vector>
#include <iostream>
#include "sort/merge_sort.hpp"
using namespace std;
int main(){
  vector<int> vec;
  for(int i = 0; i < 11; ++i){
    vec.push_back(rand() % 100);
  }
  std::cout << "before merge sort" << std::endl;
  for(auto item : vec){
    std::cout << item << " ";
  }
  std::cout << std::endl;
  merge_sort(vec, 0, vec.size() - 1);
  for(auto item : vec){
    std::cout << item << " ";
  }
  std::cout << std::endl;
}