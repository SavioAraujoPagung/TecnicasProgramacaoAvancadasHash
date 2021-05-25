#include <stdio.h>
#include <stdlib.h>
#include "hash_aberta.h"


void inicializar(HASHABERTA *hash, double tamanhoInicial, double fatorCarga, double expansao){
	hash->fatorCarga = fatorCarga;
	hash->expansao = expansao;
	hash->tamanho = tamanhoInicial;
	hash->tabelaHash = (NOHASH**) malloc(sizeof(NOHASH*)*tamanhoInicial);
	int i;
	for(i=0; i<tamanhoInicial; i++){
		hash->tabelaHash[i] = (NOHASH*) malloc(sizeof(NOHASH));//malocando memoria
		hash->tabelaHash[i]->aluno = NULL;
		hash->tabelaHash[i]->continuar = 0;
	}
}
/**/
void exibirHashAberta(HASHABERTA *hash){
	int i=0;
	printf("******** TABELA HASH ABERTA ********\n");
	printf("-------------------------------------\n");
	printf("\tSOBRE\n", i);
	printf("-> Tamanho atual: %.2f\n", hash->tamanho);
	printf("-> Expansao: %.2f\n", hash->expansao);
	printf("-> Fator de Carga: %.2f\n\n", hash->fatorCarga);
	for (i=0; i<hash->tamanho; i++){
		printf("\tPOSICAO %d\n", i);
		if(hash->tabelaHash[i]->aluno!=NULL){
			printf("sobre o aluno: \n");
			printf("Nome = %s\n", hash->tabelaHash[i]->aluno->nome);
			printf("Matricula = %d\n", hash->tabelaHash[i]->aluno->matricula);
			printf("Nota = %.2f\n", hash->tabelaHash[i]->aluno->nota);
		}
		printf("continuar: %d\n", hash->tabelaHash[i]->continuar); //verificação de consulta
		
		printf("-----------------------------\n");
		
	}
}


void inserirHash(HASHABERTA *hash, ALUNO *aluno);
ALUNO* consultarMatriculaHash(HASHABERTA *hash, int matricula);
void excluirHash(HASHABERTA *hash, int matricula);
void exibirHash(HASHABERTA *hash);
