#include<cstdio>
using namespace std;
int main()
{
    int n;
    int cnt=0;
    int a;
    while(scanf("%d",&n)!=-1)
    {
         for(int i=0;i<n;i++)
        {
             cnt=0;
             scanf("%d",&a);
			 if(a==1){printf("%d\n",1);continue;}
			 int j;
             for(j=1;j*j<a;j++)
                 if(a%j==0)
                     cnt+=2;
			 if(j*j==a)cnt++;
             printf("%d\n",cnt);
        }
    }
    return 0;
}