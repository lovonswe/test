#include<stdio.h>         //time limit exit
#include<math.h>

void sieve();
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
    int t,k,i,counter=1;
    scanf("%d",&t);
    sieve();
    while(t--)
    {
        scanf("%d",&k);

        counter=1;
        if(k==1)
            printf("2\n");
        else
        {
            for(i=3; counter<k; i+=2)
            {
                if(check(status[i/32],i%32)==0)
                        counter++;
            }
            printf("%d\n",i-2);
        }

    }
}

void sieve()
{
    int N = 86028159;

    int i, j, sqrtN;
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
}

