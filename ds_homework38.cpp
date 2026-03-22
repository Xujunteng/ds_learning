#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Edge{
	int to;
	int w;
	Edge(int v,int w0):to(v),w(w0){};
};

struct State{
	long long dist;
	int node;
	State(long long d,int u):dist(d),node(u){};
};

struct Cmp{
	bool operator()(const State &a,const State &b) const{
		return a.dist>b.dist;
	}
};

class Graph{
	public:
	int n;
	vector<vector<Edge>> adj;
	Graph(int n0):n(n0),adj(n0+1){};
	void addEdge(int u,int v,int w){
		adj[u].push_back(Edge(v,w));
	}
	long long secondShortest(int s,int t){
		const long long INF=4e18;
		vector<long long> dist1(n+1,INF);
		vector<long long> dist2(n+1,INF);
		// dist1: shortest, dist2: strictly second shortest
		priority_queue<State,vector<State>,Cmp> pq;
		dist1[s]=0;
		pq.push(State(0,s));
		while(!pq.empty()){
			State cur=pq.top();
			pq.pop();
			long long d=cur.dist;
			int u=cur.node;
			if(d>dist2[u]) continue;
			for(const auto &e:adj[u]){
				long long nd=d+e.w;
				if(nd<dist1[e.to]){
					dist2[e.to]=dist1[e.to];
					dist1[e.to]=nd;
					pq.push(State(nd,e.to));
				}else if(nd>dist1[e.to] && nd<dist2[e.to]){
					dist2[e.to]=nd;
					pq.push(State(nd,e.to));
				}
			}
		}
		if(dist2[t]>=INF/2) return -1;
		return dist2[t];
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	int m;
	int s;
	int t;
	if(!(cin>>n>>m>>s>>t)) return 0;
	Graph g(n);
	for(int i=0;i<m;i++){
		int u;
		int v;
		int w;
		cin>>u>>v>>w;
		g.addEdge(u,v,w);
	}
	cout<<g.secondShortest(s,t);
	return 0;
}
