#include<bits/stdc++.h>
using namespace std;

/*
test1:
3
2
0 1
0 2
0
2
output:
false

test2:
4
4
0 1
0 3
1 2
2 1
0
3
output:
false

test2:
4
4
0 1
0 3
1 2
2 1
0
3
output:
false


test2:
4
4
0 1
0 2
1 3
2 3
0
3
output:
true

*/


string isPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<vector<int>> graph(n);
    vector<int> inDegree(n,0);//kind of in-degree help to solve
    for(auto x:edges)
    {
        graph[x[0]].push_back(x[1]);
        inDegree[x[1]]++;
    }
    queue<int> q;
    q.push(source);
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        if(graph[t].empty() && t!=destination)return "false";
        for(int x:graph[t])
        {
            if(inDegree[x]<0)return "false";
            inDegree[x]--;
            q.push(x);
        }
    }
    return "true";
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

