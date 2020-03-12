#include <stdio.h> 
#include<stdlib.h>
#include<string.h>
void countnndSay(int n) 
{ 
	if (n == 1){
        printf("1"); 
    }	 
	if (n == 2)	{
        printf("11");
    } 
    char str[n];
    str[0]='1';
    str[1]='1';
    int k=2;
	for (int i = 3; i<=n; i++) 
	{
		int len = strlen(str); 

		int cnt = 1,h=0; 
		char tmp[len];
		for (int j = 1; j < len; j++) 
		{ 
			if (str[j] != str[j-1]) 
			{ 
				tmp[h++]= cnt + '0'; 
				tmp[h++]= str[j-1]; 
				cnt = 1; 
			} 
			else cnt++; 
		}
        str[h]='\0'; 
        for(int m=0;m<=h;m++)
            str[m]=tmp[m];
        k=h; 
	} 
	printf("%s",str); 
} 

// Driver program 
int main() 
{ 
	int N;
    scanf("%d",&N);
    countnndSay(N); 
	return 0; 
} 
