#ifndef InfoCar_HPP
#define InfoCar_HPP
#include<iostream>
#include<string> 

class infoCar
{
public:
    infoCar(); 
    infoCar(int iD, std::string name, double kapa, double bezinverbrauch);
    int getiD(){return _iD; }; 
    std::string getname(){return _name;}; 
    double getkapa(){return _kapa;}; 
    double getbezinverbrauch(){return _bezinverbrauch; }; 
    void output(std::ostream& outs); 
    void input(std::istream& ins); 
   
private: 
   int _iD; 
   std::string _name; 
   double _kapa; 
   double _bezinverbrauch; 
};
 std::ostream& operator <<(std::ostream& outs, infoCar & tmp); 
 std::istream& operator >>(std::istream& ins, infoCar & tmp); 
#endif

