//#include "car2.hpp"

template <class T>
Auto<T>::Auto(const T& iD, const std::string& name, const int& kapa, 
const double& bezinverbrauch) 
: _iD(iD), _name(name), _kapa(kapa), _bezinverbrauch(bezinverbrauch)
{
    std::cout<<"C of L"<<std::endl; 
}

template <class T> //ist auch nötig bei jeder Methode 
bool Auto<T>::refuel(double a)
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
template <class T>
double Auto<T>::drive(double a, double b) //b ist km, a ist Liter wie viel kilo möchte man noch fahren. wie kann man hier verbessern 
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
template <class T>
double Auto<T>::fillLevel()
{
    return _fuellstand; 
}
template <class T>
double Auto<T>::reach()
{ 
    return _reichWeite;  
}
template <class T>
double Auto<T>::milage()
{
    return _kilometerstand; 
}