#ifndef CarDatabase_HPP
#define CarDatabase_HPP
#include<iostream> 
#include"infoCar.hpp"

class CarDatabase
{
    public: 
    CarDatabase(); 
    CarDatabase(const CarDatabase & other );
    ~CarDatabase(); 
     void resize(); 
     void search(std::string name); 
     void search_iD(int iD); 
     void add(const infoCar & emp); 
     void display_all(); 
     void remove(std::string name); 
     void save(std::ostream & outs); //? 
     void load(std::istream & ins); //? 
     void sort_name(); 
     void sort_kapa(); 
    void operator =(const CarDatabase & other); 
    private: 
    void make_bigger(); 
    int capacity; 
    infoCar *data; 
    int used; 
}; 
#endif