#include<stdio.h>
void bubble(int[],int);
int main()
{
    int a[200],b[200];
    int m,n,i,j;
    scanf("%d %d",&n,&m);


    for(i=0;i<m;i++){
        scanf("%d %d",&a[i],&b[i]);
    }

    bubble(a,m);
    bubble(b,m);

    for(j=0;j<m;j++){
        if(a[j]==b[j])
            {printf("no");
        return 0;
        }
    }
    if(b[m-1]>n){
        printf("no");
        return 0;
    }
    printf("yes");

return 0;
}

void bubble(int array[],int m)
{

    int i,j,temp;
    for(i=0;i<m;i++){
        for(j=i+1;j<m;j++){
            if(array[i]>array[j]){
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
  }
  return array;
}
