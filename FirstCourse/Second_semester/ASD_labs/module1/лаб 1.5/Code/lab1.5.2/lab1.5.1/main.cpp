//
//  main.cpp
//  lab1.5.1
//
//  Created by Aleksandr Bogatko on 23.03.2020.
//  Copyright © 2020 Aleksandr Bogatko. All rights reserved.
//

#include <iostream>
#include <cmath>
int main(int argc, const char * argv[]) {
    int n ;
    double x, y = 0.0, a, b, z, c, mean;
    const double PI = 3.141592653589793;
    std::cout<<"Task 1.\n";
    std::cout<<"Enter n: ";
    std::cin>>n;
    std::cout<<"Enter x: ";
    std::cin>>x;
    switch(n){
        case 1: y = tan(fabs(1+exp(x+1.2))) / x+sin(x);
            std::cout<<"Result: y = "<<y<<"\n";
            break;
        case 2: y = pow(cos(fabs(PI+x)),1/4);
            std::cout<<"Result: y = "<<y<<"\n";
            break;
        case 3: y = 1 +pow(x, x+1) - log(x) / (x*x*x)+log10(fabs(x));
            std::cout<<"Result: y = "<<y<<"\n";
            break;
        default: std::cout<<"Incorrect n.";
            break;
    }
            std::cout<<"\nTask 2.\n";
            std::cout<<"Enter n: ";
            std::cin>>n;
            std::cout<<"Enter x: ";
            std::cin>>x;
            switch(n){
                case 1: a=0.4; b=2.3; z=exp(2*x);
                    if(x<3.5*a){y = a*b*x-pow(cos(z*x),2);}
                    if(x>=3.5*a && x<=b){y = pow((a-x),2)-log10(z+x);}
                    if(x>b){y = sqrt(b*x-a+z*x*x);}
                    std::cout<<"Result: y = "<<y;
                    break;
                case 2: a=0.2; b=0.8; z=exp(x);
                    if(x<3.5*a){y = a*b*x-pow(cos(z*x),2);}
                    if(x>=3.5*a && x<=b){y = pow((a-x),2)-log10(z+x);}
                    if(x>b){y = sqrt(b*x-a+z*x*x);}
                    std::cout<<"Result: y = "<<y;
                    break;
                case 3: a=0.7; b=8.1; z=0.8;
                    if(x<3.5*a){y = a*b*x-pow(cos(z*x),2);}
                    if(x>=3.5*a && x<=b){y = pow((a-x),2)-log10(z+x);}
                    if(x>b){y = sqrt(b*x-a+z*x*x);}
                    std::cout<<"Result: y = "<<y;
                    break;
            }
                    std::cout<<"\nTask 3.\n";
                    std::cout<<"Enter n: ";
                    std::cin>>n;
                    switch(n){
                        case 1: a=3;b=3.5;c=-2.1;
                            mean = (a+b+c)/3;
                            std::cout<<"Mean of a = "<<a<<", b = "<<b<<", c = "<<c<<", is: "<<mean<<"\n";
                            break;
                        case 2:a=2.1;b=-6.55;c=0.1;
                            mean = (a+b+c)/3;
                            std::cout<<"Mean of a = "<<a<<", b = "<<b<<", c = "<<c<<", is: "<<mean<<"\n";
                            break;
                        case 3:a=-9;b=-3.7;c=-0.1;
                            mean = (a+b+c)/3;
                            std::cout<<"Mean of a = "<<a<<", b = "<<b<<", c = "<<c<<", is: "<<mean<<"\n";
                            break;
                        default: std::cout<<"Incorrect n.";
                    }
    return 0;
}
