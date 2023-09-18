#include<iostream>
#include"car.hpp"
#include<fstream>
#include<string>
#include<sstream>

void creat(Auto car)
{
   // std::cout<<car.getiD()<<"\n"; 
   // std::cout<<car.getname()<<"\n"; 
   // std::cout<<car.getkapa()<<"\n"; 
   // std::cout<<car.getbezinverbrauch()<<"\n"; 
    std::fstream fout; 
    fout.open("reportcar.csv",std::ios::out|std::ios::app); 
    
   
    fout<<car.getiD()<<std::flush<<","<<car.getname()<<std::flush<<","<<car.getkapa()<<","<<car.getbezinverbrauch()<<"\n";
   //  fout<<car.getname()<<"\n";
   //  fout<<car.getkapa()<<"\n"; 
   //  fout<<car.getbezinverbrauch()<<"\n"; 
   fout.close(); }
void giveout(){
   std::ifstream fin; 
   std::string iD; 
   std::string name; 
   std::string kapa; 
   std::string bezinverbrauch;  
   fin.open("reportcar.csv"); 

   int i=1; 
   //  fout>>iD;//>>name>>kapa>>bezinverbrauch; 
   if(!fin.is_open()) std::cout<<"the file is not opened! "<<std::endl; 
   else 
 { 
   
    do{ 
      getline(fin, iD, ',');
   getline(fin, name, ',');
   getline(fin, kapa, ',');
   getline(fin, bezinverbrauch, '\n');


   std::cout<<"iD is: "<<iD<<std::endl; 
   
   

   //   std::cout<<"detail of the Car: "<<std::endl;
   //   std::cout<<"the iD is: "<<iD<<std::endl;
     std::cout<<"the name is: "<<name<<std::endl;
    std::cout<<"the capacity is: "<<kapa<<std::endl; 
      std::cout<<"the Bezinverbrauch is: "<<bezinverbrauch<<std::endl; 
      std::cout<<"i="<<i<<std::endl; 
   std::cout<<"------------------------"<<std::endl; 
   i++; 
   }while(fin.peek()!=EOF); }// here won't creat a extra line without ignoring the first parameter; different from using fin.eof(), and fin.good()
   fin.close(); 
   
}

// void creatandgiveout()
// {
//       // std::string filename; 
//       // std::cout<<"Geben Sie die Datein: "<<std::endl; 
//       // std::cin>>filename; 
//       std::fstream inOutStream("reportcar.csv");
//       int iD; 
//      // std::getline(inOutStream,iD, ',');  //geht nicht, iD muss ein String sein. 
//       inOutStream>>iD; 
//       std::cout<<"the iD is: "<<iD<<std::endl; 
//       // std::string name; 
//       // inOutStream>>name; 
//       std::cout<<"the name is: "<<name<<std::endl; 
//       std::string line; 
//       std::getline(inOutStream, line); 
//       std::cout<<"the line is: "<<line<<std::endl;
//       std::string someString="Hello World!\n"; 
//       inOutStream<<someString; 
//       std::cout<<"----------------"<<"\n"; 

// }

// Auto(const int& iD, const std::string& name, 
//             const int& kapa, const double& bezinverbrauch);

int main(){

   Auto car(11, "Hunde", 50, 0.51); 
   // creatandgiveout(); 

     creat(car);
     giveout(); 
  car.drive(20); //Tanken von 20l 
  std::cout<<car.fillLevel()<<" "<<car.milage()<<" "<<car.reach()<<std::endl; 

   car.drive(0,10);  //Fahren von 10km , wie man bei zwei Variable initialisiert. 
   std::cout<<car.fillLevel()<<" "<<car.milage()<<" "<<car.reach()<<std::endl; 


    car.refuel(50); //Volltanken, soll man hier refuel benutzen?
    std::cout<<car.fillLevel()<<" "<<car.milage()<<" "<<car.reach()<<std::endl; 
    
    car.drive(car._fuellstand); //Fahren, bis Tank leer ist
    std::cout<<car.fillLevel()<<" "<<car.milage()<<" "<<car.reach()<<std::endl; 
    
    car.refuel(50); //Volltanken, soll man hier refuel benutzen? 
    std::cout<<car.fillLevel()<<" "<<car.milage()<<" "<<car.reach()<<std::endl; 
   
    std::cout<<car.refuel(101)<<std::endl;
    std::cout<<car.fillLevel()<<" "<<car.milage()<<" "<<car.reach()<<std::endl; 
 
 return 0; 
}