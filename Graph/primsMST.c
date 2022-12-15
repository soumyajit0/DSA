//  0 _(2)_ 1 _(3)_ 2
//  |     / |      /
// (6)  (8)(5)  (7)
//  | /     | /
//  3       4

#include<stdio.h>

void prims(int graph[][5],int key[],int visited[],int parent[],int vertices)
{
    int it,itr;
    key[0]=0;
    for(it=0;it<vertices;it++)
    {
        int min=999;
        for(itr=0;itr<vertices;itr++)
        {
            if(key[itr]<=min && visited[itr]==0)
            {
                min=itr;
            }
        }
        visited[min]=1;
        for(itr=0;itr<vertices;itr++)
        {
            if(graph[min][itr]<=key[itr] && graph[min][itr]!=0)
            {
                key[itr]=graph[min][itr];
                parent[itr]=min;
            }
        }
    }

    printf("The Minimum Spanning Tree : \n");
    for(it=1;it<vertices;it++){
        printf("%d  %d -> %d\n",parent[it],it,key[it]);
    }

}

int main()
{
    int vertices=5;
    int graph[][5]={
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,0}
    };
    int visited[]={0,0,0,0,0};
    int key[]={999,999,999,999,999};
    int parent[]={-1,-1,-1,-1,-1};

    prims(graph,key,visited,parent,vertices);

    return 0;
}