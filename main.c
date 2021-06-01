#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#include "hash_aberta.h"

 int main(int argc, char *argv[]) {	
	setlocale(LC_ALL, "Portuguese");
 	
	HASHABERTA *hash = (HASHABERTA*) malloc(sizeof(HASHABERTA*));
	inicializar(hash, 7.0, 0.8, 3.0);
	exibirHashAberta(hash);
	system("PAUSE");
	system("CLS");
	
	
	ALUNO* aluno = (ALUNO*) malloc(sizeof(ALUNO*));
	aluno->matricula = 1;
	aluno->nota = 9.8;
	char nome[]="Savio1";
	strcpy(aluno->nome, nome);

	
	ALUNO* alunoDois = (ALUNO*) malloc(sizeof(ALUNO*));
	alunoDois->matricula = 2;
	alunoDois->nota = 9.7;
	char nomeDois[]="Savio2";
	strcpy(alunoDois->nome, nomeDois);

	
	ALUNO* alunoTres = (ALUNO*) malloc(sizeof(ALUNO*));
	alunoTres->matricula = 3;
	alunoTres->nota = 9.7;
	char nomeTres[]="Savio3";
	strcpy(alunoTres->nome, nomeTres);

	
	ALUNO* aluno4 = (ALUNO*) malloc(sizeof(ALUNO*));
	aluno4->matricula = 4;
	aluno4->nota = 9.7;
	char nome4[]="Savio4";
	strcpy(aluno4->nome, nome4);

	
	ALUNO* aluno5 = (ALUNO*) malloc(sizeof(ALUNO*));
	aluno5->matricula = 5;
	aluno5->nota = 9.7;
	char nome5[]="Savio5";
	strcpy(aluno5->nome, nome5);
	
	ALUNO* aluno6 = (ALUNO*) malloc(sizeof(ALUNO*));
	aluno6->matricula = 6;
	aluno6->nota = 9.7;
	char nome6[]="Savio6";
	strcpy(aluno6->nome, nome6);
	
	ALUNO* aluno7 = (ALUNO*) malloc(sizeof(ALUNO*));
	aluno7->matricula = 7;
	aluno7->nota = 9.7;
	char nome7[]="Savio7";
	strcpy(aluno7->nome, nome7);
	
	ALUNO* aluno8 = (ALUNO*) malloc(sizeof(ALUNO*));
	aluno8->matricula = 8;
	aluno8->nota = 9.7;
	char nome8[]="Savio8";
	strcpy(aluno8->nome, nome8);
	
	

	hash = inserirHashAberta(hash, aluno);
	exibirHashAberta(hash);
	system("PAUSE");
	system("CLS");
	
	hash = inserirHashAberta(hash, alunoDois);
	exibirHashAberta(hash);
	system("PAUSE");
	system("CLS");
	
	hash = excluirAlunoHashAberta(hash, 2);
	system("PAUSE");
	system("CLS");
	
	hash = inserirHashAberta(hash, alunoTres);
	exibirHashAberta(hash);
	system("PAUSE");
	system("CLS");
	
	hash = inserirHashAberta(hash, aluno4);
	exibirHashAberta(hash);
	system("PAUSE");
	system("CLS");
	
	hash = inserirHashAberta(hash, aluno5);
	exibirHashAberta(hash);
	system("PAUSE");
	system("CLS");
	
	printf("\n tem que expandir\n\n\n\n");
	
	hash = inserirHashAberta(hash, aluno6);
	exibirHashAberta(hash);
	system("PAUSE");
	system("CLS");
	
	hash = inserirHashAberta(hash, aluno7);
	exibirHashAberta(hash);
	system("PAUSE");
	system("CLS");
	
	hash = inserirHashAberta(hash, aluno8);
	exibirHashAberta(hash);
	system("PAUSE");
	system("CLS");
	
	finalizarHashAberta(hash);
	//free(hashExpandida);
	return 0;
}

    














