#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<stack>

using namespace std;

class Graph{
	public:
	int n;
	vector<vector<int>> adj;
	int startVertex;
	stack<int> path;
	vector<int> visited;
	set<string> uniq;
	vector<vector<int>> cycles;
	Graph(int n0):n(n0),adj(n0+1),startVertex(0){};
	void addEdge(int u,int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void sortAdj(){
		for(int i=1;i<=n;i++) sort(adj[i].begin(),adj[i].end());
	}
	void dfs(int u){
		for(int w:adj[u]){
			if(w==startVertex){
				if(path.size()>=3){
					stack<int> tmp=path;
					vector<int> cycle;
					while(!tmp.empty()){
						cycle.push_back(tmp.top());
						tmp.pop();
					}
					reverse(cycle.begin(),cycle.end());
					sort(cycle.begin(),cycle.end());
					string key;
					for(int x:cycle){
						key+=to_string(x);
						key.push_back('#');
					}
					if(uniq.insert(key).second) cycles.push_back(cycle);
				}
			}else if(!visited[w]){
				visited[w]=1;
				path.push(w);
				dfs(w);
				path.pop();
				visited[w]=0;
			}
		}
	}
	void findCycles(int start){
		startVertex=start;
		path = stack<int>();
		visited.assign(n+1,0);
		uniq.clear();
		cycles.clear();
		path.push(startVertex);
		visited[startVertex]=1;
		dfs(startVertex);
		sort(cycles.begin(),cycles.end());
	}
};

int main(){

	int n;
	int m;
	if(!(cin>>n>>m)) return 0;
	Graph g(n);
	for(int i=0;i<m;i++){
		int u;
		int v;
		cin>>u>>v;
		if(u<1 || u>n || v<1 || v>n || u==v) continue;
		g.addEdge(u,v);
	}
	int start;
	if(!(cin>>start)) return 0;
	if(start<1 || start>n){
		cout<<-1;
		return 0;
	}
	g.sortAdj();
	g.findCycles(start);

	if(g.cycles.empty()){
		cout<<-1;
		return 0;
	}

	for(size_t i=0;i<g.cycles.size();i++){
		for(size_t j=0;j<g.cycles[i].size();j++){
			if(j) cout<<' ';
			cout<<g.cycles[i][j];
		}
		if(i+1<g.cycles.size()) cout<<"\n";
	}
	return 0;
}