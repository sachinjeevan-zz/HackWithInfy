#include<stdio.h>
void merge(double arr[],int l,int mid,int h)
{
    int n1=mid-l+1;
    int n2=h-mid;
    double L[n1],R[n2];
    int k=0;
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
        if(L[i]<R[j])
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
void mergeSort(double arr[],int l,int h)
{
    int mid=(l+h)/2;
    if(l<h){
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    double arr[N];
    for(int i=0;i<N;i++)
    {
        scanf("%lf",&arr[i]);
    }
    int leftIndex=0;
    int totalGroups=0;
    mergeSort(arr,0,N-1);
    for(int i=N-1;i>=0 && leftIndex<=i;i--)
    {
        if(arr[i]>1.99)totalGroups+=1;
        if(arr[i]<=1.99)
        {
            if(arr[leftIndex]+arr[i]<=3.0)
            {
                leftIndex+=1;
            }
            totalGroups+=1;
        }
    }
    printf("%d",totalGroups);
}