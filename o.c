#include<stdio.h>          //not comlete
#include<math.h>

int check(int N,int pos)
{
    return (int)(N & (1<<pos));
}
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}


int status[100/32], sqrtN,prime[125];
void sieve(int N)   {
     int i, j;
     sqrtN = (int)( sqrt( N ) );
     for( i = 3; i <= sqrtN; i += 2 )
     {
		 if( check(status[i/32],i%32)==0)
		 {
	 		 for( j = i*i; j <= N; j += 2*i )
			 {
				 status[j/32]=Set(status[j/32],j % 32)   ;
	 		 }
		 }
	 }
	 int k=2;
	 prime[k++]=2;
	 for(i=3; i<=215; i+=2)
		 if( check(status[i/32],i%32)==0)
	 	prime[k++]=i;

}


int main()
{
    int N;
    sieve(N);
    if(N==2)
        printf("2 = 2\nWith 2 marbles, 1 different rectangles can be constructed.\n");
    else if( check(status[N/32],N%32)==0)
        printf("%d = %d\nWith %d24 marbles, %d different rectangles can be constructed.\n",N,N,N,counter);
    else if( sqrtN*sqrtN == N && check(status[sqrt/32],sqrtN%32)==0)
        printf("%d = %d * %d\nWith %d marbles, %d different rectangles can be constructed.\n",N,sqrtN,sqrtN,N,counter);
    else
    {

    }

}
