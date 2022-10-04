#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h> //aqui se encuentra la funcion que nos permite convertir una cadena de texto a entero

//argc = el contador de parametros
//argv[] = son lo parametros
//Normalmene en c cuando ejecutamos un programa podemos pasarle un parametro ej:./prog hola entonces argc = 2 y argv[] contendra ./prog y hola
int main(int argc, char const *argv[])
{
    if(argc != 2){
        //fprintf junto con stderr o stdout, son formas de imprimir,(en formato de error y cosas asi)
        fprintf(stderr,"\nError, el programa debe tener un parametro.\n");
        fprintf(stdout, "Uso del programa: \n\t %s <num_pid>\n\n", argv[0]);
        exit(-1); //le indicamos que salga del programa
    }

    pid_t pidParametro = atoi(argv[1]);
    kill(pidParametro, SIGUSR1); //Funcion kill, le pasas el pid de un proceso y la señal asociada y lo matara


    return 0;
}
