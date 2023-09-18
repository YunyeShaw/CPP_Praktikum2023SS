#include<iostream> 
#include<memory>
#include<stdexcept>

template<class T>  
class ListElement{
 public:   
            ListElement();
            // T& getdaten(){return daten;}; 
            // std::shared_ptr<ListElement<T>>& getnext(){return next;};
            T& daten; 
            std::shared_ptr<ListElement<T>> next;//std::make_shared<ListElement<T>>();
            // std::shared_ptr<ListElement> previous;
            // std::shared_ptr<ListElement> current;
            T dummy ;
}; 

template<class T> 
class List
{
public: 
    List();  
 
    // start=nullptr; 
    // start->next=NULL; 
    T& at( std::size_t _position);  
    void insertItem(const T &data, std::size_t _position); 
    void print(); 
    void deleteItem( std::size_t _position);
    size_t count();
    int getsize(){return _size; }; 
    // void at();
    

private: 
     friend class ListElement<T>; 
    // friend class ListIterator<T>; 
        // T& _da; 
        std::shared_ptr<ListElement<T>> _start;
        std::shared_ptr<ListElement<T>> _end; 
         int _size; 
        int _suchPosition; 
    
};

// template<typename T>
// class ListIterator: public std::iterator<std::bidirectional_iterator_tag, T>
// {
//     public: 
//             ListIterator(std::shared_ptr<ListElement<T>> item); 
//             std::shared_ptr<ListElement<T>> itemPtr() const; 
//             ListIterator &operator++(); 
//             T & operator * (); 
//             // bool operator == (const ListIterator &it); 
//             // bool operator !- (const ListIterator &it); 

//     private:
//             std::shared_ptr<ListElement<T>> _item; 
// };

// template<typename T>
// ListIterator<T>::ListIterator(std::shared_ptr<ListElement<T>> item)
// :_item(item){}
// template<class T>
// T& ListIterator<T>::operator*()
// {
    
// }

template<typename T> 
List<T>::List()
:_start(nullptr), _end(nullptr), _size(0)
{}


// :_start(start){};

template<typename T>
T& List<T>::at( std::size_t _position) 
{    
    if(_position>_size)
    {
        std::cout<<"the size is: "<<_size<<std::endl; 
        throw std::out_of_range("the Position is bigger than the size. "); //std::invalid_argument("the Posittion is bigger than the size. ");
    }
    std::shared_ptr<ListElement<T>> temp=_start; 
    while(_position>0&&temp->next!=NULL)
    {
       temp=temp->next;   
       _position=_position-1; 
    }
    return temp->daten; 

}

template<class T>
ListElement<T>::ListElement()
: daten(dummy),next(nullptr)
{}
// {
//     T& daten=T(NULL); 
//     std::shared_ptr<ListElement<T>> next = NULL; 
// };

template<typename T>
void List<T>::insertItem(const T &data, std::size_t _position)
{
    if(_position>_size) _size++; 
    std::shared_ptr<ListElement<T>> current;
    current = std::make_shared<ListElement<T>>();
    // current = std::make_unique
                                                            // std::cout<<current<<std::endl; ;
                                                            // std::cout<<current.get()<<std::endl;
    // std::cout<<std::endl;
    // std::shared_ptr<std::string> ptr;
    // ptr = std::make_shared<std::string>();
    // std::string string2 = ptr.get();
    current->daten=data;
    current->next=nullptr; 
    if(_start==NULL)
    {
        _start=current;
    }
    else{
    std::shared_ptr<ListElement<T>> temp=_start;
    while(_position>0&&temp->next!=NULL)
    {
       temp=temp->next;  
       _position=_position-1; 
    }
    if(temp->next!=NULL)
    {
    current->next=temp->next; 
    temp->next=current; 
    }
    else
    temp->next=current; 
    }
}

template<typename T> 
void List<T>::print()
{
    std::shared_ptr<ListElement<T>> current=_start; 
    if(current==NULL) {std::cout<<"Nichts"<<std::endl;return;} 
    else
    {while(current->next!=NULL)
    {
        std::cout<<current->daten<<std::endl; 
        current=current->next; 
    }
    }
}

template<typename T> 
void List<T>::deleteItem( std::size_t _position)
    {
    _size--; 
    std::shared_ptr<ListElement<T>> current=_start;
    std::shared_ptr<ListElement<T>> previous=ListElement<T>(); 
   while(_position>0&&current!=NULL)
    {
        previous=current; 
       current=current->next; 
       _position=_position-1; 
    }
    if(current!=NULL)
    {
    if (previous!=NULL)
     {
            previous->next=current->next; 
        }
        else 
            _start=current->next; 
    }}

template<typename T>
 size_t List<T>:: count()
{
std::shared_ptr<ListElement<T>> current=_start;
// current=start; 
int i=0; 
if(current!=NULL)
{
while(current->next!=NULL)
{
    current=current->next; 
    i++; 
}
return i; 
}
else return 0; 
}


// template<class T> 
// List<T>::List(); 
