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

typedef Nodo* nodoptr;

class linkedList
{
private:
    int size;    
    Nodo *head;
public:    
    linkedList();
    void insertar(int valor);
    void remove(int eliminar);
    void print();
    ~linkedList();
};

linkedList::linkedList( ){ 
    this->size = 0;   
    this->head = nullptr;
}

void linkedList :: insertar(int valor){
   
    if (head == nullptr) // case 1
    {
        head = new Nodo;
        head->element = valor;
        head->next = nullptr;
    }else
    {
        nodoptr p = head;
        if (valor < p->element) // case 2
        {
            p = new Nodo(valor);
            p->next = head;
            head = p;
        }
        while (p->next != nullptr)
        {
            if (valor > p->next->element) // case 3
            {
                p = p->next;
            }else
            {
                nodoptr aux;
                aux->element = valor;
                aux->next = p->next;
                p->next = aux;
                return;
            }
        }
        if (valor > p->element)
        {
            if (head != nullptr)
            {
                p = new Nodo(valor);
                nodoptr it = head;
                while (it->next != nullptr)
                {
                    it = it->next;
                }
                it->next = p; 
            }else
            {
                p = new Nodo(valor);
                p->next = head;
                head = p;
            } 
        }
    }
    size++;
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
    {
        aux = aux->next;
        if (aux->next->element == eliminar)
        {
            nodoptr aux2 = aux->next;
            aux->next = aux2->next;
            delete aux2;
        }  
    }    
    
}

void linkedList ::print(){
    for (nodoptr i = head; i != nullptr; i = i->next)
    {
        cout << i->element << " ";
    }
    cout << endl;
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
    for (int i = 0; i < 10; i++)
    {
        if (i % 5 == 0)
        {
            lista.remove(i);
        }
        
    }
    
    lista.print();

    return 0;
}