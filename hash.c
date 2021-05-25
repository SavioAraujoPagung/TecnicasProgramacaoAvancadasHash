#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

void inicializarHash(HASHABERTA *hash, int tamanho){
	hash->tamanhoAtual = tamanho;
	int i=0;
	hash->tabelaHash = (LISTA**) malloc(sizeof(LISTA**)*tamanho);
	for (i=0; i<hash->tamanhoAtual; i++){
		hash->tabelaHash[i] = (LISTA*) malloc(sizeof(LISTA*));
		inicializarLista(hash->tabelaHash[i]);
	}
}

void exibirHash(HASHABERTA *hash){
	int i=0;
	printf("******** TABELA HASH FECHADA ********\n");
	printf("-------------------------------------\n");
	for (i=0; i<hash->tamanhoAtual; i++){
		printf("\tPOSICAO %d\n", i);
		exibir(hash->tabelaHash[i]);
	}
}

void inserirHash(HASHABERTA *hash, ALUNO *aluno){
	int posicao = funcaoHash(hash->tamanhoAtual, aluno->matricula);
	inserirLista(hash->tabelaHash[posicao], aluno);
}
int funcaoHash(int tamanhoAtual, int matricula){
	int posicao;
	posicao = matricula%tamanhoAtual;
	return posicao;
}

ALUNO* consultarMatriculaHash(HASHABERTA *hash, int matricula){
	ALUNO *aluno = (ALUNO*) malloc(sizeof(ALUNO)); 
	int posicao = funcaoHash(hash->tamanhoAtual, matricula);
	aluno = consultarPorMatriculaLista(hash->tabelaHash[posicao], matricula);
	return aluno;
}

void excluirHash(HASHABERTA *hash, int matricula){
	int posicao = funcaoHash(hash->tamanhoAtual, matricula);
	excluir(hash->tabelaHash[posicao], matricula);
}




