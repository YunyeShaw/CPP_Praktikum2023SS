#include"fizzbuzz.hpp"
#include<iostream>
#include"fizzbuzz.hpp"

 int main()
 {
    while(1){
    std::cout<<"Geben Sie eine beliege Zahl ein: "<<std::endl; 
    int a;
    std::cin>>a; 
    fizzbuzz(a);
    }
 }
 
void fizzbuzz(int a)
{
    for(int i=1;i<=a;i++)
    {
        if(i%3==0)
        {
             if(i%5==0)
                std::cout << "FizzBuzz"<<std::endl;
            else
            std::cout <<"Fizz"<<std::endl; 
        }
       else if(i%5==0)
       std::cout <<"Buss"<<std::endl; 
       else 
       std::cout<<i<<std::endl;
        
    }
    return;
}