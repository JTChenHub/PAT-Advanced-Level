#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
struct BTNode
{
	BTNode *lchild;
	BTNode *rchild;
	char c;
}Tree[50];
int loc=0;
BTNode *creat()
{
	Tree[loc].lchild=Tree[loc].rchild=NULL;
	return &Tree[loc++];
}
char str1[40];
char str2[40];
BTNode *build(int start1,int last1,int start2,int last2)
{
	BTNode *p=creat();
	p->c=str1[start1];
	if(start1>=last1)return NULL;
	int i;
	for(i=start2;i<=last2;i++)
	{
	
		if(str1[start1]==str2[i])
		{
			break;
		}
	}
		if(i!=start2)
		{
			p->lchild=build(start1+1,start1+i-start2,start1,i-1);
		}
		if(i!=last2)
		{
			p->rchild=build(start1+i-start2+1,last1,i+1,last2);
		}
     return p;
}
void postorder(BTNode *t)
{
	if(t->lchild)
	postorder(t->lchild);
    if(t->rchild)
	postorder(t->rchild);
	printf("%c",t->c);
}
int main()
{
	int n;
	while(scanf("%s %s",str1,str2)!=EOF)
	{
		loc=0;
		int l1=strlen(str1);
		int l2=strlen(str2);
		BTNode *T=build(0,l1-1,0,l2-1);
		postorder(T);
		printf("\n");
	}
	return 0;
}