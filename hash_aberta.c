#include <stdio.h>
#include <stdlib.h>
#include "hash_aberta.h"

FILE* abrirLogHash(){
	FILE* log;
	log = fopen("HashAberta.log", "a");
	if(log == NULL){
		printf("Erro na abertura do arquivo!");
	}
	return log;
}

void inicializar(HASHABERTA *hash, double tamanhoInicial, double fatorCarga, double expansao){
	FILE* log = abrirLogHash();
	fprintf(log, "INICIALIZAR HASH\n");
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
		
	}
	fclose(log);
}

void exibirInformacoesHashAberta(HASHABERTA *hash){
	FILE* log = abrirLogHash();
	fprintf(log, "******** TABELA HASH ABERTA ********\n");
	fprintf(log, "-------------------------------------\n");
	fprintf(log, "\tSOBRE\n");
	fprintf(log, "-> Tamanho atual  : %.2f\n", hash->tamanho);
	fprintf(log, "-> Expansão       : %.2f\n", hash->expansao);
	fprintf(log, "-> Fator de Carga : %.2f\n", hash->fatorCarga);
	fprintf(log, "-> Quantidade     : %.2f\n\n", hash->quantidade);
	fprintf(log, "************************************\n");
	fclose(log);
	
	printf("******** TABELA HASH ABERTA ********\n");
	printf("-------------------------------------\n");
	printf("\tSOBRE\n");
	printf("-> Tamanho atual....%.2f\n", hash->tamanho);
	printf("-> Expansão.........%.2f\n", hash->expansao);
	printf("-> Fator de Carga...%.2f\n", hash->fatorCarga);
	printf("-> Quantidade.......%.2f\n\n", hash->quantidade);
	printf("************************************\n");
	
	
}

void exibirHashAberta(HASHABERTA *hash){
	FILE* log = abrirLogHash();
	int i=0;	
	
	printf("******** TABELA HASH ABERTA ********\n");
	printf("-------------------------------------\n");
	printf("\tSOBRE\n");
	printf("-> Tamanho atual....%.2f\n", hash->tamanho);
	printf("-> Expansão.........%.2f\n", hash->expansao);
	printf("-> Fator de Carga...%.2f\n", hash->fatorCarga);
	printf("-> Quantidade.......%.2f\n\n", hash->quantidade);
	
	for (i=0; i<hash->tamanho; i++){
		fprintf(log, "\tPOSICAO %d\n", i);
		printf("\tPOSICAO %d\n", i);
		if(hash->tabelaHash[i]->aluno!=NULL){
			fprintf(log, "-> Sobre o aluno \n");
			fprintf(log, "Nome      = %s\n", hash->tabelaHash[i]->aluno->nome);
			fprintf(log, "Matricula = %d\n", hash->tabelaHash[i]->aluno->matricula);
			fprintf(log, "Nota      = %.2f\n", hash->tabelaHash[i]->aluno->nota);
			
			printf("-> Sobre o aluno: \n");
			printf("Nome      = %s\n", hash->tabelaHash[i]->aluno->nome);
			printf("Matricula = %d\n", hash->tabelaHash[i]->aluno->matricula);
			printf("Nota      = %.2f\n", hash->tabelaHash[i]->aluno->nota);
		}
		fprintf(log, "\n--- continuar: %d\n", hash->tabelaHash[i]->continuar);
		printf("\n--- continuar: %d\n", hash->tabelaHash[i]->continuar); //verificação de consulta
		fprintf(log, "-----------------------------\n");
		printf("-----------------------------\n");
	}
	fclose(log);
}

int fancaoHashAberta(int tamanhoAtual, int matricula){
	int posicao;
	posicao = matricula%tamanhoAtual;
	return posicao;
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
		aluno = hash->tabelaHash[i]->aluno;
		return aluno;
	}else{
		//percorrendo para buscar
		int j;//buscar por posicao mais um 
		for (j=(i+1); j<tamanho; j++){//parar se chegar na posicao da funcao hash
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
				FILE* log = abrirLogHash();
				fprintf(log, " *** ERRO AO CONSULTAR -> USUARIO NÃO ENCONTRADO %d ***\n", matricula);
				printf(" ERRO AO CONSULTAR -> MATRICULA NÃO ENCONTRADA %d  ***\n", matricula);
				fclose(log);
				return NULL;
			}
		}
	}
	return aluno;
}

HASHABERTA* inserirHashAberta(HASHABERTA *hash, ALUNO *aluno){
	double fatorCargaAtual;
	int posicao;
	FILE* log = abrirLogHash();
	if(consultarMatriculaHashAberta(hash, aluno->matricula)==NULL){//ALuno já matriculado?
		//exibirInformacoesHashAberta(hash);
		fatorCargaAtual = (hash->quantidade+1)/hash->tamanho; //valor para conferir se tem que espaço para inserir mais 1 aluno
		if(fatorCargaAtual<hash->fatorCarga){//verificando se o fator de carga deixa inserir
			fprintf(log, "\n INSERINDO HASH \n");
			printf("\n 	INSERINDO \n");
			int tamanho = hash->tamanho*1; //tranformando para int
			posicao = fancaoHashAberta(tamanho, aluno->matricula);
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
			hash->quantidade = hash->quantidade+1;//aumentar a quantidade
			hash->tabelaHash[posicao]->continuar = 1;
			hash->tabelaHash[posicao]->aluno = aluno;
			hash->tabelaHash[posicao]->aluno->posicao = posicao;
			
			printf("\n->Aluno NOVO\nmatricula = %d\n", hash->tabelaHash[posicao]->aluno->matricula);
			printf("posicao = %d\n", posicao);		
		}else{//expandindo a hash e inserindo nota
			hash = expansao(hash);
			inserirHashAberta(hash, aluno);
		}
	}else{
		fprintf(log, "\n*** ESSA MATRICULA JÁ ESTA VINCULADA A UM ALUNO ***\n");
		printf("\n*** ESSA MATRICULA JÁ ESTA VINCULADA A UM ALUNO ***\n" );
	}
	fclose(log);
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
	exibirInformacoesHashAberta(hash);
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
	printf("excluindo aluno matricula = %d\n", matricula);
	ALUNO* aluno = (ALUNO* ) malloc(sizeof(ALUNO*));
	aluno = consultarMatriculaHashAberta(hash, matricula);
	if(aluno!=NULL){
		hash->tabelaHash[aluno->posicao]->aluno	= NULL;
	}
	return hash;
}




































