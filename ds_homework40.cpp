#include<iostream>
#include<vector>

using namespace std;

class Graph{
	public:
	int n;
	vector<vector<long>> dist;
	Graph(int n0):n(n0),dist(n0,vector<long>(n0)){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dist[i][j]=(i==j?0:-1);
			}
		}
	};
	void addEdge(int u,int v,long w){
		if(dist[u][v]==-1||w<dist[u][v]) dist[u][v]=w;
	}
	void floyd(){
		for(int k=0;k<n;k++){
			for(int i=0;i<n;i++){
				if(dist[i][k]==-1) continue;
				for(int j=0;j<n;j++){
					if(dist[k][j]==-1) continue;
					long nd=dist[i][k]+dist[k][j];
					if(dist[i][j]==-1||nd<dist[i][j]) dist[i][j]=nd;
				}
			}
		}
	}
	void print(){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(j>0) cout<<" ";
				if(dist[i][j]==-1) cout<<"-1";
				else cout<<dist[i][j];
			}
			if(i<n-1) cout<<"\n";
		}
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
		long w;
		cin>>u>>v>>w;
		g.addEdge(u-1,v-1,w);
	}
	g.floyd();
	g.print();
	return 0;
}