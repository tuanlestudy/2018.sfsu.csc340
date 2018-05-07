//
//  Politomial.cpp
//  Polytomial
//
//  Created by Le Tuan on 4/3/18.
//  Copyright © 2018 Le Tuan. All rights reserved.
//

#include "Polynomial.hpp"

Polynomial::Polynomial():coeff(MAX_EXP+1,0.00){
    //method 1.
    //coeff.resize(MAX_EXP+1, 0.00);
    
    //method 2. initialization list/segment
    
}

Polynomial::Polynomial(double const_val):coeff(MAX_EXP+1,0.00){
    coeff[0] = const_val; //skipped the validity check
    
}

double Polynomial::get_coeff(int exponent) const{
    if(exponent >= 0 && exponent <= MAX_EXP){
        //coeff[exponent]= 0.0;
        return coeff[exponent]; //coeff.at(exponent)
    }
    else{
        cerr << "Out of boundary ...\n";
        return 0;
    }
}

void Polynomial::set_coeff(int exponent, double new_coeff){
    //skip the validty check for exponent
    coeff[exponent] = new_coeff;
}

Polynomial Polynomial::operator-() const{
    Polynomial neg;
    
    for (int i=0; i<MAX_EXP; i ++){
        //neg.coeff[i] = -(this->coeff[i]);
        neg.coeff[i] = -(coeff[i]);
    }
    return neg;
}
