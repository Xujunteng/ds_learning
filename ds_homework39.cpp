#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph{
	public:
	int n;
	vector<vector<int>> adj;
	Graph(int n0):n(n0),adj(n0){};
	void addEdge(int u,int v){
		adj[u].push_back(v);
	}
	vector<int> bfs(int s){
		vector<int> dist(n,-1);
		queue<int> q;
		dist[s]=0;
		q.push(s);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int v:adj[u]){
				if(dist[v]==-1){
					dist[v]=dist[u]+1;
					q.push(v);
				}
			}
		}
		return dist;
	}
};

int main(){
	int n;
	if(!(cin>>n)) return 0;
	Graph g(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int x;
			cin>>x;
			if(x==1 && i!=j) g.addEdge(i,j);
		}
	}
	int v;
	cin>>v;
	vector<int> dist=g.bfs(v);
	int maxd=0;
	for(int i=0;i<n;i++){
		if(dist[i]>maxd) maxd=dist[i];
	}
	if(maxd==0){
		cout<<-1;
		return 0;
	}
	bool first=true;
	for(int i=0;i<n;i++){
		if(dist[i]==maxd){
			if(!first) cout<<" ";
			cout<<i;
			first=false;
		}
	}
	return 0;
}
