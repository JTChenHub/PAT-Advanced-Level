#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char s[100010];
int left_p[100010]={0};
int right_t=0;
int main()
{
	gets(s);
	int num=0;
/*	
	for(int i=0;i<strlen(s);i++)
	{
		for(int j=strlen(s)-1;j>=0;j--)
		{
			if(i>j)break;
			for(int k=strlen(s)-1;k>=0;k--)
			{
				if(k>j&&j>i&&s[i]=='P'&&s[j]=='A'&&s[k]=='T')
					cnt++;
				
				if(k<j)break;
			}
		}
		cnt=cnt%1000000007;
	}*/
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(i>0)
			left_p[i]=left_p[i-1];
		if(s[i]=='P')
			left_p[i]++;
	}
	
	right_t=0;
	for(int j=len-1;j>=0;j--)
	{
		
		if(s[j]=='T')
			right_t++;
		else if(s[j]=='A')
		{
			num=((num+left_p[j]*right_t)%1000000007);
			
		}
	}

	
	printf("%d",num);
	return 0;
}