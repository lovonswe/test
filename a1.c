

#include<stdio.h>
#include<math.h>

int check(int N,int pos)
{
    return (int)(N & (1<<pos));
}
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}


int status[1000000/32];
void sieve()
{
     int i, j, sqrtN;
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
	 puts("2");
	 for(i=3;i<=N;i+=2)
		 if( check(status[i/32],i%32)==0)
	 	 printf("%d\n",i);

}


int main()
{
    int t,n;
    scanf("%d",&t)
    while(t--)
    {
        scanf("%d",&n);

    }

}
