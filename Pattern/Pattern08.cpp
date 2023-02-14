/*Pattern08
 *********
  *******
   *****
    ***
     *
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n=5;
// n stores the number of rows in the pattern

    for (int i=1;i<=n;i++) // i denotes the row no. of the pattern
    {
        //SPACE
        for (int j=1;j<=(i-1);j++) // j denotes the column no. of the pattern
        {
         cout<<" ";
        }
        //STARS
        for (int j=1;j<=(2*n-2*i+1);j++){
        cout << "*";
        }
        //SPACE
        for (int j=1;j<=(i-1);j++) 
        {
         cout<<" ";
        }
        cout<<"\n";
     }
return 0;
}
