/*
Given an undirected graph with V nodes and E edges, create and return an adjacency list of the graph. 0-based indexing is followed everywhere.

Example 1:

Input:
V = 5, E = 7
edges = {(0,1),(0,4),(4,1),(4,3),(1,3),(1,2),(3,2)}

Output: 
{{1,4}, 
 {0,2,3,4}, 
 {1,3},
 {1,2,4},
 {0,1,3}}
Explanation:
Node 0 is connected to 1 and 4.
Node 1 is connected to 0,2,3 and 4.
Node 2 is connected to 1 and 3.
Node 3 is connected to 1,2 and 4.
Node 4 is connected to 0,1 and 3.
Example 2:

Input:
V = 4, E = 3
edges = {(0,3),(0,2),(2,1)}


Output: 
{{2,3} 
 {2}, 
 {0,1} 
 {0}}
Explanation:
Node 0 is connected to 2 and 3.
Node 1 is only connected to 2.
Node 2 is connected to 0 and 1.
Node 3 is only connected to 0.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>> edges) {
        vector<vector<int>> adj(V);

        for (auto x : edges) {
            int u = x.first;
            int v = x.second;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }
};

int main() {
    Solution solution;
    int V = 5;  // Number of vertices in the graph
    vector<pair<int, int>> edges = {{0, 1}, {0, 4}, {1, 2}, {1, 3}, {2, 3}, {3, 4}};

    vector<vector<int>> adjacencyList = solution.printGraph(V, edges);

    cout << "Adjacency List:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " -> ";
        for (int neighbor : adjacencyList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}

