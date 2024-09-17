/*--------BUBBLE SORT--------*/
#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter no. of element:"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter elements"<<endl;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	cout<<"after Bubble sort"<<endl;
	int count=1;
	while(count<n){
	for(int i=0; i<n-count; i++)
	{
		if(arr[i]>arr[i+1])
		{
			int c= arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=c;
		}
	}
		count++;
	}

	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
