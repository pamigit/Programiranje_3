/* Napisati program koji za definisanu matricu susedstva određuje i ispisuje stepen svakog čvora grafa postavljenog tom matricom? */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* st[5] - niz broja koja za dati cvor odredjuje stepen */
    int ms[5][5]={
        {0,1,0,1,0},
        {1,0,1,0,1},
        {0,0,0,1,0},
        {0,0,1,0,0},
        {0,1,0,1,0}
    };
    int n=5,i,j, br;
    int st[5]={0};
    // Prebrojavamo jedinice po vrstama. Ne racunamo vezu (a,a)
    for(i=0; i<n; i++){
        br=0;
        for(j=0; j<n; j++)
            if(i!=j && ms[i][j]==1)
                br++;
        st[i]=br;
        printf("\nCvor %d je stepena %d", i+1, st[i]);
    }
    return 0;
}
