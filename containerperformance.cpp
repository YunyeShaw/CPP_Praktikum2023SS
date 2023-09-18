#include<iostream>
#include<vector>
#include<list>
#include<memory>
#include<random>
#include<algorithm>
#include<iterator>
#include <chrono>
#include <thread>

int amout= 100000000; 
int voramout=100000; 

int main(){
    std::vector<int> myVector; 
    auto startTime=std::chrono::steady_clock::now();
    for (auto i=0; i<=voramout; ++i)
    {
       
        myVector.insert(myVector.begin(),0); 
    }
    //std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    auto endTime=std::chrono::steady_clock::now(); 
    auto duration=std::chrono::duration_cast<std::chrono::milliseconds>(endTime-startTime); 

    std::cout<<"Zeit von Vector von Vorne bearbeitet: "<<duration.count()<<std::endl; 

    for(auto i=0; i<=voramout; ++i)
    {
        myVector.erase(myVector.begin()); 
    }
    std::vector<int> myVector2; 
    for(auto i=0; i<50000; ++i){
        myVector2.push_back(0);
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(myVector2.begin(), myVector2.end(), g);

    // for (auto i=0; i<=amout; ++i)
    // {
    //     myVector.push_back(0); 
    // }
    // for(auto i=0; i<=amout; ++i)
    // {
    //     myVector.pop_back(); 
    // }
    //  myVector.clear(); 
   
    // for (auto i=0; i<=amout; ++i)
    // {
    //     std::cout<<myVector[i]<<std::endl; 
    // }
    //   for (auto i=0; i<=amout; ++i)
    // {
    //     myVector.erase(0); 
    // }
    // for (auto i=0; i<=amout; ++i)
    // {
    //     std::cout<<myVector[i]<<std::endl; 
    // }
     std::cout<<myVector.size()<<std::endl; 
}