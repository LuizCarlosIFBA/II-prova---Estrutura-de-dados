#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
 int info;
 struct nodo *prox;
}Nodo;

//CRIAR
Nodo * criar_no(){
    Nodo *novo =(Nodo*)malloc(sizeof(Nodo));
    return novo;
}

//INSERIR
Nodo* inserir_no_inicio(Nodo * Lista, int dado){
    Nodo *novo_no=criar_no();
    novo_no->info=dado;

    if(Lista == NULL){
        Lista=novo_no;
        novo_no->prox=NULL;
    }else{ novo_no->prox=Lista;
           Lista=novo_no;
         }
         return Lista;
}

Nodo* inserir_no_fim(Nodo * Lista, int dado){
    Nodo *novo_no=criar_no();
    novo_no->info=dado;

    if(Lista == NULL){
        novo_no->prox=NULL;
        Lista=novo_no;

    }else{ Nodo *aux=Lista;
           while(aux->prox!=NULL){
				aux=aux->prox;
		   }
		   novo_no->prox=NULL;
		   aux->prox=novo_no;
         }
         return Lista;
}

void imprimir(Nodo* lista){
        Nodo *aux=lista;

        while(aux!=NULL){
            printf("%i ",aux->info);
            aux=aux->prox;
        }
}

void main(){
    Nodo * Lista=NULL;
	
	int n=4;
	Lista=inserir_no_inicio(Lista,n);
	printf("          ");
	imprimir(Lista);
	printf("\n");
	
	int inicio = 4;
	int fim = 4;
	
	//Configura o espaçamento do triangulo
	int espaco = 4;
	
	for(int i=0;i<n;i++){
		inicio--;
		fim++;
		
		Lista=inserir_no_inicio(Lista,inicio);
		
		//Configura o espaçamento do triangulo
		for(int a=0;a<espaco;a++)
			printf("  ");
		espaco--;
		
		Lista=inserir_no_fim(Lista,fim);
		imprimir(Lista);
		printf("\n");
	}	
	free(Lista);
}