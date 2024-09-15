#include<iostream>
using namespace std;
//traversing function
void traverse(int a[], int &n)
{
	cout<<"elements are:"<<endl;
	for(int i=0; i<=n-1; i++)
		cout<<a[i]<<endl;
}
//insert at any position
void insert(int a[],int &n)
{
	 int k,item;
	cout<<"Enter element to insert in array :"<<endl;
	cin>>item;
	cout<<"Enter position to insert element"<<endl;
	cin>>k;
	for(int i=n-1; i>=k-1; i--)
		a[i+1]=a[i];
	a[k-1]=item;
	n=n+1;
}
//deletion at any position
int del(int a[],int &n)
{
	int ele, l;
	cout<<"Enter position to delete element:"<<endl;
	cin>>l;
	ele=a[l-1];
	for(int i=l-1;i<n-1;i++)
		a[i]=a[i+1];
	n=n-1;
	return ele;
}
int main()
{
    int n,k,l,ele,item;
    cout<<"Enter no of elements of the array:"<<endl;
    cin>>n;
    cout<<"Enter elements of the array:"<<endl;
    int a[n];
    for(int i=0; i<=n-1; i++)
    {
    	cin>>a[i];
	}
	int ch;
	do{
	cout<<"menu \n1. Insert at any position \n2.delete at any position \n3.display array \n4.Exit"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1: insert(a,n);
				break;
		case 2: del(a,n);
				break;
		case 3: traverse(a,n);
				break;
		case 4: cout<<"Exiting !!"<<endl;
				break;
		default: cout<<"Invalid choice"<<endl;
	}
	}
	while(ch!=4);			
    return 0;
}
