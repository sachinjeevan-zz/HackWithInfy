#include <stdio.h>
void merge(int arr[],int l,int mid,int h)
{
    int n1=mid-l+1;
    int n2=h-mid;
    int L[n1],R[n2],k=0;
    for(int i=l;i<=mid;i++){
        L[k++]=arr[i];
    }
    k=0;
    for(int i=mid+1;i<=h;i++){
        R[k++]=arr[i];
    }
    int i=0,j=0;
    while(i<n1 && j<n2)
    {
        if(L[i]>R[j])
        {
            arr[l++]=L[i++];
        }
        else
        {
            arr[l++]=R[j++];
        }
    }
    while(i<n1)
    {
        arr[l++]=L[i++];
    }
    while(j<n2)
    {
        arr[l++]=R[j++];
    }
}
void mergeSort(int arr[],int l,int h)
{
    int mid=(l+h)/2;
    if(l<h){
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}
int minimumCostOfBreaking(int X[], int Y[], int m, int n) 
{ 
	int res = 0; 
	mergeSort(X, 0,m-1); 
	mergeSort(Y,0,n-1);
	int hzntl = 1, vert = 1; 
	int i = 0, j = 0; 
	while (i < m && j < n) 
	{ 
		if (X[i] > Y[j]) 
		{ 
			res += X[i] * vert; 
			hzntl++; 
			i++; 
		} 
		else
		{ 
			res += Y[j] * hzntl; 
			vert++; 
			j++; 
		} 
	} 
	int total = 0; 
	while (i < m) 
		total += X[i++]; 
	res += total * vert; 
	total = 0; 
	while (j < n) 
		total += Y[j++]; 
	res += total * hzntl; 
	return res; 
} 
 
int main() 
{ 
	int m,n;
    scanf("%d %d",&m,&n);
    int X[m],Y[n];
    for(int i=0;i<m-1;i++)
    {
        scanf("%d",&X[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        scanf("%d",&Y[i]);
    }
    printf("%d",minimumCostOfBreaking(X,Y,m-1,n-1));
} 
