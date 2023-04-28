#include <cstdio>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

tree<double, null_type, greater<double>, rb_tree_tag, tree_order_statistics_node_update> T;

int main()
{
	//freopen("3369.in", "r", stdin);
	//freopen("3369.out", "w", stdout);

	int q, opt, x;

	scanf("%d", &q);
	for (int i = 1; i <= q; ++ i)
	{
		scanf("%d%d", &opt, &x);
		if(opt == 1) 
			T.insert(x + i * 1e-6);
		//����һ����
		if(opt == 2) 
			T.erase(T.lower_bound(x));
		//ɾ��һ����
		if(opt == 3) 
			printf("%d\n", (int)T.order_of_key(x) + 1);
		//��ѯһ����������
		if(opt == 4) 
			printf("%d\n", (int)*T.find_by_order(x - 1));
		//��ѯ��kС���� ���ص���һ�������� ����k�Ǵ�0��ʼ��ģ���˼����С�����ǵ�0С��
		if(opt == 5) 
			printf("%d\n", (int)round(*(-- T.lower_bound(x))));
		//��ѯһ������ǰ��
		if(opt == 6) 
			printf("%d\n", (int)round(*T.lower_bound(x + 1)));
		//��ѯһ�����ĺ��
	}

	return 0;
}

