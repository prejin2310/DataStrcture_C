#include<stdio.h>
void sort(int arr[],int size){  
    int i,j,temp;
    for(i=0;i<size;i++){
        for(j=i;j<size;j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] =  temp;
            }
        }
    }
}
void main(){
    int a[10],b[10],c[10];
    clrscr();
    int n,i,k=0,j=0;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
	printf("Enter the element of array A at index %d:",i);
	scanf("%d",&a[i]);
    }
    sort(a,n);
    for(i=0;i<n;i++){
	printf("Enter the element of array B at index %d:",i);
	scanf("%d",&b[i]);
    }
    sort(b,n);
    for(i=0;i<(n+n);i++){
	if(a[k]<b[j]){
	    c[i] = a[k];
	    k++;
	}
	else{
	    c[i] = b[j];
	    j++;
	}
    }
    printf("Merged Array :\n");
    for(i=0;i<(n+n);i++){
	printf(" %d ",c[i]);
    }
    getch();
}
