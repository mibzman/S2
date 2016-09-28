// Sam Borick <sb205@uakron.edu>
// rational.hpp: Definition of rational class and its interace.

#include "string.hpp"
#include <iostream>

String::String(char const * S){
  assert(S != 0);
    len = strlen(S); //I know this is ineffiecent but I was having issues with calling strlen outside the method
    str = new char[len + 1];
    strcpy(str, S);
  }

String::String (char *S, std::size_t const n)
  :len(n), str(new char[n + 1]){
    assert(S != 0);
    assert(strlen(S) >= n);
    strncpy(str, S, n);
    str[len] = '\0';
  }

std::ostream&
operator<<(std::ostream& os, String const& str)
{
  return os << str.data();
}

bool operator ==(String const & a, String const & b){
  return (strcmp(a.str,b.str)==0);
}

bool operator !=(String const & a, String const & b){
  return !(a==b);
}

String operator + (String const &a, String const &b){
  int n = a.len + b.len;
  char *p = new char[n+1];
  strcpy(p, a.str);
  strcpy(p + a.len, b.str);
  String output;
  output.str = p;
  output.len = n;
  return output;
}

bool operator <(String const &a, String const &b){
  return (strcmp(a.str,b.str)<0);
}

bool operator >(String const &a, String const &b){
  return (strcmp(a.str,b.str)>0);
}

bool operator >=(String const &a, String const &b){
  return (strcmp(a.str,b.str)>=0);
}

bool operator <=(String const &a, String const &b){
  return (strcmp(a.str,b.str)<=0);
}


char* String::data() const {
    return this->str;
}

bool String::empty() const {
    return (this->len == 0);
}


String& String::operator +=(String const &S){
    size_t n = this->len + S.len;
    char * p = new char[n+1];
    memcpy(p, str, len);
    memcpy(p + len, S.str, S.len+1);
    delete[]str;
    len = n;
    str = p;
    return *this;
}

size_t String::size()const {
    size_t temp = len;
    return temp;
}

  //assignment operator
String& String::operator =(String const &s){
    String temp(s);
    swap(temp);
    return *this;
}

void String::swap(String &s){
    std::swap(len, s.len);
    std::swap(str, s.str);
}

size_t String::find(const char c)const{
    char * p = strchr(this->str, c);
    if(p){
      return (p-str);
    }else{
       return npos;
    }
}

String String::substr(int index, int dist)const{
    String output((this->str + index) ,dist);
    return output;
}

char& String::operator[](const size_t pos)const{
    assert(pos >= 0);
    assert(pos < this->size());
    return str[pos];
}
