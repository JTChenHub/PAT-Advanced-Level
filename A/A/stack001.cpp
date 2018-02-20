#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
        if(n==0) break;
		char x;
		int p;
		stack<int> s;
		while(n--)
		{
			scanf(" %c",&x);
			if(x=='P')
			{
				scanf("%d",&p);
				s.push(p);
                
			}
			else if(x=='O')
			{
                if(!s.empty())
                {
                    s.pop();
                }
                else 
                {
                    
                    continue;
                }
				
			}
			else if(x=='A')
			{
				if(!s.empty())
				{
				printf("%d\n",s.top());
				}
				else printf("E\n");
			}
		}
		printf("\n");
	}
	return 0;
}
