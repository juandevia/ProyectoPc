#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

//esttructuras
struct carta{
    char* color;
    char* valor;
};

struct nodos{
    carta cartas;
    nodos* siguiente;
};

struct jugador{
    char* nombre;
    carta* mazo;
    int cantidad;
};


struct Pila{
    nodos* cima;
    int tam;
};

void crearCartas(carta*& vector);
bool repetido(int x, int y[],int i,int tam);
void agregarPila(Pila *& pila,carta cartas);
void imprimirPila(Pila* pila);
void revolvercartas(carta *cartas,Pila*pila);

int main()
{

    carta* cartas=new carta[108];
    srand((unsigned) time(0));
    crearCartas(cartas);
    Pila *pila=new Pila();
    //for(int i=0;i<108;i++){
      //  agregarPila(pila,*(cartas+i));
    //}
    revolvercartas(cartas,pila);
    imprimirPila(pila);
    int i;

    int posiciones[108];
    for(int i=0;i<108;i++){
        posiciones[i]=-1;
    }
    int j=0;
    while(j<108) {
        int i=0,x;
        x=rand()%109;
        if(!repetido(x,posiciones,i,108)){
            posiciones[j]=x;
            j++;
        }

    }



    delete [] cartas;



    return 0;
}

void crearCartas(carta*& vector){
    int i=0;
        int j;
        int p=0;
        char*x= "c";

        while (p<4){
            char *c;

            switch(p){
                case 0:
                    c="rojo";
                    break;
                case 1:
                    c="amarillo";
                    break;
                case 2:
                    c="azul";
                    break;
                case 3:
                    c="verde";
                    break;
            }
            (vector+i)->color=c;
            (vector+i)->valor="0";
            i++;
            int y=0;

            while(y<2) {
                for (j = 1; j < 10; j++) {
                    switch(j){
                        case 0:
                            x="1";
                            break;
                        case 1:
                            x="1";
                            break;
                        case 2:
                            x="2";
                            break;
                        case 3:
                            x="3";
                            break;
                        case 4:
                            x="4";
                            break;
                        case 5:
                            x="5";
                            break;
                        case 6:
                            x="6";
                            break;
                        case 7:
                            x="7";
                            break;
                        case 8:
                            x="8";
                            break;
                        case 9:
                            x="9";
                            break;
                    }
                    (vector + i)->valor= x;
                    (vector + i)->color = c;
                    i++;
                }
                y++;
            }
            y=0;
            while(y<2){
                (vector+i)->valor="toma2";
                (vector+i)->color=c;
                i++;
                y++;
            }
            y=0;
            while(y<2){
                (vector+i)->valor="retorno";
                (vector+i)->color=c;
                i++;
                y++;
            }
            y=0;
            while(y<2){
                (vector+i)->valor="bloqueo";
                (vector+i)->color=c;
                i++;
                y++;
            }
            p++;

            }
        int f=0;
        while(f<4) {
            (vector + i)->valor = "cambioC";
            (vector + i)->color = "todos";
            i++;
            f++;
        }
        f=0;
        while(f<4) {
            (vector + i)->valor = "toma4";
            (vector + i)->color = "todos";
            i++;
            f++;
        }

    }
//función recursiva
bool repetido(int x, int y[],int i,int tam){

if(x==y[i]){
    return true;
}
if(i==tam){
    return false;
}
i++;
return repetido(x,y,i,tam);

}


void agregarPila(Pila *& pila,carta cartas){
    nodos *nuevo_nodo=new nodos();
    nuevo_nodo->cartas=cartas;
    nuevo_nodo->siguiente=pila->cima;
    pila->cima=nuevo_nodo;
    pila->tam++;
}

void imprimirPila(Pila* pila) {
    nodos *copia;
    copia= pila->cima;
    while(copia !=NULL){
        cout<<copia->cartas.valor<<'\t'<<copia->cartas.color<<endl;
        copia=copia->siguiente;
    }

}



void revolvercartas(carta *cartas,Pila *pila) {

    int pepe[100000];
    int posiciones[108];
    for (int i = 0; i < 108; i++) {
        posiciones[i] = -1;
    }
    int j = 0;
    while (j < 108) {
        int i = 0, x;
        x = rand() % 109;
        if (!repetido(x, posiciones, i, 108)) {
            posiciones[j] = x;
            j++;
        }
    }
    for(int i=0;i<108 ;i++){
        agregarPila(pila,*(cartas+posiciones[i]-1));
    }

}





