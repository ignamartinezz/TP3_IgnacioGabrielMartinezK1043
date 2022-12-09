#include <iostream>

using namespace std;

struct Nodo 
{
    int data;
    Nodo *prev;
    Nodo *next;
};


struct Pila
{
    Nodo *inicio;
    Nodo *final;
};
    // Agregar nuevo elemento al principio
void push(int dato , Pila* &Pila)
{
    Nodo *temp = new Nodo ;
    temp->data = dato;
    temp->prev = NULL;
    temp->next = Pila->inicio;

    if (Pila->inicio != NULL) //Prev del inicio pasa a ser el nuevo nodo
        Pila->inicio->prev = temp;

    if (Pila->final == NULL) //Si la lista estaba vacia, 
        Pila->final = temp; //el final pasa a ser el nuevo nodo

    Pila->inicio = temp;
}

    // Elimina el primer elemento de la lista
int pop(Pila* &Pila){
    if (Pila->inicio == NULL)
        return 0;

    Nodo *temp = Pila->inicio;
    int value = temp->data;
    Pila->inicio = Pila->inicio->next;

    if (Pila->inicio != NULL)  //El nuevo inicio no tiene elem previo
        Pila->inicio->prev = NULL;

    if (Pila->inicio == NULL) //Si era nodo unico, no hay mas final
        Pila->final = NULL;

    delete temp;

    return value;
}


//Agrega al final
void agregar(Pila* &Pila, int dato)
{
	Nodo* temp = new Nodo;
	temp->data = dato;
	temp->next = nullptr;
    temp->prev = Pila->final; //El prev del nuevo pasa a ser el anterior final

    Pila->final->next=temp; //El next del anterior final pasa a ser el nuevo nodo

    Pila->final=temp; //El nuevo final, es el nuevo nodo
   
}


// Recorre y muestra todos los elementos en orden inverso
void mostrar_inv(Pila* &Pila)
{
    Nodo *actual = Pila->final; //Arranco por el ultimo
    while (actual != NULL)
    {
        cout << actual->data << endl;
        actual = actual->prev; //Paso al nodo anterior
    }
}


int main(void){
    Pila* Pila={};
    Pila->inicio=nullptr;
    Pila->final=nullptr;
    
    //pop(Pila) //Pruebo error
    push(1, Pila);
    push(2, Pila);
    push(3, Pila);
    pop(Pila);

    agregar(Pila,25);

    mostrar_inv(Pila);

    return 0;
}
