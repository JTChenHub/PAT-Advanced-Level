#include<iostream>
using namespace std;
typedef struct{
	int a;
	int *ab;
	int *b;
}c;
int main()
{
  printf("%d",sizeof(c));
  return 0;
}