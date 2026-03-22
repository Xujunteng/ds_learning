#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<map>

using namespace std;

class Graph{
	public:
	int n;
	vector<char> verts;
	map<char,int> pos;
	vector<vector<int>> edge;
	vector<int> indeg;
	vector<int> outdeg;
	Graph(const vector<char> &v):n(v.size()),verts(v),edge(n,vector<int>(n,0)),indeg(n,0),outdeg(n,0){
		for(int i=0;i<n;i++) pos[verts[i]]=i;
	};
	void addEdges(const string &edgeLine){
		vector<char> letters;
		for(char c:edgeLine){
			if(isalpha(c)) letters.push_back(c);
		}
		for(int i=0;i+1<(int)letters.size();i+=2){
			auto itu=pos.find(letters[i]);
			auto itv=pos.find(letters[i+1]);
			if(itu==pos.end() || itv==pos.end()) continue;
			int u=itu->second;
			int v=itv->second;
			if(edge[u][v]==0){
				edge[u][v]=1;
				outdeg[u]++;
				indeg[v]++;
			}
		}
	}
	void printKVertices(){
		int cnt=0;
		cout<<"K vertices:";
		for(int i=0;i<n;i++){
			if(outdeg[i]>indeg[i]){
				cout<<" "<<verts[i];
				cnt++;
			}
		}
		cout<<"\n";
		cout<<"Number of K vertices: "<<cnt;
	}
};

int main(){
	string line;
	if(!getline(cin,line)) return 0;
	if(line.size()==0) return 0;
	vector<char> verts;
	for(char c:line){
		if(isalpha(c)) verts.push_back(c);
	}

	string edgeLine;
	if(!getline(cin,edgeLine)) edgeLine="";

	Graph g(verts);
	g.addEdges(edgeLine);
	g.printKVertices();
	return 0;
}