#include <bits/stdc++.h>
using namespace std;
#define N 3
// int N;

int findMinCost(int costMatrix[N][N]);

int main()
{
	int costMatrix[N][N];
	string name;
	for(int i=0;i<N;i++){
		
			if(i==0)
				name="Amar";
			else if(i==1)
				name="Akbar";
			else
				name="Anthony";
		
		cout<<"\nEnter Time Taken By "<<name<< " For Cooking Gardening Cleaning Respectively.\n";
		for(int j=0;j<N;j++){
			cin >>costMatrix[i][j];
		}
	}

	cout << "\nOptimal Cost is "
		<< findMinCost(costMatrix)<<endl;

	return 0;
}

//Node defined
struct Node
	{
		Node* parent;
		int pathCost;
		int cost;
		int workerID;
		int jobID;
		bool assigned[N];
	};

//Print output
void printAssignments(Node *min)
{
	string name,work;
	if(min->parent==NULL)
		return;

	if(min->workerID==0)
		name="Amar";
	else if(min->workerID==1)
		name="Akbar";
	else
		name="Anthony";
	
	if(min->jobID==0)
		work="Cooking";
	else if(min->jobID==1)
		work="Gardening";
	else
		work="Cleaning";

	printAssignments(min->parent);
	cout << "\nAssign " << name
		<< " to " << work <<" Job"<< endl<<endl;

}

//Creation of Node
Node* newNode(int x, int y, bool assigned[],Node* parent)
{

	Node* node = new Node;

	for (int j = 0; j < N; j++)
		node->assigned[j] = assigned[j];
	node->assigned[y] = true;

	node->parent = parent;
	node->workerID = x;
	node->jobID = y;

	return node;
}

//Calculation using branch and bound.
int calculateCost(int costMatrix[N][N], int x,int y, bool assigned[])
{
	int cost = 0;

	bool available[N] = {true};

	for (int i = x + 1; i < N; i++)
	{
		int min = INT_MAX, minIndex = -1;

		for (int j = 0; j < N; j++)
		{

			if (!assigned[j] && available[j] &&
				costMatrix[i][j] < min)
			{
				
				minIndex = j;
				min = costMatrix[i][j];
			}
		}
		cost += min;
		available[minIndex] = false;
	}

	return cost;
}

//Comparision 
struct comp
{
	bool operator()(const Node* lhs,const Node* rhs) const
	{
		return lhs->cost > rhs->cost;
	}
};



int findMinCost(int costMatrix[N][N])
{
	priority_queue<Node*, std::vector<Node*>, comp> pq;
	bool assigned[N] = {false};
	Node* root = newNode(-1, -1, assigned, NULL);
	root->pathCost = root->cost = 0;
	root->workerID = -1;

	pq.push(root);


	while (!pq.empty())
	{
	
	Node* min = pq.top();

	
	pq.pop();

	
	int i = min->workerID + 1;

	
	if (i == N)
	{
		printAssignments(min);
		return min->cost;
	}


	for (int j = 0; j < N; j++)
	{
		
		if (!min->assigned[j])
		{

		Node* child = newNode(i, j, min->assigned, min);

	
		child->pathCost = min->pathCost + costMatrix[i][j];

	
		child->cost = child->pathCost +
			calculateCost(costMatrix, i, j, child->assigned);

	
		pq.push(child);
		}
	}
	}
}
