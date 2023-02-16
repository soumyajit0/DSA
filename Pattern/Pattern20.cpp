/*Pattern20
*        *
**      **
***    ***
****  ****
**********
****  **** 
***    ***
**      **
*        *
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=5;
    // n stores the number of rows in the pattern
for (int i=1;i<=n;i++) // i denotes the row no. of the pattern
    {
        //STARS
        for(int j=1;j<=i;j++)
        {
            cout<< "*";
        }
        //SPACE
        for (int j=1;j<=(2*n-2*i);j++){
        cout << " ";
        }
        //STARS
        for(int j=1;j<=i;j++)
        {
            cout<< "*";
        }
        cout<<"\n";
    }
for (int i=1;i<=n;i++)
{
    //STARS
    for (int j=1;j<=n-i;j++){
    cout<<"*";
    }
    //SPACE
    for (int j=1;j<=2*i;j++){
    cout<<" ";
    }
    //STARS
     for (int j=1;j<=n-i;j++){
    cout<<"*";
    }
    cout<<"\n";
}
return 0;
}
