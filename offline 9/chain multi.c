#include<stdio.h>

int D[100];
int M[20][20];
int S[20][20];

int main()
{
    int size,i,j,value;

    printf("Enter the number of matrices: ");
    scanf("%d",&size);

    printf("Enter the dimensions of matrices ");
    for(i=0;i<=size;i++)
    {
        scanf("%d",&D[i]);
    }

    value = chain(1,size);
    printf("\nNumber of multiplication: %d\n",value);
    printf("\nThe Optimal order is:\n");
    print_order(1,size);

    printf("\n\n");

    for(i=1;i<=size;i++){
        for(j=1;j<=size;j++){
        printf("\t%d",S[i][j]);}
        printf("\n");}

        printf("\n\n");
         for(i=1;i<=size;i++){
        for(j=1;j<=size;j++){
        printf("\t%d",M[i][j]);}
        printf("\n");}
    return 0;

}


int chain(int i,int j)
{
  if(i==j)
    return 0;
  int k,count;
  int min=1000000;
  for (k=i;k<j;k++)
  {
    count = chain(i,k) + chain(k+1,j) + D[i-1]*D[k]*D[j];
    if(count<min)
    {
      min=count;
      M[i][j]=k;
      S[i][j] = min;

    }
  }
  return min;
}

void print_order(int i,int j)
{
  if(i==j)
   printf("M%d",i);
  else
 {
   printf("(");
   print_order(i,M[i][j]);
   print_order(M[i][j]+1,j);
   printf(")");
 }
}

