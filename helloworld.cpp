#include <stdio.h>
#include <iostream>
#include<string>

using namespace std;

int main(int, char **){
    string a; 
    int b; 
    std::cout<<"Geben Sie Ihr Name ein: "<< std::endl;
    std::cin>>a;
    std::cout<<"Geben Sie Ihr Alter ein: "<< std::endl;
    std::cin>>b;
    std::cout<<a<<" "<<std::endl; 
    std::cout<<b<<" Alter"<<std::endl; 

    return 0;
}