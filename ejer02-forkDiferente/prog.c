#include <stdio.h> //importa el printf
#include <unistd.h> //importa el fork, sleep, wait
#include <sys/types.h> //importa el pid_t
#include <sys/wait.h> //importa el wait para que el padre pueda esperar al hijo


int main(int argc, char const *argv[]){
    pid_t numPid; //Es un tipo de dato que especifica que el numero que ira dentro sera un identificador de proceso, ya que en cada sistema operativo este entero ocupa tamaños diferentes
    int num = 12; //Como hay un fork despues, esta variable se duplicará y se podra modificar, el hijo trabajara con una copia y podra modificarla cuando quiera


    numPid = fork(); //se duplicara el camino, uno será el padre y el otro el hijo. Creara dos hilos de ejecucion
    //cuando se crea un fork, el hijo creado se identifica con un 0
    if (numPid == 0){ //proceso hijo devolverá cierto y entrará en el if
        printf("Soy el hijo mi pid es: %d\n", getpid());
        num = 15;
        sleep(1);// hacemos que el hijo espere un segundo
    }else{
        printf("Soy el padre mi pid es: %d\n", getpid());
        int estado = 25;//el valor 25 es indiferente, como si lo ponemos sin valor
        pid_t pidFinalizado = wait(&estado);//hemos cambiado el NULL(que este null solo indica una posicion de memoria), le hemos puesto la variable estado, que no significa que le pases el valor de 25, sino que le pasas la posicion que ocupa ese 25, esto se consigue con el & al principio, simplemente utiliza esta posicion de memoria para crear un entero que tendra informacion referente a los estados del proceso
        //pid_t pidFinalizado = wait(NULL); //Comentamos abajo por que queremos ver que hijo a finalizado, ya que al wait(NULL) te devuelve tambien que pid a acabado, asi que lo capturamos
        //wait(NULL); //el padre esperara hasta que el hijo acabe la ejecucion, pero solo esperara al primer hijo que llege, si tiene más hijos no esperara al resto
        printf("El hijo con PID: %d finalizó con estado: %d, el valor de estado es: %d\n",
                pidFinalizado,WEXITSTATUS(estado),estado);//esta ultima funcion te devuelve los 8 ultimos bits, que es donde se codifican los estados (si el proceso a muerto, si esta en espera...)
                //el parametro estado que le estamos pasando a WEXITSTATUS, es la posicion de memoria, donde se creara un entero que sera codificado para introducir el estado del proceso que pase por aqui, si ha muerto... 
        
    }
    printf("Hola a todos, num es: %d\n", num); //esto lo ejecutarán los dos



    return 0;
}