#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Graph{
	public:
	int V;
	vector<vector<int>> adj;
	vector<int> path;
	vector<int> visited;
	int target;
	bool found;
	Graph(int v):V(v),adj(v+1),visited(v+1,0),target(0),found(false){};
	void addEdge(int u,int v){
		adj[u].push_back(v);
	}
	void sortAdj(){
		for(int i=1;i<=V;i++) sort(adj[i].begin(),adj[i].end());
	}
	void dfs(int u){
		visited[u]=1;
		path.push_back(u);
		if(u==target){
			for(int i=0;i<(int)path.size();i++){
				if(i) cout<<" ";
				cout<<path[i];
			}
			cout<<"\n";
			found=true;
		}else{
			for(int nxt:adj[u]){
				if(!visited[nxt]) dfs(nxt);
			}
		}
		path.pop_back();
		visited[u]=0;
	}
};

int main(){
	int V;
	int E;
	if(!(cin>>V>>E)) return 0;
	int s;
	int t;
	cin>>s>>t;
	Graph g(V);
	for(int i=0;i<E;i++){
		int u;
		int v;
		cin>>u>>v;
		g.addEdge(u,v);
	}
	g.sortAdj();
	g.target=t;
	g.dfs(s);
	if(!g.found) cout<<"No Path";
	return 0;
}
