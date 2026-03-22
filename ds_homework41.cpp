#include<iostream>
#include<vector>
#include<string>
#include<cctype>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string line;
	if(!getline(cin,line)) return 0;
	while(line.size()==0 && getline(cin,line)){}
	if(line.size()==0) return 0;
	vector<char> verts;
	for(char c:line){
		if(isalpha(static_cast<unsigned char>(c))) verts.push_back(c);
	}
	int n=(int)verts.size();
	int pos[256];
	for(int i=0;i<256;i++) pos[i]=-1;
	for(int i=0;i<n;i++) pos[(unsigned char)verts[i]]=i;

	string edgeLine;
	if(!getline(cin,edgeLine)) edgeLine="";
	while(edgeLine.size()==0 && getline(cin,edgeLine)){}

	static int edge[256][256];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) edge[i][j]=0;
	}
	vector<int> indeg(n,0);
	vector<int> outdeg(n,0);
	vector<char> letters;
	for(char c:edgeLine){
		if(isalpha(static_cast<unsigned char>(c))) letters.push_back(c);
	}
	for(int i=0;i+1<(int)letters.size();i+=2){
		int u=pos[(unsigned char)letters[i]];
		int v=pos[(unsigned char)letters[i+1]];
		if(u==-1 || v==-1) continue;
		if(edge[u][v]==0){
			edge[u][v]=1;
			outdeg[u]++;
			indeg[v]++;
		}
	}
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
	return 0;
}
