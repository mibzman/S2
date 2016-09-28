// (c) 2016 Andrew Sutton
// All rights reserved

#include <iostream>


// A fraction is like a rational number, but is primarily designed
// to represent the ratio of two numbers, not the qotient. That is
// to say, a fraction is an unreduced rational number.
//
// NOTE: This is just a stub of a class, used for the purpose of
// testing.
struct Fraction
{
  // Initalize the raitonal to 0/1 (i.e.,, just 0).
  Fraction() : n(0), d(1) { }

  // Initilize the fracto to p/q.
  Fraction(int p, int q) : n(p), d(q) { }

  int n, d;
};


// Returns true when a and b have the same numerators and
// denominators.
bool
operator==(Fraction a, Fraction b)
{
  return a.n == b.n && a.d == b.d;
}

// Returns true when the numerators or denominators of a and
// b differ.
bool
operator!=(Fraction a, Fraction b)
{
  return !(a == b);
}


// Write the given fraction to the output stream.
std::ostream&
operator<<(std::ostream& os, Fraction f)
{
  return os << f.n << '/' << f.d;
}


int main()
{
  Fraction f1(3, 4);
  Fraction f2(1, 3);

  // Check that operator != works. Should print true.
  std::cout << (f1 != f2) << '\n';
}
