#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Producto {
    int productoID; //Numerado en ciclo iterativo
    int cantidad; // entre 1 y 10
    char *tipoProducto; // Algún valor del arreglo TiposProductos
    float precioUnitario; // entre 10 - 100
    }typedef producto;

struct Cliente {
    int clienteID; // Numerado en el ciclo iterativo
    char *nombreCliente; // Ingresado por usuario
    int cantidadProductosAPedir; // (aleatorio entre 1 y 5)
    producto *productos; //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
}typedef cliente;

void mostrarClientes(cliente *lista,int cantClientes);
void cargarClientes(cliente *lista, int cantClientes);
int coste(producto item);

int main()
{
    srand(time(NULL));
    int nroDeClientes;
    puts("Indique la cantidad de clientes");
    scanf("%d",&nroDeClientes);
    cliente *clientes= (cliente *) malloc(nroDeClientes*sizeof(cliente));

    cargarClientes(clientes,nroDeClientes);
    mostrarClientes(clientes,nroDeClientes);
    getchar();
    free(clientes);
    fflush(stdin);
    getchar();
    return 0;
}

int coste(producto item){
    int total= item.cantidad*item.precioUnitario;
    return total;
}

void cargarClientes(cliente *lista, int cantClientes){

    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    char *buffer=malloc(100*sizeof(char));

    for (int i = 0; i < cantClientes; i++)
    {
        lista[i].clienteID = i + 1;
        puts("Ingrese el nombre del cliente");
        fflush(stdin);
        gets(buffer);
        lista[i].nombreCliente= (char *) malloc(strlen(buffer)+1 * sizeof(char));
        strcpy(lista[i].nombreCliente, buffer);
        lista[i].cantidadProductosAPedir = rand() % 5 + 1;
        lista[i].productos = (producto*) malloc(lista[i].cantidadProductosAPedir * sizeof(producto));
        for (int j = 0; j < lista[i].cantidadProductosAPedir; j++){
            lista[i].productos[j].productoID = j+1;
            lista[i].productos[j].cantidad= rand()% 10 + 1;
            lista[i].productos[j].tipoProducto = (char *) malloc(15 * sizeof(char));
            strcpy(lista[i].productos[j].tipoProducto,TiposProductos[rand()%4]);
            lista[i].productos[j].precioUnitario= rand() % 100 + 10;
        }
    }
    free(buffer);
}

void mostrarClientes(cliente *lista,int cantClientes){
    for (int i = 0; i < cantClientes; i++)
    {
        printf("---------------------------------------------------\n");
        printf("-----Cliente %d--------\n",lista[i].clienteID);
        printf("Nombre del cliente: %s\n",lista[i].nombreCliente);
        printf("Cantidad de productos pedidos: %d\n\n",lista[i].cantidadProductosAPedir);
        printf("-------PRODUCTOS PEDIDOS-------\n");
        for (int j = 0; j < lista[i].cantidadProductosAPedir; j++)
        {
            printf("--------Producto %d--------\n",lista[i].productos[j].productoID);
            printf("Cantidad: %d\n",lista[i].productos[j].cantidad);
            printf("Tipo del producto: %s\n",lista[i].productos[j].tipoProducto);
            printf("Precio por unidad: %f\n\n",lista[i].productos[j].precioUnitario);
            printf("------------TOTAL------------\n");
            printf("------------%d------------\n\n",coste(lista[i].productos[j]));
            printf("---------------------------------------------------\n");
        }
    }
}