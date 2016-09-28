
//Sam Borick

#include <iostream>
#include <assert.h>

void print(int* first, int* last){
  while (first != last) {
    if(last -1 == first){
       std::cout << *first;
    }else{
    std::cout << *first << ' ';
    }
    ++first;
  }
  std::cout << '\n';
}

int* find(int* first, int* limit, int value){
  while (first != limit) {
    if(*first == value){
      return first;
    }else{
    ++first;
    }
  }  
  return nullptr;  
}

bool in(int* first, int* limit, int value){
  if(find(first, limit, value) != nullptr){
    return true;
  }else{
    return false;
  }
}

int count(int* first, int* limit, int value){
  int output = 0;
  while (first != limit) {
    if(*first == value)
      output++;
    ++first;
  }
  return output;
}

bool equal(int* first1, int* limit1, int* first2, int* limit2){
  while (first1 != limit1 && first2 != limit2) {
    if(*first1 != *first2){
      return false;
    }
    ++first1;
    ++first2;
  }
  return true;
}

int* minimum(int* a, int* b){
 int val = *a; 
 int* min = &val;
  while (a != b) {
    if(*min > *a){
      min = a;
    }
    ++a;
  }
  return min;
}

int minimum(int a, int b){
  if(a < b)
    return a;
  else
    return b;
}


int* maximum(int* a, int* b){
 int val = *a; 
 int* min = &val;
  while (a != b) {
    if(*min < *a){
      min = a;
    }
    ++a;
  }
  return min;
}

int maximum(int a, int b){
  if(a > b)
    return a;
  else
    return b;
}

int compare(int* first1, int* limit1, int* first2, int* limit2){
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

void copy(int* first1, int* limit1, int* first2, int* limit2){
  assert(limit1 - first1 == limit2 - first2);
  while (first1 != limit1 && first2 != limit2) {
    *first2 = *first1;
    first1++;
    first2++;
  }
}

void fill(int* first, int* limit, int value){
  while (first != limit) {
    *first = value;
    ++first;
  }
}

int main(){
  int a[] = {1,2,3,4,5};
  int* first = a;
  int* limit = a +5;
  int b[] = {1,2,3,4,4};
  int* first2 = a;
  int* limit2 = a+5;
  int c[] = {0,0,0,0,0};
  int* first3 = c;
  int* limit3 = c+5;
  
  print(first, limit); //test print
  std::cout << "Find: " << find(first, limit, 2) << '\n';
  std::cout << "In: " << in(first, limit, 4) << '\n';
  std::cout << "count: " << count(first, limit, 1) << '\n';
  std::cout << "equal: " << equal(first, limit, first2, limit2) << '\n';
  std::cout << "minimum int: " << minimum(1,3) << '\n';
  std::cout << "minimum pointer: " <<* minimum(first, limit) << '\n';  
  std::cout << "maximum int: " << maximum(1,3) << '\n';
  std::cout << "maximum pointer: " <<* minimum(first, limit) << '\n';
  copy(first, limit, first3, limit3);
  print(first3, limit3);
  fill(first3, limit3, 0);
  print(first3, limit3);
  return 0;
}

