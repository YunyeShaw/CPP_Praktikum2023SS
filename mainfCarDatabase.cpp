#include"infoCar.hpp"
#include"CarDatabase.hpp"
#include<fstream> 

int menu(); 
int main(){
    CarDatabase database; 
    infoCar emp; 
    std::string filename; 
    std::cout<<"Enter name of file(No file extension)"<<std::endl; 
    std::cin>>filename; 
    filename=filename+".txt"; 
    std::fstream fin; 
    std::cout<<filename<<'\n'; 
    fin.open(filename, std::fstream::out | std::fstream::in); 
    if(fin.is_open())
    {
        database.load(fin); 
        fin.close(); 
        int choice; 
        while(choice!=7)
        {
            choice=menu(); 
            switch(choice){
                case 1: {
                    std::cin>>emp; 
                    database.add(emp); 
                    break; 
                }
                case 2: {
                    system("clear"); //????????
                    std::string name; 
                    std::cout<<"Enter name of the car: "<<std::endl; 
                    if(std::cin.peek()=='\n') std::cin.ignore(); 
                    database.search(name); 
                    break; 
                }
                case 3: {
                    system("clear"); 
                    int id; 
                    std::cout<<"Enter Car's name: "<<std::endl; 
                    std::cin>>id; 
                    database.search_iD(id); 
                    break; 
                }
                case 4: {
                    // system("clear"); 
                    std::cout<<"All the name of the car is in the database:  "<<std::endl; 
                    database.display_all(); 
                    break; 
                }
                case 5: {
                    system("clear"); 
                    std::string name; 
                    std::cout<<"Enter car that hast been sacked: "; 
                    if(std::cin.peek()=='\n')std::cin.ignore(); 
                    std::getline(std::cin, name); 
                    database.remove(name); 
                    break; 

                }
                case 6: 
                {
                    system("clear"); 
                    database.sort_name(); 
                    std::cout<<"Car sorted by name"; 
                    database.display_all(); 
                    break; 
                }
                case 7: 
                {break; }
                default: {
                    system("clear"); 
                    std::cout<<"Not a valide input dammy!"<<std::endl; 
                    break; 
                }
            }
            fin.close(); 
        
        }
        std::cout<<"Thank you for using this system. "<<std::endl; 
    }
        
        else
        {
            std::cout<<"File doesn't open"<<std::endl; 
           

        }
        return 0; 


}

int menu()
{
    int choice; 
    std::cout<<"1. Add new Car"<<std::endl; 
    std::cout<<"2. search for car by name"<<std::endl; 
    std::cout<<"3. search for car by iD "<<std::endl; 
    std::cout<<"4. Display all current car"<<std::endl; 
    std::cout<<"5. remove car by name"<<std::endl; 
    std::cout<<"6. Sort car by name"<<std::endl; 
    std::cout<<"7. Quit"<<std::endl; 
    std::cin>>choice; 
    return choice; 

}