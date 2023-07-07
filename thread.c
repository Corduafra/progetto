#include <malloc.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <pthread_time.h>
#include "funzioni.c"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <c++/bits/atomic_futex.h>
#include "windows.h"


typedef struct semaphore semaphore;
int som=0;
/*
HANDLE semaforo;

void Wait() {
    WaitForSingleObject(semaforo, INFINITE);
}

void Signal() {
    ReleaseSemaphore(semaforo, 1, NULL);
}
 */


int Funziona(void){
    void *tmp = malloc(10);
    free(tmp); // Assegna NULL al puntatore dopo averlo liberato
    return tmp ? 1 : 0;
}
struct dati{
    int *a;
    int inizio;
    int fine;
    int nArray;
};

//creazione semaforo
sem_t mutex;

void threads(){
    int segmentSize = dimArray() / numThread();
    int stato=0;

    pthread_t threads[numThread()];

    auto startTime = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numThread(); i++) {
        int startIndex = i * segmentSize;
        int endIndex = (i == numThread() - 1) ? dimArray() - 1 : (i + 1) * segmentSize - 1;

        threads[i] = std::thread(funzione(a), startIndex, endIndex);
    }

    for (int i = 0; i < numThread(); i++) {
        pthread_join(threads[i], stato);

        if (stato != 0) {
            printf("errore thread , %d", i);
            exit(-2);
        }
    }
    auto endTime = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    printf( "Tempo impiegato: %d ",duration); //<< duration.count() << " millisecondi" << std::endl;
};





//funzione del thread cioè che dovrà fare
void *funzione(struct dati* a){
    int totale;
    int tot;
    struct dati *dato=a;
    if (Funziona()) {
        for(int j = 0; j < dato->nArray; j++)
            for(int i =0 ; i < dimArray(); i++)
                totale += dato->a[i];


        sem_wait(mutex);

        sem_post(mutex);

        pthread_exit(1);
    }
    else
        pthread_exit(0);
}















//gara del calcolo










/*
sem_destroy(mutex);

// Deallocazione memoria dinamica utilizzata
free(dati);
free(mutex);
t_sum = 0;
 */

//
// Created by cordua francesco on 06/07/2023.
//

