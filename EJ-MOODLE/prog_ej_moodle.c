#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char const *argv[]){

    //char* lista [] = {"/home/usuario/Documentos/fichero1","/home/usuario/Documentos/fichero2","/home/usuario/Documentos/fichero3","/home/usuario/Documentos/fichero4"};
    //int tamanio = sizeof(argv); //con esto calculamos cuantas rutas hay en nuestra lista para preparar el for de abajo
   printf("argc %i: pid del padre: %d\n", argc, getpid());

    if(argc < 2){
        fprintf(stderr,"\nError, Especifica al menos un archivo.\n");
        fprintf(stdout, "Uso del programa: \n\t %s <Nombre de fichero>\n\n", argv[0]);
        exit(-1);
    }

    //Este for va creando los ficheros pasados como argumentos en la ruta donde se ejecute el programa
    for (int i = 1; i <= argc; i++){
        char touch[7];
        char fichero2 [250];
        strcpy(touch, "touch ");
        strcpy(fichero2, argv[1]);

        strcat(touch,fichero2);
        system(touch);
    }

   //Los ficheros se pasan como argumentos a la hora de ejecutar el programa
   //se crearan un archivo con extension .hashes por cada fichero pasado como argumento, que contendra en su interior las 4 variantes de hash
    for (int i = 1; i <= argc; i++){
        
        
        if(fork() == 0){
            
            char md5sum[8];
            char sha1sum[9];
            char sha256sum[11];
            char sha512sum[11];
            char operador[4];
            char operador2[5];
            char extension[8];
            char fichero [256];


            //Para crear cadenas con los valores necesarios
            strcpy(md5sum, "md5sum ");
            strcpy(sha1sum, "sha1sum ");
            strcpy(sha256sum, "sha256sum ");
            strcpy(sha512sum, "sha512sum ");
            strcpy(operador, " > ");
            strcpy(operador2, " >> ");
            strcpy(extension, ".hashes");
            strcpy(fichero, argv[i]);

            //Para crear hash md5sum
            strcat(md5sum,fichero);
            strcat(md5sum,operador);
            strcat(md5sum,fichero);
            strcat(md5sum,extension);
            //printf("%s\n",md5sum);
            system(md5sum);

            //Para crear hash sha1sum
            strcat(sha1sum,fichero);
            strcat(sha1sum,operador2);
            strcat(sha1sum,fichero);
            strcat(sha1sum,extension);
            //printf("%s\n",sha1sum);
            system(sha1sum);

            //Para crear hash sha256sum
            strcat(sha256sum,fichero);
            strcat(sha256sum,operador2);
            strcat(sha256sum,fichero);
            strcat(sha256sum,extension);
            //printf("%s\n",sha256sum);
            system(sha256sum);

            //Para crear hash sha512sum
            strcat(sha512sum,fichero);
            strcat(sha512sum,operador2);
            strcat(sha512sum,fichero);
            strcat(sha512sum,extension);
            //printf("%s\n",sha512sum);
            system(sha512sum);

            printf("Soy el hijo: %d \n", getpid());

            return 0;

        }
        
        for (size_t i = 0; i < argc; i++)
        {
            /* code */
        }
        
           
        
        
    }




    return 0;
}