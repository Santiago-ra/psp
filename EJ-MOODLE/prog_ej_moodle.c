#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char const *argv[]){

    //char* lista [] = {"/home/usuario/Documentos/fichero1","/home/usuario/Documentos/fichero2","/home/usuario/Documentos/fichero3","/home/usuario/Documentos/fichero4"};
    //int tamanio = sizeof(argv); //con esto calculamos cuantas rutas hay en nuestra lista para preparar el for de abajo
   printf("Texto %s %i", argv[1], argc);

    if(argc != 2){
        //fprintf junto con stderr o stdout, son formas de imprimir,(en formato de error y cosas asi)
        fprintf(stderr,"\nError, Especifica al menos un archivo.\n");
        fprintf(stdout, "Uso del programa: \n\t %s <Nombre de fichero>\n\n", argv[0]);
        exit(-1); //le indicamos que salga del programa
    }

   //Los ficheros se pasan como argumentos a la hora de ejecutar el programa
   //se crearan un archivo con extension .hashes por cada fichero pasado como argumento, que contendra en su interior las 4 variantes de hash
    for (int i = 1; i <= argc; i++){
        char ruta2[7];
        char touch[7];
        strcpy(ruta2, argv[i]);
        strcpy(touch, "touch ");
        strcat(touch, ruta2);
        printf("%s",touch);
        system(touch);

        /*if(fork() == 0){
            char ruta[7];
            char md5sum[8];
            char sha1sum[9];
            char sha256sum[11];
            char sha512sum[11];
            char operador[4];
            char operador2[5];
            char extension[8];

            //Para crear cadenas con los valores necesarios
            strcpy(md5sum, "md5sum ");
            strcpy(sha1sum, "sha1sum ");
            strcpy(sha256sum, "sha256sum ");
            strcpy(sha512sum, "sha512sum ");
            strcpy(ruta, argv[i]);
            strcpy(operador, " > ");
            strcpy(operador2, " >> ");
            strcpy(extension, ".hashes");

            //Para crear hash md5sum
            strcat(md5sum,ruta);
            strcat(md5sum,operador);
            strcat(md5sum,ruta);
            strcat(md5sum,extension);
            //printf("%s\n",md5sum);
            system(md5sum);

            //Para crear hash sha1sum
            strcat(sha1sum,ruta);
            strcat(sha1sum,operador2);
            strcat(sha1sum,ruta);
            strcat(sha1sum,extension);
            //printf("%s\n",sha1sum);
            system(sha1sum);

            //Para crear hash sha256sum
            strcat(sha256sum,ruta);
            strcat(sha256sum,operador2);
            strcat(sha256sum,ruta);
            strcat(sha256sum,extension);
            //printf("%s\n",sha256sum);
            system(sha256sum);

            //Para crear hash sha512sum
            strcat(sha512sum,ruta);
            strcat(sha512sum,operador2);
            strcat(sha512sum,ruta);
            strcat(sha512sum,extension);
            //printf("%s\n",sha512sum);
            system(sha512sum);

            printf("Soy el hijo: %d ", getpid());

            return 0;

        }*/
            
        
        
    }




    return 0;
}