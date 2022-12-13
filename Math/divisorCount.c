#include<stdio.h>

int main()
{
    int n,it;
    printf("Enter the no. whose divisor you want to print : ");
    scanf("%d",&n);
    for(it=1;it*it<=n;it++)
    {
        if (n%it==0)
        {
            printf("%d ",it);
            if (it!=n/it)
            {
                printf("%d ",n/it);
            }
        }
    }
    printf("\n");

    return 0;
}