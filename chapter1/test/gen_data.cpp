#include <iostream>
#include <set>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

int main(){
  std::set<long> data_set;
  long num = 5200000;
  while(data_set.size() < num){
    long tmp_data = rand();
    if(tmp_data > 0){
      data_set.insert(tmp_data);
    }
  }
  // 注意set集合中的数据都是有序排列的，因此我们需要将其输入到vector中，然后对
  // vector进行shuffle操作。 
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::vector<long> vec(data_set.begin(), data_set.end());
  shuffle(vec.begin(), vec.end(), default_random_engine(seed));
  ofstream outfile;
  outfile.open("data.txt", ios::out | ios::trunc);
  for(auto item : vec){
    outfile << item << std::endl;
  } 
  outfile.close();
}
