
/* Estructuras de datos 2021
 * Practica:  Colas en C
 * Author: arevalo
 * funciones: mostrar, eliminar, agregar.
 */

#include<stdio.h>
#include<stdlib.h>

struct nodo {
    int info;
    struct nodo *sig;
};

struct nodo *raiz = NULL;
struct nodo *fondo = NULL;

int vacia() {
    if (raiz == NULL)
        return 1;
    else
        return 0;
}

void insertar(int x) {
    struct nodo *nuevo;
    nuevo = malloc(sizeof (struct nodo));
    nuevo->info = x;
    nuevo->sig = NULL;
    if (vacia()) {
        raiz = nuevo;
        fondo = nuevo;
    } else {
        fondo->sig = nuevo;
        fondo = nuevo;
    }
}

int extraer() {
    if (!vacia()) {
        int informacion = raiz->info;
        struct nodo *bor = raiz;
        if (raiz == fondo) {
            raiz = NULL;
            fondo = NULL;
        } else {
            raiz = raiz->sig;
        }
        free(bor);
        return informacion;
    } else
        return -1;
}

void imprimir() {
    struct nodo *reco = raiz;
    printf("Listado de todos los elementos de la cola.\n");
    while (reco != NULL) {
        printf("%i - ", reco->info);
        reco = reco->sig;
    }
    printf("\n");
}

void liberar() {
    struct nodo *reco = raiz;
    struct nodo *bor;
    while (reco != NULL) {
        bor = reco;
        reco = reco->sig;
        free(bor);
    }
}

int ultimo() {
  if (fondo == NULL)
    return -1;
  return fondo->info;
}
int primero() {
  if (raiz == NULL)
    return -1;
  return raiz->info;
}

int tamanio(void) {
  int contador = 0;
  if (raiz == NULL)
    return contador;
  struct nodo *temporal = raiz ;
  while (temporal != NULL) {
    contador++;
    temporal = temporal->sig;
  }
  return contador;
}

int main() {
    int eleccion;
    int numero;
    while (eleccion != -1) {
        printf("\n--BIENVENIDO--\n1.- Agregar\n2.- Eliminar\n3.- Imprimir "
                "Cola\n4.- Imprimir tamaño\n5.- Comprobar si está vacía\n6.- "
                "Mostrar último elemento\n-1.- Salir\n\n\tElige: ");
        scanf("%d", &eleccion);
        switch (eleccion) {
            case 1:
                printf("Ingresa el número que agregaremos:\n");
                scanf("%d", &numero);
                insertar(numero);
                break;
            case 2:
                printf("Extraemos uno de la cola: %i\n", extraer());
                break;
            case 3:
                imprimir();
                break;
            case 4:
                printf("La cola tiene %d elementos\n", tamanio());
                break;
            case 5:
                if (vacia()) {
                    printf("La pila está vacía\n");
                } else {
                    printf("La pila NO está vacía\n");
                }
                break;
            case 6:
                 printf("El primer elemento es: %d\n", primero());
                 printf("El último elemento es: %d\n", ultimo());
                break;
        }
      
    }
  liberar();
    return 0;
}