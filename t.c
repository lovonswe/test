#include<stdio.h>                 // time limit exit

int gcd(int a, int b);

int main()
{
    int t,q,i;
    unsigned int x,n,Gcd,counter,j;
    scanf("%d",&t);
    for(i = 1; i<=t; i++)
    {
        printf("Case %d\n",i);

        scanf("%u %d",&n, &q);
        while(q--)
        {
            scanf("%u",&x);

            counter=0;
            for(j=1; j<=n; j++)
            {
                Gcd = gcd(j, n);
                if(Gcd<=x)
                    counter++;
            }
            printf("%d\n",counter);
        }
    }
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
