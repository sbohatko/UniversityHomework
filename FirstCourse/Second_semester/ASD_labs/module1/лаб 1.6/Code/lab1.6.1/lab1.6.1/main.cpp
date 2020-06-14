//
//  main.cpp
//  lab1.6.1
//
//  Created by Aleksandr Bogatko on 24.03.2020.
//  Copyright © 2020 Aleksandr Bogatko. All rights reserved.
//

#include <iostream>
#include <cmath>
long double fact(int N)
{
    if(N < 0) // если пользователь ввел отрицательное число возвращаем ноль
        return 0;
    if (N == 0) // если пользователь ввел ноль,возвращаем факториал от нуля
        return 1;
    else // Во всех остальных случаях - делаем рекурсию.
        return N * fact(N - 1);
}
int main(int argc, const char * argv[]) {
    double x, k, y = 0.0, sum = 0;
    int p = 1;
    std::cout<<"Task 1.\n";
    std::cout<<"Enter x: ";
    std::cin>>x;
    for(int i=1;i<=6;i++){
        y =pow(-1,i)*pow(x, 2*i)/fact(3*i-1);
        sum+=y;
    }
    std::cout<<"Sum = "<<y;
        std::cout<<"\nTask 2.\n";
        std::cout<<"Enter k: ";
        std::cin>>k;
        for(int j =-4;j<=k;j++){
            p *= j+2./j-3.;
            for(int i = -4; i<=k+5;i++){
                if(i%2==0){
                    sum +=pow(i+5., 1/5) / (i-11.) *p;}
            }
        }
        std::cout<<"Sum = "<<sum<<"\n";
    return 0;
}
