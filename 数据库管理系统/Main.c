#include<stdio.h>
#include <windows.h>
void dataSearch();   
void Renew();
void View();
void screenup();
void adminMainScreen();
void studentMainScreen();
char database[30][10];       //�ö�ά���鱣��ѧ�� 
char adminId[]={"teacher"};   // ��ʼ������Ա�˺����� 
char adminPw[]={"123456"};    //
char studentId[]={"student"}; //��ʼ��ѧ���˺����� 
char studentPw[]={"654321"};  //
FILE* fp1;
FILE* fp2;


int main()
										{

	int i,j;
fp1=fopen("database.txt", "r");       //��database.txt����ѧ������ 


 
for (i = 0; i < 30; i++)
    {
      fscanf(fp1,"%s",database[i]); //���ļ����ݵ�database 
    }
    fclose(fp1);


	
system("cls");			
int power=0;char temId[10],temPw[10];int n=0;	 //����������û��������ж�Ȩ�� 

while(power==0)
{system("cls");
screenup();
printf("                      �������˺�(����Ա:teacher���û�:student)\n");
scanf("%s",temId);
printf("                      ����������(����Ա:123456),�û�(654321)\n");
scanf("%s",temPw);

if(strcmp(temId,adminId)==0&&strcmp(temPw,adminPw)==0)                
{power=1;}

else if(strcmp(temId,studentId)==0&&strcmp(temPw,studentPw)==0)
{power=2;}

else 
{
printf("�˺��������\n");  Sleep(1000);	continue;
}
system("cls");
}

if(power==1)                                 //Ȩ����1��ʱ��������Ա���� 
{
 adminMainScreen();
}


if(power==2)                                  //Ȩ����2��ʱ������û����� 
{
studentMainScreen();
}


										}



void adminMainScreen()                       //����Ա���ܺ��� 
{
	int n;
	screenup();
	printf("1.ѧ�����ݲ�ѯ\n2.ѧ�������޸�\n3.ע��\n4.ȫ��ѧ������һ��\n\n\n\n\n\n\n\n\n��������:");
	scanf("%d",&n);
	while(1)
	{
	if(n==1)
	{
	dataSearch();
	adminMainScreen();	
	}    
	else if(n==2)   Renew();
	else if(n==3)   main();
	else if(n==4) 	View();
	scanf("%d",&n);
	}
}

void dataSearch()                        //�������ݹ��ܺ���
{

	system("cls");
	screenup();
	char tem[10];
	printf("������Ҫ��ѯ����Ż�����������,(����back����):");
	scanf("%s",tem);
	while(strcmp(tem,"back")!=0)
	{
		system("cls");
		screenup();
		datasearchMain(tem);
		
		scanf("%s",tem);
	}
	system("cls");

	
}
void datasearchMain(char tem[])
{	
	int i,j;char c[10];
	printf("������Ҫ��ѯ����Ż�����������,(����back����):");

	if('0'<tem[0]&&tem[0]<='9'||'0'<tem[0]&&tem[0]<='9'&&'0'<tem[1]&&tem[1]<'9')
	{
			c[0]=tem[0];
			c[1]=tem[1];
			i=atoi(c);
			if(i<=9)
			printf("\n����:%s,ѧ��15100410%i\n",database[i-1],i);
			else
			printf("\n����:%s,ѧ��1510041%i\n",database[i-1],i);
	}
	else 
	{
		for(i=0;i<30;i++)
			for(j=0;j<10;j++)
			{	
			if(strlen(tem)<=2)
			{
				if(database[i][j]==tem[0]&&database[i][j+1]==tem[1]&&i<=9)
				printf("\n����:%s,ѧ��15100410%i\n",database[i],i+1);
				else if
				(database[i][j]==tem[0]&&database[i][j+1]==tem[1]&&i>9)
				printf("\n����:%s,ѧ��1510041%i\n",database[i],i+1);
			}
			
				else if(database[i][j]==tem[0]&&database[i][j+1]==tem[1]&&database[i][j+2]==tem[2]&&database[i][j+3]==tem[3]&&i<=9)
				printf("\n����:%s,ѧ��15100410%i\n",database[i],i+1);
				else if
				(database[i][j]==tem[0]&&database[i][j+1]==tem[1]&&database[i][j+2]==tem[2]&&database[i][j+3]==tem[3]&&i>9)
				printf("\n����:%s,ѧ��1510041%i\n",database[i],i+1);
			}
		
	}
	
}

void studentMainScreen()                  // //�û����ܺ���  
{
    int n;
	screenup();
	printf("1.ѧ�����ݲ�ѯ\n2.ע��\n\n\n\n\n\n\n\n\n��������:");
	scanf("%d",&n);
	while(1)
	{
    if(n==1) 	
	{
		dataSearch();
		studentMainScreen();
	}	
	
    else if(n==2) 
	main(); 

	scanf("%d",&n);
	}
 
}

void Renew()                             //¼�빦�ܺ��� 
{  
	system("cls");
	screenup();
	int num=0,t1,t2,i;char tem[10],t;
	printf("������Ҫ�޸�ѧ������Ż�ѧ������-1����:");

	while(num!=-1)
								{
	scanf("%d",&num);
	if(num==-1) break;
	else if(num>151004100)
	{
		t1=num%10;
		t2=(num/10)%10;
		num=t1+t2*10;
	}
	else if(num<30);
	else 
	{
	printf("���뷶Χ����\n");
	continue;
	}
								
	printf("�������޸ĺ������:\n");
	scanf("%s",tem);
	if(num<9)
	printf("�����Ϊ15100410%d�޸�Ϊ%s?������Y/N:",num,tem);
	else	
	printf("�����Ϊ1510041%d�޸�Ϊ%s?������Y/N:",num,tem);
	scanf("%c",&t);
	scanf("%c",&t);
	if(t=='y'||t=='Y')
	{
	strcpy(database[num-1],tem);
	printf("�޸ĳɹ�!\n������Ҫ�޸�ѧ������Ż�ѧ������-1����:");
	}
	else continue;
	}
	fp2=fopen("database.txt", "w");
	for (i = 0; i < 30; i++)
    {
      fprintf(fp2,"%s\n",database[i]); 
    }
    fclose(fp2);
    system("cls");
 adminMainScreen();   
}




void screenup()                                  //������⺯�� 
{
	printf("\n\n                        *******ѧ�����ݹ���ϵͳ******\n\n\n");
}
void View()                                      //�鿴���ݹ��ܺ��� 
{
	int i;
	for(i=0;i<30;i++)
	{	if(i<=8)
		printf("ѧ��:15100410%d  ����%s\n",i+1,database[i]);
		else 
		printf("ѧ��:1510041%d  ����%s\n",i+1,database[i]);
	}
	printf("��������:");
}

