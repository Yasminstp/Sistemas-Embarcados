#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv[ ]){

    int fp;
    char mensagem[200] = "Ola mundo!" ;

    fp = open("ola_mundo.txt", O_WRONLY | O_CREAT, S_IRWXU);

    if (fp == -1){
        printf("Erro. O arquivo não foi criado.");
        exit(1);
    }

    //Esta chamada de sistema escreve em um descritor de arquivo.
    //fp corresponde ao descritor do arquivo a ser escrito.
    //&mensagem é um ponteiro para a área com os dados a serem escritos em fp.
    //sizeof(é a quantidade máxima de bytes a ser escrita).

    write(fp, &mensagem, sizeof(mensagem));
    close(fp);

    return 0;
}

