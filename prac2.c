#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


int suma;

void* rutina(void* valor){
    long numero;
    numero = (long) valor;
    suma = suma +numero;
}

int main(int argc, char*argv[]){
    int nh=atoi(argv[1]);
    pthread_t hilos[nh];
    for (int i = 0; i < nh; i++)
    {
        long aux;
        printf("Ingrese el %d numero para sumar:",i+1);
        scanf("%ld",&aux);
        if(pthread_create(&hilos[i],NULL,&rutina, (void *)aux)!=0){
            return -1;
        }
        if (pthread_join(hilos[i],NULL)!=0){
            return -2;
        }
    }
    printf("La suma es: %d\n",suma);
    return 0;
}