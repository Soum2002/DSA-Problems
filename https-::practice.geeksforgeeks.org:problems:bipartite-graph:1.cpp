//Check for Bipartite Graph
// https://practice.geeksforgeeks.org/problems/bipartite-graph/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//USING BFS
// class Solution {
//     private:
//     bool check(int start, int V, vector<int>adj[], int coloured[]){
//         queue<int> q;
// 	    coloured[start] = 0;
// 	    q.push(start);
// 	    while(!q.empty()){
// 	        int node = q.front();
// 	        q.pop();
// 	        for(auto it: adj[node]){
// 	            if(coloured[it] == -1){
// 	                coloured[it] = !coloured[node];
// 	                q.push(it);
// 	            }
// 	            else if(coloured[it] == coloured[node]) return false;
// 	        }
// 	    }
// 	    return true;
//     }
// public:
// 	bool isBipartite(int V, vector<int>adj[]){
// 	    // Code here
// 	    int coloured[V];
// 	    for(int i = 0; i< V; i++) coloured[i] = -1;
// 	    for(int i = 0; i<V; i++){
// 	        if(coloured[i] == -1){
// 	            if(check(i, V, adj, coloured)== false){
// 	                return false;
	                
// 	            }
// 	        }
// 	    }
// 	    return true;

// 	}

//Time Complexity: O(N) + O(2E)
//Space Complexity: O(3N) =~ O(N);


// USING DFS
class Solution {
private:
    bool dfs(int node, int color, int coloured[], vector<int> adj[]){
        coloured[node] = color;
        for(auto it: adj[node]){
            if(coloured[it] == -1){
                if(dfs(it, !color, coloured, adj) == false) return false;
            }
            else if(coloured[it] == coloured[node]){
                return false;
            }
            
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int coloured[V];
	    for(int i = 0; i<V; i++) coloured[i] = -1;
	    
	    for(int i = 0 ; i<V ; i++){
	        if(coloured[i] == -1){
	            int color = 0;
	            if(dfs(i, color, coloured, adj) == false) return false;
	        }
	    }
	    return true;

	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends