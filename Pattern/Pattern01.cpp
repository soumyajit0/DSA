/*Pattern01
*****
*****
*****
*****
*****
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n=5;
// n stores the number of rows in the pattern

    for (int i=1;i<=n;i++)  // i denotes the row no. of the pattern
    {
        for(int j=1;j<=n;j++) // j denotes the column no. of the pattern
        {
            cout<<"* ";
        }
      cout<<"\n";
    }
 return 0;
}