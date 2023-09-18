#include<iostream>
#include"car2.hpp"

int main(){

   Auto<int> car=Auto<int>(11, "Hunde", 50, 0.51); 
  car.drive(20); //Tanken von 20l 
  std::cout<<car.fillLevel()<<" "<<car.milage()<<" "<<car.reach()<<std::endl; 

   car.drive(0,10);  //Fahren von 10km , wie man bei zwei Variable initialisiert. 
   std::cout<<car.fillLevel()<<" "<<car.milage()<<" "<<car.reach()<<std::endl; 


    car.refuel(50); //Volltanken, soll man hier refuel benutzen?
    std::cout<<car.fillLevel()<<" "<<car.milage()<<" "<<car.reach()<<std::endl; 
    
    car.drive(car._fuellstand); //Fahren, bis Tank leer ist
    std::cout<<car.fillLevel()<<" "<<car.milage()<<" "<<car.reach()<<std::endl; 
    
    car.refuel(50); //Volltanken, soll man hier refuel benutzen? 
    std::cout<<car.fillLevel()<<" "<<car.milage()<<" "<<car.reach()<<std::endl; 
   
    std::cout<<car.refuel(101)<<std::endl;
    std::cout<<car.fillLevel()<<" "<<car.milage()<<" "<<car.reach()<<std::endl; 
 
 return 0; 
}