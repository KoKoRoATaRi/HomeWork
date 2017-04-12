#include "stdio.h"
#include "stdlib.h"

typedef struct btnode//���������洢�ṹ����
{char data;
 struct btnode *left,*right;
}btnode;

void CreateBiTree(btnode* &T)//�����������н���������
{
char ch;
scanf("%c",&ch);       //����һ���ַ�   
if(ch=='#') T=NULL;
else 
{
  T=(btnode*)malloc(sizeof(btnode)); //����һ���½��
  T->data=ch;
  CreateBiTree( T->left );  //����������
  CreateBiTree( T->right  );;  //����������
}
}

void  preorder(btnode *b)   //�������
{if(b)
{printf("%c", b->data) ; //"���ʽ��"
 preorder(b->left); //�ݹ����������
 preorder(b->right); //�ݹ����������
}
}

void  inorder(btnode *b)   //�������
{if(b)
{	inorder( b->left ); //�ݹ����������
	printf("%c", b->data);//���ʽڵ� 
    inorder( b->right );; //�ݹ����������
}
}
void  lastorder(btnode *b)   //�������
{if(b)
{lastorder(b->left); //�ݹ����������
 lastorder(b->right); //�ݹ����������
 printf("%c", b->data) ; //"���ʽ��"
}
}

int depth(btnode *b)//������������
{int depthl,depthr;
 if( b->left == NULL && b->right == NULL) return 0;
 else
{ depthl = depth( b->left );
  depthr = depth( b->right );
 if(depthl>depthr) return(depthl+1);
 else 
 return(depthr+1);
}
}

int node_counter(btnode *b)//����������ܽ����
{int cl,cr;
 if(!b) return 0;
 else if(b->left ==NULL && b->right == NULL)
 {
 	return 1;
 }
else {
 cl=node_counter(b->left);
 cr=node_counter(b->right);
 return( 1+cl + cr );
}
}

int leaf_counter(btnode *b)//���������Ҷ�����
{int cl,cr;
 if(!b) return 0;
 else
 if( b->left == NULL && b->right == NULL )  return 1;
 else
{cl=leaf_counter(b->left);
 cr=leaf_counter(b->right);
 return( cl+cr );
}
}

void outputbt(btnode *b)//�����������Ƕ�����ű�ʾ
{
if(b)
{ printf("%c",b->data);
  if( b->left != NULL || b->right != NULL )
  {
  printf("(");
  outputbt( b->left );
  if( b->right != NULL) printf(",");
  outputbt( b->right );
  printf(")");
  }
}
}
int main()
{btnode *btree; int t;

printf("��������������������У��磺ab##c##���س�������������������");
 CreateBiTree(btree);//����������������������������������У��磺ab##c##
 printf("\n��������Ƕ�����ű�ʾ:");
 
 outputbt(btree);
printf("\n���ֱ������зֱ���:");
 printf("\n����:");
 preorder(btree);
 printf("\n����:");
 inorder(btree);
 printf("\n����:");
 lastorder(btree);
 t=depth(btree);//����������
 printf("\n����������ǣ�%d",t);
 t=node_counter(btree);//������������
 printf("\n�������ܽ�����ǣ�%d",t);
 t=leaf_counter(btree);//�������Ҷ�����
 printf("\n������Ҷ������ǣ�%d",t);

}

