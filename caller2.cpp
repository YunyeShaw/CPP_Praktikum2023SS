#include<iostream> 
#include<thread> 
#include<chrono> 
#include<atomic>
#include<functional>
#include<memory> 
std::atomic<bool> flagDone(false); 
// std::atomic<int> amout(0); 
int amout = 0;
std::mutex m;

void caller(std::chrono::seconds period, bool continuous, std::function<void()>callback) 
{
    
    while(continuous)
    {
        std::this_thread::sleep_for(period); 
        // std::atomic<void>::wait(period); 
        callback();
        // amout++; 
        // std::cout<<amout<<std::endl; 
        if(flagDone.load())
        return; 
    }
    std::this_thread::sleep_for(period); 
    callback();

    return;
    
}

void Fibonacci(){
    int n=10; 
    int a=0, b=1, c; 
    for(int i=0; i<n; i++)
    {
        c=a+b; 
        a=b; 
        b=c; 
    }
    amout++; 
    std::cout<<"The Value is: "<<c<<std::endl; 
   
    std::cout<<amout<<std::endl; 
}
auto adder=[](){
    //std::cout<<"Hallo Welt! "<<std::endl;
    std::cout << "test1" << std::endl;
    m.lock();
    std::cout << "test2" << std::endl;
    amout++;
    m.unlock(); 
    std::cout << "test3" << std::endl;
    //std::cout<<amout<<std::endl;
    }; 

//.... wird noch ausgeführt 
//m.lock(); ab hier erst wenn anderer thread unlock / niemand anderer lock
//amout++;
//m.unlock();
//... 

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
    //std::thread t1(caller, std::chrono::seconds(1), 1, &Fibonacci);

    //std::thread t2(caller, std::chrono::seconds(1), 1, adder);
    //std::thread t3(caller, std::chrono::seconds(1), 1, label);

    std::thread t[100];
    for(int i = 0; i < 100; i++)
        t[i] = std::thread(caller, std::chrono::seconds(1), 0, adder); //hier kostet auch Zeit, damit die vorherige Thread Test3 ausgeben kann. 
    int bbb = 0;
    for(int i = 0; i < 100; i++){
        bbb++;
        if(t[i].joinable())
        t[i].join();
    }
    std::cout << bbb << amout << std::endl;
    // delete label; 
    flagDone=true; 
    /*if(t1.joinable())
    t1.join();
    if(t2.joinable())
    t2.join();
    if(t3.joinable())
    t3.join();
    return 0; */
}


/*
a = 0


b = a + 1
a = b



1: b = 1
2: b = 1
1: a = 1
2: a = 1


*/