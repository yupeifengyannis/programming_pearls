#include <vector>
using namespace std;
template <typename Dtype>
void merge(vector<Dtype>& vec, unsigned long start, unsigned long end, unsigned long mid){
  vector<Dtype> left_vec;
  vector<Dtype> right_vec;
  for(unsigned long i = start; i <= end; ++i){
    if(i <= mid){
      left_vec.push_back(vec[i]);
    }
    else{
      right_vec.push_back(vec[i]);
    }
  }
  unsigned long left_index = 0;
  unsigned long right_index = 0;
  unsigned long vec_index = start;
  while(left_index < left_vec.size() && right_index < right_vec.size()){
    if (left_vec[left_index] < right_vec[right_index]){
      vec[vec_index++] = left_vec[left_index++];
    }
    else{
      vec[vec_index++] = right_vec[right_index++];
    }
  }
  while(left_index < left_vec.size()){
    vec[vec_index++] = left_vec[left_index++];
  }
  while(right_index < right_vec.size()){
    vec[right_index++] = right_vec[right_index++];
  }
}

template <typename Dtype>
void merge_sort(vector<Dtype>& vec, unsigned long start, unsigned long end){
  if(start < end){
    unsigned long mid = (start + end) / 2;
    merge_sort(vec, start, mid);
    merge_sort(vec, mid + 1, end);
    merge(vec, start, end, mid);
  }
}