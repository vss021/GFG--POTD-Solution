/*
Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    // Depth-First Search (DFS) to count reachable vertices from 'i'
    void dfs(int V, vector<int> adj[], vector<bool>& vis, int i, int& c) {
        vis[i] = true;
        c++;
        for (const auto& it : adj[i]) {
            if (!vis[it]) {
                dfs(V, adj, vis, it, c);
            }
        }
    }

public:
    int findMotherVertex(int V, vector<int> adj[]) {
        // Vector to track visited vertices
        vector<bool> vis(V, false);
        
        int ans;  // Stores the potential mother vertex
        int c = 0;  // Count of reachable vertices
        
        // Perform DFS for each unvisited vertex
        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                dfs(V, adj, vis, i, c);
                ans = i;  // Update the potential mother vertex
                c = 0;    // Reset count
            }
        }
        
        // Reset the visited vector
        vis.assign(V, false);
        
        // Perform DFS from the potential mother vertex to check reachability
        dfs(V, adj, vis, ans, c);
        
        // If the count of reachable vertices is equal to the total vertices,
        // then 'ans' is a mother vertex; otherwise, return -1.
        if (c == V) {
            return ans;
        }
        
        return -1;
    }
};

int main() {
    int V = 4;
    vector<int> adj[V];

    // Example graph: 0 -> 1, 0 -> 2, 1 -> 3
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);

    Solution sol;
    int motherVertex = sol.findMotherVertex(V, adj);

    if (motherVertex != -1) {
        cout << "Mother Vertex: " << motherVertex << endl;
    } else {
        cout << "No mother vertex found." << endl;
    }

    return 0;
}
/*
Time Complexity:

DFS for Counting Reachable Vertices: In the first DFS traversal, you visit each vertex once to count the reachable vertices from each unvisited vertex. In the worst case, this involves visiting all vertices and edges in the graph, resulting in a time complexity of O(V + E), where V is the number of vertices, and E is the number of edges.

Second DFS for Verification: After identifying a potential mother vertex, you perform another DFS traversal from that vertex to verify if it is indeed a mother vertex. This second DFS traversal has a time complexity of O(V + E) as well.

Overall, the time complexity of the solution is O(V + E) + O(V + E), which simplifies to O(V + E), where V is the number of vertices, and E is the number of edges in the graph.

Space Complexity:

The space complexity primarily depends on the data structures used for bookkeeping:

Visited Array: The vis array of size V is used to keep track of visited vertices during both DFS traversals. Hence, the space complexity due to the vis array is O(V).

Function Call Stack: In the worst case, when the DFS traversal goes as deep as the number of vertices (V), the space required for the function call stack can be O(V). This occurs when there's a long chain of vertices.

Additional Variables: The ans, c, and other local variables consume constant space and do not significantly impact the overall space complexity.

Therefore, the overall space complexity is dominated by the vis array and the function call stack, resulting in a space complexity of O(V).

In summary, the time complexity of the solution is O(V + E), and the space complexity is O(V).
*/