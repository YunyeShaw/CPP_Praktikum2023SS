#include <stdio.h>
#include <iostream>
#include<string>

using namespace std;

int printNameAndAge(string name, int alter){
    std::cout<<name<<" "<<std::endl; 
    std::cout<<alter<<" Jahre"<<std::endl; 
    if(alter>30)
    std::cout<<"du bist aber alt."<<std::endl; 
    else
    std::cout<<"Jundspund"<<std::endl; 
    return 0 ; 
}

int main(int, char **){
    string a, a1, a2; 
    int b; 
    std::cout<<"Geben Sie Ihr Name ein: "<< std::endl;
    std::cin>>a1>>a2;
    a = a1 + " " + a2;
    std::cout<<"Geben Sie Ihr Alter ein: "<< std::endl;
    std::cin>>b;
    printNameAndAge(a,b); 


    return 0;
}