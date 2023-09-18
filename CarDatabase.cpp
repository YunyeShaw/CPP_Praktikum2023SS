#include"CarDatabase.hpp"
#include<algorithm>


CarDatabase::CarDatabase()
:used(0), capacity(4), data(new infoCar[capacity])
{}

CarDatabase::CarDatabase(const CarDatabase& other)
: used(other.used), capacity(other.capacity), data(new infoCar[capacity])
{std::copy(other.data, other.data+used,data);}

CarDatabase::~CarDatabase()
{
    delete[]data; 
}
void CarDatabase::search(std::string name)
{
    int num_found=0; 
    for(int i=0; i<used; i++)
    {
        if(data[i].getname()==name) 
        {
            std::cout<<"Found the Car!"<<std::endl; 
            data[i].output(std::cout); //?
            num_found+=1; 
        }
    }
    if(num_found==0)
    {
        std::cout<<"Not Found!"<<std::endl; 
    }
}
void CarDatabase::search_iD(int id)
{
    int num_found=0; 
    for(int i=0; i<used; i++)
    {
        if(data[i].getiD()==id)
        num_found=1; 
        data[i].output(std::cout); 
    }
    if(num_found==0)
    {
        std::cout<<"Not Found!"<<std::endl; 
    }
}
void CarDatabase::add(const infoCar & emp)
{
    if(used<=capacity)
    {
        make_bigger(); 
        data[used]=emp; 
        used++; 
}
}
void CarDatabase::display_all()
{
    for(int i=0; i<used; i++)
    {
        data[i].output(std::cout); 
    }
}
void CarDatabase::remove(std::string name)
{
    for(int i=0; i<used; i++)
    {
        if(data[i].getname()==name)
        {
            data[i]=data[used-1]; 
            used--; 
        }
    }
}
void CarDatabase::save(std::ostream &outs)
{
    sort_name(); 
    for(int i=0; i<used; i++)
    {
        outs<<data[i]; 
    }
}
void CarDatabase::load(std::istream & ins)
{
    infoCar tmp; 
    while (ins>>tmp)
    {
        if(used>= capacity)
        {
            make_bigger(); 
        }
        data[used]=tmp; 
        used++; 
    }
}

void CarDatabase::sort_name()
{
    bool done=false; 
    infoCar tmp; 
    while(!done)
    {
        done=true; 
        for(int i=0; i<used-1; i++)
        {
            if(data[i].getname()>data[i+1].getname())
            {
                done=false; 
                tmp=data[i]; 
                data[i]=data[i+1]; 
                data[i+1]=tmp; 
            }
        }
    }
}

void CarDatabase::sort_kapa()
{
    bool done=false; 
    infoCar tmp; 
    while(!done)
    {
        done=true; 
        for(int i=0; i<used-1; i++)
        {
            if(data[i].getkapa()<data[i+1].getkapa())
            {
                done=false; 
                tmp=data[i]; 
                data[i]=data[i+1]; 
                data[i+1]=tmp; 
    
            }
        }
    }
}
void CarDatabase::make_bigger()
{
    infoCar * tmp; 
    tmp=new infoCar[capacity+4]; 
    std::copy(data, data+used, tmp); 
    delete[]data; 
    data=tmp; 
    capacity +=4; 

}

void CarDatabase::operator = (const CarDatabase &other) 
{
    if(&other==this )
    {
        return ; 
    }
    delete[]data; 
    capacity=other.capacity; 
    used=other.used; 
    data=new infoCar[capacity]; 
    std::copy(other.data, other.data+used, data); 

}