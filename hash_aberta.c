#include <stdio.h>
#include <stdlib.h>
#include "hash_aberta.h"


void inicializar(HASHABERTA *hash, double tamanhoInicial, double fatorCarga, double expansao){
	hash->fatorCarga = fatorCarga;
	hash->expansao   = expansao;
	hash->tamanho    = tamanhoInicial;
	hash->quantidade = 0;
	hash->tabelaHash = (NOHASH**) malloc(sizeof(NOHASH*)*tamanhoInicial);
	int i;
	for(i=0; i<tamanhoInicial; i++){
		hash->tabelaHash[i] = (NOHASH*) malloc(sizeof(NOHASH));//malocando memoria
		hash->tabelaHash[i]->aluno = NULL;//(ALUNO*) malloc(sizeof(ALUNO));
		hash->tabelaHash[i]->continuar = 0;
	}
}

void exibirInformacoesHashAberta(HASHABERTA *hash){
	printf("******** TABELA HASH ABERTA ********\n");
	printf("-------------------------------------\n");
	printf("\tSOBRE\n");
	printf("-> Tamanho atual: %.2f\n", hash->tamanho);
	printf("-> Expansão: %.2f\n", hash->expansao);
	printf("-> Fator de Carga: %.2f\n", hash->fatorCarga);
	printf("-> Quantidade: %.2f\n\n", hash->quantidade);
	printf("************************************\n");
}
void exibirHashAberta(HASHABERTA *hash){
	int i=0;
	printf("******** TABELA HASH ABERTA ********\n");
	printf("-------------------------------------\n");
	printf("\tSOBRE\n");
	printf("-> Tamanho atual: %.2f\n", hash->tamanho);
	printf("-> Expansão: %.2f\n", hash->expansao);
	printf("-> Fator de Carga: %.2f\n", hash->fatorCarga);
	printf("-> Quantidade: %.2f\n\n", hash->quantidade);
	
	for (i=0; i<hash->tamanho; i++){
		printf("\tPOSICAO %d\n", i);
		if(hash->tabelaHash[i]->aluno!=NULL){
			printf("sobre o aluno: \n");
			printf("Nome = %s\n", hash->tabelaHash[i]->aluno->nome);
			printf("Matricula = %d\n", hash->tabelaHash[i]->aluno->matricula);
			printf("Nota = %.2f\n", hash->tabelaHash[i]->aluno->nota);
		}
		printf("\n--- continuar: %d\n", hash->tabelaHash[i]->continuar); //verificação de consulta
		
		printf("-----------------------------\n");
		
	}
}

int fancaoHashAberta(int tamanhoAtual, int matricula){
	int posicao;
	posicao = matricula%tamanhoAtual;
	return 4;
}

ALUNO* consultarMatriculaHashAberta(HASHABERTA *hash, int matricula){
	ALUNO* aluno = (ALUNO* ) malloc(sizeof(ALUNO*));
	aluno = NULL;
	int posicao=0;
	
	int tamanho = hash->tamanho*1; //tranformando para int
	posicao = fancaoHashAberta(tamanho, matricula);
	
	int i=posicao;
	if((hash->tabelaHash[i]->continuar!=0)&&(hash->tabelaHash[i]->aluno->matricula == matricula)){
		//encontrou de primeira
		aluno=hash->tabelaHash[i]->aluno;
		return aluno;
	}else{
		//percorrendo para buscar
		int j=i+1; //buscar por posicao mais um 
		for (j=i; j<tamanho; j++){//parar se chegar na posicao da funcao hash
			if(hash->tabelaHash[j]->continuar == 1){//verifica se pode continuar buscando na lista
				if(hash->tabelaHash[j]->aluno!=NULL){//existe um aluno na posicao?
					if(hash->tabelaHash[j]->aluno->matricula == matricula){//confere se esta nessa posicao e retorna o aluno
						aluno=hash->tabelaHash[j]->aluno;
						return aluno;
					}
				}
				if((j+1)>tamanho){//voltar ao inicio da lista
					j=-1;
				}
			}else {//não esta na lista
				printf("\n*** USUARIO NÃO ENCONTRADO ***\n" );
				return NULL;
			}
		}
	}
	aluno=hash->tabelaHash[i]->aluno;
	return aluno;
}

void inserirHashAberta(HASHABERTA *hash, ALUNO *aluno){
	double fatorCargaAtual;
	int posicao;
	if(consultarMatriculaHashAberta(hash, aluno->matricula)==NULL){//ALuno já matriculado?
		fatorCargaAtual = (hash->quantidade+1)/hash->tamanho; //valor para conferir se tem que espaço para inserir mais 1 aluno
		if(fatorCargaAtual<hash->fatorCarga){//verificando se o fator de carga deixa inserir
			printf("\n INSERINDO \n");
			int tamanho = hash->tamanho*1; //tranformando para int
			posicao = fancaoHashAberta(tamanho, aluno->matricula);
			hash->quantidade = hash->quantidade+1;//aumentar a quantidade
			hash->tabelaHash[posicao]->continuar = 1;
			hash->tabelaHash[posicao]->aluno = aluno;
		}else{//expandindo a hash e inserindo nota
			printf("\n 	EXPANDINDO \n");
			hash = expansao(hash);
			inserirHashAberta(hash, aluno);
			exibirInformacoesHashAberta(hash);		
		}
	}else{
		printf("\n*** ESSA MATRICULA JÁ ESTA VINCULADA A UM ALUNO ***\n" );
	}
}

HASHABERTA* expansao(HASHABERTA *hash){
	HASHABERTA *hashExpandida = (HASHABERTA*) malloc(sizeof(HASHABERTA*));
	double novoTamanho = (hash->tamanho*hash->expansao);
	inicializar(hashExpandida, novoTamanho, hash->fatorCarga, hash->expansao);
	hashExpandida->quantidade = hash->quantidade+1;
	
	int i;
	for(i=0; i<hash->tamanho; i++){
		if(hash->tabelaHash[i]->continuar==1){
			inserirHashAberta(hashExpandida, hash->tabelaHash[i]->aluno);
		}
	}
	return hashExpandida;
}

void excluirHash(HASHABERTA *hash, int matricula);
void exibirHash(HASHABERTA *hash);








