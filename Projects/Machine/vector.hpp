// Sam Borick <sb205@uakron.edu>

#ifndef Vector_HPP
#define Vector_HPP

#include "test.hpp"
#include "memory.hpp"
#include <initializer_list>

template<typename T>
struct Vector
{
  Vector(std::initializer_list<T> list)
  :base(), last(), limit()
{
  reserve(list.size());
  for (T const& s : list)
    push_back(s);
}

  T* base = nullptr;
  T* last = nullptr;
  T* limit = nullptr;

  Vector(){
   // reserve(8);
  }

  Vector(const Vector& v){
    reserve(v.size());
    base = last;
    last = uninitialized_copy(v.base, v.last, base);
}

  Vector& operator=(const Vector & v){  //this is a neat optimization I found on stackoverflow.  I think it's
  //really elegant and now I understand the difference between copy construction and copy assingnment better
    Vector p = v; 
    swap(*this, p);
    return *this;
  }

  T& operator[](const size_t pos)const{
    assert(pos >=0);
    assert(pos < size());
    return base[pos];
  }

   ~Vector(){
    initialized_destroy(base, last);
    deallocate(base); 
  }

  void clear(){
    resize(0);
  }

  size_t size()const{
    return last - base;
  }
  
  void swap(Vector & v1, Vector & v2){
    std::swap(v1.base, v2.base);
    std::swap(v1.last, v2.last);
    std::swap(v1.limit, v2.limit);
  }

  void reserve(std::size_t n){
    if(!base){
      base = allocate<T>(n);
      last = base;
      limit = n + base;
    }else if(n <= capacity()){
    }else{
      T* p = allocate<T>(n);
      T* q = p;
      for(T*i = base; i != last; ++i){
        new(q)T(*i);
        ++q;
      }
      for(T*i = base; (i==last); ++i){
        i ->~T();
      }
      deallocate<T>(base);
      base = p;
      last = q;
      limit = base + n;
    }
  }

  void resize(std::size_t n){
    if(n == size()){
    }else if(n < size()){
      //int counter = size() - n;
      for(int counter= size() - n; counter > 0; --counter){
         destroy(--last);
      }
    }else{
      //int counter = n - size();
      for(int counter= n - size(); counter >= 0; --counter){
        push_back("");//yeah, gross
        //TODO: make this better with construct
      }
    }
  }

  bool empty()const{
    return (base == last);
  }
  
  void push_back(T const & s){
    if(!base){
      reserve(8);
    }else if(last == limit){
      reserve(2*capacity());
    }
    construct(last++, s);
  }

  void pop_back(){
    assert(!empty());
    destroy(--last);
  }
 
  size_t capacity()const{
    return limit - base;
  }
  
  const T& back()const{
    return *(last-1); 
  }

  T const* data(){
    return base;
  }
  
  using iterator = T*;
  using const_iterator = T*;

  iterator begin(){
    return base;
  }

  iterator end(){
    return last;
  }

  const_iterator begin()const{
    return base;
  }

  const_iterator end()const{
    return last;
  }

};

template<typename T>
bool operator==(Vector<T> const &, Vector<T> const &);
template<typename T>
bool operator!=(Vector<T> const &, Vector<T> const &);
template<typename T>
bool operator<(Vector<T> const &, Vector<T> const &);
template<typename T>
bool operator>(Vector<T> const &, Vector<T> const &);
template<typename T>
bool operator<=(Vector<T> const &, Vector<T> const &);
template<typename T>
bool operator>=(Vector<T> const &, Vector<T> const &);

template<typename T>
bool operator ==(Vector<T> const & v1, Vector<T> const & v2){
 /* std::size_t counter = 0;
  if(v1.size() != v2.size()){
    return false;
  }
  while (counter < v1.size()) {
    if(v1.base+counter != v2.base+counter){
      return false;
    }
    ++counter;
  }
  return true;
  */
  return std::equal(v1.base, v1.last, v2.base);
}
template<typename T>
bool operator !=(Vector<T> const &v1, Vector<T> const & v2){
  return !(v1==v2);
}
template<typename T>
bool operator<(Vector<T> const &v1, Vector<T> const & v2){
  return std::lexicographical_compare(v1.base, v1.last, v2.base, v2.last);
}
template<typename T>
bool operator>(Vector<T> const& v1, Vector<T> const & v2){
  return std::lexicographical_compare(v2.base, v2.last, v1.base, v2.last);
}
template<typename T>
bool operator<=(Vector<T> const& v1, Vector<T> const & v2){
  return !(v1>v2);
}
template<typename T>
bool operator>=(Vector<T> const& v1, Vector<T> const & v2){
  return!(v1<v2);
}


#endif

/*#ifndef VECTOR_HPP  //old vector re-direct
#define VECTOR_HPP

#include "test.hpp"

#include <vector>


template<typename T>
using Vector = std::vector<T>;


#endif*/
