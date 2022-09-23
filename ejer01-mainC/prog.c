/*Incluimos las librerias para imprimir por pantalla*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/*Como se compila y ejecuta un programa en C gcc prog.c -o prog.exe*/


int main(int argc, char const *argv[])
{
    /*Es como un tenedor, paraleliza el programa en varios programas, todo lo de despues de fork, se ejecutara 2 veces*/
    fork();
    fork();
    printf("Mi PID es %d y mi padre es %d\n", getpid(), getppid());


    return 0;
}
