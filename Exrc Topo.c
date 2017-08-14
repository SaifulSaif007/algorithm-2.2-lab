 #include<stdio.h>

 int n,top=-1,s,k=0;
 int a[20][20], ind[20], stack[20], list[20];

 void topsort(int n,int a[20][20])
 {
     int i,j;
     for(i=1;i<=n;i++){
        s=0;
     for(j=1;j<=n;j++){
        s=s+a[j][i];
     }
     ind[i] = s;
     }

     for(i=1;i<=n;i++){
        if(ind[i]==0)
            stack[++top] = i;
     }

     while(top!=-1){
        i= stack[top--];
        list[k++] = i;
        for(j=1;j<=n;j++){
            if(a[i][j]==1){
                ind[j]--;
                if(ind[j]==0)
                    stack[++top] = j;

            }
        }



     }



 }




 void input()
 {
     int i,j,v1,v2,e;
     printf("numbr of vertex:\n");
     scanf("%d",&n);
     printf("nubr of edge..\n");
     scanf("%d",&e);

     printf("V1 & V2");
     for(i=1;i<=e;i++){
     scanf("%d %d",&v1,&v2);
     a[v1][v2] = 1;
     }
 }

 int main()
 {
     int i,j,k,flag=1;
     input();
     topsort(n,a);
     for(i=0;i<n;i++){
        if(list[i]==0)
            flag=0;
     }
     if(flag==1){
        printf("topo:\n");
        for(i=0;i<n;i++)
            printf("%d  ",list[i]);
     }
     else
        printf("not possible");

     return 0;

 }
