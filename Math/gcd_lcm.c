#include<stdio.h>

//Euclidean Algorithm

int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}

int lcm(int a,int b,int hcf)
{
    return a*b/hcf;
}

int main()
{
    int a,b;
    printf("Enter the first no. : ");
    scanf("%d",&a);
    printf("Enter the second no. : ");
    scanf("%d",&b);

    int hcf=gcd(a,b);
    printf("The GCD is : %d\n",hcf);
    printf("The LCM is : %d\n",lcm(a,b,hcf));

    return 0;
}
