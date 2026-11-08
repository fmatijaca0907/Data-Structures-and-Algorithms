
#include <stdlib.h>
#include <stdio.h>

void print(int *n,int l){
    for(int i = 0;i < l;i++){
        printf("%d ",n[i]);
    }
}

int* podniz(int *niz,int start,int stop){

    int n = stop - start;
    int *niz_n = (int*)malloc(sizeof(int)*n);

    int idx = 0;
    for(int i = start; i < stop;i++){
        //printf("%d",i);
        niz_n[idx] = niz[i];
        idx++;
    }
    return niz_n;
}

int* filtriraj(int *niz,int n,int th, int *nth){
    int broj = 0; //2
    for(int i = 0;i < n;i++){
        if(niz[i]<th) broj++;
    }
    int *novo = (int*)malloc(sizeof(int)*broj);
    int idx = 0;
    for(int i = 0;i<n;i++){
        if(niz[i]<th){
            novo[idx] = niz[i];
            idx++;
        }
    }
    *nth = broj;
    return novo;
}
/*
int** podijeli(int *niz, int n) – dijeli niz dužine n na dva jednaka dijela i stvara kopije prvog i drugog dijela. 
Funkcija vraća dva pokazivača koji pokazuju na prvi i na drugi dio. 
U slučaju neparne dužine niza, centralni element ide u drugi niz koji će imati jedan element više.
*/

int* podjeli_prvi(int *niz,int n,int* l){
    n = n/2;
    int *novo = malloc(sizeof(int)*n);
    for(int i = 0;i<n;i++){
        novo[i] = niz[i];
    }
    *l = n;
    return novo;
}

int* podjeli_drugi(int* niz,int n,int *l){
    int *novo = malloc(sizeof(int)*n/2);
    int broj = 0;
    for(int i = n/2;i<n;i++){
        novo[broj] = niz[i]; 
        broj++;
    }
    *l = broj;
    return novo;
}

int** podjeli(int *niz,int n){
    int n1;
    int *prvi = podjeli_prvi(niz,n,&n1);
    int n2;
    int *drugi = podjeli_drugi(niz,n,&n2);
    int **novo = malloc(sizeof(int)*(n1+n2));

    novo[0] = prvi;
    novo[1] = drugi;
    return novo;
}

int main(){
    int niz[] = {1,2,3,4,5,6,7};
    int n = sizeof(niz)/sizeof(niz[0]);
    int n1;
    filtriraj(niz,n,4,&n1);
    int **novo = podjeli(niz,n);
    free(novo);

}