#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<vector>
#define N (5005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
#define END 0
#define GO 1
#define IF 2
#define OTHER 3
struct node{
	int line;
	int type;
	string opt_code;
	int jump_line;
	bool operator< (const node &x) const{
		return x.line>line;
	}
};
vector<node> code;
int str_to_int(string x){
	int t=0;
	for(char c:x){
		t=t*10+(c-'0');
	}
	return t;
}
void process(string x,int line){
	if(x.size()<=2) return;
//	int i=0;
	int i=1;
//	string str_line="";
//	for(;i<(int)x.size();i++){
//		if(!isdigit(x[i])) break;
//		str_line+=x[i];
//	}
//	int line=str_to_int(str_line);
//	i++;//ignore " "
	int code_type=-1,jump_line=0;
	string opt_code="",str_jump_line="";
	if(x[i]=='I' && x[i+1]=='F'){
		code_type=IF;
		i+=3;// "IF "
		for(;i<(int)x.size();i++){
			if(x[i]==' ') break;
			opt_code+=x[i];
		}
		i+=4;//ignore "GO " 妈了个逼的为什么要+4
		for(;i<(int)x.size();i++){
			str_jump_line+=x[i];
		}
//		cout<<"str_jump_line: "<<str_jump_line<<endl;
		jump_line=str_to_int(str_jump_line);
	}else if(x[i]=='E' && x[i+1]=='N' && x[i+2]=='D'){
		code_type=END;
		i+=3;// "END"
	}else if(x[i]=='G' && x[i+1]=='O'){
		code_type=GO;
		i+=3;// "GO "
		for(;i<(int)x.size();i++){
			str_jump_line+=x[i];
		}
		jump_line=str_to_int(str_jump_line);
	}else{
		code_type=OTHER;
		for(;i<(int)x.size();i++){
			opt_code+=x[i];
		}
	}
	code.push_back({line,code_type,opt_code,jump_line});
}
int ans,now;
map<string,int> var_map;
int line_map[N];
bool check(int x){
	string str_var="";
	int i=0;
	string opt_code=code[x].opt_code;
	for(;i<(int)opt_code.size();i++){
		if(opt_code[i]=='=') break;
		str_var+=opt_code[i];
	}
	i++;
	string str_val=""; int val;
	for(;i<(int)opt_code.size();i++){
		str_val+=opt_code[i];
	}
	val=str_to_int(str_val);
//	cout<<"check: "<<str_var<<"="<<var_map[str_var]<<", expected "<<val<<endl;
	return var_map[str_var]==val;
}
void change(int x){
	string str_var="";
	int i=0;
	string opt_code=code[x].opt_code;
	for(;i<(int)opt_code.size();i++){
		if(opt_code[i]=='+') break;
		if(opt_code[i]=='?') return;
		str_var+=opt_code[i];
	}
	i++;
	string str_val=""; int val;
	for(;i<(int)opt_code.size();i++){
		str_val+=opt_code[i];
	}
	val=str_to_int(str_val);
	var_map[str_var]+=val;
//	cout<<"change: "<<str_var<<"+="<<val<<endl;
//	cout<<"now "<<str_var<<"="<<var_map[str_var]<<endl;
}
void solve(){
	sort(code.begin(),code.end());
	now=code.front().line;
	for(int i=0;i<(int)code.size();i++){
		line_map[code[i].line]=i;
	}
	while(1){
		node now_code=code[line_map[now]];
		if(ans>=10000000){
			cout<<-1<<endl;
			exit(0);
		}
//		getchar();
//		cout<<"goto line: "<<now<<endl;
		if(now_code.type==END){
//			printf("type: END\n");
			ans++;
			break;
		}
		if(now_code.type==GO){
			now=now_code.jump_line;
//			printf("type: GO %d\n",now);
			ans++;
			continue;
		}
		if(now_code.type==IF){
//			printf("type: IF\n");
			if(check(line_map[now])){
				now=now_code.jump_line;
//				printf("TRUE, GO %d\n",now);
				ans++;
				continue;
			}else{
				now=code[line_map[now]+1].line;
//				printf("FALSE, GO %d\n",now);
				ans++;
				if(now==N-1) break;
				continue;
			}
		}
		if(now_code.type==OTHER){
			ans++;
			change(line_map[now]);
			now=code[line_map[now]+1].line;
//			printf("OTHER GO %d\n",now);
			continue;
		}
	}
}
int main(){
	freopen("P5756_1.in","r",stdin);
	string s;
	int line;
	while(cin>>line){
//	while(scanf("%d",&line)!=EOF){
//		getchar();
//		cin.ignore();
		getline(cin,s);
		cout<<s<<endl;
		process(s,line);
	}
	code.push_back({N-1,END,"",0});
	cout<<"line\ttype\topt_code\tjump_line"<<endl;
	for(node i:code){
		cout<<i.line<<'\t'<<i.type<<'\t'<<i.opt_code<<'\t'<<i.jump_line<<endl;
	}
	solve();

	cout<<ans<<endl;
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

