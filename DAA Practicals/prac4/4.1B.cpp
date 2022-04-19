#include <bits/stdc++.h>
using namespace std;
 
// All denominations of Indian Currency
// int deno[] = { 1,2,3 };
// int deno[] = {18,17,5,1 };
int deno[] = {100,25,10,5,1};
int n = sizeof(deno) / sizeof(deno[0]);
 
void findMin(int V)
{
    sort(deno, deno + n);//nlogn
 
   
    vector<int> ans;
 
    for (int i = n - 1; i >= 0; i--) {
 
   
        while (V >= deno[i]) {
            V -= deno[i];
            ans.push_back(deno[i]);
        }
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}
 

int main()
{
    // int n = 5;
    // int n = 22;
    int n = 289;
    cout << "Following is minimal"
         << " number of change for " << n
         << ": ";
    findMin(n);
    return 0;
}