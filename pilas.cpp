#include <iostream>

using namespace std;

struct NodoPar
{
    int dato;
    NodoPar
     *sig;
    NodoPar
     *prev;
}*inicioPar;

struct NodoImpar
{
    int dato;
    NodoImpar
     *sig;
    NodoImpar
     *prev;
}*inicioImpar;


class PilaPar{

    public:
        NodoPar
        * crearNodo(int valor){
            NodoPar
            *n = new NodoPar
            ;
            n->dato=valor;
            n->sig=nullptr;
            return n;
        }

        void push(int valor){
            NodoPar
             *n = crearNodo(valor);
            n->sig=inicioPar;
            inicioPar=n;
        }
        void pop(){
            NodoPar
             *temp=inicioPar;
            inicioPar = inicioPar->sig;
            free(temp);
        }

        void mostrarPila(){
            NodoPar
             *temp=inicioPar;
            if(!inicioPar){
                cout<<"La pila esta vacia"<<endl;
            }
            else{
                while(temp){
                    cout<<temp->dato<<" ";
                    temp=temp->sig;
                }
            }
        }

        Pila(){
            inicioPar =nullptr;
        }
};


class PilaImpar{

    public:
        NodoImpar
        * crearNodo(int valor){
            NodoImpar
            *n = new NodoImpar
            ;
            n->dato=valor;
            n->sig=nullptr;
            return n;
        }

        void push(int valor){
            NodoImpar
             *n = crearNodo(valor);
            n->sig=inicioImpar;
            inicioImpar=n;
        }
        void pop(){
            NodoImpar
             *temp=inicioImpar;
            inicioImpar = inicioImpar->sig;
            free(temp);
        }

        void mostrarPila(){
            NodoImpar
             *temp=inicioImpar;
            if(!inicioImpar){
                cout<<"La pila esta vacia"<<endl;
            }
            else{
                while(temp){
                    cout<<temp->dato<<" ";
                    temp=temp->sig;
                }
            }
        }

        Pila(){
            inicioImpar =nullptr;
        }
};

int main(){

    PilaPar pilaPar;
    PilaImpar pilaImpar;
    int dato,contPar=0,contImpar=0;
    cout<<"----- Ingrese numeros enteros(Cero termina el ingreso de datos)----\n";
    
    while(dato!=0){        
        cin>>dato;
        if(dato==0){
            break;
        }
        else if(dato%2==0){
            pilaPar.push(dato);
            contPar++;
        }else{
            pilaImpar.push(dato);
            contImpar++;
        }
    }
    
    (contPar>contImpar)?cout<<"*** Hay mas pares que impares ***":cout<<"*** Hay mas impares que pares ***";

    cout<<"\n Pares:"<<endl;
    pilaPar.mostrarPila();cout<<"\n Impares: "<<endl;
    pilaImpar.mostrarPila();cout<<endl; 
   
    return 0;
}