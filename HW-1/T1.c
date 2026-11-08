#include <stdio.h>

void print(char *s){
    for(char *c = s;*c!='\0';c++){
        printf("%c",*c);
    }
}

int mystrlen(char * s){
    int num = 0;
    for(char *c = s; *c != '\0'; c++){
        num++;
    }
    return num;
}

void mystrcpy(char * w1,char *w2){
    int w2_n = mystrlen(w2);
    int n = mystrlen(w1) + w2_n;
    int nw = n - w2_n; 
    int idx = 0;

    for(int i = nw;i<n;i++){
        w1[i] = w2[idx];
        idx++;
    }
    w1[n] = '\0';
}

int mystrcmp(char* w1,char* w2){
    if(w1[0]<w2[0]) return -1;
    else if(w1[0]>w2[0]) return 1;
    else return 0;
}

char* mystrstr(char *w1,char* s){
    int n = mystrlen(s); //2
    for(char *c = w1;*c!='\0';c++){
        if(*c == s[0]){
            int match = 1;
            for(int i = 1;i < n; i++){
                if(c[i]!=s[i]){
                    match = 0;
                    break;
                }
            }
            if(match) return c;
        }
        
    }
    return NULL;
}

//reverse() – prima dva stringa i kopira prvi string u drugi string naopako (funkcija ne postoji u string.h)

void reverse(char *w1,char* w2){
   int n = mystrlen(w1) + mystrlen(w2); // 5
   int n1 = mystrlen(w1); // 3
   
    int idx = n - n1; // 2
   for(int i = n1 -1; i < n; i++){
        //printf("%d",i);
        w2[i] = w1[idx];
        idx--;
   }
   w2[n] = '\0';
}

int main(){
    char word1[] = "12345";
    char word2[] = "678";
    char string[] = "23";

    mystrcpy(word1,word2);
    mystrcmp(word1,word2);
    mystrstr(word1,string);
    reverse(word2,string);
    print(string);





    return 0;
}