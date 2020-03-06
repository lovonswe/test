#include<stdio.h>            //Time limit exit
#include<math.h>

int sieve(int N);
int check(int N,int pos)
{
    return (int)(N & (1<<pos));
}
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}

int status[3125000];
int main()
{
    int t,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);

        if(k==1)
            printf("2\n");
        else
            printf("%d\n",sieve(k));
    }
}

int sieve(int N)
{

    int k;
    k=N;
    N = 18*N;

    int i, j, sqrtN,counter=1;
    sqrtN = (int)( sqrt( N ));
    for(i = 3; i <= sqrtN; i += 2)
    {
        if( check(status[i/32],i%32)==0)
        {
            for( j = i*i; j <= N; j += 2*i )
            {
                status[j/32]=Set(status[j/32],j % 32);
            }
        }
    }

    for(i=3; counter<=k; i+=2)
        {
            if(check(status[i/32],i%32)==0)
                counter++;
        }
    return i;
}
