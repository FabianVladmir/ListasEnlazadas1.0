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
    ~Nodo();
};

Nodo::Nodo()
{
    this->element = element;
    next->next = nullptr;
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
    void insertar(int valor, Nodo *p);
    void remove(Nodo* v, int eliminar);
    void print();
    ~linkedList();
};

linkedList::linkedList()
{
    this->size = size;
    this->head = head;
}
void linkedList :: insertar(int valor, Nodo *p){
    if (valor < 0 || p->element < valor)
    {
        p->next->element = valor;
        valor = p->element;
    }else
    {
        nodoptr aux;
        aux->element = valor;
        while (aux->next != nullptr && aux->next->element < p->element)
        {
            aux = aux->next;
        }
        valor = aux->next->element;
        aux->next->element = valor;
    }
}

void linkedList :: remove(Nodo *v, int eliminar){
    if (v != nullptr)
    {
        nodoptr aux = v;
        if (v->element == eliminar)
        {
            v = v->next;
            delete aux;
        }else
        {
            while (v->next != nullptr && v->next->element != eliminar)
            {
                aux = aux->next;
            }
            if (v->next->element == eliminar)
            {
                nodoptr aux2 = aux->next;
                aux->next = aux2->next;
                delete aux2;
            }
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
    
    

    return 0;
}