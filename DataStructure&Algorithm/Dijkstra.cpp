#include<iostream>
#include<vector>
#include<set>
#define inf 99999
using namespace std;
int ** dist_matrix = NULL;
int N = 0;
int M = 0;
int S = 0;
int D = 0;

int * pathfind(int s)
{
	int *D = new int [N];               //�м�����D 
	int *Path = new int [N];            //��Path��¼·��
	set<int> Set;
	Set.insert(s);                      //��ʼ������뼯�� 
	for(int i = 0; i < N;i++)
	{
		D[i] = dist_matrix[s][i];      //�����м�����
		Path[i] = 0;                   //��ʼ��Path 
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
			if( Set.find(i)==Set.end() && temp < D[i])                     //��������δ���뼯�ϵĵ�,�ҿɱ�num���ɳ� 
			{
				D[i] = temp;                                   //�ص����ˣ��ɳڲ���
				Path[i] = num;                                 //��¼num�㣬��˼Ϊ���㵽i֮�侭��num 
			}                             
		}                           
		Set.insert(num);
	}
	cout<<"Path:";
	for(int i = 0; i < N;i++)
	{
		cout<<Path[i]<<" ";
	}                   
		cout<<endl;

	return D;                       //D[i]��Ϊ���㵽i�����̾��� 	                                      
}


void init_matrix(int**& matrix,int N)
{
	matrix  = new int*[N];
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
void view_map(int **& m)
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
int main()
{
	N = 4;        //��ĸ��� 
	M = 5;		  //�ߵĸ��� 
	S = 0;        //���� 
	D = 3;        //�յ� 
	init_matrix(dist_matrix,N);
	dist_matrix[0][1] = 1;
	dist_matrix[1][3] = 2;
	dist_matrix[0][3] = 4;
	dist_matrix[0][2] = 2;
	dist_matrix[2][3] = 1;
	for(int i = 0; i< N ;i++)
	{
		for(int j =0 ;j<N;j++)
		{
			dist_matrix[j][i] = dist_matrix[i][j];
		}
	} 
//	for(int i = 0 ; i < M ; i++)
//	{
//		int start, destination,dist;
//		cin >> start >> destination >> dist;
//		dist_matrix[start][destination] = dist;
//		dist_matrix[destination][start] = dist;
//	}
	view_map(dist_matrix);     //�鿴�ڽӾ��� 
	cout<<"��ʼ��Ϊ:"<<S<<endl;
	cout<<"�յ�Ϊ:"<<D<<endl;
	cout<<"��̾���Ϊ:"<<pathfind(S)[D]; 
}
