#include<iostream>
const int N=1005;
using namespace std;
int h,w;
char t[N][N];
int tong[N];
int main(){
	cin>>h>>w;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin>>t[i][j];
			if(t[i][j]=='#'){
				tong[j]++;
			}
		}
	}
	for(int i=1;i<=w;i++){
		cout<<tong[i]<<' ';
	}
	cout<<endl;
    return 0;
}

