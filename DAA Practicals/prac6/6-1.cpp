#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, source;
	cout << "Enter rows and columns: ";
	cin >> n >> m;
	cout << "\nEnter the matrix that contains weights of edges: " << '\n';
	vector<pair<int, int>> g[n + 1]; // 1-indexed adjacency list for of graph
	int mat[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
			if (mat[i][j])
			{
				g[i].push_back(make_pair(j, mat[i][j]));
				g[j].push_back(make_pair(i, mat[i][j]));
			}
		}
	}
	cout << "\nEnter source vertex: ";
	cin >> source;

	// Dijkstra's algorithm begins from here
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> distTo(n + 1, INT_MAX);

	distTo[source] = 0;
	pq.push(make_pair(0, source)); // (dist,from)

	while (!pq.empty())
	{

		pair<int, int> temp = pq.top();
		int dist = temp.first;
		int prev = temp.second;
		pq.pop();

		for (auto it : g[prev])
		{
			int next = it.first;
			int nextDist = it.second;
			if (distTo[next] > distTo[prev] + nextDist)
			{
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
	}

	cout << "\nThe shortest distances from source " << source << " are: ";
	for (int i = 1; i <= n; i++)
	{
		if (distTo[i] == INT_MAX)
			cout << "NA" << ' ';
		else
			cout << distTo[i] << ' ';
	}
	cout << "\n";
	return 0;
}



