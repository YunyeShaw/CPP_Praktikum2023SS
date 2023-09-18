#include"linkedlist.hpp"

int main()
{
    // std::shared_ptr<ListElement<int>> start=std::make_shared<ListElement<int>>(); 
   std::shared_ptr<List<int>> test=std::make_shared<List<int>>();  //wenn wir hier nicht im Speicher einen Platz reservieren, kommt der Segmentation fault. 
   
    for(int j=0; j<=5; j++)
     {
        test->insertItem(j*10, j); 
     }
   

   //   test->print(); 
   //   std::cout<<test->at(6)<<std::endl; 
 int n=3; 
     auto txt=[&](void){
         std::cout<<test->at(n)<<std::endl;  //die unterschreitene Positionszahl 
         if (n>=(test->getsize()-1)){
            throw std::invalid_argument("The position must be larger than the size-1 . "); //std::out_of_range("The position must be larger than the size-1 . "); //
         }
     };
     
     try{
          try{
               txt(); 
            }
         catch(std::out_of_range & fortxt)
         {
            std::cerr<<fortxt.what()<<std::endl; //cerr hingegen ist nicht gepufferrt, und deshalb für Fehlerausgaben geeignet(wenn z.B. das Programm mitten in der Ausgabe hängen bleibt, dass trotzdem so viel wie möglich ausgegeben wird. )
            //std::cout<<"The Error is: "<<fortxt.what()<<std::endl; 
         }
         catch(...)
          {
            std::cout<<"usighweiog"<<std::endl; 
            throw; 
         }
      }
         
     catch(...)
     {
      std::cout<<"Unresolvable error in main.cpp"<<std::endl; 
      throw; 
     }
    
return 0; 

}