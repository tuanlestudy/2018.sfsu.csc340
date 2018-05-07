//
//  Politomial.hpp
//  Polytomial
//
//  Created by Le Tuan on 4/3/18.
//  Copyright © 2018 Le Tuan. All rights reserved.
//

#ifndef Polynomial_hpp
#define Polynomial_hpp

#include <iostream>
#include <vector>

using namespace std;

const int MAX_EXP = 1000;

class Polynomial {
private:
    vector<double> coeff;   //records the coefficients of up to (MAX_EXP+1)
                            //the i-th value in this vector is the coefficient of the x^i term
public:
    //constructors (don't need to include a destrucdtor)
    Polynomial();   //default constructor: initialize coeff to a vector of MAX_EXP+1 of 0.00
    explicit Polynomial(double const_val);   //initialize coeff to a vector of MAX_EXP+1 of 0.00 except coeff[0] = const_val
    //accessors
    double get_coeff(int exponent) const;     //return the coefficient of the x^exponent term
    //mutators
    void set_coeff(int exponent, double new_coeff); //coeff exponent } = new_coeff
    //overload the negation operatior (-) as a member function
    Polynomial operator-();
};

#endif /* Polynomial_hpp */
