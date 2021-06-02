#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#include "hash_aberta.h"

 int main(int argc, char *argv[]) {	
	setlocale(LC_ALL, "Portuguese");
	printf("\n ABRINDO ARQUIVO\n\n\n\n");
 	
 	//Lendo o arquivo txt e adicionando a uma FILA os alunos do arquivo
	LISTA* alunos = (LISTA*) malloc(sizeof(LISTA));
	inicializarLista(alunos);
	lerArquivo(alunos, "aleatorio300000.txt");

	//criando a hashAberta
	HASHABERTA *hash = (HASHABERTA*) malloc(sizeof(HASHABERTA*));
	inicializar(hash, 7.0, 0.8, 3.0);
	
	//provoando a hash com os alunos da FILA
	NO *aux = (NO*) malloc(sizeof(NO));
	aux = alunos->inicio;
	while(aux != NULL){
		hash = inserirHashAberta(hash, aux->aluno);
		exibirHashAberta(hash);
		aux = aux->proximo;
	}
	system("cls");	
	exibirHashAberta(hash);
	system("pause");	
	return 0;
}

void lerArquivo(LISTA* alunos, char url[]){
	char info[43];
	FILE *arq = fopen(url, "r");
	
	if(arq != NULL) {	
		while(fgets(info, 43, arq)!=NULL){
			if((fgets(info, 43, arq))=="300000"){
			}else{
				ALUNO* aluno = (ALUNO*) malloc(sizeof(ALUNO*));
				char *arquivo;				
				arquivo = strtok(info, ";");				
				aluno->matricula = atoi(arquivo);
								
				arquivo = strtok(NULL, ";");
				strcpy(aluno->nome, arquivo);
								
				arquivo = strtok(NULL, "");
				
				aluno->nota = atof(arquivo);

				aluno->posicao = -1;
				inserirFila(alunos, aluno);						
			}
		}
	}else{
		printf("Erro, não foi possivel abrir o arquivo\n");
	}
	fclose(arq);
}
    
/**/













