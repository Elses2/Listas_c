#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


////si encuentra una letra me da un 1
int es_letra(char x[],int tam){

    int j=0,retorno=0,i=0;
    j=strlen(x);
    while(i<j && retorno==0){
    if(isdigit(x[i])==0){
        retorno=1;

    }
    else{
        i++;
    }
    }
    return retorno;

}
//// si encuentra un numero me da un 1
int es_numero(char x[],int tam){
    int j=0,retorno=0,i=0;
    j=strlen(x);
    while(i<j && retorno==0){
    if(isdigit(x[i])==1){
        retorno=1;

    }
    else{
        i++;
    }
    }
    return retorno;

}
///verifica que el dato ingresado sea un numero
void controlador_numero(char x[],int tam){

    while(es_letra(x,tam)==1){
        printf("Solo numeros:\n");
        fflush(stdin);
        strcpy(x,"");
        gets(x);
    }

}

///verifica que el dato ingresado sea una palabra
void controlador_caracter(char x[],int tam){

        while(es_numero(x,tam)==1){
        printf("Solo letras:\n");
        fflush(stdin);
        strcpy(x,"");
        gets(x);
    }


}
///verifica que el dato ingresado sea un numero y que este en el rango establecido
void controlador_entero(char x[],int tam,int *alm,int desde,int hasta){

    int parcial;
    parcial= atoi(x);
     while(es_letra(x,tam)==1 || parcial>hasta || parcial<desde){
        printf("Solo numeros del %d hasta %d:\n",desde,hasta);
        fflush(stdin);
        strcpy(x,"");
        gets(x);
        fflush(stdin);
        parcial= atoi(x);
    }
    *alm=parcial;

}

///limpia pantalla
void clear(){

    system("cls");

}

void presentacion(){
    printf(" 1:Insertar Trabajador\n 2:Mostrar personas estresadas \n 3:saber si un empleado se encuentra en peligro \n 4:Pares enemigos\n 5:trabajadores con mayor complejidad \n 6:Trabajadores con una sola tarea\n 7:cerrar programa \n ?");
}

struct Tarea{
    char des[100];///descripcion
    int comp;//complejidad

};
struct Trabajador{
    int dni;
    struct Tarea *tareas[5];//maximo 5 tareas por persona
    bool estres;// si esta estresado o no
    int lugar;//poder ejecutivo judicial, ejecutivo o prensa
    int partido ;// partidos politicos
    int comp_max;//la complejidad masa alta de todas las tareas que tiene
    int cant_t;//cantidad de tareas


};
struct Nodo{
    struct Trabajador *dato;
    struct Nodo *ptrsig;

};
typedef struct Nodo nodo;
typedef nodo *newptr;//puntero nodo
typedef struct Tarea tarea;
typedef struct Trabajador trabajador;



////funciones de estructuras:

///Esta funcion devuelve una funcion tipo tarea--faltan aplicar controladores
tarea* crear_tarea (){///n es el numero de tareas

    tarea* nuevo=NULL;
    int complejidad=0;
    char descripcion[100];

        fflush(stdin);
        printf("Dime la descripcion de la tara: \n");
        gets(descripcion);
        fflush(stdin);
        printf("Dime la complejidad de esta tara: \n");
        scanf("%d",&complejidad);
        fflush(stdin);

        nuevo= malloc(sizeof(tarea));
        nuevo->comp=complejidad;
        strcpy(nuevo->des, descripcion);

        return nuevo;
}
///esta funcion crea un trabajador-- faltan controladores

trabajador * crear_trabajador(){
    trabajador * nuevo=NULL;
    nuevo= malloc(sizeof(trabajador));
    ////sin sentido
    int dni;
    bool estres=false;
    int lugar;
    int partido;
    int comp_max=0;
    int cant_t;
    ////

    printf("Dame el dni\n");
    scanf("%d",&dni);
    printf("Dame el lugar 1:poder judicial, 2:legislativo,3:ejecutivo,4:prensa\n");
    scanf("%d",&lugar);
    printf("Dame el partido 1:derecha  2:izquierda \n");
    scanf("%d",&partido);
    printf("Dime la cantidad de tareas que tiene este trabajador:\n");
    scanf("%d",&cant_t);
    for(int i=0; i<cant_t; i++){
        nuevo->tareas[i]=malloc(sizeof(tarea));
        nuevo->tareas[i]=crear_tarea();
        ///si la complejidad de una tarea s mayor de 5 esta estresado osea estres es true
        if(nuevo->tareas[i]->comp>5){

            estres=true;
        }
        if(comp_max<nuevo->tareas[i]->comp)comp_max=nuevo->tareas[i]->comp;

    }
    nuevo->cant_t=cant_t;
    nuevo->comp_max=comp_max;
    nuevo->dni=dni;
    nuevo->estres=estres;
    nuevo->lugar=lugar;
    nuevo->partido=partido;
    return nuevo;
}
///esta funcio crea un nodo que contiene un trabajador
nodo* crear_nodo(trabajador *dato){
    newptr nuevo;
    nuevo= malloc(sizeof(nodo));
    if(nuevo!=NULL){
    nuevo->dato=dato;
    nuevo->ptrsig=NULL;
    }
    return nuevo;

}
void insertar_nodo(struct Nodo **raiz, trabajador *dato){

    newptr *nuevo=NULL;
    nuevo=crear_nodo(&dato);

    if(*nuevo != NULL){

        (*nuevo)->ptrsig=*raiz;
        *raiz=nuevo;
    }
}

void imprimir(struct Nodo **raiz){

    printf("DNI:%d \n", (*raiz)->dato->dni);

}

int main()
{
    struct Nodo *raiz=NULL;
    int n=2;
    char boton_c [20];
    int boton=0;

    while(n == 2){

        presentacion();
        gets(boton_c);
        fflush(stdin);

        controlador_entero(boton_c,20,&boton,1,7);



        switch(boton){
        case 1:

            ///raiz=crear_nodo(crear_trabajador());
            insertar_nodo(&raiz,crear_trabajador());
            printf("%d \n", raiz->dato->dni );
            break;
        case 2:
            imprimir(&raiz);

            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:

            printf("Gracias por usarnos \n");
            n=4;
            break;

        }

    }
    return 0;
}
