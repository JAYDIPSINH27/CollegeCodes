#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, count1 = 0;
    cout<<"Enter Number:";
    cin >> n;
    int *a = new int(n);
    a[0] = 0;
    a[1] = 1;
    cout << a[0] << " " << a[1] << " ";
    for (int i = 2; i < n; i++)
    {
        count1++;
        a[i] = a[i - 1] + a[i - 2];
        count1++;
        cout << a[i] << " ";
    }
    cout << endl
         << "Count:" << count1;
    // delete a;
    return 0;
}
