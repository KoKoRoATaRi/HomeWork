#include<iostream>
using namespace std;
//����������������� 
int ftc(int,char,int,char,int);//�����ƶ���һ��ĺ��� 
int stc(int,char,int,char,int);//�����ƶ��ڶ���ĺ��� 
int ttc(int,char,int,char,int);//�����ƶ�������ĺ��� 
int fiftc(int,char,int,char,int);//�����ƶ�������ĺ��� 
int fasts(int,char,int,char,int);//�����һ����֮���ƶ������ĺ��� 
int fatts(int,char,int,char,int);//�����һ����֮���ƶ������ĺ��� 
int fafits(int,char,int,char,int);//�����һ����֮���ƶ������ĺ��� 
int safots(int,char,int,char,int);//����ڶ�����֮���ƶ������ĺ��� 
int safits(int,char,int,char,int);//����ڶ�����֮���ƶ������ĺ��� 
int tafits(int,char,int,char,int);//�����������֮���ƶ������ĺ���
 //�ö�Ԫ�������洢һ���û�����ʾ������ͨ������  ����  �ƶ� ���ܵı������ ��������ͨ���ƶ� ���� ���� �����ı����֣�����-10�����ȱ��ʹԭ����������������Ӧ�������Ӧ�� 
int move[10][3]={6,9,-10,    -10,-10,-10,   3,-10,-10,    2,5,-10,     -10,-10,-10,   3,-10,-10,    0,9,-10,    -10,-10,-10,  -10,-10,-10,  0,6,-10};
int  add[10][3]={8,-10,-10,    -10,-10,-10,  -10,-10,-10,   9,-10,-10,   -10,-10,-10,   6,9,-10,      8,-10,-10,  -10,-10,-10,  -10,-10,-10,  8,-10,-10};
int  ajj[10][3]={-10,-10,-10,  -10,-10,-10,  -10,-10,-10,  -10,-10,-10,  -10,-10,-10,   -10,-10,-10,  5,-10,-10,  -10,-10,-10,   0,6,9,     5,3,-10};
int main(){
int a,b,c;char d,j;cout<<"   A       +       B         =        C"<<endl;cout<<"��һ��   �ڶ���   ������   ������   ������"<<endl; cout<<"�������ʽ:"<<endl;
while(cin>>a>>j>>b>>d>>c){
if(j=='+'){if(a+b==c){cout<<"��ȷ��ʽ"<<endl;continue;}}                                                   //���жϵ�ʽ�Ƿ����  �����������ȷ��ʽ 
if(j=='-'){if(a-b==c){cout<<"��ȷ��ʽ"<<endl;continue;}}
if((a>9||a<0)||(b>9||b<0)||(c>9||c<0)){cout<<"������Χ"<<endl;continue;}                                   //ִ�иı�����ĺ��� 
int result0,result1,result2,result3,result4,result5,result6,result7,result8,result9;                       //����result 0-9 ����¼ÿ����������ķ���ֵ   ͨ���ı��  ��ʽ�����������ȷ��ʽ������Ӧ��result��Ϊ1   
result0=ftc(a,j,b,d,c);
result1=stc(a,j,b,d,c);
result2=ttc(a,j,b,d,c);
result3=fiftc(a,j,b,d,c);
result4=fasts(a,j,b,d,c);
result5=fatts(a,j,b,d,c);
result6=fafits(a,j,b,d,c);
result7=safots(a,j,b,d,c);
result8=safits(a,j,b,d,c);
result9=tafits(a,j,b,d,c);
if(result0==0&&result1==0&&result2==0&&result3==0&&result4==0&&result5==0&&result6==0&&result7==0&&result8==0&&result9==0){//���Թ����������  ������result��Ϊ0������������ 
cout<<"�������"<<endl;}
}                                                                                       
 return 0;  
}


	
int ftc(int a,char j,int b,char d ,int c){
if(j=='+'){
     for(int i=0;i<3;i++){if(move[a][i]+b==c){a=move[a][i];cout<<a<<j<<b<<d<<c<<"��һ���ƶ�һ�����"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(add[a][i]+b==c){a=add[a][i];cout<<a<<j<<b<<d<<c<<"��һ�����һ�����"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(ajj[a][i]+b==c){a=ajj[a][i];cout<<a<<j<<b<<d<<c<<"��һ����ȥһ�����"<<endl;return 1;}}
}
if(j=='-'){
	 for(int i=0;i<3;i++){if(move[a][i]-b==c){a=move[a][i];cout<<a<<j<<b<<d<<c<<"��һ���ƶ�һ�����"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(add[a][i]-b==c){a=add[a][i];cout<<a<<j<<b<<d<<c<<"��һ�����һ�����"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(ajj[a][i]-b==c){a=ajj[a][i];cout<<a<<j<<b<<d<<c<<"��һ����ȥһ�����"<<endl;return 1;}}
}return 0;
}



int stc(int a,char j,int b,char d,int c){
if(a+b==c){cout<<a<<'+'<<b<<d<<c<<"�ڶ������һ�����"<<endl;return 1;}
if(a-b==c){cout<<a<<'-'<<b<<d<<c<<"�ڶ�����ȥһ�����"<<endl;return 1;}                                
return 0;	
}



int ttc(int a,char j,int b,char d,int c){
	if(j=='+'){
     for(int i=0;i<3;i++){if(a+move[b][i]==c){b=move[b][i];cout<<a<<j<<b<<d<<c<<"�������ƶ�һ�����"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(a+add[b][i]==c){b=add[b][i];cout<<a<<j<<b<<d<<c<<"�������һ�����"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(a+ajj[b][i]==c){b=ajj[b][i];cout<<a<<j<<b<<d<<c<<"��������ȥһ�����"<<endl;return 1;}}
}
if(j=='-'){
	 for(int i=0;i<3;i++){if(a-move[b][i]==c){b=move[b][i];cout<<a<<j<<b<<d<<c<<"�������ƶ�һ�����"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(a-add[b][i]==c){b=add[b][i];cout<<a<<j<<b<<d<<c<<"���������һ�����"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(a-ajj[b][i]==c){b=ajj[b][i];cout<<a<<j<<b<<d<<c<<"��������ȥһ�����"<<endl;return 1;}}
}return 0;	
}



int fiftc(int a,char j,int b,char d,int c){
if(j=='+'){
     for(int i=0;i<3;i++){if(a+b==move[c][i]){c=move[c][i];cout<<a<<j<<b<<d<<c<<"�������ƶ�һ�����"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(a+b==add[c][i]){c=add[c][i];cout<<a<<j<<b<<d<<c<<"�������ƶ�һ�����"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(a+b==ajj[c][i]){c=ajj[c][i];cout<<a<<j<<b<<d<<c<<"�������ƶ�һ�����"<<endl;return 1;}}
}
if(j=='-'){
	 for(int i=0;i<3;i++){if(a-move[b][i]==c){b=move[b][i];cout<<a<<j<<b<<d<<c<<"�������ƶ�һ�����"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(a-add[b][i]==c){b=add[b][i];cout<<a<<j<<b<<d<<c<<"���������һ�����"<<endl;return 1;}}
     for(int i=0;i<3;i++){if(a-ajj[b][i]==c){b=ajj[b][i];cout<<a<<j<<b<<d<<c<<"��������ȥһ�����"<<endl;return 1;}}
}return 0;		
}



int fasts(int a,char j,int b,char d,int c){
if(j=='+'){for(int i=0;i<3;i++){if(add[a][i]-b==c){a=add[a][i];cout<<a<<'-'<<b<<d<<c<<"�ڶ����ƶ�һ��������һ��"<<endl;return 1;}}}
if(j=='-'){for(int i=0;i<3;i++){if(ajj[a][i]+b==c){a=ajj[a][i];cout<<a<<'+'<<b<<d<<c<<"��һ���ƶ�һ�������ڶ���"<<endl;return 1;}}}
return 0;
	}



int fatts(int a,char j,int b,char d,int c){
if(j=='+')          {
for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
			if(add[a][i]+ajj[b][j]==c){a=add[a][i];b=ajj[b][j];cout<<a<<'+'<<b<<d<<c<<"�������ƶ�һ��������һ��"<<endl;return 1;} 
			if(ajj[a][i]+add[b][j]==c){a=ajj[a][i];b=add[b][j];cout<<a<<'+'<<b<<d<<c<<"��һ���ƶ�һ������������"<<endl;return 1;}	}
			 }
					}
if(j=='-')                              {
for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
			if(add[a][i]-ajj[b][j]==c){a=add[a][i];b=ajj[b][j];cout<<a<<'-'<<b<<d<<c<<"�������ƶ�һ��������һ��"<<endl;return 1;} 
			if(ajj[a][i]-add[b][j]==c){a=ajj[a][i];b=add[b][j];cout<<a<<'-'<<b<<d<<c<<"��һ���ƶ�һ������������"<<endl;return 1;}	}
			        }
				                    	}	return 0;  				                    
}



int fafits(int a,char j,int b,char d,int c){
if(j=='+')          {
for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
			if(add[a][i]+b==ajj[c][i]){a=add[a][i];c=ajj[c][j];cout<<a<<'+'<<b<<d<<c<<"�������ƶ�һ��������һ��"<<endl;return 1;} 
			if(ajj[a][i]+b==add[c][i]){a=ajj[a][i];c=add[c][j];cout<<a<<'+'<<b<<d<<c<<"��һ���ƶ�һ������������"<<endl;return 1;}	}
			 }
					}
if(j=='-')                              {
for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
			if(add[a][i]-b==ajj[c][i]){a=add[a][i];c=ajj[c][j];cout<<a<<'-'<<b<<d<<c<<"�������ƶ�һ��������һ��"<<endl;return 1;} 
			if(ajj[a][i]-b==add[c][i]){a=ajj[a][i];c=add[c][j];cout<<a<<'-'<<b<<d<<c<<"��һ���ƶ�һ������������"<<endl;return 1;}	}
			        }
				                    	}return 0;
}



int safots(int a,char j,int b,char d,int c){
if(j=='-'){if(a==b-c){cout<<a<<'='<<b<<'-'<<c<<"�������ƶ�һ�������ڶ���"<<endl;return 1;}}return 0;
}



int safits(int a,char j,int b,char d,int c){
if(j=='+'){for(int i=0;i<3;i++){if(a-b==add[c][i]){c=add[c][i];cout<<a<<'-'<<b<<d<<c<<"�ڶ����ƶ�һ������������"<<endl;return 1;}}}
if(j=='-'){for(int i=0;i<3;i++){if(a+b==ajj[c][i]){c=ajj[c][i];cout<<a<<'+'<<b<<d<<c<<"�������ƶ�һ�������ڶ���"<<endl;return 1;}}}
return 0;
}



int tafits(int a,char j,int b,char d,int c){
if(j=='+')          {
for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
			if(a+ajj[b][j]==add[c][i])
			{c=add[c][i];b=ajj[b][j];cout<<a<<'+'<<b<<d<<c<<"�������ƶ�һ������������"<<endl;return 1;} 
			if(a+add[b][j]==ajj[c][i])
			{c=ajj[c][i];b=add[b][j];cout<<a<<'+'<<b<<d<<c<<"�������ƶ�һ������������"<<endl;return 1;}	}
			 }
					}
if(j=='-')                              {
for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
			if(a-ajj[b][j]==add[c][i]){c=add[c][i];b=ajj[b][j];cout<<a<<'-'<<b<<d<<c<<"�������ƶ�һ������������"<<endl;return 1;} 
			if(a-add[b][j]==ajj[c][i]){c=ajj[c][i];b=add[b][j];cout<<a<<'-'<<b<<d<<c<<"�������ƶ�һ������������"<<endl;return 1;}	}
			        }
				                    	}	return 0;
}
