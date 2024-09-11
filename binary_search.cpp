/*-----------------Binary search-----------------*/
#include<iostream>
using namespace std;
int bi(int arr[], int n, int key)
{
	int s=0;
	int e=n-1;
	while(s<=e)
	{
	int mid=(s+e)/2;
	if(arr[mid]==key)
		return mid;
	else if(arr[mid]<key)
		s=mid+1;
	else
		e=mid-1;
	}
	return -1;
}

int main()
{
	int n;
	cout<<"Enter no. of element:"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter elements"<<endl;
	for(int i=0; i<=n-1; i++)
		cin>>arr[i];
	cout<<"Enter element to binary search "<<endl;
	int key;
	cin>>key;
	int result=bi(arr,n,key);	//function calling
	if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found." << endl;
	return 0;
}
