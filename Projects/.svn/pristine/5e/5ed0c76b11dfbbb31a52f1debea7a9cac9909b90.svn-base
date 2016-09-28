//Sam Borick
// string.hpp: Definition of the string class and its interace.

#ifndef STRING_HPP
#define STRING_HPP

#include "test.hpp"
#include <cstring>
#include <iosfwd>
#include <iostream>

struct String
{
  // Defines the npos value.
  static constexpr std::size_t npos = -1;
  int len;
  char *str;

  String()
  :len(0), str(0){}
 
  String(char const * S);
  ~String(){
     delete[]str;
  }
  String (char *S, std::size_t const n);
  String(const String &s)
   :len(s.len), str(strcpy(new char[s.len + 1], s.str)){}
 
  String & operator +=(String const &S);
  char* data() const;
  bool empty() const;
  size_t size() const;  
  String &operator =(String const &s); //assignment operator
  void swap(String &s);
  size_t find(const char c)const;
  char &operator[](const size_t pos)const;
  String substr(int index, int dist)const;
};


// Output
std::ostream& operator<<(std::ostream&, String const&);
//String operator +=(String const &);
bool operator <(String const &, String const &);
bool operator >(String const &, String const &);
bool operator <=(String const &, String const &);
bool operator >=(String const &, String const &);
bool operator ==(String const &, String const &);
bool operator!=(String const &, String const &);
String operator +(String const &, String const &);

#endif
