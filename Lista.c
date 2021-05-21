#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

int listaVazia(LISTA *lista){
	if ((lista->inicio == NULL)&&(lista->fim == NULL)) return 0;
	else return 1;
}

void exibir(LISTA *lista){
	printf("\n\n\tLISTAR POR CODIGO\n");
	printf("\t------\n");
	NO *no = (NO*) malloc(sizeof(NO));
	no = lista->inicio;
	if(no == NULL){
		printf("\nLista vazia\n");
	}
	while(no!=NULL){
		printf("Nome = %s\n", no->aluno->nome);
		printf("Matricula = %d\n", no->aluno->matricula);
		printf("-----------------------------\n");
		no = no->proximo;
	}
	printf("\n==============================================\n");
}

void inserir(LISTA *lista, char nome[30], int matricula, double nota){
	NO *aux = (NO*) malloc(sizeof(NO)); //auxilia para percorrer a lista 
	NO *noNovo = (NO*) malloc(sizeof(NO)); //criacao do novo NO
	ALUNO *aluno = (ALUNO*) malloc(sizeof(ALUNO)); //criacao do novo Aluno para colocar no NO
	
	aluno->matricula = matricula;
	aluno->nota = nota;
	
	//inicializando noNovo
	noNovo->anterior = NULL;
	noNovo->proximo = NULL;
	noNovo->aluno = aluno;
	
	//inicializando No Auxiliar
	aux = lista->inicio;
	
	//inserindo
	if (aux==NULL){
		lista->inicio = noNovo;
		lista->fim = noNovo;
		
	}else{
		while((aux->aluno->matricula < noNovo->aluno->matricula)){
			//encontrar o lugar
			if (aux->proximo==NULL) break;
			aux = aux->proximo;
		}
		if((aux->proximo==NULL)&&(aux->aluno->matricula < noNovo->aluno->matricula)){
			//printf("\nadd no fim CODIGO\n");
			aux->proximo = noNovo;
			noNovo->anterior = aux;
			lista->fim = noNovo;			
		}else{
			//meio da lista ou inicio 
			if(aux == lista->inicio){
				//inicio da lista
				noNovo->proximo = aux;
				aux->anterior = noNovo;
				lista->inicio = noNovo;
			}else{
				//meio
				noNovo->proximo = aux;
				noNovo->anterior = aux->anterior;
				aux->anterior->proximo = noNovo;
				aux->anterior = noNovo;
			}//else
		}//else
	}//else (aux==NULL)

}

void remover(NO* lixo, LISTA* lista){
	//verificar se existe o no lixo
	
	if (lista->inicio == lista->fim){
		lista->fim = NULL;
		lista->inicio = NULL;
		return;
	}
	
	if(lixo->aluno->matricula == lista->inicio->aluno->matricula){
		//inicio da lista
		lista->inicio = lixo->proximo;
		lixo->proximo->anterior = NULL;
		
		free(lixo);
		return;
	}/**/else if(lixo->aluno->matricula == lista->fim->aluno->matricula){
		//final da lista
		lista->fim = lixo->anterior;
		lixo->anterior->proximo = NULL;
		
		free(lixo);
		//return 1;
	}else{
		//meio da lista
		lixo->proximo->anterior = lixo->anterior;
		lixo->anterior->proximo = lixo->proximo;
		
		free(lixo);
		//return 1;
	}
}

int excluir(LISTA *lista, int matricula){
	// ponteiros para auxiliar a exclusao ...
	NO *lixo = (NO*) malloc(sizeof(NO));
	lixo = NULL;
	
	// lista com somente 1 elemento
	if(lista->inicio==lista->fim){
		lixo=lista->inicio;
		remover(lixo, lista);
		return 1;
	}
	
 
	//	encontrar o NO responsavel LCodigo
	lixo = lista->inicio;
	while((lixo!=NULL)&&(lixo->aluno->matricula!=matricula)){ 
		lixo=lixo->proximo;
	}
	
	//nao encontrado
	if(lixo==NULL) {
		return 0; 
	}
	
	
	//remover os NO's
	remover(lixo, lista);

	return 1;
	//exibir(lista);	
}

ALUNO *consultarMatricula (LISTA *lista, int matricula){
	// ponteiros para auxiliar a exclusao ...
	NO *noAtual = (NO*) malloc(sizeof(NO));	
	
	noAtual = NULL;
	noAtual = lista->inicio;
	
	while((noAtual!=NULL)&&(noAtual->aluno->matricula != matricula)){ //entrontar o NO responsavel LNome
		noAtual=noAtual->proximo;
	}
	
	//nao encontrado
	if(noAtual == NULL) {
		printf("\nALUNO ENCONTRADO! \n\n");
		return NULL;
	}else{
		return noAtual->aluno;
	}
}












