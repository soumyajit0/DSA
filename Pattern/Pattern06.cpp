/*Pattern05
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n=5;
// n stores the number of rows in the pattern

    for (int i=1;i<=n;i++) // i denotes the row no. of the pattern
    {
        for (int j=1;j<=(n-(i-1));j++) // j denotes the column no. of the pattern
        {
         cout<<j<< " ";
        }
        cout<<"\n";
     }
return 0;
}
