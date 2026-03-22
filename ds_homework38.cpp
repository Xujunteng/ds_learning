#include<iostream>
#include<vector>
using namespace std;

struct Edge{
	int to,w;
	Edge(int v,int w0):to(v),w(w0){};
};

class Graph{
	public:
	int n;
	vector<vector<Edge>> adj;
	Graph(int n0):n(n0),adj(n0+1){};
	void addEdge(int u,int v,int w){adj[u].push_back(Edge(v,w));}
	long  secondShortest(int s,int t){
		vector<long > d1(n+1,-1),d2(n+1,-1);
		vector<bool> v1(n+1,false),v2(n+1,false);
		d1[s]=0;
		while(1){
			int u=-1;long best;bool sec=0;
			for(int i=1;i<=n;i++){
				if(!v1[i]&&d1[i]!=-1&&(u==-1||d1[i]<best)) u=i,best=d1[i],sec=0;
				if(!v2[i]&&d2[i]!=-1&&(u==-1||d2[i]<best)) u=i,best=d2[i],sec=1;
			}
			if(u==-1)break;
			if(sec)v2[u]=1;else v1[u]=1;
			for(auto &e:adj[u]){
				long nd=best+e.w;
				if(d1[e.to]==-1||nd<d1[e.to]){
					d2[e.to]=d1[e.to];d1[e.to]=nd;
				}else if(nd>d1[e.to]&&(d2[e.to]==-1||nd<d2[e.to])){
					d2[e.to]=nd;
				}
			}
		}
		return d2[t];
	}
};

int main(){
	int n,m,s,t;cin>>n>>m>>s>>t;
	Graph g(n);
	for(int i=0,u,v,w;i<m;i++){cin>>u>>v>>w;g.addEdge(u,v,w);}
	cout<<g.secondShortest(s,t);
	return 0;
}