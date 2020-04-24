#include <stdio.h>
#include <stdlib.h>

int *wczytaj(int n, int *tab)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Podaj %d element tablicy:",i+1);
        scanf("%d",&tab[i]);
    }
    return tab;
}

int *sortbabelkowe(int n, int *tab)
{
    int i,j,rob;
    for(i=n-1;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            if(tab[j-1]>tab[j])
            {
                rob=tab[j-1];
                tab[j-1]=tab[j];
                tab[j]=rob;
            }
        }
    }
    return tab;
}

int *insertsort(int n, int *tab)
{
    int i;
    for(i=1;i<n;i++)
    {
        int j=i;
        int p=tab[j];
        while((j>0)&&(tab[j-1]>p))
        {
            tab[j]=tab[j-1];
            j--;
        }
        tab[j]=p;
    }
    return tab;
}

int *selectsort(int n, int *tab)
{
    int i,j,max,p;
    for(i=n-1;i>=1;i--)
    {
        max=tab[0];
        p=0;

        for(j=1;j<=i;j++)
        {
            if(max<tab[j])
            {
            max=tab[j];
            p=j;
            }
        }
        tab[p]=tab[i];
        tab[i]=max;
    }
    return tab;
}

void wydruk(int n, int *tab)
{
    int i;
    if(n!=1)
    {
        for(i=0;i<n;i++)
        {
            printf("element %d to %d\n",i+1,tab[i]);
        }
    }else printf("TABLICA JEST PUSTA\n\n");
}

int main()
{
    int w,n=1;
    int *tab;
    tab=(int*)malloc(n*sizeof(int));
   do
   {
       printf("WYBIERZ OPCJE:\n");
        printf("1.Podanie danych\n");
        printf("2.sort.babelkowe\n");
        printf("3.insert sort\n");
        printf("4.select sort\n");
        printf("5.wydruk tablicy\n");
        printf("6.KONIEC PROGRAMU\n");
       scanf("%d",&w);
        switch(w)
        {
            case 1: {
                    do
                    {
                        printf("Podaj liczbe elementow:");
                        scanf("%d",&n);
                    }while(n<=0);
                    tab=(int*)malloc(n*sizeof(int));
                    wczytaj(n,tab);
                    break;
                    }
            case 2: sortbabelkowe(n,tab);break;
            case 3: insertsort(n,tab);break;
            case 4: selectsort(n,tab);break;
            case 5: wydruk(n,tab);break;
        }
   }while(w!=6);
   free(tab);
    return 0;
}

