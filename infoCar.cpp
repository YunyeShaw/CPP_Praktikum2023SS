#include"infoCar.hpp"

infoCar::infoCar()
:_iD(0), _name("UNDEFINE"), _kapa(0.0), _bezinverbrauch(0.0)
{}; 

infoCar::infoCar(int iD, std::string name, double kapa, double bezinverbrauch)
:_iD(iD), _name(name), _kapa(kapa), _bezinverbrauch(bezinverbrauch)
{}; 

void infoCar::output(std::ostream & outs)
{
    outs<<"The iD is: "<<_iD<<std::endl; 
    outs<<"The Name is: "<<_name<<std::endl; 
    outs<<"The capacity is: "<<_kapa<<std::endl; 
    outs<<"The used petrol:  "<<_bezinverbrauch<<std::endl; 
    std::cout << _iD << std::endl;
}

void infoCar::input(std::istream &ins)
{
    if(ins.peek()=='\n') ins.ignore(); 
    std::cout<<"ID: "; 
    ins>>_iD; 
    std::cout<<"The Name: "; 
    if(ins.peek()=='\n') ins.ignore(); 
    std::getline(ins, _name); 
    std::cout<<"The Capacity: "; 
    ins>>_kapa; 
    std::cout<<"The used petrol: "; 
    ins>>_bezinverbrauch; 
}

std::ostream& operator <<(std::ostream & outs, infoCar &temp)
{
    temp.output(outs); 
    return outs; 
}

std::istream &operator>>(std::istream &ins, infoCar &tmp)
{
    tmp.input(ins); 
    return ins; // TODO: insert return statement here
}

