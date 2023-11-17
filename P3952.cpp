#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<stack>
#define N (105)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int t,n;
#define o_n 1
#define o_1 0
#define o_0 -1
#define ch -1
struct T{
	char var;//名称 
	int dep;//层数
	int val;//复杂度
	int calc,fa;
	/*
	 1-O(n) o_n
	 0-O(1) o_1
	-1-O(0) o_0
	*/ 
};
/*
	O(n)
	O(1)
	O(0)
*/
bool is_num(char x){
	return (x>='0' && x<='9');
}
int calc_num(string x){
//	int ans=0;
	//只可能出现1~3位 
	if(x.size()==3){
		return (x[0]-'0')*100+(x[1]-'0')*10+(x[2]-'0');
	}else if(x.size()==2){
		return (x[0]-'0')*10+(x[1]-'0');
	}
	return x[0]-'0';
}
int flex_rec[N],max_dep=0;
bool process(int &tg_flex,vector<T> &rec){
	int calc_flex=0;
	stack<int> st;//直接记录编号
	//先记录一下父节点 
	st.push(0);
	for(int i=0+1;i<(int)rec.size();i++){
//		if(rec[st.top()].dep<=rec[i].dep){
//			st.push(i);
//		}else{
//			while(rec[st.top()].dep>rec[i].dep){
//				int t=st.top(); st.pop();
//				rec[t].fa=i;
//			}
//			st.push(i);
//		}
		while(rec[st.top()].dep>rec[i].dep){
			int t=st.top(); st.pop();
			rec[t].fa=i;
		}
		st.push(i);
	}
	while(!st.empty()){
		rec[st.top()].fa=0;
		st.pop();
	} 
//	st.clear();
	
	st.push(0);
	for(int i=0+1;i<(int)rec.size();i++){
		while(rec[st.top()].dep>rec[i].dep){
			int t=st.top(); st.pop();
			if(rec[t].val==o_0) rec[t].calc=0;
		}
		st.push(i);
	}
	for(T i:rec){
		
	}
	return (tg_flex==calc_flex);
}
void solve(){
	//O(n^2)
	//012345
	string s_tg_flex;
	int tg_flex;//目标复杂度 
	cin>>n>>s_tg_flex;
	/*
		计算目标复杂度，存于tg_flex 
	*/
	if(is_num(s_tg_flex[2])){//常数复杂度 
		tg_flex=o_1;
	}else{
		//含n 
		if(is_num(s_tg_flex[5])){//复杂度两位，即第五位也是数字 
			tg_flex=(s_tg_flex[4]-'0')*10+(s_tg_flex[5]-'0');
		}else{//复杂度一位 
			tg_flex=s_tg_flex[4]-'0';
		}
	}
	/*
		处理for数据 
	*/
	vector<T> rec;//记录所有循环 
	stack<char> st;//同上，与used配合 
	bool used[30]={false};//记录使用过的字符 
	int top=0;//统计深度
	max_dep=0;
	bool is_err=0;
	for(int i=1;i<=n;i++){
		char opt,cha; string s_s,s_t;
		cin>>opt;
		if(opt=='F'){
			cin>>cha>>s_s>>s_t;
			//处理信息，O(n)/O(1)/O(0)
			if(used[cha-'a']){//字符被复用过，ERR 
//				printf("ERR\n");
//				return;
				is_err=1;
			}
			used[cha-'a']=1;
			/*
				处理s,t 
			*/
			int s=0,t=0;
			//处理s 
			if(is_num(s_s[0])) s=calc_num(s_s);
			else s=ch;
			//处理t
			if(is_num(s_t[0])) t=calc_num(s_t);
			else t=ch;
			/*
				判断复杂度 
			*/
			int rec_flex=0;
			//两个常数 
			if(s!=ch && t!=ch){
				// F i 3 1
				if(s>t) rec_flex=o_0;
				// F i 1 3
				else rec_flex=o_1;
			// F i 3 n 左常数右n 
			}else if(s!=ch && t==ch) rec_flex=o_n;
			// F i n 3 左n右常数
			else if(s==ch && t!=ch) rec_flex=o_0;
			// F i n n 俩n
			else if(s==ch && t==ch) rec_flex=o_1;
			top++;//深度++ 
			max_dep=max(max_dep,top);
			/*
				char var;//名称 
				int dep;//层数
				int val;//复杂度
			*/
			st.push(cha);//记录 
			rec.push_back({cha,top,rec_flex,0,0});
		}else{//碰到E 
			char ttop=st.top(); st.pop(); top--;
			used[ttop-'a']=0;//反标记一下 
		}
	}
	
//	printf("top=%d\n",top);
	
	if(top){//不匹配 
		is_err=1;
//		printf("ERR\n");
//		return;
	}
		
	if(is_err){
		printf("ERR\n");
		return;
	} 
	
	/*
		debug
	*/
//	for(T i:rec){
//		printf("%c: val=%d, dep=%d\n",i.var,i.val,i.dep);
//	}
//	printf("tg_flex=%d\n",tg_flex);
	
	
	memset(flex_rec,0,sizeof(flex_rec));
	if(process(tg_flex,rec)) printf("Yes\n");
	else printf("No\n");
}
int main(){
	cin>>t;
	while(t--){
		solve();
	}
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

