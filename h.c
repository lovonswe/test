
#include<stdio.h>                        //accepted

int divisor[1000000+10] , factful[11][1000000+10] ; //number of n_factorful [a,b] =factful

void sieve()
{
    for(int i=2;i<=1000000;i++)
    {
        if(divisor[i]==0)
        {
            for(int j=i;j<=1000000;j+=i) divisor[j]++;
        }
    }

    for(int n=0;n<=10;n++)
    {
        for(int i=1;i<=1000000;i++)
        {
            if(divisor[i] == n )
            {
                factful[n][i] = factful[n][i-1] + 1;
            }
            else
                factful[n][i] = factful[n][i-1];
        }
    }
}

int main()
{
    sieve();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int a, b, n;
        scanf("%d %d %d", &a, &b, &n);
        printf("%d\n",factful[n][b]-factful[n][a-1]);
    }
}
