#include<bits/stdc++.h>
using namespace std;

#define print(a) for (auto x : a) cout << x << " "; cout << endl

void Merge(vector<int> &arr,int low,int mid,int high){
  int left=low;
  int right=mid+1;
  vector<int> temp;
  while(left<=mid && right<=high){
    if(arr[left]<arr[right]){
      temp.emplace_back(arr[left]);
      left++;
    }
    else{
      temp.emplace_back(arr[right]);
      right++;
    }
  }
  while(left<=mid){
    temp.emplace_back(arr[left]);
    left++;
  }
  while(right<=high){
    temp.emplace_back(arr[right]);
    right++;
  }
  for(int i=low;i<=high;i++)
      arr[i]=temp[i-low]; // Indexing of temp starts from 0 unlike arr
}

void MergeSort(vector<int> &arr,int low,int high){
  if(low>=high)
    return;
  int mid=low+(high-low)/2;
  MergeSort(arr,low,mid);
  MergeSort(arr,mid+1,high);
  Merge(arr,low,mid,high);
}

int main(){
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
    cin >> arr[i];
  MergeSort(arr,0,arr.size()-1);
  print(arr);
  return 0;
}