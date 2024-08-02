#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> profit,vector<int> weight,int W,int n){
  if(W==0 || n==0)
    return 0;
  if(weight[n-1]<=W)
    return max(profit[n-1]+knapsack(profit,weight,W-weight[n-1],n-1),knapsack(profit,weight,W,n-1));
  else if(weight[n-1]>W)
    return knapsack(profit,weight,W,n-1);
}

int main(){
  vector<int> profit={60,100,100,140,210};
  vector<int> weight={10,20,30,40,50};
  int W=50;
  int n=weight.size();
  cout << knapsack(profit,weight,W,n) << endl;
  return 0;
}