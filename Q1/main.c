#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
 char info;
 struct nodo *prox;
}Nodo;

//CRIAR
Nodo * criar_no(){
    Nodo *novo =(Nodo*)malloc(sizeof(Nodo));
    return novo;
}

//INSERIR
Nodo* inserir_no_inicio(Nodo * Lista, char dado){
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

//Imprimir
void imprimir(Nodo* lista){
        Nodo *aux=lista;

        while(aux!=NULL){
            printf("%c ",aux->info);
            aux=aux->prox;
        }
}

//Excluir
Nodo* apagar(Nodo *Lista){
    Nodo *aux = Lista;
	Lista = aux->prox;
	free(aux);
	return Lista;
}

int main(){
    Nodo * Lista=NULL;
    
	//Inserir letra A
	int i;
	for(i=0;i<3;i++)
		Lista=inserir_no_inicio(Lista,'A');
    if(i%2!=0)
		Lista=apagar(Lista);
	
	//Inserir letra B
	int j;
	for(j=0;j<2;j++)
		Lista=inserir_no_inicio(Lista,'B');
    if(j%2==0)
		Lista=apagar(Lista);
	
    imprimir(Lista);
    free(Lista);
    return 0;
}