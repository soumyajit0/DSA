#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i+j==n+1)
                cout<<"* ";
            else
                cout<<"  ";
            }
            int countrow=2;
            int countcolumn=1;
        for(int j=1;j<=n;j++){
            if(i==countrow&&j==countcolumn){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
            countrow++;
            countcolumn++;
        }
            cout<<endl;
        }
        int countrow=1;
        int countcolumn=2;
        for(int i=1;i<=n-1;i++){
            for(int j=1;j<=n;j++){
                if(i==countrow&&j==countcolumn){
                    cout<<"* ";
                }
                else{
                    cout<<"  ";
                }  
            }
            countrow++;
            countcolumn++;
            for(int j=1;j<=n-1;j++){
                if(i+j==n-1){
                    cout<<"* ";
                }
                else{
                    cout<<"  ";
                }
            }
            cout<<endl;    
            }
            
        }
