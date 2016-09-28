// Sam Borick <sb205@uakron.edu>

#ifndef STACK_HPP
#define STACK_HPP

#include "test.hpp"
#include "vector.cpp"
#include <stack>



template<typename T>
//using Stack = std::stack<T>;

struct Stack{
  Vector<T> vec;

  Stack(){}//vec is already initialized to empty
  
  Stack(const Stack & S){
    vec = S->vec;
  }

  Stack& operator=(const Stack & S){
    Stack p = S;
    swap(*this, p);
    return *this;
  }

  void swap(Stack & a, Stack & b){
    swap(a->vec, b->vec);
  }

  bool empty(){
    return (vec.size() == 0);
  }

  size_t size(){
    return vec.size();
  }

  const T top()const{
    return vec.back();
  }

 /* T & top(){
    return vec.back();
  }*/

  void push(T input){
    vec.push_back(input);
  }

  void pop(){
    assert(!vec.empty());
    vec.pop_back();
  }

  
};



#endif
