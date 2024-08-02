#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> profit,vector<int> weight,int W,int n,vector<vector<int>> &dp){
  for(int i=1;i<=W;i++){
    for(int j=1;j<=n;j++){
      if(weight[j-1]<=i)
        dp[i][j]=max(profit[j-1]+dp[W-weight[j-1]][j-1],dp[i][j-1]);
      else if(weight[j-1]>W)
        dp[i][j]=dp[i][j-1];
    }
  }
  return dp[W][n];
}

int main(){
  vector<int> profit={60,100,100,140,210};
  vector<int> weight={10,20,30,40,50};
  int W=50;
  int n=weight.size();
  vector<vector<int>> dp(W+1,vector<int>(n+1));
  for(int i=0;i<=W;i++){
    for(int j=0;j<=n;j++){
      if(i==0 && j==0)
        dp[i][j]=0;
    }
  }
  cout << knapsack(profit,weight,W,n,dp) << endl;
  return 0;
}