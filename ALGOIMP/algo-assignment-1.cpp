#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#define size 20000



int comparsion=0, movement=0;
clock_t start,ending ;



void bubblesort(int a[],int n){
    start = clock();
    comparsion=0;
    movement=0;

    int k,t,j,temp;
    k=n;
    while(k!=0){
        t=0;
        for(j=1;j<=k-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                movement++ ;
                t=j;
            }
            comparsion++;
        }
      k=t;
    }
    ending =clock();

}

void insertionsort(int a[],int n){

    start = clock();
    comparsion=0;
    movement=0;
   int j,i,t;
   for(j=2;j<=n;j++){
       i=j-1;
       t=a[j];
       while(t<a[i]){
            comparsion++ ;
            a[i+1]=a[i];
            i=i-1;
            movement++ ;
       }
        comparsion++ ;
        a[i+1]=t;
        movement++ ;
   }
    ending = clock();
}

void selectionsort(int a[],int n){
    start = clock();
    comparsion=0;
    movement=0;
    int j,k,temp,t;
    for (j=n;j>=2;j--){
        t=1;
        for(k=2;k<=j;k++){
            comparsion++ ;
                if(a[t]<a[k]){
                    t=k;
                }
        }

        temp=a[j];
        a[j]=a[t];
        a[t]=temp;
        movement++;
    }
    ending = clock();
}

int main(){


    int x[size],y[size],z[size];
    float time=0;
    int i;
    for(i=1;i<=size; i++)
    {
        x[i]=rand();
        y[i]=x[i];
        z[i]=x[i];
    }
    y[0]= INT_MIN;
    bubblesort(x,size);

    time = (float)(ending-start)/CLOCKS_PER_SEC;

    printf("bubblesort: %f comarision %d movement %d \n",time,comparsion,movement);

    insertionsort(y,size);

    time = (float)(ending-start)/CLOCKS_PER_SEC;
    printf("insertionsort: %f comarision %d movement %d \n",time,comparsion,movement);

    selectionsort(z,size);
    time = (float)(ending-start)/CLOCKS_PER_SEC;

    printf("selectionsort: %f comarision %d movement %d \n",time,comparsion,movement);

    return 0;

}


