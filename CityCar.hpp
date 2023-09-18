#ifndef CITYCAR_HPP
#define CITYCAR_HPP
#include<iostream>
#include"car.hpp"

class CityCar: public Auto{
    public:
    CityCar(const int& iD, const std::string& name, 
            const int& kapa, const double& bezinverbrauch, double lade, const double maxlade );
    double beladen(double c);
    double entladen(double b);
    std::string honk(){return "TOOT";}; 
    private: 
    const double _maxlade;
    double _lade; 
    
};





#endif 