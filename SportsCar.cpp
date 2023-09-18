#include"SportsCar.hpp"

SportsCar::SportsCar(const int& iD, const std::string& name, 
            const int& kapa, const double& bezinverbrauch, bool verdeck )
:Auto(iD, name,  kapa, bezinverbrauch), _verdeck(verdeck)
{}

bool SportsCar::checken(){
    double b=_verdeck; 
    if(b)
    return 0; 
    else
    return b; 
}