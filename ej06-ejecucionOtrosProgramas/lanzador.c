#include <unistd.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    //Utilizamos mediante el path (ruta de un lanzador) + nombre ejecutable + (parametros si se quiere) + null
    //execl("/usr/bin/firefox", "firefox" ,"www.youtube.com", NULL);

    //sirve para ejecutar en el sistema un comando
    //system("ls -l > ls.txt");
    
    //char* es un string en c y esta manera es como se define un array en c
    char* v[] = {"firefox","https:www.youtube.es", NULL};
    execv("/usr/bin/firefox",v);
    return 0;
}
