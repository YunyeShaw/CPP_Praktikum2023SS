#include "car.hpp"

Auto::Auto(const int& iD, const std::string& name, const int& kapa, 
const double& bezinverbrauch) 
: _iD(iD), _name(name), _kapa(kapa), _bezinverbrauch(bezinverbrauch)
{
    std::cout<<"C of L"<<std::endl; 
}

bool Auto::refuel(double a)
{
    if(a+_fuellstand>=_kapa)
    {
        _fuellstand=_kapa;
        _reichWeite=0; 
        return 1; }
    else
    {
        _reichWeite=0; 
        _fuellstand+=a; 
    return 0; 
    } 

}
double Auto::drive(double a, double b) //b ist km, a ist Liter wie viel kilo möchte man noch fahren. wie kann man hier verbessern 
{
    if(a!=0){
         _fuellstand=_fuellstand-a;
    _reichWeite=a/_bezinverbrauch;
    _kilometerstand=_kilometerstand+_reichWeite; 
    return 0; 
    }
    else{
    if ((b*_bezinverbrauch+_fuellstand)>=_kapa)
    {_fuellstand=0; 
    _reichWeite=_fuellstand*_bezinverbrauch; 
    _kilometerstand=_kilometerstand+_reichWeite; 
   return _reichWeite;}
   else {
    _fuellstand=_fuellstand-b*_bezinverbrauch;
    _reichWeite=b;  
    _kilometerstand=_kilometerstand+b; 
    return _reichWeite; 
   }
    }
}
double Auto::fillLevel()
{
    return _fuellstand; 
}
double Auto::reach()
{ 
    return _reichWeite;  
}
double Auto::milage()
{
    return _kilometerstand; 
}

std::string Auto::honk()
{
    return "BEEP";
}