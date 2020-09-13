#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char ime[20];
    char prezime[20];
} Osoba;
int prijatelji(int a[][4]);

int main()
{
    #define n 4
    int i, j;
    Osoba osoba[n] = {
        {"Nikola", "Nikolic"},
        {"Marko", "Markovic"},
        {"Petar", "Petrovic"},
        {"Ivan", "Ivanović"},
    };

    int poz[][n]={
        {0,1,1,1},
        {1,0,0,0},
        {1,0,0,1},
        {1,0,0,0}

    };

//    int poz[4][4]={0};
//
//    printf("Unesi poznanstva osoba:\n");
//    for(i=0; i<n; i++){
//        printf("\n%s da li poznajes:\n", osoba[i].ime);
//        for(j=0; j<n; j++){
//            if(i!=j){
//                printf("%s:", osoba[j].ime);
////            fflush(stdin);
////            printf("\n%s da li poznajes %s:", osoba[i].ime,osoba[j].ime);
//                scanf("%d", &poz[i][j]);
//            }
//        }
//    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++)
            printf("%d ", poz[i][j]);
        printf("\n");
    }
    printf("\nNajvise prijatelja ima: ");
    printf("%s %s", osoba[prijatelji(poz)].ime,osoba[prijatelji(poz)].prezime) ;
    return 0;
}
int prijatelji(int a[][n]){
    int max=0,maxi=0, br=0, i, j;
    for(i=0; i<n; i++){
        br=0;
        for(j=0; j<n; j++)
            if(i!=j && a[i][j]==1){
                br++;
            }
        if(max<br){
            max=br;
            maxi=i;
        }
    }
    return maxi;
}
