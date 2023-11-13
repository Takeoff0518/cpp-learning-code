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
	char var;//���� 
	int dep;//����
	int val;//���Ӷ�
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
	//ֻ���ܳ���1~3λ 
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
	stack<T> st;
	
	rec.push_back({'z',0,o_1});
	//��һ����ջ 
	st.push(rec.front());
	bool is_o_0=0;
	for(auto it=rec.begin()+1;it!=rec.end();it++){
		
		/*
			debug
		*/
//		printf("get %c: val=%d, dep=%d\n",(*it).var,(*it).val,(*it).dep);
		
		//������һ�㣬��ջ 
		if((*it).dep>=st.top().dep){
			
			/*debug*/
//			printf("goto fork 1\n");
			
			st.push(*it);
			//���O(0)��û��������һ��ѭ�� 
			//����������Ȼ����O(0)Ҳû��Ӱ��
			if((*it).val==o_0){
				is_o_0=1;
			}
		}
		//����һ�㣬��ջ������һ����ƽ
		//ͬʱ��¼
		else{
			
			/*debug*/
//			printf("goto fork 2\n");
			
			int max_flex=flex_rec[(*it).dep];
			while((int)st.size()>(*it).dep){
				T ttop=st.top(); st.pop();
				
				/*debug*/
//				printf("pop: %c\n",ttop.var);
				
				//������O(0)ʱ���ܼ�¼ 
				if(!is_o_0){
					if(ttop.val==o_1){
						//����ԭ�� 
					}else if(ttop.val==o_n){
						max_flex++;
						
						/*debug*/
//						printf("max_flex++,=%d\n",max_flex);
					}
				}
				flex_rec[ttop.dep]=max(flex_rec[ttop.dep],max_flex);
			}
			st.push(*it);
			if((*it).val==o_0) is_o_0=1;
			else is_o_0=0; 
		}
	}
	
	
	
	/*
		debug
	*/
//	printf("flex_rec: ");
//	for(int i=0;i<=max_dep;i++){
//		printf("%d ",flex_rec[i]);
//	}puts("");
	
//	if(!flex_rec[1]) flex_rec[1]=1;
	calc_flex=flex_rec[1]; 
	return (tg_flex==calc_flex);
}
void solve(){
	//O(n^2)
	//012345
	string s_tg_flex;
	int tg_flex;//Ŀ�긴�Ӷ� 
	cin>>n>>s_tg_flex;
	/*
		����Ŀ�긴�Ӷȣ�����tg_flex 
	*/
	if(is_num(s_tg_flex[2])){//�������Ӷ� 
		tg_flex=o_1;
	}else{
		//��n 
		if(is_num(s_tg_flex[5])){//���Ӷ���λ��������λҲ������ 
			tg_flex=(s_tg_flex[4]-'0')*10+(s_tg_flex[5]-'0');
		}else{//���Ӷ�һλ 
			tg_flex=s_tg_flex[4]-'0';
		}
	}
	/*
		����for���� 
	*/
	vector<T> rec;//��¼����ѭ�� 
	stack<T> st;//ͬ�ϣ���used��� 
	bool used[30]={false};//��¼ʹ�ù����ַ� 
	int top=0;//ͳ�����
	max_dep=0;
	bool is_err=0;
	for(int i=1;i<=n;i++){
		char opt,cha; string s_s,s_t;
		cin>>opt;
		if(opt=='F'){
			cin>>cha>>s_s>>s_t;
			//������Ϣ��O(n)/O(1)/O(0)
			if(used[cha-'a']){//�ַ������ù���ERR 
//				printf("ERR\n");
//				return;
				is_err=1;
			}
			used[cha-'a']=1;
			/*
				����s,t 
			*/
			int s=0,t=0;
			//����s 
			if(is_num(s_s[0])) s=calc_num(s_s);
			else s=ch;
			//����t
			if(is_num(s_t[0])) t=calc_num(s_t);
			else t=ch;
			/*
				�жϸ��Ӷ� 
			*/
			int rec_flex=0;
			//�������� 
			if(s!=ch && t!=ch){
				// F i 3 1
				if(s>t) rec_flex=o_0;
				// F i 1 3
				else rec_flex=o_1;
			// F i 3 n ������n 
			}else if(s!=ch && t==ch) rec_flex=o_n;
			// F i n 3 ��n�ҳ���
			else if(s==ch && t!=ch) rec_flex=o_0;
			// F i n n ��n
			else if(s==ch && t==ch) rec_flex=o_1;
			top++;//���++ 
			max_dep=max(max_dep,top);
			/*
				char var;//���� 
				int dep;//����
				int val;//���Ӷ�
			*/
			st.push({cha,top,rec_flex});//��¼ 
			rec.push_back({cha,top,rec_flex});
		}else{//����E 
			T ttop=st.top(); st.pop(); top--;
			used[ttop.var-'a']=0;//�����һ�� 
		}
	}
	
//	printf("top=%d\n",top);
	
	if(top){//��ƥ�� 
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

