 /********************************************************************
  * Lab 13 : Rational.cpp
  *
  * Author: Your Name
  *         UANETID@zips.uakron.edu
  *
  * Purpose: Implementation file containing definitions for Rational class
  *
  ********************************************************************/

#include "Rational.h"

/* Default constructor already provided */
Rational::Rational() {
    numerator = 1;
    denominator = 1;
}

/* Implement overloaded (int, int) constructor */


/* Implement printOut() member function */


/* Implement reduce() member function */



/*
  Greatest common factor is already 
  implemented for you, so do not modify it.

  This function uses recursion,
  you will learn about it later.
 */
int gcf(int a, int b) {
    int result = 0;

    if (a < b) {
        result = gcf(b, a);
    }
    else if (b == 0) {
        result = a;
    }
    else {
        result = gcf(b, (a % b));
    }
    return result;
}

