#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *buff,**vector;
    int size;
    buff= (char *) malloc(20*sizeof(char));
    puts("Cuantos nombres quiere ingresar");
    scanf("%d",&size);
    vector= (char **) malloc(size*sizeof(char *));
    printf("Ingrese %d Nombres y apellidos \n",size);
    for (int i = 0; i < size; i++)
    {
        fflush(stdin);
        gets(buff);
        *(vector+i)= (char *) malloc((strlen(buff)+1)*sizeof(char));
        strcpy(*(vector+i),buff);
    }
    for (int i = 0; i < size; i++)
    {
        puts("---------------------");
        puts(*(vector+i));
        free(*(vector+i));
    }
    free(buff);
    getchar();
    return 0;
}