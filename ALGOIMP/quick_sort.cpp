#include <bits/stdc++.h>
int a[200];

clock_t start,ending;
void quicksort(int f,int l){
    start = clock();
    int i,j,temp,t;
    if(f<l){
        i=f+1;
        while(a[i]<a[f]){
            i=i+1;
        }
        j=l;
        while(a[j]>a[f]){
            j=j-1;
        }
        while(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            while(a[i]<a[f]){
                i=i++;
            }
            while(a[j]>a[f]){
                j=j--;
            }
        }
            t=a[f];
            a[f]=a[j];
            a[j]=t;
            quicksort(f,j-1);
            quicksort(j+1,l);
        }
        ending =clock();
    }
    int main(){
        int i;
        int lastIndex;
        scanf("%d",&lastIndex);
        for(i=1;i<=lastIndex;i++){
            a[i]=rand()%50;
            printf("%d ", a[i]);
        }
        printf("\n");
        quicksort(1,lastIndex);

    for(i=1;i<=lastIndex;i++) printf("%d ", a[i]);
    printf("\n");
    float time=0;

    time=(float)(ending-start)/CLOCKS_PER_SEC ;
    printf("%f",time);

    }

