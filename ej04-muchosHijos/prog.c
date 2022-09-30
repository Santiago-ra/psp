//definimos una constante osea una variable que siempre va a valer lo mismo
#define N_HIJOS 5
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main (int argc, char const *argv[]){

    for (int i = 0; i < N_HIJOS; i++)
    {
        //Si es un hijo que salude, si no que continue, recordamos que al hacer fork() el hijo se queda con valor 0
        if (fork() == 0){
            //Codigo de los hijos
            printf("Hola soy el hijo número: %d.\n", getpid());
            sleep(1);
            return i; //Ponemos un return i para que los hijos mueran aqui y no sigan por abajo recorriendo el codigo
                        //Ponemos i para que se queden como valor de retorno en la vuelta en la que estaban
        }
    }

    int estado;
    int pidHijo;
    //El wait devuelve el codigo pid del hijo que finaliza
    for (int i = 0; i < N_HIJOS; i++)
    {
        pidHijo = wait(&estado);
        printf("El hijo %d ha finalizado con valor de retorno %d\n",
        pidHijo, WEXITSTATUS(estado));
    }
    
    


    return 0;
}