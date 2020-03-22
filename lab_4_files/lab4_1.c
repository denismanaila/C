#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int cmp(const void *n1, const void *n2){
    const int *numar1=(const int*)n1;
    const int *numar2=(const int*)n2;
    if(*numar1<*numar2)
        return -1;
    if(*numar1>*numar2)
        return 1;
    return 0;
}

int cmp1(int n1 , int n2)
{
    if(n1<n2)
        return -1;
    if(n1>n2)
        return 1;
    return 0;
}
int main(int argc, char *argv[])
{
    FILE *fout;
    int i,v[100],x,k=0;
    if(argc==2){
        printf("e ok");
    }
    else
    {
        printf("numar incorect de argumente");
        return errno;
    }
    
    fout=fopen(argv[1],"w");
    if(fout==NULL){
        printf("eroare");
        exit(EXIT_FAILURE);
    }
    printf("Introduceti numere. La numarul 0 programul se va opri.\n");
    scanf("%d",&x);
    if(x==0)
    {
        return 0;
    }
    v[k]=x;
    k++;
    while(x)
    {
        scanf("%d",&x);
        if(x==0)
            break;
        else
        {
            v[k]=x;
            k++;
        }
    }
    qsort(v,k,sizeof(int),cmp);
    for(i=0;i<k;i++)
    {
        fprintf(fout,"%d ",v[i]);
    }
    fclose(fout);
    return 0;
}
