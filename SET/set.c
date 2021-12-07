#define MAX 30
#include<stdio.h>
#include<stdlib.h>
void create(int set[]);
void print(int set[]);
void Union(int set1[],int set2[],int set3[]);
void intersection(int set1[],int set2[],int set3[]);
void difference(int set1[],int set2[],int set3[]);
void symmdiff(int set1[],int set2[],int set3[]);
int member(int set[],int x);
void main()
{ 
    int set1[MAX],set2[MAX],set3[MAX];
    int x,op;
    set1[0]=set2[0]=set3[0]=0;
    do{
        printf("\n1)Create 2)Print 3)Union 4)Intersection 5)Difference 6)Symmetric Difference 7)Quit");
        printf("\nEnter Your Choice:");
        scanf("%d",&op);
        switch(op){
            case 1: 
                printf("---Creating First Set---");
                create(set1);
                printf("---Creating Second Set---");
                create(set2);
                break;
            case 2: 
                printf("First Set : ");
                print(set1);
                printf("Second Set : ");
                print(set2);
                break;
            case 3: 
                Union(set1,set2,set3);
                print(set3);
                break;
            case 4: 
                intersection(set1,set2,set3);
                print(set3);
                break;
            case 5: 
                difference(set1,set2,set3);
                print(set3);
                break;
            case 6: 
                symmdiff(set1,set2,set3);
                print(set3);
                break;}
            printf("\nPRESS ANY KEY");
        }while(op!=7);}
void create(int set[])
{ 
    int n,i,x;
    set[0]=0;
    printf("\n No. of elements in the set:");
    scanf("%d",&n);
    printf("enter set elements :");
    for(i=1;i<=n;i++)
        scanf("%d",&set[i]);
        set[0]=n; }
void print(int set[])
{ 
    int i,n;
    n=set[0];
    printf("\n Members of the set :-->");
    for(i=1;i<=n;i++)
        printf("%d ",set[i]);
}

void Union(int set1[],int set2[],int set3[])
{ 
    int i,n;
    set3[0]=0;
    n=set1[0];
    for(i=0;i<=n;i++)
        set3[i]=set1[i];
        n=set2[0];
    for(i=1;i<=n;i++)
        if(!member(set3,set2[i]))
        set3[++set3[0]]=set2[i]; 
}

int member(int set[],int x)
{ int i,n;
n=set[0]; 
for(i=1;i<=n;i++)
if(x==set[i])
return(1);
return(0);
}
void intersection(int set1[],int set2[],int set3[])
{
int i,n;
set3[0]=0; 
n=set1[0];
for(i=1;i<=n;i++)
if(member(set2,set1[i])) 
set3[++set3[0]]=set1[i]; 
}

void difference(int set1[],int set2[],int set3[])
{ int i,n;
n=set1[0];
set3[0]=0;
for(i=1;i<=n;i++)
if(!member(set2,set1[i]))
set3[++set3[0]]=set1[i]; 
}
void symmdiff(int set1[],int set2[],int set3[])
{ int i,n;
n=set1[0];
set3[0]=0;

for(i=1;i<=n;i++)
if(!member(set2,set1[i]))
set3[++set3[0]]=set1[i]; 
n=set2[0];
for(i=1;i<=n;i++)
if(!member(set1,set2[i]))
set3[++set3[0]]=set2[i]; 
}