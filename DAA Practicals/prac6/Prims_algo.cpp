#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;
    vector<pair<int, int>> adj[n]; // array of vector(pair)

    cout << "\nEnter the matrix that contains weights of edges: " << '\n';
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        adj[x].push_back({y, wt}); // pair of adjacent element and weight
        adj[y].push_back({x, wt}); // pair of adjacent element and weight
    }

    int parent[n];   // for printing the spanning tree
    int dist[n];     // for count the minimum cost
    bool visited[n]; // to determine if this is already visited or not, to avoid cycle

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0}); // distance , node
    dist[0] = 0;
    parent[0] = -1;

    while (!pq.empty())
    {

        int node = pq.top().second;
        visited[node] = true; // node visited to avoid cycle
        pq.pop();

        for (auto x : adj[node])
        {

            int adj_vertex = x.first;
            int wtt = x.second;

            // if not visited & weight is lesser than other adjcent vertex, update else continue
            if (visited[adj_vertex] == false && wtt < dist[adj_vertex])
            {
                parent[adj_vertex] = node;
                dist[adj_vertex] = wtt;
                pq.push({dist[adj_vertex], adj_vertex}); //  pushing the new pair with min distance
            }
            else
                continue;
        }
    }

    int cost = 0;
    cout << endl << "MST : "
         << "\n";
    for (int i = 1; i < n; i++)
    {
        cost += dist[i];
        cout << parent[i] << " - " << i << " \n";
    }
    cout << "\nMinimum cost: " << cost << '\n';
}

