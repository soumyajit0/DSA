#include<stdio.h>

void heapify(int arr[], int arraySize)
{
    int it;
    for(it=arraySize/2;it>=1;it--)
    {
        int child1=it*2;
        int child2=it*2+1;
        if (arr[child1]>=arr[child2])
        {
            if(arr[child1]>arr[it])
            {
                int temp=arr[it];
                arr[it]=arr[child1];
                arr[child1]=temp;
            }
        }
        else{
                if(arr[child2]>arr[it])
                {
                    int temp=arr[it];
                    arr[it]=arr[child2];
                    arr[child2]=temp;
                }
        }
    }
    printf("The Heap is : \n");
    for(it=1;it<=arraySize;it++)
    {
        printf("%d ",arr[it]);
    }
    printf("\n");
}

int main()
{
    int arraySize,it;
    printf("Enter the size of the array : ");
    scanf("%d",&arraySize);
    int arr[arraySize+1];
    arr[0]=-99999;
    for(it=1;it<=arraySize;it++)
    {
        printf("Enter the %d element of the array : ",it+2);
        scanf("%d",&arr[it]);
    }

    heapify(arr, arraySize);

    return 0;
}