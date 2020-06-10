#include <iostream>
using namespace std;
class Nodo
{
private:
    int element;
    Nodo *next;
    friend class linkedList;
public:
    Nodo();
    Nodo(int element_);
    Nodo(int p, Nodo* n);    
    ~Nodo();
};

Nodo::Nodo(){
    this->element = 0;
    this->next = nullptr;
}

Nodo::Nodo(int element_)
{
    this->element = element_;
    this->next = nullptr;
}

Nodo::Nodo(int p, Nodo *n){
    this->element = p;
    this->next = n;
}

Nodo::~Nodo()
{
}

typedef class Nodo* nodoptr;

class linkedList
{
private:       
    Nodo *head;
    
public:    
    linkedList();
    void insertar(int valor);
    void remove(int eliminar);
    void print();
    void find(int valor);
    ~linkedList();
};

linkedList::linkedList( ){ 
       
    this->head = nullptr;
}

void linkedList :: insertar(int valor){   
    
    nodoptr new1;
    nodoptr aux;
    nodoptr aux2;
    
    new1 = (Nodo*)malloc(sizeof(Nodo));
   
    if(new1 == NULL) 
    {
        cout << "Erro en la memoria" << endl;
        return;
    }   

    new1->element = valor;
    new1->next = NULL;
    
    if (head == NULL) // case 1
    {       
        head = new1;
    } 
    
    else if(valor < head->element) // case 2
    {
        new1 -> next = head;
        head = new1;
    } 
    else 
    {   
        aux2 = head;
        aux = head -> next;
            
            while(aux != NULL && valor > aux -> element) // search
            {
                aux2 = aux;
                aux = aux->next;
            }
            
           if(aux == NULL) 
           {
                aux2 -> next = new1;
           } 
           else 
           {
                new1 -> next = aux;
                aux2 -> next = new1;
           }
    }
}

void linkedList :: remove(int eliminar){
    if (head == nullptr) // case 1
    {
        return;
    }

    if (head->element == eliminar) // case2
    {
        nodoptr aux = head;
        head = head->next;
        delete aux;
        return;        
    }
    nodoptr aux = head;
    while (aux->next != nullptr && aux->next->element != eliminar) // case3
    
    aux = aux->next;
    if (aux->next == nullptr)    {
        return;
    }  
    nodoptr aux2 = aux->next;
    aux->next = aux2->next;
    delete aux2;    
    
}

void linkedList ::print(){
    for (nodoptr i = head; i != nullptr; i = i->next)
    {
        cout << i->element << " ";
    }
    cout << endl;
}

void linkedList::find(int valor){
    
    nodoptr aux = head;
    while (aux != nullptr && aux->element != valor)
    {       
        aux = aux->next;
    }
    if(aux != nullptr){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
}

linkedList::~linkedList()
{
    while (head != nullptr)
    {
        nodoptr p = head; 
        head = head->next;
        cout << "Eliminando: " << p->element << endl;
        delete p;
    }    
}


int main(){
    linkedList lista;
    for (int i = 0; i < 20; i+=2)
    {
        lista.insertar(i);
    }
    
    lista.print();
  
    for(int i=1; i<10; i+=2){
      lista.insertar(i);
    }
    
    lista.print();

    for(int i=1; i<13; i++){
      if(i % 3 == 0){
        lista.remove(i);
      }
    }
    
    cout << endl;

    lista.print();

    lista.find(16);
    lista.find(3);
    
    cout << endl;
    
    return 0;
}