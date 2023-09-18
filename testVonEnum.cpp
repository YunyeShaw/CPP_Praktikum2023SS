#include<iostream>
#include<utility>
#include<string> 

// enum myEnum: char{value1, value2}; 

// void identify(myEnum value){
//     std::string a="It is the Value of : "; 
//     switch(value){
//     case 0:
//     std::cout<<a<<"Value 1"<<std::endl; 
//     break; 
//     case  value2:
//     std::cout<<a<<"Value 2"<<std::endl; 
//     break;
//     default: 
//     std::cout<<"this is not a value. "<<std::endl; 
// }
// }


int main(){
    // myEnum myEnum1=value1; 
    // identify(myEnum1);
    // uint8_t someNumber=128; 
    
    // std::cout<<"This someNumber is: "<<std::hex<<someNumber<<std::endl; 
    // const double pi=3.14; 
    // double & toAnotherNumber=const_cast<double &>(pi); 
    // toAnotherNumber=4.0; 
    // std::cout<<toAnotherNumber<<std::endl; 
    // std::cout<<pi<<std::endl; 
    auto studentName=std::pair<std::string, size_t>("Hans Meier",1); 
    std::cout<<"balabala is : "<<studentName.first<<" balabal is: "<<studentName.second<<std::endl; 

    return 0;  
}