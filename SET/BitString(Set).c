#include<stdio.h>
void input();
void output();
void setunion();
void intersection();
void difference();
int a[]={0,0,0,0,0,0,0,0,0};
int b[]={0,0,0,0,0,0,0,0,0};
int c[]={0,0,0,0,0,0,0,0,0};
int main()
{
  int ch,wish;
  clrscr();
  do{
    printf("\n1. Input \n2.Union \n3.Intersection \n4.Difference \n5.Exit");
    printf("\n Enter the choice :");
    scanf("%d",&ch);
    switch(ch){
      case 1:
	   input();
	   break;
      case 2:
	   setunion();
	   break;
      case 3:
	   intersection();
	   break;
      case 4:
	   difference();
	   break;
      case 5:
	   exit(0);
	   break;
      }
  }while(ch!=5);
  }
void input(){
  int n,x,i;
  printf("Enter size of the 1st set \n");
  scanf("%d",&n);
  printf("\n Enter elements: \t");
  for(i=1;i<=n;i++)
  {
   scanf("%d",&x);
   a[x]=1;
  }
  printf("\n Enter the size of the 2nd Set : \n");
  scanf("%d",&n);
  printf("\n Enter Elements: \t");
  for(i=1;i<=n;i++)
  {
   scanf("%d",&x);
   b[x]=1;
  }
  printf("\n 1st Set : \t");
  for(i=1;i<=9;i++)
  {
   printf("%d",a[i]);
  }
  printf("\n 2nd Set : \t");
  for(i=1;i<=9;i++)
  {
   printf("%d",b[i]);
  }
}
void output(){
  int i;
  printf("\n Set is : \t");
  for(i=1;i<=0;i++)
  {
  if(c[i]!=0)
  printf("%d \t",i);
  }
}
void setunion(){
  int i,c[10];
  for(i=1;i<=9;i++)
  {
   if(a[i]!=b[i])
    c[i]=1;
   else
    c[i]=a[i];
  }
  for(i=1;i<=9;i++)
  {
   printf("%d ",c[i]);
  }
 output(c);
}
void intersection(){
  int i,c[10];
  for(i=1;i<=9;i++)
  {
   if(a[i]==b[i])
    c[i]=a[i];
   else
    c[i]=0;
  }
  for(i=1;i<=9;i++)
  {
  printf("%d ",c[i]);
  }
output(c);
}
void difference()
{
 int i,c[10];
 for(i=1;i<=9;i++)
 {
  if(a[i]==1&&b[i]==0)
  c[i]=1;
  else
  c[i]=0;
 }
 for(i=1;i<=9;i++)
 {
  printf("%d ",c[i]);
 }
output(c);
 }
