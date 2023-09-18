
#include"CityCar.hpp"

CityCar::CityCar(const int& iD, const std::string& name, 
            const int& kapa, const double& bezinverbrauch, double lade,const double maxlade )
:Auto(iD, name,  kapa, bezinverbrauch), _lade(lade), _maxlade(maxlade)
{};


   double CityCar::beladen(double c)
   {
    if(_lade+c>_maxlade)
    {_lade=_maxlade; 
    return _maxlade; }
    else
    {
    _lade=_lade+c; 
    return _lade; }
   }
   
   double CityCar::entladen(double b)
   {
    if(b>_lade)
        {
            _lade=0; 
            return _lade; 
        }
        else {_lade=_lade-b; return _lade;  }
   }
