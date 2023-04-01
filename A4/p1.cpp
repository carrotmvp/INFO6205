#include<bits/stdc++.h>
using namespace std;

/*
test1:
3
3
0 1
1 2
2 0
0
2
output:
true

test2:
6
5
0 1
0 2
3 5
5 4
4 3
0
5
output:
false

*/


string isPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        // Build the graph
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        // BFS
        queue<int> q;
        vector<int> visited(n, 0);
        q.push(source);
        visited[source] = 1;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            if(top == destination)
                return "true";

            for(int i=0; i<graph[top].size(); i++){
                if(visited[graph[top][i]] == 0){
                    q.push(graph[top][i]);
                    visited[graph[top][i]] = 1;
                }
            }
        }
        return "false";
}


int main(){

    //input
    int n;
    cin>>n;
    vector<vector<int>> edges;
    int num;//number of edges
    cin>>num;
    for(int i=0;i<num;i++){
        int x,y;
        cin>>x>>y;
        edges.push_back(vector<int> {x,y});
    }
    int s;//int for source
    int d;//int for destination
    cin>>s>>d;
    cout<<isPath(n,edges,s,d)<<endl;

}