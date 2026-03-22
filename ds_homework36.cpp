#include<iostream>
#include<vector>

using namespace std;

class Graph{
	public:
	int V;
	vector<vector<int>> adj;
	Graph(int v):V(v),adj(v){};
	void addEdge(int u,int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int countComponents(){
		vector<int> visited(V,0);
		int cnt=0;
		for(int i=0;i<V;i++){
			if(visited[i]) continue;
			++cnt;
			vector<int> st;
			st.push_back(i);
			visited[i]=1;
			while(!st.empty()){
				int cur=st.back();
				st.pop_back();
				for(int nxt:adj[cur]){
					if(!visited[nxt]){
						visited[nxt]=1;
						st.push_back(nxt);
					}
				}
			}
		}
		return cnt;
	}
};

int main(){
	int V;
	int E;
	if(!(cin>>V>>E)) return 0;
	Graph g(V);
	for(int i=0;i<E;i++){
		int u;
		int v;
		cin>>u>>v;
		g.addEdge(u,v);
	}
	cout<<g.countComponents();
	return 0;
}
