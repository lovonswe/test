#incldue<stdio.h>
#include<math.h>


int N=1000000;
int status[1000001];
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
}

int I;
void factorization(int N)
{
     I=0;
     sieve();
    while(N!=1)
    {
        spf[I++]=status[N];
        N=N/status[N];
    }
}




int main()
{
    int t,n;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
    }
}
