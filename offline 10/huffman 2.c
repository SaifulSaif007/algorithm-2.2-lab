#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

void main()
{
  int i,j,k,num,temp_o,run,remaining,order_low,order_up,order[10][10],code[10][10];
  float sum,prob[10],temp_p;


  // initialise order matrix
  for(i=0;i<10;i++)
  {
	 order[i][0]=i+1;
	 for(j=1;j<10;j++)
	   order[i][j]=-1;
  }

  //initialising code array
  for(i=0;i<10;i++)
	for(j=0;j<10;j++)
	  code[i][j]=-1;

  //inputting data
  printf("how many messages do you have: ");
  scanf("%d",&num);
  printf("Enter the probabilities of the messages:\n");
  sum=0;
  for(i=0;i<num;i++)
  {
	printf("Probability of message %d: ",i+1);
	scanf("%f",&prob[i]);
	sum=sum+prob[i];
  }
  //check for invalid data
  if(sum!=1.0)
  {
	printf("------------invalid data-------------");
	getch();
	exit(0);
  }

  //arrange in descending order
  for(i=0;i<num;i++)
	for(j=0;j<num-i;j++)
	  if(prob[j]<prob[j+1])
	 {
		temp_p=prob[j];
		prob[j]=prob[j+1];
		prob[j+1]=temp_p;
		temp_o=order[j][0];
		order[j][0]=order[j+1][0];
		order[j+1][0]=temp_o;
	  }

  // display messages in descending order of probabilities
  printf(" \nthe various messages can be arranged as:\n");
  for(i=0;i<num;i++)
	printf("\nmessage %d\tprobability: %f",order[i][0],prob[i]);

  //coding
  run=0;
  remaining=num-1;
  while(remaining)
  {
	run++;
	sum=prob[remaining]+prob[remaining-1];
	for(i=0;i<remaining+1;i++)
	  if(prob[i]<sum)
	  {
		order_low=order[remaining][0];
		order_up=order[remaining-1][0];
		for(j=remaining-2;j>=i;j--)
		{
		  prob[j+1]=prob[j];
		  for(k=9;k>=0;k--)
		  if(order[j][k]!=-1)
			order[j+1][k]=order[j][k];
		}
		prob[i]=sum;
		for(k=0;k<10;k++)
		if(order[i][k]==-1)
		{
		   order[i][k]=order_low;
		   order[i][k+1]=order_up;
		}
		break;
	  }
  //display current set of probabilities
	printf("\nafter run %d",run);
	for(j=0;j<remaining;j++)
	  printf("\n%f",prob[j]);
	getch();
	code[order[i][k]-1][run-1]=0;
	code[order[i][k+1]-1][run-1]=1;
	remaining--;
  }

  //printing the codes
  printf("\nFinal codes: \n");
  for(i=0;i<num;i++)
  {
	printf("\nmessage %d: ",i+1);
	for(j=9;j>=0;j--)
	{
	   if(code[i][j]!=-1)
	   printf("%d",code[i][j]);
	}
  }
  getch();
}


