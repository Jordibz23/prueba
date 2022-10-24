#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


int suma;
int numeros[10]={1,4,8,6,10,25,84,41,60,3};
void* rutina(void* valor){
    long numero;
    int aux;
    numero = (long) valor;
    int sumahilo = 0;
    if (numero=1)
        {
            if (suma>1)
            {
                aux=5;
            }else{
                aux=0;
            }
        }
        printf("%ld",numero);
        printf("%d\n",aux);
    for (int i = aux; i < aux+5; i++)
    {
        printf("%d\n",numeros[i]);
        sumahilo = sumahilo + numeros[i];
    }
    //printf("El hilo sumo: %d",sumahilo);
    suma = suma +sumahilo;
}

int main(int argc, char*argv[]){
    
    pthread_t hilos[2];
    for (int i = 0; i < 2; i++)
    {
        long aux=i+1;
        
        printf("%ld",aux);
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