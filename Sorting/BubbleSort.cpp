#include<bits/stdc++.h>
using namespace std;

#define print(a) for (auto x : a) cout << x << " "; cout << endl

void BubbleSort(vector<int> &arr){
  int n=arr.size();
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
      if(arr[j]>arr[j+1])
        swap(arr[j],arr[j+1]);
    }
  }
}

int main(){
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
    cin >> arr[i];
  BubbleSort(arr);
  print(arr);
  return 0;
}