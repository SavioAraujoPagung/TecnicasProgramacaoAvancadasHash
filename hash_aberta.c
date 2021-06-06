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
		hash->tabelaHash[i]->aluno = NULL;
		hash->tabelaHash[i]->continuar = 0;
		hash->tabelaHash[i]->tamanho = 0;	
	}
}

void exibirInformacoesHashAberta(HASHABERTA *hash){
	printf("\n******** TABELA HASH ABERTA ********\n");
	printf("-------------------------------------\n");
	printf("\tSOBRE\n");
	printf("-> Tamanho atual....%.2f\n", hash->tamanho);
	printf("-> Expansão.........%.2f\n", hash->expansao);
	printf("-> Fator de Carga...%.2f\n", hash->fatorCarga);
	printf("-> Quantidade.......%.2f\n\n", hash->quantidade);
	printf("************************************\n");
	
	
}

void exibirHashAberta(HASHABERTA *hash){
	FILE *hashAbertaInfo;
	hashAbertaInfo = fopen("hashAbertaInfo.txt", "w");

	int i=0;	
	fprintf(hashAbertaInfo, "******** TABELA HASH ABERTA ********\n");
	fprintf(hashAbertaInfo, "-------------------------------------\n");
	fprintf(hashAbertaInfo, "\tSOBRE\n");
	fprintf(hashAbertaInfo, "-> Tamanho atual....%.2f\n", hash->tamanho);
	fprintf(hashAbertaInfo, "-> Expansão.........%.2f\n", hash->expansao);
	fprintf(hashAbertaInfo, "-> Fator de Carga...%.2f\n", hash->fatorCarga);
	fprintf(hashAbertaInfo, "-> Quantidade.......%.2f\n\n", hash->quantidade);
	/*
	printf("******** TABELA HASH ABERTA ********\n");
	printf("-------------------------------------\n");
	printf("\tSOBRE\n");
	printf("-> Tamanho atual....%.2f\n", hash->tamanho);
	printf("-> Expansão.........%.2f\n", hash->expansao);
	printf("-> Fator de Carga...%.2f\n", hash->fatorCarga);
	printf("-> Quantidade.......%.2f\n\n", hash->quantidade);
	*/
	for (i=0; i<hash->tamanho; i++){
		fprintf(hashAbertaInfo, "\tPOSICAO %d\n", i);
		if(hash->tabelaHash[i]->aluno!=NULL){
			fprintf(hashAbertaInfo, "-> Sobre o aluno: \n");
			fprintf(hashAbertaInfo, "Nome      = %s\n", hash->tabelaHash[i]->aluno->nome);
			fprintf(hashAbertaInfo, "Matricula = %d\n", hash->tabelaHash[i]->aluno->matricula);
			fprintf(hashAbertaInfo, "Nota      = %.2f\n", hash->tabelaHash[i]->aluno->nota);
			/*
			printf("-> Sobre o aluno: \n");
			printf("Nome      = %s\n", hash->tabelaHash[i]->aluno->nome);
			printf("Matricula = %d\n", hash->tabelaHash[i]->aluno->matricula);
			printf("Nota      = %.2f\n", hash->tabelaHash[i]->aluno->nota);
			*/
		}
		fprintf(hashAbertaInfo, "\n--- continuar: %d\n", hash->tabelaHash[i]->continuar); //verificação de consulta
		fprintf(hashAbertaInfo, "-----------------------------\n");
	}
	fclose(hashAbertaInfo);
}

int fancaoHashAberta(int tamanhoAtual, int matricula){
	int posicao;
	posicao = matricula%tamanhoAtual;
	return posicao;
}

