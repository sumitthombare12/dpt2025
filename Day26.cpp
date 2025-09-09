#include <iostream>
#include <vector>
using namespace std;

bool isCycle(int curr, vector<vector<int>>& mp, vector<bool>& visited) {
    
    if(visited[curr]) {
        return true;
    }
    
    visited[curr] = true;
    bool isValid = false;
    
    for(auto &nxt: mp[curr]) {
        isValid = isValid || isCycle(nxt, mp, visited);
    }
    
    return false || isValid;
}

int main()
{
    //Enter a number of vertexes
    int V = 0;
    cin>>V;
    
    //Enter size of graph
    int n = 0;
    cin>>n;
    
    //Enter a graph edges
    vector<vector<int>> graph;
    for(int i=0; i<n; i++) {
        int a, b;
        cin>>a>>b;
        graph.push_back({a,b});
    }
    cout<<endl;
    if(n >= V) {
        cout<<true;
        return 0;
    }
    
    //Store edges in vertexes wise
    vector<vector<int>> mp(V+1);
    
    for(int i=0; i<n; i++) {
        int a = graph[i][0];
        int b = graph[i][1];
        
        mp[a].push_back(b);
    }
    
    vector<bool> visited(V+1, false);
    for(int i=0; i<=V; i++) {
        if(!visited[i] && isCycle(i, mp, visited)) {
            cout<<true;
            return 0;
        }
    }
    
    cout<<false;
    return 0;
}
