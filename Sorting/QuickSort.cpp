#include<bits/stdc++.h>
using namespace std;

#define print(a) for (auto x : a) cout << x << " "; cout << endl

int partition (vector<int> &arr, int low, int high){
  int i=low,j=high;
  int pivot=arr[low];
  while(i<j){
    while(i<=high && arr[i]<=pivot){
      i++;
    }
    while(j>=low && arr[j]>pivot){
      j--;
    }
    if(i<j){
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[low],arr[j]);
  return j;
}

void QuickSort(vector<int> &arr, int low, int high){
  if(low>=high)
    return;
  int index=partition(arr,low,high);
  QuickSort(arr,low,index-1);
  QuickSort(arr,index+1,high);
}

int main(){
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
    cin >> arr[i];
  QuickSort(arr,0,n-1);
  print(arr);
  return 0;
}