#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

static int startVertex;
static vector<vector<int>> adj;
static vector<int> path;
static vector<int> visited;
static set<string> uniq;
static vector<vector<int>> cycles;

static void dfs(int u){
	for(int w: adj[u]){
		if(w==startVertex){
			if(path.size()>=3){
				vector<int> cycle = path;
				sort(cycle.begin(), cycle.end());
				string key;
				for(int x: cycle){
					key += to_string(x);
					key.push_back('#');
				}
				if(uniq.insert(key).second) cycles.push_back(cycle);
			}
		}else if(!visited[w]){
			visited[w]=1;
			path.push_back(w);
			dfs(w);
			path.pop_back();
			visited[w]=0;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	if(!(cin>>n>>m)) return 0;
	adj.assign(n+1, vector<int>());
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		if(u<1 || u>n || v<1 || v>n || u==v) continue;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int start;
	if(!(cin>>start)) return 0;
	if(start<1 || start>n){
		cout<<-1;
		return 0;
	}
	startVertex = start;
	for(int i=1;i<=n;i++){
		sort(adj[i].begin(), adj[i].end());
	}

	path.clear();
	visited.assign(n+1, 0);
	uniq.clear();
	cycles.clear();

	path.push_back(startVertex);
	visited[startVertex]=1;

	dfs(startVertex);

	if(cycles.empty()){
		cout<<-1;
		return 0;
	}

	sort(cycles.begin(), cycles.end());
	for(size_t i=0;i<cycles.size();i++){
		for(size_t j=0;j<cycles[i].size();j++){
			if(j) cout<<' ';
			cout<<cycles[i][j];
		}
		if(i+1<cycles.size()) cout<<"\n";
	}
	return 0;
}
