#include<iostream> 
using namespace std;

enum  ShirtColor :  long{
    Red=1, Black, WHITE
}; 

namespace FlowerColor{ //mit enum class kann diesen namespace sparen. 
enum FlowerColor : long{
    ROSE_RED, LILAC, SUN_YELLOW, WHITE
};
}

int main(){
   ShirtColor shirtColor; 
   shirtColor = ShirtColor::Red;
   switch(shirtColor)
   {
    case(ShirtColor::Red): 
   cout<<"Red"<<std::flush;  break; 
    case(ShirtColor::Black): 
    cout<<"Black"<<flush; break; 
    case(ShirtColor::WHITE): 
    cout<<"weiß"<<endl; 
    break; 
    default: 
    cout<<"Unbekannte Farbe"<<endl; 
   }
    // cout<<shirtColor<<endl; 

    return 0; 
}