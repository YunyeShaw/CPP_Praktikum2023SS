#ifndef CAR_HPP
#define CAR_HPP

#include<iostream>

class Auto
{
    public: 
            Auto(const int& iD, const std::string& name, 
            const int& kapa, const double& bezinverbrauch); 

            bool refuel(double a); 
            double drive(double a=0, double b=0); 
            double fillLevel(); 
            double reach(); 
            double milage(); 
            double _fuellstand=50.0; 
            double _kilometerstand=0.0 ; 
            double _reichWeite=0.0; //braucht man hier ? 
            virtual std::string honk(); 
            int getiD(){return _iD; };
            std::string getname(){return _name; }; 
            int getkapa(){return _kapa; }; 
            double getbezinverbrauch(){return _bezinverbrauch; }; 

    private: 
            int _iD; 
            std::string _name; 
            int _kapa; 
            double _bezinverbrauch; 
    
};
#endif