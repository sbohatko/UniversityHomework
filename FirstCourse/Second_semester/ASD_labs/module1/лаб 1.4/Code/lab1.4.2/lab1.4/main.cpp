//
//  main.cpp
//  lab1.4
//
//  Created by Aleksandr Bogatko on 18.03.2020.
//  Copyright © 2020 Aleksandr Bogatko. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
// Задание 1
    int i, sum = 0, x, sum1 = 0;
    for(i=1; i<=10; i++) {
    std::cout<<"Enter "<<i<<" number: ";
    std::cin >> x;
        if(x>0)
        {
            sum += x;
        }
    }
    std::cout<<"\nSum of positive elements = "<<sum<<"\n\n";
        int arr[10];
    
// Задание 2
        for (int i = 0; i < 10; i++) { // Заполняем массив с клавиатуры
            std::cout << "[" << i + 1 << "]" << ": ";
            std::cin >> arr[i];
            if(arr[0]<arr[i]) //если следующий елемент больше чем первый
            {
                sum1+=arr[i];
            }
        }
    std::cout<<"Sum of elements larger than first = " << sum1<<"\n\n";
    return 0;
}
