#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *buff, *vector[5];
    buff= (char *) malloc(20*sizeof(char));
    puts("Ingrese 5 nombres y apellidos");
    for (int i = 0; i < 5; i++)
    {
        gets(buff);
        *(vector+i)= (char *) malloc((strlen(buff)+1)*sizeof(char));
        strcpy(*(vector+i),buff);
    }
    for (int i = 0; i < 5; i++)
    {
        puts("---------------------");
        puts(*(vector+i));
        free(*(vector+i));
    }
    free(buff);
    getchar();
    return 0;
}