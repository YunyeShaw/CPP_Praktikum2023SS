#include<iostream>
#include"car.hpp"
#include<fstream>
#include<string>
#include<sstream>
#include"infoCar.hpp"

void creat(Auto car)
{
    std::fstream fout; 
    fout.open("reportcar.csv",std::ios::out|std::ios::app); 
    fout<<car.getiD()<<std::flush<<","<<car.getname()<<std::flush<<","<<car.getkapa()<<","<<car.getbezinverbrauch()<<"\n";
   fout.close();
}



void giveout(){
   std::ifstream fin; 
   int iD; 
   //std::string iDs;
   std::string name; 
   std::string kapa; 
   std::string bezinverbrauch;  
   fin.open("reportcar.csv"); 

   int i=1; 
   if(!fin.is_open()) std::cout<<"the file is not opened! "<<std::endl; 
   else 
 { 
   
    do{ 
   //  getline(fin, iDs, ',');
   //  iD = std::stoi(iDs);
    getline(fin, name, ',');
    getline(fin, kapa, ',');
    getline(fin, bezinverbrauch, '\n');
    std::cout<<"iD is: "<<iD<<std::endl; 
    std::cout<<"the name is: "<<name<<std::endl;
    std::cout<<"the capacity is: "<<kapa<<std::endl; 
    std::cout<<"the Bezinverbrauch is: "<<bezinverbrauch<<std::endl; 
    std::cout<<"i="<<i<<std::endl; 
    std::cout<<"------------------------"<<std::endl; 
    i++; 
   }while(fin.peek()!=EOF); }// here won't creat a extra line without ignoring the first parameter; different from using fin.eof(), and fin.good()
   fin.close(); 
   
}

int main(){
    // Auto car(11,"Great", 50, 0.15); 
    // creat(car);
    giveout(); 
    return 0; 
}