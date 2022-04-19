#include <bits/stdc++.h>
using namespace std;

void ScheduleActivity(int s[], int f[], int n)
{
    int i, j;
    cout << "Selected Activities" << endl;
    i = 0;
    cout << " " << i;
    for (j = 1; j < n; j++)
    {
        if (s[j] >= f[i])
        {
            cout << " " << j;
            i = j;
        }
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    //for getting input from input.txt
    freopen("input1.txt", "r", stdin);
    //for writing output from output.txt
    freopen("output1.txt", "w", stdout);
#endif

    //(1,2), 1,3),(1,4),(2,5),(3,7),(4,9), (5,6), (6,8), (7,9)
    //(1,4),(3,5),(0,6),(3,8),(5,7),(5,9), (6,10), (8,12),(8,11),(12,14), (2,13)

    //Input 1
    // int s[] = {1, 1, 1, 2, 3, 4, 5, 6, 7};
    // int f[] = {2, 3, 4, 5, 7, 9, 6, 8, 9};

    //Input2
    // int s[] = {1, 3, 0, 3, 5, 5, 6, 8, 8, 12, 2};
    // int f[] = {4, 5, 6, 8, 7, 9, 10, 12, 11, 14, 13};

    int n;
    cin >> n;
    int *s = new int(n);
    int *f = new int(n);


    // cout<<"Enter Start Times:";
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    // cout<<"Enter Finish Times:";
    for (int j = 0; j < n; j++) {
        cin >> f[j];
    }




    // int n = sizeof(s) / sizeof(s[0]);

    ScheduleActivity(s, f, n);

    return 0;
}