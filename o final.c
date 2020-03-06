
// run time error

#include<stdio.h>
#include<math.h>

int N=10000000;
int status[10000000];
int spf[24]; //smallest prime factor
void sieve()
{
     int i, j, sqrtN;
     sqrtN = sqrt( N );

     for(i=2; i<=N; i+=2)
     {
         status[i]=2;
     }
     for( i = 3; i <= sqrtN; i += 2 )
     {
		 if( status[i]==0)
		 {
		     status[i] = i;
	 		 for( j = i*i; j <= N; j += 2*i )
			 {
				 status[j]= i;
	 		 }
		 }
	 }
	 printf("%d\n",status[45]);
}

int I;
void factorization(int N)
{
     I=0;
    while(N!=1)
    {
        spf[I++]=status[N];
        N=N/status[N];
    }
}

int main()
{
    sieve();
    int N;
    while(scanf("%d",&N)==1 && N!=0)
    {
        factorization(N);
        printf("%d = %d",N,spf[0]);
        for(int i=1; i<I; i++)
        {
            printf(" * %d",spf[i]);
        }
        printf("\nWith %d marbles, %d different rectangles can be constructed.\n",N,I);
    }

return 0;
}
