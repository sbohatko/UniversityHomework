//
//  main.cpp
//  lab1.6.2
//
//  Created by Aleksandr Bogatko on 24.03.2020.
//  Copyright © 2020 Aleksandr Bogatko. All rights reserved.
//
long double fact(int N)
{
    if(N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * fact(N - 1);
}

#include <iostream>
#include <math.h>
int main(int argc, const char * argv[]) {
    double x,f,u, s=0;
    int N, i, k=0, first = 0;
    std::cout<<"Enter num x: "; //Task 1
    std::cin>>x;
    std::cout<<"\nResults:\n";
    do{k++;
        for(i=1,f=1;i<=2*k-1;i++)
            f*=i;
        u=pow(-1, k+1)*pow(x, 2*k)/fact(k)*pow(x,k-1);
        s+=u;
    }while(fabs(u)>=1e-4);
    std::cout<<"Sum = "<<s<<"\n";
    std::cout<<"Quantities of additions = "<<k<<"\n";
        std::cout<<"Enter x: ";//Task 2
        std::cin>>x;
        std::cout<<"####MENU####\n";
        std::cout<<"1.for\n";
        std::cout<<"2.while\n";
        std::cout<<"3.do while\n";
        std::cout<<"Choose command: ";
        int ch, sum =0;
        std::cin>>ch;
    switch(ch){
        case 1:for(int k=1;k<=9;k++){
            u=pow(x, k+1)/pow(k+1, x); sum+=u;
        }   std::cout<<"Sum = "<<sum<<"\n";
            break;
        case 2:while(k<=9){k++;u=pow(x, k+1)/pow(k+1, x);
        sum+=u;};
            std::cout<<"Sum = "<<sum<<"\n";
        case 3:do{k++;u=pow(x, k+1)/pow(k+1, x);
            sum+=u;}while(k<=9);
            std::cout<<"Sum = "<<sum<<"\n";
    }
    
    
            std::cout<<"N = ";  std::cin>>N; //Task3
            while(N>0)
            {
                first=N%10;
                N=N/10;
            }
            std::cout << "First = " << first << "\n";
    return 0;
}
