#include<iostream>
#include<string> 
#include<cstdio>
using namespace std;
const int WARRIOR_NUM=5;
const int WEAPON_NUM=3;
class Headquarter;
class Warrior
{
	private:
		Headquarter* pHeadquarter;//ÿ����ʿ��ָ�����Լ����ڻ��ص�һ��ָ�� 
		int kindNo;//��ʿ������ 
		int weaponNum;//�������� 
		int weaponNo[2];//�洢������������ 
		int no;
		double morale;//ʿ�� 
		int loyalty;//�ҳ϶� 
	public:
		static string names[WARRIOR_NUM];//names����������ʿ������ 
		static string weapons[WEAPON_NUM];//weapon����3������������ 
		static int initialLifeValue[WARRIOR_NUM];//initiallifevalue�����ʿ��ʼ������ֵ 
		Warrior(Headquarter*p,int no_,int kindNo_);//���캯������һ�����ص�ָ�룬�ڶ���Ϊno��������Ϊ���� 
		void PrintResult(int nTime);//��ӡnTimeʱ�����Ϣ 
		void PrintInformation();  
};
//HQ��Warrior,Warriorָ��HQ���߼����� 
class Headquarter
{
	private:
		int totalLifeValue;//ÿ��������������ֵ 
		bool stopped;//�Ƿ�ֹͣ 
		int totalWarriorNum;//����ʿ���� 
		int color;//��ɫ ��or�� 
		int curMakingSeqIdx;//��ǰ����ʿ������ 
		int warriorNum[WARRIOR_NUM];//�����ʿ������ 
		Warrior *pWarriors[1000];//ָ��warrior��ָ������ 
	public:
		friend class Warrior;
		static int makingSeq[2][WARRIOR_NUM];//��ʿ������˳������   ���� 
		void Init(int color_,int lv);//��ʼ�� 
		~Headquarter();//�������� 
		int Produce(int nTime);//������ʿ 
		string GetColor();//����"red" ��"blue" 
};
Warrior::Warrior(Headquarter *p,int no_,int kindNo_)
{
	no=no_;//��ʿ����� 
	kindNo=kindNo_;//��ʿ������ 
	pHeadquarter=p;//��ʿ�Ĺ��� 
	if(kindNo!=3&&kindNo!=4)
	{
		if(kindNo==1)
		weaponNum=2;
		else weaponNum=1;
	}//�����1����ʿ������ӵ�����������������2����ʿ������ӵ��һ������ 
	else weaponNum=0;
	for (int i=0;i<weaponNum;i++)//Warrior����Ĺ�������   
	weaponNo[i]=(no+i)%3;
	if(kindNo==0)
	morale=(double)p->totalLifeValue/initialLifeValue[0];
	else morale=0;
	if(kindNo==3)
	loyalty=p->totalLifeValue;
	else loyalty=0;
} 
void Warrior::PrintResult(int nTime)
{
	string color=pHeadquarter->GetColor() ;//�õ���ʿ�Ļ��ص���ɫ 
	printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n",nTime,color.c_str(),names[kindNo].c_str(),no,initialLifeValue[kindNo],pHeadquarter->warriorNum[kindNo],names[kindNo].c_str(),color.c_str());
} 

void Warrior::PrintInformation() 
{
	if(kindNo==0) printf("It has a %s,and it's morale is %.2f\n",weapons[weaponNo[0]].c_str(),weapons[weaponNo[1]].c_str(),morale);
	if(kindNo==1) printf("It has a %s and a %s\n",weapons[weaponNo[0]].c_str(),weapons[weaponNo[1]].c_str());
	if(kindNo==2) printf("It has a %s\n",weapons[weaponNo[0]].c_str());
	if(kindNo==3) printf("It's loyalty is %d\n",loyalty);
}
void Headquarter::Init(int color_,int lv)
{
	color=color_;
	totalLifeValue=lv;
	totalWarriorNum=0;
	stopped=false;
	curMakingSeqIdx=0;
	for(int i=0;i<WARRIOR_NUM;i++)
	warriorNum[i]=0;
}

Headquarter::~Headquarter()
{
	for(int i=0;i<totalWarriorNum;i++)
	{
		delete pWarriors[i];
	}
}

int Headquarter::Produce(int nTime)
{
	if(stopped)
	return 0;
	int searchingTimes=0;
	while(Warrior::initialLifeValue [makingSeq[color][curMakingSeqIdx]]>totalLifeValue&&searchingTimes<WARRIOR_NUM)
	{
	curMakingSeqIdx=(curMakingSeqIdx+1)%WARRIOR_NUM;
	searchingTimes++;
	}
	int kindNo=makingSeq[color][curMakingSeqIdx];
	if(Warrior::initialLifeValue [kindNo]>totalLifeValue)
	{
		stopped=true;
		if(color==0)
		printf("%03d red headquarter stops making warriors\n",nTime);
		else
		printf("%03d blue headquarter stops making warriors\n",nTime);
		return 0;
	}
//����ʿ�� 
totalLifeValue-=Warrior::initialLifeValue [kindNo];
curMakingSeqIdx=(curMakingSeqIdx+1)%WARRIOR_NUM;
pWarriors[totalWarriorNum]=new Warrior(this,totalWarriorNum+1,kindNo);
warriorNum[kindNo]++;
pWarriors[totalWarriorNum]->PrintResult(nTime);
pWarriors[totalWarriorNum]->PrintInformation() ;
totalWarriorNum++;
return 1; 
}

string Headquarter::GetColor() 
{
	if(color==0)
	return "red";
	else 
	return "blue";
} 
 string Warrior::names[WARRIOR_NUM]={"dragon","ninja","iceman","lion","wolf"};
 string Warrior::weapons[WEAPON_NUM]={"sword","bomb","arrow"};
 int Warrior::initialLifeValue [WARRIOR_NUM];
 int Headquarter::makingSeq[2][WARRIOR_NUM]={{2,3,4,1,0},{3,0,1,2,4}};
 int main()
 {
 	int t;
	int m;
 	Headquarter RedHead,BlueHead;
 	scanf("%d",&t);
 	int nCaseNo=1;
 	while(t--)
	 {        

	 	scanf("%d",&m);
	 	for(int i=0;i<WARRIOR_NUM;i++)
	 		scanf("%d",&Warrior::initialLifeValue [i]);
	 	RedHead.Init(0,m);
		BlueHead.Init(1,m);
		int nTime=0;
	     printf("Case:%d\n",nCaseNo++); 

		while(true)
		{
			int tmp1=RedHead.Produce(nTime);
			int tmp2=BlueHead.Produce(nTime);
			if(tmp1==0&&tmp2==0)
			break;
			nTime++;  
		} 
	 }

 
 
 
 
 
 
 }
