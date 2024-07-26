#include<bits/stdc++.h>
using namespace std;

#define print(a) for (auto x : a) cout << x << " "; cout << endl

void QuickSort(vector<int> &arr){
  
}

int main(){
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
    cin >> arr[i];
  QuickSort(arr);
  print(arr);
  return 0;
}