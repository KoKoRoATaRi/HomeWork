#include<iostream>
#include<cstdio>
#include<list>
#include<set>
#include<algorithm>
#define inf 99999
using namespace std;
int ** dist_matrix = NULL;
int ** cost_matrix = NULL;
list<int> * pre = NULL; 
int N = 0;
int M = 0;
int S = 0;
int D = 0;
class List:public list<int>
{
	public:
		int total_distance()
		{
			if (this->size() == 1)
			{
				return 0;
			}
			int sum = 0;
			list<int>::iterator e = this->end();
			e--;		
			for(list<int>::iterator i = this->begin(); i != e;)
			{
				sum = sum + dist_matrix[*i][*(++i)];
			}
			return sum;
		}
		int total_cost()
		{
			if (this->size() == 1)
			{
				return 0;
			}
			int sum = 0;
			list<int>::iterator e = this->end();
			e--;
			for(list<int>::iterator i = this->begin(); i != e;)
			{
				sum = sum + cost_matrix[*i][*(++i)];
			}
			return sum;
		}
};

list<int>* pathfind(int s)   
{
	int *D = new int [N];               //�м�����D 
	list<int>* Path = new list<int>[N];
	set<int> Set;
	Set.insert(s);                      //��ʼ������뼯�� 
	for(int i = 0; i < N;i++)
	{
		D[i] = dist_matrix[s][i];      //�����м�����
		Path[i].clear();
	}                                   
	while( Set.size() < N)              //not all node in Set, DO!
	{
		int num = 0;
		int dist = inf;
		for(int i = 0; i < N; i++)
		{
			if( Set.find(i)==Set.end() && D[i] < dist) //�ҳ��붥��������̵�,�Ҵ˵�δ���뼯�� 
			{                          
				num = i;
				dist = D[i];                           //��¼���num 
			}
		}                                
		for(int i = 0; i < N; i++)
		{
			int temp = dist + dist_matrix[num][i];
			if( Set.find(i)==Set.end() && temp < D[i])                    
			{
				D[i] = temp;                                   
				Path[i].clear();
				Path[i].push_back(num);	                                         
			}
			else if( Set.find(i)==Set.end() && temp == D[i])                    
			{
				D[i] = temp;                                  
				Path[i].push_back(num);	                                         
			}                             
		}                           
		Set.insert(num);
	}
	return Path;                       //D[i]��Ϊ���㵽i�����̾��� 	                                      
}


void init_matrix(int**& matrix,int N)
{
	matrix = new int*[N];
	for (int i = 0; i < N; i++)
	{
		matrix[i] = new int[N];
	}
	for(int i = 0;i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(i==j)
			{
				matrix[i][j] = 0;
				continue;
			}
			matrix[i][j] = inf;
		}
	}
}
//void view_map(int **& m)
//{
//	cout<<"*****************************"<<endl;
//	for(int i = 0; i< N; i++)
//	{
//		for(int j = 0; j< N;j++)
//		{
//			if(m[i][j]==inf)
//			{
//				cout<<"��"<<"    ";
//			}
//			else
//				cout<<m[i][j]<<"    ";
//		}
//		cout<<endl;
//	}
//}
list<List> find_all_path( int end )
{	
	list<List> all_path;
	for(list<int>::iterator i = pre[end].begin(); i != pre[end].end(); i++)          //��i���ڵ������ǰ���� 
	{
		if ( (*i) == end )                                            //���i��ǰ���ڵ�����end 
		{
			List direct_path;
			direct_path.push_back(*i);
			direct_path.push_back(S);
			all_path.push_back(direct_path);          
			return all_path;                                          //����һ��·   start<-i(==end) 
		}
		else
		{                                                    //��������i,�ȼ���end������i�Ƿ�����·�ص���� 
			list<List> another_path = find_all_path(*i);      //                         start<-i����·<-end
			for( list<List>::iterator i = another_path.begin(); i != another_path.end();i++)
			{
				List sub_path;
				sub_path.push_back(end);
				sub_path.insert(sub_path.end(),(*i).begin(),(*i).end());           //���пɻص�������· 
				all_path.push_back(sub_path);
			}
		}
	}
	return all_path;
}

int main()
{
	cin >> N;
	cin >> M;
	cin >> S;
	cin >> D;
	init_matrix(dist_matrix,N);
	init_matrix(cost_matrix,N);
	for (int i = 0 ; i < M ; i++)
	{
		int start, destination,dist,cost;
		cin >> start >> destination >> dist >>cost;
		dist_matrix[start][destination] = dist;
		dist_matrix[destination][start] = dist;
		cost_matrix[destination][start] = cost;
		cost_matrix[start][destination] = cost;
	}  
	pre = pathfind(S);
	list<List> all_path = find_all_path(D);
	auto best_path = all_path.begin();
	for(auto i = all_path.begin(); i!= all_path.end();i++)
	{
		if(i->total_distance() <= best_path->total_distance())
			best_path = i;                                       //��� 
	}
	
	for(auto i = all_path.begin(); i!=all_path.end();i++)
	{
		if(i->total_distance() == best_path->total_distance() && i->total_cost()<best_path->total_cost())
			best_path = i;                                       //���cost 
	}
	reverse(best_path->begin(),best_path->end());
	for(auto i = (*best_path).begin(); i!= (*best_path).end();i++)
	{
		cout<<*i<<' ';
	}
	cout<<best_path->total_distance()<<' '<<best_path->total_cost();
}
