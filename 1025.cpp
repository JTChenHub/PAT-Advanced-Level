#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef struct student{
int score;
int local_rank,local_num,fin_rank;
char no[13];
}stu;
stu s[310010]={0};
int n[111];
bool cmp(stu a,stu b)
{
	if(a.score!=b.score)
		return a.score>b.score;
	else
		return strcmp(a.no,b.no)<0;
}
int main()
{
	int N;
	int total=0;
	cin>>N;
	int last_score;
	stu *p=s;
	for(int i=1;i<N+1;i++)
	{
		
		cin>>n[i];
		for(int j=0;j<n[i];j++)
		{
			scanf("%s %d",s[total].no,&s[total].score);
			s[total].local_num=i;
			total++;
		}
		sort(s+total-n[i],s+total,cmp);
		last_score=s[total-n[i]].score;
		s[total-n[i]].local_rank=1;
		for(int j=total-n[i]+1;j<total;j++)
		{
			if(last_score==s[j].score)
				s[j].local_rank=s[j-1].local_rank;
			else
				s[j].local_rank=j-(total-n[i])+1;
			last_score=s[j].score;
		}
		p+=n[i];
	}
	sort(s,s+total,cmp);
	cout<<total<<endl;
	last_score=s[0].score;
	s[0].fin_rank=1;
	cout<<s[0].no<<" "<<s[0].fin_rank<<" "<<s[0].local_num<<" "<<s[0].local_rank<<endl;
	for(int i=1;i<total;i++)
	{
		if(last_score==s[i].score)
			s[i].fin_rank=s[i-1].fin_rank;
		else
			s[i].fin_rank=i+1;
		last_score=s[i].score;
		cout<<s[i].no<<" "<<s[i].fin_rank<<" "<<s[i].local_num<<" "<<s[i].local_rank<<endl;
	}
		
	return 0;
}