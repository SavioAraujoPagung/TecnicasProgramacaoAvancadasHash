#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hash_aberta.h"


 int main(int argc, char *argv[]) {	
	HASHABERTA *hash = (HASHABERTA*) malloc(sizeof(HASHABERTA));
	inicializar(hash, 10.0, 0.8, 3.0);
	exibirHashAberta(hash);
	ALUNO* aluno = consultarMatriculaHashAberta(hash, 5);
	return 0;
}

    














