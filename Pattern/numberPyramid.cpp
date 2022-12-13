//Pattern
//        1
//      2 1 2
//    3 2 1 2 3
//  4 3 2 1 2 3 4
//5 4 3 2 1 2 3 4 5
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=n-1;j>=i;j--){
            cout<<"  ";
        }
        for(int k=i;k>=1;k--){
            cout<<k<<" ";
        }
        for(int r=2;r<=i;r++){
            cout<<r<<" ";
        }
        cout<<endl;
    }
    return 1;
}
