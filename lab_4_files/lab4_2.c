#include<stdlib.h>
#include<stdio.h>
#include<errno.h>

void eliberare (int **v,int k)
{
    int i;
    for(i=0;i<k;i++){
        free(v[i]);
    }
    free(v);
}
     

FILE* deschidere_fisier(char a[],int **v,int m)
{
    FILE *fis;
    fis=fopen(a,"w");
    if(fis==NULL){
        eliberare(v,m);
        perror("eroare deschidere fisier");
        return errno;
    }
    return fis;
}

   

int** citire (int m , int n)
{
    int **a;
    int i,j;
    a=(int **)malloc(m*sizeof(int));
    if(a==NULL){
        perror("eroare de alocare a memoriei");
        return errno;
    }
    for(i=0;i<m;i++)
    {
        a[i]=(int *)malloc(n*sizeof(int));
        if(a[i]==NULL)
        {
            eliberare(a,i);
            perror("eroare de alocare a memoriei");
            return errno;
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("a[%d][%d]=",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    return a;
}

void afisare(int **v,int m,int n,FILE *fis)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            fprintf(fis,"%d ",v[i][j]);
        }
        fprintf(fis,"\n");
    }
}
void afisare_transpusa(int **v,int m,int n,FILE *fis)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            fprintf(fis,"%d ",v[j][i]);
        }
        fprintf(fis,"\n");
    }
}


int main(int argc,char *argv[])
{
    FILE *fout;
    int **a;
    int m,n;
    printf("m=");
    scanf("%d",&m);
    printf("n=");
    scanf("%d",&n);
    a=citire(m,n);
    fout=deschidere_fisier(argv[1],a,m);
    afisare(a,m,n,fout);
    fprintf(fout,"\n");
    afisare_transpusa(a,m,n,fout);
    eliberare(a,m);
    fclose(fout);
    return 0;
}
    
        
    
