// Sam Borick <sb205@uakron.edu>

#ifndef STRING_VECTOR_HPP
#define STRING_VECTOR_HPP

#include "string.hpp"
#include "memory.hpp"
#include "test.hpp"

#include <initializer_list>


struct String_vector
{
  String_vector(std::initializer_list<String>);
  String* base = nullptr;
  String* last = nullptr;
  String* limit = nullptr;

  String_vector(){
   // reserve(8);
  }

  String_vector(const String_vector& v);

  String_vector& operator=(const String_vector & v){  //this is a neat optimization I found on stackoverflow.  I think it's
  //really elegant and now I understand the difference between copy construction and copy assingnment better
    String_vector p = v; 
    swap(*this, p);
    return *this;
  }

  String& operator[](const size_t pos)const{
    assert(pos >=0);
    assert(pos < size());
    return base[pos];
  }

  ~String_vector();

  void clear();

  size_t size()const;
  
  void swap(String_vector & v1, String_vector & v2);

  void reserve(std::size_t n);

  void resize(std::size_t n);

  bool empty()const;
  
  void push_back(String const & s);

  void pop_back();
  
  size_t capacity()const;

  String const* data();
  
  using iterator = String*;
  using const_iterator = String*;

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

bool operator==(String_vector const &, String_vector const &);
bool operator!=(String_vector const &, String_vector const &);
bool operator<(String_vector const &, String_vector const &);
bool operator>(String_vector const &, String_vector const &);
bool operator<=(String_vector const &, String_vector const &);
bool operator>=(String_vector const &, String_vector const &);


#endif
