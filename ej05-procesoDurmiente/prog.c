// programa para probar con los procesos y comando kill, matarlos, etc..
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>//Hay que incluir esta libreria para que entienda el texto SIGUSR1 y no poner solo su numero de señal

//Si queremos cambiar el comportamiento de las señales que podemos modificar, hay que hacer una funcion antes del main
void manejadorSenyal(int numSenyal); //Podemos desarrollarla aqui, o solo definirla/declararla y luego desarrollarla abajo, es indiferente

int main(int argc, char const *argv[])
{
    signal(SIGUSR1,manejadorSenyal); //Estamos vinculando la señal SIGUSR1 con la funcion, asi cuando reciba esta señal, parara lo que este haciendo y lanzar lo que tenga definida en la funcion manejadorSenyal
    printf("PID: %d\n", getpid());
    //sleep(20);
    pause(); //Para el proceso hasta que una señal llegue
    return 0;
}

//El sleep es interrumpido cuando recibe cualqueir señal
void manejadorSenyal(int numSenyal){
    printf("He recibido una señal número: %d\n", numSenyal); //numSenyal guarda el número de la señal
}


