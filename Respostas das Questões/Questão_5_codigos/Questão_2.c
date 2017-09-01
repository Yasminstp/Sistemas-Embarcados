#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv[ ]){

    int fp;

    char nome[100];
    char arquivo[100];
    char mensagem[100];
    char informa[100];
    int idade;

    printf("Digite o seu nome:\n");
    scanf("%s", &nome);
    printf("\nDigite sua idade:\n");
    scanf("%d", &idade);

    sprintf(arquivo,"%s.txt", nome);
    sprintf(mensagem, "Idade: %d anos\0", idade);
    sprinf(informa, "Nome: %s\0", nome);

    fp = open(arquivo, O_WRONLY | O_CREAT, S_IRWXU);

    if(fp == -1){
        printf("Erro. O arquivo não foi criado.");
        exit(1);
    }
    write(fp, &mensagem, strlen(mensagem));
    write(fp, &informa, strlem(informa));
    close(fp);

    return 0;
}
