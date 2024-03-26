#include<stdio.h>

int mountEverest(int arr[], int n){
	int s = 0;
	int a = n-1;
	while(s<=a){
		int mid = s+(a-s)/2;
		if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
			return mid;
		else if(arr[mid]>arr[mid+1])
			a = mid-1;
		else
			s = mid+1;
	}
	return -1;	
}

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int result = mountEverest(arr, n);
	printf("%d\n",result);
	return 0;
}