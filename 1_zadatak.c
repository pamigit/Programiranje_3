/* 1. Napisati program koji za graf dat matricom susedstva proverava da li je usmeren ili ne i izdaje odgovarajuću poruku na ekranu.
Kako bi glasila odgovarajuća funkcija za proveru? */


#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* nus - neusmeren, n - broj cvorova, ms - matrica susedstva */
    int ms[5][5]={
        {0,1,1,1,0},
        {1,0,1,0,1},
        {1,1,0,1,0},
        {0,0,1,0,1},
        {1,1,1,1,0}
    };
    int n=5,i,j,nus=1;

    /* Ispitamo da li postoji (a,a) - nije usmeren */
    for(i=0; i<n; i++)
        if(ms[i][i]==1)
            nus=0;
    /* Pitamo da li je simetrican*/
    if (nus){
        for(i=0; i<n; i++){
            for(j=i+1; j<n; j++)
                if(ms[i][j]!=ms[j][i]){
                    nus=0;
                    break;
                }
        }
    }
    if (nus)
        printf("Graf je neusmeren");
    else
        printf("\nGraf je usmeren");

    return 0;
}
