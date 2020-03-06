#include<stdio.h>             //time limit exit
#include<math.h>

int status[3125000];

int check(int N,int pos)
{
    return (int)(N & (1<<pos));
}
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}

int sieve(int N)
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
	 int counter = 1;
	 for(i=3;i<=N;i+=2)
		 if( check(status[i/32],i%32)==0)
	 	 counter++;
	 	 return counter;
}

int main()
{
    double x,ln,num_p,result;
    while(scanf("%lf",&x) && (x!=0))
    {
        ln = x/log(x);
        num_p = sieve(x);

        result =(num_p - ln)/num_p*100;
        if(result<0)
            result *= (-1);
        printf("%0.1lf\n",result);
    }
}
