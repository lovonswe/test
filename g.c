#include<stdio.h>
#include<math.h>

int check(int N,int pos);
int Set(int N,int pos);
int segmented_sieve(int l, int h);
int sieve(int l, int h);

int prime[500],r_prime[500],array[1000]; // Range_prime == r_prime;

int main()
{
    int t,n,l,h,cntr;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        h = n;
        l=(h/2)+1;
         cntr = segmented_sieve(l,h);
         printf("%d\n",cntr);
    }
}

int check(int N,int pos)
{
    return (int)(N & (1<<pos));
}

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}

int sieve(int l, int h)
{
    int k=0,i,j;
    int sqrt_h = sqrt(h);

    int s_sqrt_h = sqrt(sqrt_h);

    if(s_sqrt_h >= 2)
        prime[k++]=2;

    for(i=3; i<=s_sqrt_h; i+=2)
    {

        if(array[i]==0)  //then i is a prime.
        {
            for(j = i*i; j<=sqrt_h; j+=i*2 )
            {
                array[j]=1;  //j is not a prime.
            }
        }
    }
    for(int i=3; i<=sqrt_h; i+=2)
    {
        if(array[i]==0)
            prime[k++] = i;
    }

    return k;
}


int segmented_sieve(int l, int h)
{
    int k,j,m,in_value,sqr;
    k=sieve(l, h);

    l=(l/2)*2;

    for(int i=1; i<k; i++)
    {
        sqr = prime[i]*prime[i];
        if(sqr>=l)
        {
            for(j = prime[i]*prime[i]; j<=h; j+=prime[i]*2)
            {
                r_prime[(j-l)/32] = Set(r_prime[(j-l)/32],(j-l) % 32);
            }
        }
        else
        {
            j = (l-sqr)/(prime[i]*2);
            j = (j*prime[i]*2)+sqr;
            if(j<l)
                j=j+prime[i]*2;
            for(j = j; j<=h; j+=prime[i]*2)
            {
                 r_prime[(j-l)/32] = Set(r_prime[(j-l)/32],(j-l) % 32);
            }

        }
    }
int cntr=0;
    if(l==2)
    {
        cntr=1;
        for(int i = 1; i<=h-l; i+=2)
        {
            if(check(r_prime[i/32], i%32)==0)
                cntr++;
        }
    }
    else{
        for(int i = 1; i<=h-l; i+=2)
        {
            if(r_prime[i]==0)
               cntr++;
        }
    }
    return cntr;
}
