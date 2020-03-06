
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

int N =99999999,counter=1;
int status[3125000];
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
         {
             counter++;
             if(counter%100 == 1)
                printf("%d\n",i);
         }


}


int main()
{
    sieve();
}

