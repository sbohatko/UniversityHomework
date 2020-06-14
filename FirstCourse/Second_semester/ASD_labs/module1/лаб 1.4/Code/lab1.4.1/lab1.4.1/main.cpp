//
//  main.cpp
//  lab1.4.1
//
//  Created by Aleksandr Bogatko on 19.03.2020.
//  Copyright © 2020 Aleksandr Bogatko. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std; int main()
{
double x, h, z, y, u, s=0;
    
int i, n;
std::cout<<"Enter number n = ";
std::cin>> n;
std::cout<< "\nResults:\n";
    for(i=1; i<=n; i++)
    {
    u = pow(-1,i+1.0)/2*(i+1);
    std::cout<< "Addition " << i << " = " << u << endl;
    s+=u;
    }
std::cout<< "Sum = " << s << "\n";
    std::cout<<"\nFunction.";
    std::cout<<"\nEnter x: ";
    std::cin>>x;
    std::cout<<"Enter h: ";
    std::cin>>h;
    std::cout<<"\tResults\n";
    for(x=-6; x<=1+0.1*h; x+=h){
        y=atan(x+3.1);
        z=exp(x);
        std::cout<<"x = " <<x<<"\ty = "<<y<<"\tz = "<<z<<"\n";
    }
return 0;
}
