//
//  main.cpp
//  lab4
//
//  Created by Aleksandr Bogatko on 17.03.2020.
//  Copyright © 2020 Aleksandr Bogatko. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <cmath>

int main(int argc, const char * argv[]) {
    double y, n, d,
             t, x, b, a, v, C, L, T,
            v2;
    
    std::cout<<"First Task.\n"; //Первое задание
    std::cout << "Enter y : ";
    std::cin>>y;
    std::cout << "Enter n : ";
    std::cin>>n;
    d = pow(y, 2)+(0.5*n+4.8)/sin(y); // уравнение
    std::cout<<d;
        std::cout<<"\n\nSecond Task.\n"; //Второе задание
        std::cout<<"Enter x: ";
        std::cin>>x;
        std::cout<<"Enter b: ";
        std::cin>>b;
        std::cout<<"Enter a: ";
        std::cin>>a;
        t = (sqrt(x+b-a)+log10(x)) / (cos(b+a)/sin(b+a)); // уравнение
        std::cout<<t;
            std::cout<<"\n\nThird Task.\n"; //Третье задание
            std::cout<<"Enter x: ";
            std::cin>>x;
            v2 = pow(sin(x)- 5.4, 3*x) + sqrt(abs(pow(log(x-1.5), 1.0/3.0))+ pow(x, 3.5)); // уравнение
            std::cout<<v2;
                std::cout<<"\n\nFourth Task.\n"; //Четвёртое задание
                std::cout<<"Enter x: ";
                std::cin>>x;
                y = ((log(pow(x, 2))+pow(cos(x),2)) / (cos(2*x)+pow(x,2))) + pow(x, 1.0/3.0)/x;
                std::cout<<y;
                    std::cout<<"\n\nFifth Task.\n"; //Пятое задание
                    const double p = 5.3, k = 3;
                    std::cout<<"Enter a: ";
                    std::cin>>a;
                    std::cout<<"Enter b: ";
                    std::cin>>b;
                    y = pow(a, 2) + pow(b, 2);
                    a = log(abs(p));
                    b = exp(k) + a;
                    std::cout<<"y = "<< y;
                    std::cout<<"\na = "<< a <<"\n";
                    std::cout<<"b = "<< b <<"\n";
                        std::cout<<"\n\nSixth Task\n"; //Шестое задание
                        std::cout<<"Enter C: ";
                        std::cin>>C;
                        std::cout<<"Enter L: ";
                        std::cin>>L;
                        const double pi = 3.1415;
                        T = 2*pi*sqrt(L*C);
                        v = 1/T;
                        std::cout<<"T = " << T << "\n";
                        std::cout<<"v = " << v << "\n";
    return 0;
}
