#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

void inicializarHash(HASHFECHADA *hash, int tamanho){
	hash->tamanhoAtual = tamanho;
	hash->indiceMaior = 0;
	int i=0;
	hash->tabelaHash = (LISTA**) malloc(sizeof(LISTA**)*tamanho);
	for (i=0; i<hash->tamanhoAtual; i++){
		hash->tabelaHash[i] = (LISTA*) malloc(sizeof(LISTA*));
		inicializarLista(hash->tabelaHash[i]);
	}
}

void exibirHash(HASHFECHADA *hash){
	FILE *hashFechadaInfo;
	hashFechadaInfo = fopen("hashFechadaInfo.txt", "w");
	int i=0;
	fprintf(hashFechadaInfo, "******** TABELA HASH FECHADA ********\n");
	fprintf(hashFechadaInfo, "-------------------------------------\n");
	for (i=0; i<hash->tamanhoAtual; i++){
		fprintf(hashFechadaInfo, "\tPOSICAO %d\n", i);
		escreverTxt(hash->tabelaHash[i], hashFechadaInfo);
	}
	fclose(hashFechadaInfo);
}

void exibirInformacoesHash(HASHFECHADA *hash){
	printf("\n******** TABELA HASH FECHADA ********\n");
	printf("---------------------------------------\n");
	printf("\tSOBRE\n");
	printf("-> Indice Maior....%d\n", hash->indiceMaior);
	printf("-> Tamanho Atual...%d\n", hash->tamanhoAtual);
	printf("***************************************\n");
}

void inserirHash(HASHFECHADA *hash, ALUNO *aluno){
	int posicao = funcaoHash(hash->tamanhoAtual, aluno->matricula);
	inserirLista(hash->tabelaHash[posicao], aluno);
	if (hash->tabelaHash[hash->indiceMaior]->tamanho < hash->tabelaHash[posicao]->tamanho){
		hash->indiceMaior=posicao;	
	}
}
int funcaoHash(int tamanhoAtual, int matricula){
	int posicao;
	posicao = matricula%tamanhoAtual;
	return posicao;
}

ALUNO* consultarMatriculaHash(HASHFECHADA *hash, int matricula){
	ALUNO *aluno = (ALUNO*) malloc(sizeof(ALUNO)); 
	int posicao = funcaoHash(hash->tamanhoAtual, matricula);
	aluno = consultarPorMatriculaLista(hash->tabelaHash[posicao], matricula);
	return aluno;
}

void excluirHash(HASHFECHADA *hash, int matricula){
	int posicao = funcaoHash(hash->tamanhoAtual, matricula);
	excluir(hash->tabelaHash[posicao], matricula);
}




