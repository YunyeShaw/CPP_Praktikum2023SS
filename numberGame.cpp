#include<stdio.h> 
#include<iostream> 
#include<random> 
#include<chrono> 

int getNumber()
{
int a=std::rand(); 
if (a<=65536&&a>=0)
return a; 
else
return getNumber();

}
int playGame()
{
  int b; 
  std::cout<<"Geben Sie eine Zahl aus"<<std::endl; 
  std::cin>>b; 
  return b; 
}

int main()
{
    std::srand(std::time(0)); //seed for std::randon() später. 
    int someRandomNumber=getNumber();
    // int someRandomNumber= std::rand(); 
    int guess=playGame(); 
    std::cout<<someRandomNumber<<std::endl; 

    while (guess!=someRandomNumber)
        guess=playGame(); 
    std::cout<<"Congratulations!"<<std::endl; 
    return 0;
}