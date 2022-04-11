#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
    }typedef producto;

struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    producto *Productos; //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
}typedef cliente;

int coste(producto item);

int main()
{
    srand(time(NULL));
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    int nroDeClientes;
    puts("Indique la cantidad de clientes");
    scanf("%d",&nroDeClientes);
    cliente *clientes= (cliente *) malloc(nroDeClientes*sizeof(cliente));

// Carga de Clientes

    for (int i = 0; i < nroDeClientes; i++)
    {
        clientes[i].ClienteID = i + 1;
        clientes[i].NombreCliente= (char *) malloc(20 * sizeof(char));
        puts("Ingrese el nombre del cliente");
        fflush(stdin);
        gets(clientes[i].NombreCliente);
        clientes[i].CantidadProductosAPedir = rand() % 5 + 1;

//Carga de Productos

            clientes[i].Productos = (producto*) malloc(clientes[i].CantidadProductosAPedir * sizeof(producto)+1);
            for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++){
                clientes[i].Productos[j].ProductoID = j+1;
                clientes[i].Productos[j].Cantidad= rand()% 10 + 1;
                clientes[i].Productos[j].TipoProducto = (char *) malloc(15 * sizeof(char));
                strcpy(clientes[i].Productos[j].TipoProducto,TiposProductos[rand()%4]);
                clientes[i].Productos[j].PrecioUnitario= rand() % 100 + 10;
            }
    }
    for (int i = 0; i < nroDeClientes; i++)
    {
        printf("---------------------------------------------------\n");
        printf("-----Cliente %d--------\n",clientes[i].ClienteID);
        printf("Nombre del cliente: %s\n",clientes[i].NombreCliente);
        printf("Cantidad de productos pedidos: %d\n\n",clientes[i].CantidadProductosAPedir);
        printf("-------PRODUCTOS PEDIDOS-------\n");
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            printf("--------Producto %d--------\n",clientes[i].Productos[j].ProductoID);
            printf("Cantidad: %d\n",clientes[i].Productos[j].Cantidad);
            printf("Tipo del producto: %s\n",clientes[i].Productos[j].TipoProducto);
            printf("Precio por unidad: %f\n\n",clientes[i].Productos[j].PrecioUnitario);
            printf("------------TOTAL------------\n");
            printf("------------%d------------\n\n",coste(clientes[i].Productos[j]));
            printf("---------------------------------------------------\n");
        }
    }
    free(clientes);
    fflush(stdin);
    getchar();
    return 0;
}

int coste(producto item){
    int total=item.Cantidad*item.PrecioUnitario;
    return total;
}
