#include <stdio.h> 
int countKdivPairs(int A[], int n, int K) 
{ 
	int freq[K];
    for(int i=0;i<K;i++)freq[i]=0;
	for (int i = 0; i < n; i++){ 
		++freq[A[i] % K]; 
    }
	int sum = freq[0] * (freq[0] - 1) / 2; 
	for (int i = 1; i <= K / 2 && i != (K - i); i++) 
		sum += freq[i] * freq[K - i]; 
	if (K % 2 == 0) 
		sum += (freq[K / 2] * (freq[K / 2] - 1) / 2); 
	return sum; 
} 
int main() 
{ 
    int N,K;
    scanf("%d %d",&N,&K);
	int A[N];
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    printf("%d",countKdivPairs(A,N,K)); 
	return 0; 
} 
