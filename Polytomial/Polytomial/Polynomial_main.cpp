//
//  main.cpp
//  Polytomial
//
//  Created by Le Tuan on 4/3/18.
//  Copyright © 2018 Le Tuan. All rights reserved.
//

#include <iostream>
#include "Polynomial.hpp"

int main(int argc, const char * argv[]) {
    Polynomial p1;
    Polynomial p2(1.1), p3;
    
    p1 = Polynomial(2.2);
    
    //p1 = 3.3;
    
    cout << p1.get_coeff(0) << endl;
    p1.set_coeff(2, 12.22);
    
    p3 = -p1.operator-( );
    return 0;
}
