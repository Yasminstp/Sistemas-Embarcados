1. Como se utiliza o comando ps para:

(a) Mostrar todos os processos rodando na máquina?

$ ps -a

(b) Mostrar os processos de um usuário?

$ ps -u

(c) Ordenar todos os processos de acordo com o uso da CPU?

ps aux --sort=-pcpu
$ ps -e -o pid,pcpu,pmem

(d) Mostrar a quanto tempo cada processo está rodando?


$ ps -e -o pid,user,etime

2. De onde vem o nome fork()?

Uma bifurcação ou ramificação é quando se inicia um projeto com base em outro já existente. Por isso é criado dois processo, pai e filho.

3. Quais são as vantagens e desvantagens em utilizar:

(a) system()?

Permite executar um comando dentro de um programa, criando um processo filho (sub-processo). Em sua saída retoma os dados do comando shell. Apesar disso não é recomendado a sua utilização na maioria dos casos, pois possui brechas a falhas de execução por depender muito do sistema.

(b) fork() e exec()?

A função forka() cria uma cópia do processo atual e a função exec() substitui o conteúdo do novo processo criado a partir do fork() por um novo programa. Uma possivel desvantagem é que se não ocorrer uma utilização correta no fork()o a comunicação entre pai e filho torna-se confusa, já para o exec() é que o subprocessor precisa morrer para continuar.

4. É possível utilizar o exec() sem executar o fork() antes?

Sim, a definição de exec() é a capacidade que um programa tem de rodar um outro layout dentro do outro, não depende de fork() para executar. Sendo assim o exec() cria um novo processo, mas a função mata o pai e o filho pega sua PID.

5. Quais são as características básicas das seguintes funções:

(a) execp()?

Aceita programas que estejam na mesma pasta.

(b) execv()?

Aceita que a lista de argumentos seja nula.

(c) exece()?

Aceita um argumento adicional.

(d) execvp()?

Aceita programas da mesma pasta e lista nula.

(e) execve()?

Aceita uma lista nula e argumento adicional.

(f) execle()?

Aceito que em sua lista de argumentos aceitem mecanismo var args em C.
