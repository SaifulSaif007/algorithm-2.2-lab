#include<conio.h>
#include<stdio.h>

int rearrange(int count1[]);
int z=0,m=0;

void main()
{
    char input[100];                 /* Up to 100 characters can be encoded*/
    int i, num,count,n=1, numchar,count1[100],a=0;

    printf("\n Enter the number of characters to be encoded: ");
    scanf("%d", &numchar);

    printf("\n The sentence to encode is: ");

    for(i=0; i<= numchar; ++i)
     {
        scanf("%c", &input[i]);      /* The sentence to be encoded is entered*/
      }                             /* using a for loop*/

    for(count=n; count<= numchar; ++count)
    {
        num=1;
        for(i=1; i<=numchar; ++i)
        {
            if(n!=i && input[n]==input[i])   /* the input[n] e.g input[0] is compared */
            {                                /* with all the other inputs i.e input[1], input[2],...*/
            ++num;                           /* if input[n]=input[i], the latter is replaced by '|'*/
            input[i]='|';
            }

        }

        if(input[n]==' ')
        {
        printf("\n' '=%d", num);
         count1[a]=num;
         ++a;
         ++z;
        }


        else if(input[n]!='|')           /* thus an output is obtained only if the latter is not*/
        {                                          /* '|' so that there is no repetition*/
          printf("\n %c =%d ", input[n],num);
         count1[a]=num;
         ++a;
         ++z;
        }
        ++n;
      }

     for(i=0;i<z;++i)                         /* count1[1]=frequency of input[o]*/
                                                             /* count1[2]=frequency of input[1] if input[0]!=input[1]...*/
     {
        printf("\n count[]=%d",count1[i]);
      }

        for(i=0;i<z;++i)
      {
        printf("\n rearrange %d", rearrange(count1));
        ++m;
     }
 }

int rearrange(int count1[])
{
        int minimum,p;

        minimum=count1[m];


        for(m; m<z; ++m)
        {

        if(minimum>count1[m])
        {
        p=minimum;
        minimum=count1[m];
        count1[m]=p;

        }
        }
        m=0;
    return(minimum);
}
