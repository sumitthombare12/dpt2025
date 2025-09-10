#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int main()
{
    
    int V = 0;
    cin>>V;
    
    int n = 0;
    cin>>n;
    
    vector<pair<int, int>> graph(n);
    
    for(int i=0; i<n; i++) {
        cin>>graph[i].first;
        cin>>graph[i].second;
    }
    
    int start = 0, end = 0;
    cin>>start;
    cin>>end;
    
    if(start == end) {
        cout<<0;
        return 0;
    }
    
    unordered_map<int, vector<int>> mp;
    vector<bool> visited(V+1, false);
    
    for(auto &g: graph) {
        mp[g.first].push_back(g.second);
        mp[g.second].push_back(g.first);
    }
    
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pri_que;
    
    pri_que.push({start, 1});
    
    while(!pri_que.empty()) {
        int curr = pri_que.top()[0];
        int dist = pri_que.top()[1];
        pri_que.pop();
        
        for(auto &nxt: mp[curr]) {
            if(nxt == end) {
                cout<<endl<<dist;
                return 0;
            }
            if(!visited[nxt]) {
                pri_que.push({nxt, dist+1});
            }
            visited[nxt] = true;
        }
    }

    cout<<endl<<-1;
    return 0;
}
