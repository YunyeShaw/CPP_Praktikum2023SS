#include<iostream> 
#include<thread> 
#include<chrono> 
#include<atomic>
#include<functional>
#include<memory> 
std::atomic<bool> flagDone(false); 
int amout=0; 

void caller(std::chrono::seconds period, bool continuous, std::function<void()>callback) 
{
    
    while(continuous)
    {
        std::this_thread::sleep_for(period); 
        // std::atomic<void>::wait(period); 
        callback();
        amout++; 
        std::cout<<amout<<std::endl; 
        if(flagDone.load())
        return; 
    }
    std::this_thread::sleep_for(period); 

    return;
    
}

void Fibonacci(){
    int n=30; 
    int a=0, b=1, c; 
    for(int i=0; i<n; i++)
    {
        c=a+b; 
        a=b; 
        b=c; 
    }
    std::cout<<"The Value is: "<<c<<std::endl; 
    
}
auto adder=[](){std::cout<<"Hallo Welt! "<<std::endl; }; 

// void test(){
//     std::cout << "test" << std::endl;
//     return;
// }

// void test2(){
//     bool i=true; 
//     while(!flagDone)
//     {
//         std::string out=(i)? "/":"\\"; 
//         std::cout<<"\b"<<out<<std::endl; 
//         i=!i; 
//     }
// }

class Label{
    public: void operator()(){std::cout<<"This is a test!"<<std::endl; }
};

int main(){
    bool continuous=true; 
    namespace p=std::placeholders; 
    // std::thread runner1(Fibonacci); 
    // std::thread runner2(adder); 
    // std::thread runner3(test2); 
    // caller(std::chrono::seconds(1), 0, &test);
    Label label; 
    std::thread t1(caller, std::chrono::seconds(3), 1, &Fibonacci); //threads gleichzeitig laufen 

    std::thread t2(caller, std::chrono::seconds(1), 1, adder) ;
    std::thread t3(caller, std::chrono::seconds(2), 1, label);
    // delete label; 
    flagDone=true; 
    if(t1.joinable())
    t1.join();
    if(t2.joinable())
    t2.join();
    if(t3.joinable())
    t3.join();
    return 0; 
}