#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<queue>
#define ll long long
const int N=3000005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
#define p(x1,x2) make_pair(x1,x2)
#define PII pair<int,int>
#define id second
#define val first
using namespace std;
int t,n,a[N];
signed main(){
    scanf("%d",&t);
    for(int round=1;round<=t;round++){
        if(round==1){
            scanf("%d",&n);
            for(int i=1;i<=n;i++){
                scanf("%d",&a[i]);
            }
        }else{
            int k,x,y;
            scanf("%d",&k);
            while(k--){
                scanf("%d %d",&x,&y);
                a[x]=y;
            }
        }
        // for(int i=1;i<=n;i++){
        //     printf("%d ",a[i]);
        // }
        //puts("awa");
        int ans;
        deque<PII > q1,q2;
        for(int i=1;i<=n;i++){
            q1.push_back({a[i],i});
            // printf("%d ",i);
        }
        //puts("pushed!");
        // int timer=0;
        while(1){
            // cout<<++timer<<endl;
            if(q1.size()+q2.size()==2){
                ans=1;
                break;
            }
            int weaker,stronger,idx;
            weaker=q1.front().val;
            q1.pop_front();
            //printf("%d\n",weaker);
            if(q2.empty() || !q1.empty() && q1.back()>q2.back()){
                stronger=q1.back().val;
                idx=q1.back().id;
                q1.pop_back();
            }else{
                stronger=q2.back().val;
                idx=q2.back().id;
                q2.pop_back();
            }
            PII newer=p(stronger-weaker,idx);
            if(q1.empty() || q1.front().val>newer.val){
                // 从q2里面比，give up
                int cnt=0;
                ans=q1.size()+q2.size()+2;
                while(1){
                    cnt++;
                    if (q1.size()+q2.size()+1==2) {
                        if (cnt%2==0){
                            ans--;
                        }
                        break;
                    }
                    if(q2.empty() || !q1.empty() && q1.back()>q2.back()){
                        stronger=q1.back().val;
                        idx=q1.back().id;
                        q1.pop_back();
                    }else{
                        stronger=q2.back().val;
                        idx=q2.back().id;
                        q2.pop_back();
                    }
                    newer=p(stronger- newer.val, idx);
                    if(!((q1.empty() || newer < q1.front()) && (q2.empty() || newer < q2.front()))){
                        if(cnt%2==0){
                            ans--;
                        } 
                        break;
                    }
                }
                break;
            }else{
                q2.push_front(newer);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}