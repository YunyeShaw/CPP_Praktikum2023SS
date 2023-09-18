#include<iostream>
#include<map>

int main(){
    // std::string name;  
    // std::string nummer; 
    std::map<std::string, std::string> map1; 
    map1["Michael"]="1823739434";
    map1["Thomas"]="182134";
    map1["Alexander"]="182300039434";
    map1["Joseph"]="18203840000000000004";
    std::map<std::string, std::string>::iterator it; 
    for (it=map1.begin(); it!=map1.end(); it++)
    {
        std::cout<<"Name: "<<it->first<<std::endl; 
        std::cout<<"Telefonnummer: "<<it->second<<std::endl; 
    }
     std::map<std::string, std::string, std::greater<std::string>> map2; 
    map2["Michael"]="1823739434";
    map2["Thomas"]="182134";
    map2["Alexander"]="182300039434";
    map2["Joseph"]="18203840000000000004";
   
    for (it=map2.begin(); it!=map2.end(); it++)
    {
        std::cout<<"Name: "<<it->first<<std::endl; 
        std::cout<<"Telefonnummer: "<<it->second<<std::endl; 
    }
}