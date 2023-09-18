#include<iostream> 
using namespace std; 

int getValue()
{
    int a; 
    cout<<"Geben Sie Wert ein: "<<endl; 
    cin>>a; 
    return a; 
}

void swapInt(int &a, int &b){
    int c; 
    c=a; 
    a=b; 
    b=c;
    cout<<"in der swapInt Funktion: "<<a<<"  "<<b<<endl; 
}

void swapInt2(int *a, int *b) //der Zeiger, zeigt die Werte, die Werte eingegeben werden. 
{
    int v; 
    v=*a; 
    *a=*b; 
    *b=v; 
    cout<<"in der swapInt2 Funktion: "<<*a<<" "<<*b<<endl; 
}

int main(){
    int a, b, c, d; 
    int *ra, *rb; 
    c=getValue(); 
    d=getValue(); 

    a=getValue(); 
    b=getValue(); 
    ra=&c; rb=&d; //die Adresse initialisieren
    cout<<"initialisierte Werte: "<<a<<" "<<b<<endl; 
    swapInt(a, b); 
    cout<<"nach Vertauschen: "<<a<<" "<<b<<endl; 

    cout<<"jetzt in main Funktion: "<<c<<" "<<d<<endl; 
    swapInt2(ra, rb); 
    cout<<"nach Vertauschen: "<<*ra<<" "<<*rb<<endl; //den Wert von Zeiger  eingegeben 

    cout<<"jetzt in main Funktion: "<<a<<" "<<b<<endl; 
    swapInt2(&a, &b); //hier ist kein Zeiger gegebeb. 
    cout<<"nach Vertauschen: "<<a<<" "<<b<<endl;
    return 0;
}