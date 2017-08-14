#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<limits.h>

int a[100];
int n;

int main()
{

    printf("how many ");
    scanf("%d",&n);
    random(n);
    quick_sort(1,n);
    print();
    return 0;
}

random(int n)
{
    int i;
    for(i=1;i<=n;i++){
        a[i] = rand()%100+2;
        printf("%d  ",a[i]);
    }
    a[0]=INT_MIN;
}

quick_sort(int f,int l)
{
    int i,j,temp;

    if(f<l){
        i=f+1;
        j=l;

    while(a[i]<a[f]){
        i=i+1;
    }
    while(a[j]>a[f]){
        j=j-1;
    }

    while(i<j){
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;

    while(a[i]<=a[f]){
        i=i+1;
    }
    while(a[j]>a[f]){
        j=j-1;
    }
    }
   temp = a[f];
   a[f] = a[j];
   a[j] = temp;

   quick_sort(f,j-1);
   quick_sort(j+1,l);
}

}

print()
{
    int i;
    for(i=1;i<=n;i++){
        printf(" %d",a[i]);
    }
}
