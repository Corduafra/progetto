#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h> // Semafori
#include <pthread.h> // Threads
#include "thread.c"
#include "processi.c"
#include "funzioni.c"
#include <stdexcept>
#include <thread>



using namespace std;












/*
int sum=0;
pthread_mutex_t mutex;

void* routine(int n, int a[]) {
    for (int i = 0; i < n; ++i) {
        // Genera un numero casuale
        int random_number = rand() % MAX_LIMIT;

        a[i]=random_number;

    }
    for (int i = 0; i <n ; ++i) {
        printf("%d) %d\n", i + 1, a[i]);

    }
}



void threads(){
    int mails =5;








        pthread_t th[8];
        int i;
        pthread_mutex_init(&mutex, NULL);
        for (i = 0; i < 8; i++) {
            if (pthread_create(th + i, NULL, reinterpret_cast<void *(*)(void *)>(&routine), NULL) != 0) {
                perror("Failed to create thread");

            }
            printf("Thread %d has started\n", i);
        }
        for (i = 0; i < 8; i++) {
            if (pthread_join(th[i], NULL) != 0) {

            }
            printf("Thread %d has finished execution\n", i);
        }
        pthread_mutex_destroy(&mutex);
        printf("Number of random: %d\n", mails);
    return;

    }

*/


void processes(){

}

void threads_vs_processes(){

}



int main(){
    int scelta;

   // routine(n,a);

    cout<<" ## menu ## "<<endl<<
    "1 uso dei thread "<<endl<<
    "2 uso dei processi "<<endl<<
    "3 confronto thread e processi "<< endl<<
    "4 terminazione programma "<< endl;

    do{
        scelta=faiScelta();


        switch(scelta){
            case 1: threads();
                break;
            case 2: processes();
                break;
            case 3: threads_vs_processes();
                break;
        }

    } while(scelta != 4);

/*
    cout<<"calcolo somma dal main "<< endl;
    int totale=0;
    for (int i = 0; i < n; ++i) {
        totale += a[i];

    }
    cout<<totale;
*/


    return 0;
}

void threads() {

}









