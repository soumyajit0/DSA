#include<iostream>
using namespace std;
int getMax( int arr[], int n);
void radixSort( int arr[],int n);
void countSort(int arr[], int n, int pos);
int main(){
    int arr[]={432,8,530,90,88,231,11,45,677,199};
    int n=sizeof(arr)/sizeof(int);
    radixSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int getMax( int arr[], int n){
    int k=arr[0];
    for(int i=0;i<n;i++){
        k=max(k,arr[i]);
    }
    return k;
        }
void radixSort( int arr[],int n){
    int max=getMax(arr,n);
    for(int pos=1;max/pos>0;pos*=10){
        countSort(arr,n,pos);
    }
}
void countSort(int arr[], int n, int pos){
    int count[10]={0};
    int max=getMax(arr,n);
    for(int i=0;i<n;i++){
        count[(arr[i]/pos)%10]++;
    }
    for(int i=1;i<n;i++){
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[--count[(arr[i]/pos)%10]]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}
    