ALUNO* consultarMatriculaHashAberta(HASHABERTA *hash, int matricula){
	ALUNO* aluno = (ALUNO* ) malloc(sizeof(ALUNO*));
	aluno = NULL;
	int posicao = 0;
	
	int tamanho = hash->tamanho*1; //tranformando para int
	posicao = fancaoHashAberta(tamanho, matricula);
	int i=posicao;
	if((hash->tabelaHash[i]->continuar!=0)&&(hash->tabelaHash[i]->aluno->matricula == matricula)){
		//encontrou de primeira
		aluno = hash->tabelaHash[i]->aluno;
		return aluno;
	}else{
		//percorrendo para buscar
		int j=(i+1);//buscar por posicao mais um 
		if(j>=tamanho){
			j = 0;
		}
		for (j=j; j<tamanho; j++){//parar se chegar na posicao da funcao hash
			if(hash->tabelaHash[j]->continuar == 1){//verifica se pode continuar buscando na lista
				if(hash->tabelaHash[j]->aluno!=NULL){//existe um aluno na posicao?
					if(hash->tabelaHash[j]->aluno->matricula == matricula){//confere se esta nessa posicao e retorna o aluno
						aluno=hash->tabelaHash[j]->aluno;
						return aluno;
					}
				}
				if((j+1)>tamanho){//voltar ao inicio da hash
					j=-1;
				}
			}else {//não esta na lista
				return NULL;
			}
			
		}
	}
	return aluno;
}

HASHABERTA* inserirHashAberta(HASHABERTA *hash, ALUNO *aluno){
	double fatorCargaAtual;
	int posicao;
	if (aluno == NULL){
		printf("\naluno invalido\n");
		return hash;
	}
	if(consultarMatriculaHashAberta(hash, aluno->matricula)==NULL){//ALuno já matriculado?
		//exibirInformacoesHashAberta(hash);
		fatorCargaAtual = (hash->quantidade+1)/hash->tamanho; //valor para conferir se tem que espaço para inserir mais 1 aluno
		if(fatorCargaAtual<hash->fatorCarga){//verificando se o fator de carga deixa inserir
			int tamanho = hash->tamanho*1; //tranformando para int
			
			posicao = fancaoHashAberta(tamanho, aluno->matricula);
			
			hash->tabelaHash[posicao]->tamanho = hash->tabelaHash[posicao]->tamanho + 1;//para verificar qual a maior sequencia em uma hash aberta
			if(hash->tabelaHash[hash->indiceMaior]->tamanho < hash->tabelaHash[posicao]->tamanho){
				hash->indiceMaior = posicao;
			}
			
			//printf("\nmatricula = %d posicao = %d\n", aluno->matricula, posicao);
			//system("pause");
			if(hash->tabelaHash[posicao]->aluno != NULL){
				int j;
				for(j=(posicao+1); j!=posicao; j++){//buscando um lugar disponível para adicionar a posicao
					if(j < hash->tamanho){//verificando se nao vai ultrapassar o tamanho da hash
						if(hash->tabelaHash[j]->aluno == NULL){//verifica de posicao esta disponivel
							posicao = j; //encontrou a posicao ideal
							break; 
						}
					}else{
						j = -1;
					}							
				}
			}			
			
			hash->quantidade = hash->quantidade+1; //aumentar a quantidade
			hash->tabelaHash[posicao]->continuar = 1;
			hash->tabelaHash[posicao]->aluno = aluno;
			hash->tabelaHash[posicao]->aluno->posicao = posicao;		
			
		}else{//expandindo a hash e inserindo nota
			hash = expansao(hash);
			inserirHashAberta(hash, aluno);
		}
	}else{
	}
	return hash;
}

HASHABERTA* expansao(HASHABERTA *hash){ //multiplica a quantidade pelo fator de cargo
	HASHABERTA* hashExpandida = (HASHABERTA*) malloc(sizeof(HASHABERTA*));
	double novoTamanho = ((hash->tamanho)*(hash->expansao));
	inicializar(hashExpandida, novoTamanho, hash->fatorCarga, hash->expansao);
	int i;
	for(i=0; i<hash->tamanho; i++){ //inserir os alunos da antiga hash na nova;
		if(hash->tabelaHash[i]->aluno!=NULL){
			inserirHashAberta(hashExpandida, hash->tabelaHash[i]->aluno);
		}
	}
	hash = hashExpandida;
	return hashExpandida;
}

void finalizarHashAberta(HASHABERTA *hash){
	int i;
	for(i=0; i<hash->tamanho; i++){
		free(hash->tabelaHash[i]);//malocando memoria
	}
	free(hash);
}

HASHABERTA* excluirAlunoHashAberta(HASHABERTA *hash, int matricula){
	ALUNO* aluno = (ALUNO* ) malloc(sizeof(ALUNO*));
	aluno = consultarMatriculaHashAberta(hash, matricula);
	if(aluno!=NULL){
		hash->tabelaHash[aluno->posicao]->aluno	= NULL;
	}
	
	return hash;
}




































