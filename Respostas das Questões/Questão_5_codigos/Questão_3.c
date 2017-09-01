#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]){

    int fp;

    char nome[100];
    char idade[100];
    char arquivo[100];


    sprintf(arquivo, "%s.txt", argv[1]);

    fp = open(arquivo, O_WRONLY | O_CREAT, S_IRWXU);

    if (fp == -1) {
        printf("Erro. O arquivo não foi criado.");
        exit(1);
    }

    sprintf(nome, "Nome: %s \n", argv[1]);
    sprintf(idade, "Idade: %s anos\n", argv[2]);

    write(fp, &nome, strlen(nome));
    write(fp, &idade, strlen(idade));
    close(fp);

    return 0;
}
