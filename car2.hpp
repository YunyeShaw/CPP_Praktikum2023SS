// #ifndef CAR2_HPP
// #define CAR2_HPP 

#include<iostream>

template<class T> 
class Auto
{
    public: 
            Auto(const T& iD, const std::string& name, 
            const int& kapa, const double& bezinverbrauch); 

            bool refuel(double a); 
            double drive(double a=0, double b=0); 
            double fillLevel(); 
            double reach(); 
            double milage(); 
            double _fuellstand=50.0; 
            double _kilometerstand=0.0 ; 
            double _reichWeite=0.0; //braucht man hier ? 
    private: 
            const T _iD; 
            std::string _name; 
            int _kapa; 
            double _bezinverbrauch; 
    
};

 #include"car2.tpp"

//#endif