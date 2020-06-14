//
//  main.cpp
//  lab1.5
//
//  Created by Aleksandr Bogatko on 23.03.2020.
//  Copyright © 2020 Aleksandr Bogatko. All rights reserved.
//

#include <iostream>
#include <cmath>

int main(int argc, const char * argv[]) {
    double x, y = 0.0;

    std::cout<<"Task 1.\n";
    std::cout<<"Enter x: ";
    std::cin>>x;
    if(x<-3){
        y=2*x+2;
    }else
        if(x>=-3 && x<=0)
    {
        y =2*x-2;
    }else
        if(x>0){
            y = x*x;
        }
    std::cout<<"Result: y = "<<y<<"\n\n";
        std::cout<<"Task 2\n";
        std::cout<<"Enter x:";
        std::cin>>x;
        double a = 0.54, b = 0.34, p = a*x+b;
        if(fabs(x)<0.7){y = pow(a, 2*b)*(x*x)+sqrt((pow(b,4)+2,7));}
        else if(fabs(x)==0.7){y = atan(pow(3, x) - p*x);}
        else if(fabs(x)>0.7){y = cbrt(log(fabs(a-p*x))+4.3);}
        std::cout<<"Result: y = "<<y<<"\n\n";
            std::cout<<"Task 3\n";
            std::cout<<"Enter angle value: ";
            std::cin>>x;
            double sinus = sin(x), cosinus = cos(x);
            std::cout<<"Sin = "<<sinus<<"\tCos = "<<cosinus;
            if (sinus>cosinus){std::cout<<"\nSin if grater than Cos";}
            else if(sinus<cosinus){std::cout<<"\nCos is grater than Sin\n";}
    return 0;
}
