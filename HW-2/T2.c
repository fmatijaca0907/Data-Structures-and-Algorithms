#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float x,y;
}Tocka;

typedef struct 
{
    Tocka *niz;
    int n;
}Poligon;

Poligon* novi_poligon(float *niz_x,float *niz_y,int n){
    Tocka *t = malloc(sizeof(Tocka)*n);
    for(int i = 0;i<n;i++){
        t[i].x = niz_x[i];
        t[i].y = niz_y[i];
    }

    Poligon *novi = malloc(sizeof(Poligon));
    novi->niz = t;
    novi->n = n;
    return novi;
}

Tocka** pozitivni(Poligon *p,int *np){
    int brojac = 0;
    for(int i = 0;i<*np;i++){
        if(p->niz[i].x>0  && p->niz[i].y > 0) brojac++;
    }
    Tocka **t = malloc(sizeof(Tocka*)*brojac);
    brojac = 0;
    for(int i = 0;i<*np;i++){
        if(p->niz[i].x>0  && p->niz[i].y > 0){
            t[brojac] = &p->niz[i];
            brojac++;
        }
    }
    return t;
}

int main(){
    Tocka t1 = {1,2};
    Tocka t2 = {3,4};

    Tocka skup[] = {t1,t2};
    int n = sizeof(skup) / sizeof(skup[0]);

    float x[] = {1,2.3,5.7};
    float y[] = {-0.3,0.5,3.2};
    
    Poligon *p = novi_poligon(x,y,3);
    n = 3;
    Tocka **novo = pozitivni(p,&n);
    free(novo);
    free(p->niz);
    free(p);
    return 0;
}