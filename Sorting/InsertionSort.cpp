#include<bits/stdc++.h>
using namespace std;

#define print(a) for (auto x : a) cout << x << " "; cout << endl

void InsertionSort(vector<int> &arr){
  int n=arr.size();
  for(int i=1;i<n;i++){
    int j=i;
    while(j>0 && arr[j]<arr[j-1]){
      int temp=arr[j];
      arr[j]=arr[j-1];
      arr[j-1]=temp;
      j--;
    }
  }
}

int main(){
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
    cin >> arr[i];
  InsertionSort(arr);
  print(arr);
  return 0;
}