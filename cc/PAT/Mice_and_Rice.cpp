#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct mice
{
	int weight;
	int rank = 5;
	int num;
};
struct mycomp
{
	bool operator ()(mice&a,mice & b)
	{
		return a.weight<b.weight;
	}
};
int main()
{
	int Np = 0;
	int Ng = 0;
	cin >> Np >> Ng;
	mice* mices = new mice[Np];
	vector<int> per;                        //��ս��� 
	for(int i = 0; i < Np;i++)
	{
		cin >> mices[i].weight;
	}
	for(int i = 0; i < Np; i++)
	{
		int t;
		cin >> t;
		per.push_back(t);
		mices[i].num = i;
	}
	if(Ng == 1)
	{
		for(int i = 0; i < Np ;i++)
		{
			if(i == Np-1)
			cout<<1;
			else 
			cout<<1<<' ';
		}
		return 0;
	}
	int i = 0;
	vector<int> victory;                                          //ʤ���߱�� 
	priority_queue<mice,vector<mice>,mycomp> combat;              //���ȶ��� 
	while( per.size()!=1 )                                        //����ս��ֹһ����ʱһֱս��                          
	{
		while(i < per.size())                                     //�ҳ�����ʤ���� 
		{
			while(i < per.size()&& combat.size() != Ng) 
			{
				combat.push(mices[per[i]]);
				i++;                                
			}
			victory.push_back(combat.top().num);                  //���ȶ��У��Ӷ�Ϊʤ���� 
			combat = priority_queue<mice,vector<mice>,mycomp>();  //��� 
		}
		for(auto&i:per)                                          //��������ʧ����(all player not in victory) 
		{
			if(find(victory.begin(),victory.end(),i)==victory.end())
			{
				mices[i].rank = victory.size() + 1;              //ʧ���ߵȼ�Ϊʤ������+1  (rank of lost is the size of victory plus one.) 
			}
		}
		per.clear();
		for(auto&i:victory)
		{	
			per.push_back(i);                                    //ʤ���߼�����ս 
		}
		victory.clear();
		i = 0; 
	}
	mices[*(victory.begin())].rank = 1;                          //û�ж���ʱ�ͳ��˵�һ 
	for(int i = 0;i < Np;i++)
	{
		if( i!= Np-1)
		cout << mices[i].rank << ' ';
		else
		cout << mices[i].rank;
	}
	return 0;
} 


