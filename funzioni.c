#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>



#define MAX 500

int dimArray();

int numThread(){
    int num=0;
    printf("scegliere un numero di thread tra 5 e 10 \n" ) ;
    scanf("%d", &num);
    if(num < 5 || num >10){
        printf("sbagliato, uscita dal programma");
        exit(-1);
    }
    return num;

}
int numProcess() {
    int num = 0;
    printf("scegliere un numero di thread tra 5 e 10 \n");
    scanf("%d", &num);
    if (num < 5 || num > 10)
        if(num < 5 || num >10){
            printf("sbagliato, uscita dal programma");
            exit(-1);
        }
    return num;
}

int faiScelta(){
    int scelta =0;
    printf("inserisci la tua scelta: ");
    scanf("%d", &scelta);
    return scelta;
}

double somma(int *a){
    double totale=0;
    for (int i = 0; i < dimArray(); ++i) {
        totale += a[i];

    }
    return totale;
}

int dimArray() {
    int n;
    printf("inserisci il numero di elementi nell'array: ");
    scanf("%d",&n);
    return n;
}


void RiempiamoArray(int num, int* a) {
    srand((time(NULL)));

    for (int i = 0; i < num; ++i) {
        // Genera un numero casuale
        int random_number = rand() % MAX;

        a[i] = random_number;
    }
}

double cronometro(struct timespec inizio){
    struct timespec fine;
    clock_gettime(CLOCK_REALTIME, &fine);
    //cronometro(inizio);
    double durata = (fine.tv_nsec-inizio.tv_nsec) +(fine.tv_sec-inizio.tv_sec);
    return durata;

}





