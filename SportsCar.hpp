#ifndef SPORTSCAR_HPP
#define SPORTSCAR_HPP
#include<iostream>
#include"car.hpp"
class SportsCar: public Auto{
    public:
    SportsCar(const int& iD, const std::string& name, 
            const int& kapa, const double& bezinverbrauch, bool verdeck);
    bool checken(); 
     std::string honk(){return "Get off my lane!!";}; 
    private: 
    bool _verdeck; 
   
};

#endif