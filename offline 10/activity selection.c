#include<stdio.h>

void Activities(int s_time[], int f_time[], int n)
{
int i, j;
printf ("Selected Activities are:");
i = 1;
printf("A%d ", i);
for (j = 2; j < n; j++)
    { if (s_time[j] >= f_time[i]) {
printf ("A%d ", j+1);
 i = j;
}
}
}

int main() {


int i,j,n;
int s_time[20], f_time[20];
printf("enter the no of length : ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
    scanf("%d",&s_time[i]);
}
 for(j=0;j<n;j++)
        scanf("%d",&f_time[j]);


Activities(s_time, f_time, n);
return 0;
}
