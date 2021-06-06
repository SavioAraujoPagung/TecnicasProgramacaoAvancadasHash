#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "hash_aberta.h"

 int main(int argc, char *argv[]) {	
	setlocale(LC_ALL, "Portuguese");
	 	
	//Lendo o arquivo txt e adicionando a uma FILA os alunos do arquivo
	LISTA* alunos = (LISTA*) malloc(sizeof(LISTA));
	inicializarLista(alunos);
	lerArquivo(alunos, "aleatorio300000ddd.txt");

	//criando a hashAberta
	HASHABERTA *hashAberta = (HASHABERTA*) malloc(sizeof(HASHABERTA*));
	
	inicializar(hashAberta, 20.0, 0.9, 2.0);
	//inicializar(hashAberta, 100000.0, 0.9, 2.0);
	
	//provoando a hash aberta com os alunos da FILA
	NO *aux = (NO*) malloc(sizeof(NO));
	aux = alunos->inicio;
	while(aux != NULL){
		hashAberta = inserirHashAberta(hashAberta, aux->aluno);
		aux = aux->proximo;
	}
	
	//criando arquivo
	//exibirHashAberta(hashAberta); =====================================
	
	//criando a hashAberta
	HASHFECHADA *hashFechada = (HASHFECHADA*) malloc(sizeof(HASHFECHADA*));
	//inicializarHash(hashFechada, 997);
	inicializarHash(hashFechada, 10);
	//inserindo na hash fechada
	aux = alunos->inicio;
	while(aux != NULL){
		inserirHash(hashFechada, aux->aluno);
		aux = aux->proximo;
	}
	//criando arquivo
	//exibirHash(hashFechada); =====================================
		
	//índice da hash fechada com maior quantidade de elementos e a quantidade de elementos nesse índice.
	system("cls");
	exibirInformacoesHash(hashFechada);
	printf("---> INDICE DA HASH FECHADA COM MAIOR QUANTIDADE == [%d]\n", hashFechada->indiceMaior);
	printf("---> QUANTIDADE DE ELEMENTO NO MAIOR NO DA HASH == %d\n", hashFechada->tabelaHash[hashFechada->indiceMaior]->tamanho);
	ALUNO* alunoPiorCaso = hashFechada->tabelaHash[hashFechada->indiceMaior]->fim->aluno;
	//atrícula e nome do aluno que seria o pior caso de busca na hash fechada;
	printf("\n---> ALUNO PIOR CASO <---\n");
	printf("---> MATRICULA: %d <---\n", alunoPiorCaso->matricula);
	printf("---> NOME: %s <---\n", alunoPiorCaso->nome);
	
	printf("\n\n\n");

	//Quantidade de índices atual da hash aberta.
	exibirInformacoesHashAberta(hashAberta);
	
	//Índice inicial e índice final da maior sequência de posições ocupadas na hash aberta;
	printf("--> MAIOR SEQUENCIA \n");
	int indiceFinal = hashAberta->tabelaHash[hashAberta->indiceMaior]->tamanho + hashAberta->indiceMaior;
	if(indiceFinal >= hashAberta->tamanho){
		indiceFinal = indiceFinal - (hashAberta->tamanho+1) ;
	}
	printf("-Inicial [%d]... final [%d]... quantidade = %d\n",hashAberta->indiceMaior, indiceFinal, hashAberta->tabelaHash[hashAberta->indiceMaior]->tamanho);
	
	//Matrícula e nome do aluno que seria o pior caso de busca na hash aberta
	printf("--> Matricula aluno pior caso = %d\n\n\n", hashAberta->tabelaHash[indiceFinal]->aluno->matricula);
	system("pause");
	system("cls");
	
	menu(hashFechada, hashAberta);
	
	return 0;
}


