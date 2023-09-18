#include"CityCar.hpp"
#include"SportsCar.hpp"
#include"car.hpp"
#include<iostream>
int main(){

   //Auto car(11, "Hunde", 50, 0.51);  //mit virtual kann diese Klasse nicht mehr durchgeführt werden.Linkerfehler) dient als eine Vorlage. 
   CityCar citycar(12, "Hundie", 50, 0.51,30,100);
   SportsCar sportscar1(13, "Hundy", 50, 0.51,10.0);
   SportsCar *sportcar; 
   Auto *carPtr; //aber der Zeiger kann definiert werdenm und auf Objekt vom Typ erbender Klasse zu zeigen. 
   carPtr=&sportscar1; //hier zeigt untergeordnete klasse, dann wird die virtuelle Methodie nicht aufgerufen.
   sportcar=&sportscar1; 

   std::cout<<carPtr->checken()<<std::endl; //nach Zeigen auf der erbender Klasse, der Zeiger kann trotzdem der zusätzlcihen Member nicht zugreifen. 
   std::cout<<citycar.honk()<<std::endl; 
   std::cout<<sportscar1.honk()<<std::endl; 

// std::cout<<"hahahaahahaah"<<std::endl; 

//   std::cout<<citycar.drive(10)<<std::endl; 

//  //Fahren von 10km , wie man bei zwei Variable initialisiert. 
//    std::cout<<citycar.entladen(25.0)<<std::endl; 

//     std::cout<<citycar.beladen(25.0)<<std::endl; 
    

//     std::cout<< sportcar->checken()<<std::endl; 
    
//     std::cout<<sportcar->checken()<<std::endl; 
    delete(sportcar); 
    delete(carPtr); 
 
 return 0; 
}