#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
bool cmp(char a,char b)
{return a>b;}
int main()
{
	int n,a,b;
	n=0;
	a=0;
	b=0;
	char s[20]={0};
	scanf("%d",&n);
	sprintf(s,"%04d",n);
	if(s[1]==s[2]==s[3]==s[0])
		printf("%s - %s = 0000\n",s,s);
	if(n==6174)
		printf("7641 - 1467 = 6174\n");
	while(n!=6174&&n!=0)
	{
		sort(s,s+4);
		sscanf(s,"%d",&a);
		sort(s,s+4,cmp);
		sscanf(s,"%d",&b);
		n=b-a;
		printf("%04d - %04d = %04d\n",b,a,n);
		sprintf(s,"%04d",n);
	}
	return 0;
}