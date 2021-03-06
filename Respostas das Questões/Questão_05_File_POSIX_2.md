
Para todas as questões, utilize as funções da norma POSIX (open(), close(), write(), read() e lseek()). Compile os códigos com o gcc e execute-os via terminal.

1.	Crie um código em C para escrever "Ola mundo!" em um arquivo chamado 'ola_mundo.txt'.

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

2.	Crie um código em C que pergunta ao usuário seu nome e sua idade, e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

$ ./ola_usuario_1
$ Digite o seu nome: Eu
$ Digite a sua idade: 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos

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
    int idade;

    printf("Digite o seu nome:\n");
    scanf("%s", &nome);
    printf("\nDigite sua idade:\n");
    scanf("%d", &idade);

    sprintf(arquivo,"%s.txt", nome);
    sprintf(mensagem, "Idade: %d anos\0", idade);

    fp = open(arquivo, O_WRONLY | O_CREAT, S_IRWXU);

    if(fp == -1){
        printf("Erro. O arquivo não foi criado.");
        exit(1);
    }
    write(fp, &mensagem, strlen(mensagem));
    close(fp);

    return 0;
}



3.	Crie um código em C que recebe o nome do usuário e sua idade como argumentos de entrada (usando as variáveis argc e *argv[]), e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por 
exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

$ ./ola_usuario_2 Eu 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
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

4. Crie uma função que retorna o tamanho de um arquivo, usando o seguinte protótipo: int tam_arq_texto(char *nome_arquivo); Salve esta função em um arquivo separado chamado 'bib_arqs.c'. Salve o protótipo em um arquivo chamado 'bib_arqs.h'. Compile 'bib_arqs.c' para gerar o objeto 'bib_arqs.o'.



bibs_arqs.c:

#include <stdio.h> // printf
#include <fcntl.h> // open
#include <unistd.h>// close
#include <stdlib.h>// exit
#include <string.h> // string
#include "bib_arqs.h"


int tam_arq_texto(char *nome_arquivo){

    int i = 0;
    int leitura;
    char c;

    leitura = open(nome_arquivo, O_RDONLY | O_CREAT, S_IRWXU);

    if(leitura == -1){
        printf("Erro. O arquivo não foi criado.");
        exit(1);
    }

    while(read(leitura, &c, 1) != 0) //read -> esta chamada de sistema ler um descritor de arquivo.
         i++;

    close(leitura);
    return i;
}

5. Crie uma função que lê o conteúdo de um arquivo-texto e o guarda em uma string, usando o seguinte protótipo: void le_arq_texto(char *nome_arquivo, char *conteúdo); Repare que o conteúdo do arquivo é armazenado no vetor conteudo[]. Ou seja, ele é passado por referência. Salve esta função no mesmo arquivo da questão 4, chamado 'bib_arqs.c'. Salve o protótipo no arquivo 'bib_arqs.h'. Compile 'bib_arqs.c' novamente para gerar o objeto 'bib_arqs.o'.


#include <stdio.h> // printf
#include <fcntl.h> // open
#include <unistd.h>// close
#include <stdlib.h>// exit
#include <string.h> // string
#include "bib_arqs.h"


int tam_arq_texto(char *nome_arquivo){

    int i = 0;
    int leitura;
    char c;

    leitura = open(nome_arquivo, O_RDONLY | O_CREAT, S_IRWXU);

    if(leitura == -1){
        printf("Erro. O arquivo não foi criado.");
        exit(1);
    }

    while(read(leitura, &c, 1) != 0) //read -> esta chamada de sistema ler um descritor de arquivo.
         i++;


    close(leitura);
    return i;
}


//Crie uma função que lê o conteúdo de um arquivo-texto e o guarda em uma string

void le_arq_texto(char *nome_arquivo, char *conteúdo){


    int i = 0;
    int leitura;
    char c;

    leitura = open(nome_arquivo, O_RDWR | O_CREAT, S_IRWXU);
    
    if(leitura == -1){
        printf("Erro. O arquivo não foi aberto.");
        exit(1);
    }

    while(read(leitura, &c, 1) != 0){
        conteudo[i] = c;
        i++;
        }

    close(leitura);
    printf("Contem no arquivo: \n%s\n", conteudo);

}

6. Crie um código em C que copia a funcionalidade básica do comando cat: escrever o conteúdo de um arquivo-texto no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'cat_falsificado':

$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./cat_falsificado ola.txt
$ Ola mundo cruel! Ola universo ingrato!

#include <stdio.h> 
#include <fcntl.h> 
#include <unistd.h>
#include <stdlib.h>
#include <string.h> 
#include "bib_arqs.hpp"

int main(int argc, char *argv[])
{
    char c;
    char conteudo[100];
    int leitura; 

    leitura = open(argv[1], O_RDWR | O_CREAT, S_IRWXU);

    if(leitura == -1){
        printf("Erro. O arquivo não foi aberto.");
        exit(-1);
    }

    le_arq_texto(argv[1], conteudo);
    printf("O tamanho do arquivo eh %d BYTES\n", tam_arq_texto(argv[1]));

    close(leitura);
    return 0;
}

7. Crie um código em C que conta a ocorrência de uma palavra-chave em um arquivo-texto, e escreve o resultado no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'busca_e_conta':

$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./busca_e_conta Ola ola.txt
$ 'Ola' ocorre 2 vezes no arquivo 'ola.txt'.

#include <stdio.h> 
#include <fcntl.h> 
#include <unistd.h>
#include <stdlib.h>
#include <string.h> 
#include "bib_arqs.hpp"

int main(int argc, char *argv[]){

    char c;
    char conteudo[250];
    char palavra[20];
    int i = 0, j = 0, k, l, ocorrencia = 0; 
    
    int leitura;
      
    leitura = open(argv[1], O_RDWR | O_CREAT, S_IRWXU);

    if(leitura == -1){
        printf("Erro. O arquivo não foi aberto.");
        exit(1);
    }

    // Nessa parte ocorre o reposicionamento do ponteiro descrito do arquivo na posição 0
    lseek(leitura, 0, SEEK_SET);

    while(read(leitura, &c, 1) != 0){
		conteudo[i] = c;
		i++;
    }

    l = i;
    i = 0;

    printf("\nO conteudo do arquivo: %s\n", conteudo);
    printf("A palavra que se deseja procurar: %s\n", argv[2]);
    printf("A quantidade de caracteres do conteudo do arquivo: %d\n\n", l);

    while(i <= (l+20)){
    	if(conteudo[i] != ' ' && conteudo[i] != ',' && conteudo[i] != '.' && conteudo[i] != '!'){
    		palavra[j] = conteudo[i];
    		j++;
    	}else{

    		printf("Palavra: %s\n", palavra);
    		if(strcmp(palavra, argv[2]) == 0){
    			ocorrencia++;
    		}

    		// onde limpa a variável palavra
    		for(k = 0; k < j; k++)
    			palavra[k] = null;
    		j = 0;
    	}
    	i++;
    }

    printf("\n%s ocorreu %d vezes no arquivo %s\n\n", argv[2], ocorrencia, argv[1]);

    close(leitura);

    return 0;
}


