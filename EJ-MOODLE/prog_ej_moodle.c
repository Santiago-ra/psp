#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char const *argv[]){

    printf("Comienza el programa y soy el padre con PID: %d\n", getpid()); //Esto lo dejo como ayuda para hacer el seguimiento, del padre y de los hijos

    if(argc < 2){
        fprintf(stderr,"\nError, Especifica al menos un archivo.\n");
        fprintf(stdout, "Uso del programa: \n\t %s <Nombre de fichero>\n\n", argv[0]);
        exit(-1);
    }

    //Este for va creando los ficheros pasados como argumentos en la ruta donde se ejecute el programa, porque es necesario que esten creados antes para luego poder buscarlos y
    //crear el fichero .hashes
    for (int i = 1; i < argc; i++){
        char touch[7];
        char fichero [250];
        strcpy(touch, "touch ");
        strcpy(fichero, argv[i]);

        strcat(touch,fichero);
        system(touch);
    }

   //Los ficheros se han pasado como argumentos a la hora de ejecutar el programa
   //se crearan un archivo con extension .hashes por cada fichero pasado como argumento, que contendra en su interior las 4 variantes de hash
   //El ford se ejecutara como tantos argumentos haya introducido. (Recordamos que el tambien cuenta como argumento el lancamiento del propio programa ./programa.exe), asi que hay que tenerlo en cuenta
    for (int i = 1; i < argc; i++){
        
        
        if(fork() == 0){ //hacemos el fork directamente en el if, si el fork ha salido bien, se optendra como retorno 0 para el hijo, con lo cual el hijo entrara en el if
            
            //Creamos las variables que luego iremos rellenando con la funcion strcpy
            char md5sum[8];
            char sha1sum[9];
            char sha256sum[11];
            char sha512sum[11];
            char operador[4];
            char operador2[5];
            char extension[8];
            char fichero [256];


            //Rellenamos las variables con los valores que utilizaremos
            strcpy(md5sum, "md5sum ");
            strcpy(sha1sum, "sha1sum ");
            strcpy(sha256sum, "sha256sum ");
            strcpy(sha512sum, "sha512sum ");
            strcpy(operador, " > ");
            strcpy(operador2, " >> ");
            strcpy(extension, ".hashes");
            strcpy(fichero, argv[i]);

            //Ahora vamos concatenando las variables segun lo que necesitemos con la funcion strcat
            //Para crear hash md5sum
            strcat(md5sum,fichero);
            strcat(md5sum,operador);
            strcat(md5sum,fichero);
            strcat(md5sum,extension);
            //printf("%s\n",md5sum); --> Es una comprobacion para ver que la cadena esta bien montada
            system(md5sum);

            //Para crear hash sha1sum
            strcat(sha1sum,fichero);
            strcat(sha1sum,operador2);
            strcat(sha1sum,fichero);
            strcat(sha1sum,extension);
            //printf("%s\n",sha1sum); --> Es una comprobacion para ver que la cadena esta bien montada
            system(sha1sum);

            //Para crear hash sha256sum
            strcat(sha256sum,fichero);
            strcat(sha256sum,operador2);
            strcat(sha256sum,fichero);
            strcat(sha256sum,extension);
            //printf("%s\n",sha256sum); --> Es una comprobacion para ver que la cadena esta bien montada
            system(sha256sum);

            //Para crear hash sha512sum
            strcat(sha512sum,fichero);
            strcat(sha512sum,operador2);
            strcat(sha512sum,fichero);
            strcat(sha512sum,extension);
            //printf("%s\n",sha512sum); --> Es una comprobacion para ver que la cadena esta bien montada
            system(sha512sum);

            printf("Soy el hijo: %d \n", getpid()); //Esto es una ayuda para identificar que hijo pasa en cada momento

            return 0;

        }    
        
    }

    int estado;
    pid_t hijoFinalizado;
    for (int i = 1; i < argc; i++){
        hijoFinalizado = wait(&estado); //espera a que un hijo acabe, (Solo al primero que llegue), en hijoFinalizado guardaremos el pid del hijo y en estado el valor de retorno
        if (WEXITSTATUS(estado) == 0){
            printf("El hijo con PID: %d ha finalizado con éxito\n", hijoFinalizado);
        }else{
            printf("El hijo con PID: %d ha finalizado con error\n", hijoFinalizado);
        }
    }



    return 0;
}