void menu(HASHFECHADA* hashFechada, HASHABERTA* hashAberta){
	int menuOn = 1;
	while(menuOn!=0){
		system("cls");
		printf("1 - Efetuar busca por matrícula\n");
		printf("2 - Excluir por matrícula\n");
		printf("3 - Incluir aluno\n");
		printf("0 - Sair\n");
		printf("Opção: ");
		scanf("%d", &menuOn);
		//printf("\n%d\n", men);
		ALUNO *alunoNovo = (ALUNO*) malloc(sizeof(ALUNO*));
		char nome[30];
		int matricula;
		double nota;
		int posicao;
		int matriculaNew;
		switch (menuOn){
			case 1:
				//62367539
				system("cls");
				printf("*** CONSULTA DE ALUNO ***\n");
				printf("Matricula -> ");
				scanf("%d", &matricula);
				system("cls");
				ALUNO* aluno;
				aluno = consultarMatriculaHash(hashFechada, matricula);
				printf("\n\n-- RESULTADO HASH FECHADA --\n");
				if(aluno==NULL){
					printf("ALUNO NÃO MATRICULADO!\n");
				}
			
				printf("MATRICULA = %d\n", aluno->matricula);
				printf("NOME = %s\n", aluno->nome);
				printf("NOTA = %.2f\n", aluno->nota);
				aluno = consultarMatriculaHashAberta(hashAberta, matricula);
				printf("\n\n-- RESULTADO HASH ABERTA --\n");
				if(aluno==NULL){
					printf("ALUNO NÃO MATRICULADO!\n");
				}
				printf("MATRICULA = %d\n", aluno->matricula);
				printf("NOME = %s\n", aluno->nome);
				printf("NOTA = %.2f\n", aluno->nota);
				printf("POSIÇÃO = %.2f\n", aluno->posicao);
				system("pause");
				break;
			case 2:
				system("cls");
				printf("*** MATRICULA EXCLUIR ***\n");
				printf("Matricula -> ");
				scanf("%d", &matricula);
				system("cls");
				aluno = consultarMatriculaHash(hashFechada, matricula);
				printf("\n\n-- ALUNO EXCLUIDO --\n");
				printf("MATRICULA = %d\n", aluno->matricula);
				printf("NOME = %s\n", aluno->nome);
				printf("NOTA = %.2f\n", aluno->nota);
				printf("\nantes de excluir");
				system("\n\npause");
				
				hashAberta = excluirAlunoHashAberta(hashAberta, matricula);
				excluirHash(hashFechada, matricula);
				system("\n\npause");
				break;
			case 3:
				system("cls");
				printf("*** INSERIR ALUNO ***\n");
				printf("MATRICULA = ");
				scanf("%d", &alunoNovo->matricula); //int
				printf("\nNOTA = ");
				scanf("%lf", &alunoNovo->nota); 
				printf("\nNOTA = %.2f", alunoNovo->nota);//double
				printf("\nNOME = ");
				gets(alunoNovo->nome); //string
				gets(alunoNovo->nome);
				hashAberta = inserirHashAberta(hashAberta, alunoNovo);
				inserirHash(hashFechada, alunoNovo);
				printf("\nALUNO INSERIDO!!!\n\n");
				system("pause");
				
				break;
			case 0:
				exibirHashAberta(hashAberta);
				exibirHash(hashFechada);
				printf("\tARQUIVOS GERADOS\n");
				system("\n\npause");
				break;
			default:
				system("cls");
				printf("\tVALOR INVÁLIDO!!!\n");
				system("pause");
		}
	}
}


void lerArquivo(LISTA* alunos, char url[]){
	char info[44];
	FILE *arq = fopen(url, "r");
	if(arq != NULL) {	
		fgets(info, 44, arq);
		while(fgets(info, 44, arq)!=NULL){
			
			ALUNO* aluno = (ALUNO*) malloc(sizeof(ALUNO*));
			char *arquivo = NULL;
				
			arquivo = strtok(info, ";");				
			aluno->matricula = atoi(arquivo);
			
			arquivo = strtok(NULL, ";");
			strcpy(aluno->nome, arquivo);	
					
			arquivo = strtok(NULL, "\n");
			aluno->nota = atof(arquivo);
			
			aluno->posicao = -1;
			inserirFila(alunos, aluno);						
		}
	}else{
		printf("Erro, não foi possivel abrir o arquivo\n");
	}
	fclose(arq);
}
    
/**/














