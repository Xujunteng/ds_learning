#include<algorithm>
#include<fstream>

using namespace std;

struct ele{
    int row;
    int col;
    int val;
};

class Matrix{
    public:
    int row;
    int col;
    int cnt;
    ele *m;
    Matrix(int row,int col,int cnt);
    void MT();
};

Matrix::Matrix(int row,int col,int cnt):row(row),col(col),cnt(cnt){
    m=new ele[cnt];
}

void Matrix::MT(){
    for(int i=0;i<cnt;i++){
        swap(m[i].row,m[i].col);
    }
    sort(m,m+cnt,[](const ele& a,const ele& b){
        if(a.row!=b.row)return a.row<b.row;
        return a.col<b.col;
    });
    swap(row,col);
}

int main(){
    ifstream fin("in.txt");
    ofstream fout("abc.out");
    int a;
    int b;
    int c;
    fin>>a>>b>>c;
    Matrix m1(a,b,c);
    for(int i=0;i<c;i++){
        fin>>m1.m[i].row>>m1.m[i].col>>m1.m[i].val;
    }
    m1.MT();
    fout<<m1.row<<' '<<m1.col<<' '<<m1.cnt<<endl;
    for(int i=0;i<c;i++){
        fout<<m1.m[i].row<<' '<<m1.m[i].col<<' '<<m1.m[i].val<<endl;
    }
    return 0;
}