#include <bits/stdc++.h>
using namespace std;

// Union Find Algo
vector<int> p(100005), r(100005);
void make_set(int v)
{
    for (int i = 0; i < v; ++i)
        p[i] = i;
    p[v] = v;
    r[v] = 1;
}

int find(int node)
{
    if (p[node] == node)
        return node;
    return p[node] = find(p[node]);
}

void union_sets(int u, int v)
{

    int a = find(u);
    int b = find(v);
    if (r[u] < r[v])
    {
        p[a] = b;
        r[v] += r[u];
    }
    else
    {
        p[a] = b;
        r[u] += r[v];
    }
}

int main()
{
    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m; // vertices & edges
    int x, y, wt;
    make_set(n);
    cout << "\nEnter the matrix that contains weights of edges: " << '\n';
    vector<pair<int, pair<int, int>>> krskl;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> wt;
        krskl.push_back({wt, {x, y}}); // making pair of pair of vector [pair2:vertexes] [pair1:weight&pair2]
    }
    cout << krskl.size() << '\n';
    sort(krskl.begin(), krskl.end()); //  sorting according to weights of edges
    int cost = 0;

    vector<pair<int, int>> mst;

    for (int i = 0; i < m; i++)
    {
        int x = krskl[i].second.first;
        int y = krskl[i].second.second;
        int c = krskl[i].first;

        if (find(x) != find(y))
        { // if in not in same set then, include in MST & make it in one set
            cost += c;
            mst.push_back({x, y});
            union_sets(x, y);
        }
    }
    cout << "\nMST : "
         << "\n";
    for (auto x : mst)
    {
        cout << x.first << " - " << x.second << '\n';
    }
    cout << "\nMinimum cost: " << cost << '\n';
}
