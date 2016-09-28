
//Sam Borick

#include <iostream>
#include <assert.h>
#include<vector>
#include<list>
#include<string>

template<typename T>
void print(T first, T last){
  while (first != last) {
    std::cout << *first << ' ';
    ++first;
  }
  std::cout << '\n';
}

template<typename T, typename S>
T find(T first, T limit, S value){
  while (first != limit) {
    if(*first == value){
      return first;
    }else{
    ++first;
    }
  }  
  return limit;  
}

template<typename T, typename S>
bool in(T first, T limit, S value){
  if(find(first, limit, value) != limit){
    return true;
  }else{
    return false;
  }
}

template<typename T, typename S>
int count(T first, T limit, S value){
  int output = 0;
  while (first != limit) {
    if(*first == value)
      output++;
    ++first;
  }
  return output;
}

template<typename T>
int getSize(T first, T limit){
  int output = 0;
  while (first != limit){
    output++;
    ++first;
  }
  return output;
}

template<typename T>
bool equal(T first1, T limit1, T first2, T limit2){
  while (first1 != limit1 && first2 != limit2) {
    if(*first1 != *first2){
      return false;
    }
    ++first1;
    ++first2;
  }
  return true;
}

template<typename T>
T minimum(T a, T b){
 T min = a;
  while (a != b) {
    if(*min > *a){
      min = a;
    }
    ++a;
  }
  return min;
}

template<typename T>
T maximum(T a, T b){ 
 T min = a;
  while (a != b) {
    if(*min < *a){
      min = a;
    }
    ++a;
  }
  return min;
}

template<typename T>
int compare(T first1, T limit1, T first2, T limit2){
  while (first1 != limit1 && first2 != limit2) {
  if (*first1 < *first2)
    return -1;
  if (*first2 < *first1)
    return 1;
  }
  if (first1 == limit1) {
    if (first2 != limit1)
      return -1; // [first1, last1) is a prefix of [first2, last2)
    else
      return 0;  // [first1, last1) and [first2, last2) are equivalent
  }
  else {
    return 1;    // [first2, last1) is a prefix  of [first1, last1)
  }
}

template<typename T>
void copy(T first1, T limit1, T first2, T limit2){
  assert(getSize(first1, limit1) == getSize(first2, limit2));
  while (first1 != limit1 && first2 != limit2) {
    *first2 = *first1;
    first1++;
    first2++;
  }
}

template<typename T, typename S>
void filler(T first, T limit, S value){ //NOTE:  this function name had to be changed becuase there is a function 
//with the same name in iostream, or some other include I have
  while (first != limit) {
    *first = value;
    ++first;
  }
}

template<typename T>
void reverse(T first, T last){
  --last;
  T behind = first; //this accounts for the case where the vector is even
  bool init = true;
  while(first != last && behind != last){
    //std::swap(*first, *last);
    auto temp = *last;
    *last = *first;
    *first = temp;
    --last;
    ++behind;
    ++first;
    if (init){
      --behind;
      init = false;
    }
  }
}

int main(){
/*
  int a[] = {1,2,3,4,5};
  //int* first = a;
  //int* limit = a +5;
  int b[] = {1,2,3,4,4};
  //int* first2 = a;
  //int* limit2 = a+5;
  int c[] = {0,0,0,0,0};
  int* first3 = c;
  int* limit3 = c+5;*/
  std::vector<double> vec = {9.0, 2.0, 3.0};
  std::vector<double> vec2 ={9.0,2.0,3.0};
  std::vector<double> vec3 = {0.0,0.0,0.0};

  std::list<int> lst = {1,2,3};  
  std::list<int> lst2 = {9,2,3};
  std::list<int> lst3 ={0,0,0};


  print(vec.begin(), vec.end()); //test print
  find(vec.begin(), vec.end(), 2);
  in(vec.begin(), vec.end(), 4);
  count(vec.begin(), vec.end(), 1);
  equal(vec.begin(), vec.end(), vec2.begin(), vec2.end());
  std::cout << "minimum pointer: " <<* minimum(vec.begin(), vec.end()) << '\n';
  std::cout << "maximum pointer: " <<* maximum(vec.begin(), vec.end()) << '\n';
  copy(vec.begin(), vec.end(), vec3.begin(), vec3.end());
  int num = 0;
  filler(vec3.begin(), vec3.end(), num);
  print(vec.begin(), vec.end()); //test print
  reverse(vec.begin(), vec.end());
  print(vec.begin(), vec.end()); //test print
  


  print(lst.begin(), lst.end()); //test print
  find(lst.begin(), lst.end(), 2);
  in(lst.begin(), lst.end(), 4);
  count(lst.begin(), lst.end(), 1);
  equal(lst.begin(), lst.end(), lst2.begin(), lst2.end());
  std::cout << "minimum pointer: " <<* minimum(lst.begin(), lst.end()) << '\n';
  std::cout << "maximum pointer: " <<* maximum(lst.begin(), lst.end()) << '\n';
  copy(lst.begin(), lst.end(), lst3.begin(), lst3.end());
  filler(lst3.begin(), lst3.end(), num);
  return 0;
}

