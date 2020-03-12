#include <stdio.h>
#include<stdlib.h>
int max(int a,int b)
{
    return a>b?a:b;
}  
int findLen(char *A, int n, int k, char ch) 
{ 
	int maxlen = 1; 
	int cnt = 0; 
	int l = 0, r = 0; 
	while (r < n) { 
		if (A[r] != ch) 
			++cnt; 
		while (cnt > k) { 
			if (A[l] != ch) 
				--cnt; 
			++l; 
		} 
		maxlen = max(maxlen, r - l + 1); 
		++r; 
	} 
	return maxlen; 
} 
int answer(char* A, int n, int k) 
{ 
	int maxlen = 1; 
	for (int i = 0; i < 26; ++i) { 
		maxlen = max(maxlen, findLen(A, n, k, i+'A')); 
		maxlen = max(maxlen, findLen(A, n, k, i+'a')); 
	} 
	return maxlen; 
} 
int main() 
{ 
	int n, k;
    scanf("%d %d",&n,&k); 
	char* A = (char*)malloc(n);
    scanf("%s",A); 
	printf("%d" ,answer(A, n, k));
} 
