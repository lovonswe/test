#include<stdio.h>
#include<math.h>

int gcd(int a, int b);
int commDiv(int a,int b);

int main()
{
    int a, b, t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a, &b);

        printf("%d\n",commDiv(a,b));
    }
    return 0;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int commDiv(int a,int b)
{
    int n = gcd(a, b);

    int result = 0;
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i==0)
        {

            if (n/i == i)
                result += 1;
            else
                result += 2;
        }
    }
    return result;
}
