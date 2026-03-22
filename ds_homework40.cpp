#include<iostream>

using namespace std;

const long long INF=4e18;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	int m;
	if(!(cin>>n>>m)) return 0;
	static long long dist[205][205];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j]=(i==j?0:INF);
		}
	}
	for(int i=0;i<m;i++){
		int u;
		int v;
		long long w;
		cin>>u>>v>>w;
		if(w<dist[u][v]) dist[u][v]=w;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(dist[i][k]>=INF/2) continue;
			for(int j=1;j<=n;j++){
				if(dist[k][j]>=INF/2) continue;
				long long nd=dist[i][k]+dist[k][j];
				if(nd<dist[i][j]) dist[i][j]=nd;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j>1) cout<<" ";
			if(dist[i][j]>=INF/2) cout<<"INF";
			else cout<<dist[i][j];
		}
		if(i<n) cout<<"\n";
	}
	return 0;
}
