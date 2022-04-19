#include <bits/stdc++.h> using namespace std;

#define N 3


struct Node
{

// stores parent node of current node
// helps in tracing path when answer is found Node* parent;

// contains cost for ancestors nodes
// including current node int pathCost;

// contains least promising cost int cost;

// contain worker number int workerID;

// contains Job ID int jobID;
