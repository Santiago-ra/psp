//definimos una constante osea una variable que siempre va a valer lo mismo
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#define N_HIJOS 5

int main (int argc, char const *argv[]){

    for (int i = 0; i < N_HIJOS; i++)
    {
        //Si es un hijo que salude, si no que continue, recordamos que al hacer fork() el hijo se queda con valor 0
        if (fork() == 0){
            //Codigo de los hijos
            printf("Hola soy el hijo número: %d.\n", getpid());
            sleep(1);
            return i; //Ponemos un return i para que los hijos obtengan un valor de retorno y no sigan abajo si hubiera un else
                        //Ponemos i para que se queden como valor de retorno en la vuelta en la que estaban
        }
    }

    int estado;
    int pidHijo;
    //La funcion wait() va asociada a la funcion fork(), wait espera a que el/los procesos hijos acaben, si asocias wait() a 
    //una variable, te devolverá el id del hijo que ha esperado
    for (int i = 0; i < N_HIJOS; i++)
    {
        pidHijo = wait(&estado); //Con esto ademas de guardar el pid del hijo que haya llegado al final en la 
        //variable pidHijo, se guarda en la variable estado el byte de la posicion que ocupa en cada vuelta y para cada hijo
        printf("El hijo %d ha finalizado con estado %d y valor de retorno %d\n",
        pidHijo, estado,WEXITSTATUS(estado));

        //la funcion WEXITSTATUS(estado) busca dentro de los bytes que ocupa, justo en los 8 ultimos bytes el estado en el que se encuentra, 
        //en este caso como los hijos tienen un return guardado en memoria, te devolvera el valor del return
    }
    
    


    return 0;
}