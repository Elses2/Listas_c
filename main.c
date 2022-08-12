#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


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
    printf(" 1: Insertar nodo\n 2: Eliminar nodo \n 3: Mostrar lista \n 4: Cerrar programa\n");
}
struct Nodo{

    char dato;
    struct nodo *ptrSiguiente;

};
typedef struct Nodo nodo;
typedef struct Nodo *ptrNodo;
int main()
{

    ptrNodo nuevo;
    nuevo=malloc(sizeof(nodo));
    int n=2;
    char boton_c [20];
    int boton=0;

    while(n == 2){

        presentacion();
        gets(boton_c);
        fflush(stdin);

        controlador_entero(boton_c,20,&boton,1,4);



        switch(boton){
        case 1:
            scanf("%c", &nuevo->dato);
            fflush(stdin);
            printf("%c\n",nuevo->dato);


            break;
        case 2:
            break;
        case 3:
            break;
        case 4:

            printf("Gracias por usarnos \n");
            n=4;
            break;

        }

    }
    return 0;
}
