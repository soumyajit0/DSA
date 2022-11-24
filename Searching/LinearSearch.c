#include<stdio.h>
#include<stdbool.h>

bool linearSearch(int arr[], int arraySize, int searchElement)
{
    int it;
    for(it=0;it<arraySize;it++)
    {
        if (arr[it]==searchElement)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int arraySize,it;
    printf("Enter the size of the array : ");
    scanf("%d",&arraySize);
    int arr[arraySize];
    for(it=0;it<arraySize;it++)
    {
        printf("Enter the %d element of the array : ",it+1);
        scanf("%d",&arr[it]);
    }
    printf("\n");

    int searchElement;
    printf("Enter the element you want to search for : ");
    scanf("%d",&searchElement);

    if (linearSearch(arr, arraySize, searchElement))
    {
        printf("The element is present in the array\n");
    }
    else{
        printf("The element is absent in the array\n");
    }

    return 0;
}