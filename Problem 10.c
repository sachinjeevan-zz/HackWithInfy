#include<stdio.h>
int minFold(int h1,int w1,int h2,int w2)
{
	int count=0;
	while(h1>h2)
	{
		if(h1&1==1)
		{
			count++;
			h1--;
			if(h1<=h2)break;
		}
		h1=h1>>1;
		count++;
	}
	while(w1>w2)
	{
		if(w1&1)
		{
			count++;
			w1--;
			if(w1<=w2)break;
		}
		w1=w1>>1;
		count++;
	}
	return count;
}
int main()
{
	long long int h1=9,w1=6,h2=9,w2=2,count=0;
	//scanf("%lld %lld %lld %lld",&h1,&w1,&h2,&w2);
	printf("%lld",minFold(h1,w1,h2,w2));
}