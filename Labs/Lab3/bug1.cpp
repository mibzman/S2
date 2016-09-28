 // (c) 2016 Andrew Sutton
// All rights reserved
//Modified by Sam Borick 2016

#include <iostream>
#include <vector>


int main()
{
  // Print the numbers in v in reverse order.
  std::vector<int> v =  { 1, 2, 3, 4, 5 };
  for (int i=4; i >= 0; i--)
    std::cout << v[i] << '\n';
  return 0;
}

