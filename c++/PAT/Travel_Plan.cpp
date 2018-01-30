#include<iostream>
#include<list>
#include<set>
#include<algorithm>
#define inf 99999
using namespace std;
int ** dist_matrix = NULL;                //�����ڽӾ��� 
int ** cost_matrix = NULL;                //cost�ڽӾ��� 
list<int> * pre = NULL;                   //ǰ����� 
int N = 0;
int M = 0;
int S = 0;
int D = 0;
class List:public list<int>              //list������ ����һ��·�� 
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

list<int>* pathfind(int s)               //Dijkstra�㷨������ǰ���ڵ����� 
{
	int *D = new int [N];                //�м�����D 
	list<int>* Path = new list<int>[N];  //��¼ǰ���ڵ� 
	set<int> Set;
	Set.insert(s);                      //��ʼ������뼯�� 
	for(int i = 0; i < N;i++)
	{
		D[i] = dist_matrix[s][i];      //�����м�����
		Path[i].clear();
	}
	int Set_size = 0;   
    //ע�⣺���ܴ��ڹ����㣬������ѭ��
	//����취��ʹ��һ��ֵ���ж�Set��С�Ƿ����仯������Ӳ���ȥ������ʱ�˳�ѭ�� 
	while( Set.size() != Set_size)             
	{
		int num = 0;
		int dist = inf;
		Set_size = Set.size();
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
				Path[i].clear();                       //�ɽ����ɳڵĵ� 
				Path[i].push_back(num);	                                         
			}
			else if( Set.find(i)==Set.end() && temp == D[i])                    
			{
				D[i] = temp;                           //������ȵĵ�       
				Path[i].push_back(num);                       	                                         
			}                             
		}                           
		Set.insert(num);
	}
	return Path;                                      //Path[i]�������ʼ�㵽i�������ǰ���ڵ�(�������)                      
}


void init_matrix(int**& matrix,int N)        //��̬���䲻�˷� 
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
void view_map(int **& m)           //debug�ã��鿴���� 
{
	cout<<"*****************************"<<endl;
	for(int i = 0; i< N; i++)
	{
		for(int j = 0; j< N;j++)
		{
			if(m[i][j]==inf)
			{
				cout<<"��"<<"    ";
			}
			else
				cout<<m[i][j]<<"    ";
		}
		cout<<endl;
	}
}
list<List> find_all_path( int end )                        // DFS,ʹ��ǰ������end�ҳ���start������· 
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
			list<List> another_path = find_all_path(*i);      //                 start<-i����·<-end
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
	/* ��ʼ��*/
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
	/* debug�� �鿴���� */
	//	view_map(dist_matrix); 
	//	view_map(cost_matrix);
	 
	/*�ҳ���start������ǰ���ڵ�*/
	pre = pathfind(S);
	/*�ҳ�����·�� */
	list<List> all_path = find_all_path(D);
	/* ��� */
	if(all_path.empty())
	{
		return 0;                          
	}	
	list<List>::iterator best_path = all_path.begin();    //���ڼ�¼��õ�һ��· 
	
	for(list<List>::iterator i = all_path.begin(); i!= all_path.end();i++)
	{
		if(i->total_distance() <= best_path->total_distance())
			best_path = i;                                       //��� 
	}
	for(list<List>::iterator i = all_path.begin(); i!=all_path.end();i++)
	{
		if(i->total_distance() == best_path->total_distance() && i->total_cost()<best_path->total_cost())
			best_path = i;                                       //���cost 
	}
	
	reverse(best_path->begin(),best_path->end());               //��תpath,��start->end 
	for(list<int>::iterator i = (*best_path).begin(); i!= (*best_path).end();i++)
	{
		cout<<*i<<' ';
	}
	cout<<best_path->total_distance()<<' '<<best_path->total_cost();
	return 0;
}
