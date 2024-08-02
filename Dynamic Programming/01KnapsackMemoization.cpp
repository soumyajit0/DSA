#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> profit,vector<int> weight,int W,int n,vector<vector<int>> &dp){
  if(dp[W][n]!=-1)
    return dp[W][n];
  if(W==0 || n==0)
    return dp[W][n]=0;
  if(weight[n-1]<=W)
    return dp[W][n]=max(profit[n-1]+knapsack(profit,weight,W-weight[n-1],n-1,dp),knapsack(profit,weight,W,n-1,dp));
  else if(weight[n-1]>W)
    return dp[W][n]=knapsack(profit,weight,W,n-1,dp);
}

int main(){
  vector<int> profit={60,100,100,140,210};
  vector<int> weight={10,20,30,40,50};
  int W=50;
  int n=weight.size();
  vector<vector<int>> dp(W+1,vector<int>(n+1,-1));
  cout << knapsack(profit,weight,W,n,dp) << endl;
  return 0;
}