//Crrear un proceso que cree un hijo, espere con un sleep y le mande al padre una señal 
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>

//Declaramos la cabecera de la funcion para asociar la señal
void tratarSenyal (int codSenyal);

int main(int argc, char const *argv[])
{
    pid_t padre, hijo;
    padre = getpid();
    hijo = fork();

    if(hijo == 0){
        //soy el hijo
        printf("[HIJO] Soy el hijo (PID:%d) y mi padre es: %d.\n", hijo, padre);
        printf("[HIJO] En un segundo le envio la señal al padre");
        sleep(1);
        kill(getppid(), SIGUSR1);
        printf("[HIJO]: Señal enviada, en un segundo terminaré.\n");
        sleep(1);
    }else{ 
        //Soy el padre
        signal(SIGUSR1, tratarSenyal);
        printf("[PADRE]: Me quedo esperando señal del hijo\n");
        pause();
        int estado;
        printf("[PADRE]: Me quedo esperando la finalizacion del hijo\n");
        hijo = wait(&estado); //El wait esepera al primer hijo y te devuelve el pid de ese hijo, pero ademas como extra si le pones "&estado" rellenara la variable estado con un numero con inforemación extra del estado en el que se encuentra
        printf("[PADRE]Un hijo %d ha terminado con estado %d\n",hijo, WEXITSTATUS(estado)); //WEXITSTATUS(estado) mira en los ultimos 8bits de la variable estado y ahi esta programado el valor del estado
    }    
    return 0;
}
void tratarSenyal (int codSenyal){
    printf ("He recibido una señal. \n");
}

