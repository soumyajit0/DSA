#include<bits/stdc++.h>
using namespace std;

#define print(a) for (auto x : a) cout << x << " "; cout << endl

void SelectionSort(vector<int> &arr){
  int n=arr.size();
  int index=0;
  for(int index=0;index<n-1;index++){
    int minIndex=index;
    for(int i=index+1;i<n;i++){
      if (arr[i]<arr[minIndex])
        minIndex=i;
    }
    swap(arr[index],arr[minIndex]);
  }
}

int main(){
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
    cin >> arr[i];
  SelectionSort(arr);
  print(arr);
  return 0;
}