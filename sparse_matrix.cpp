#include<iostream>				//sparse matrix
using namespace std;
class sp{
	public:
		void sparse(int arr[][50],int m, int n)
		{
			int x=m*n;
			cout<<"no. of elements:"<<x<<endl;
			float y=(2.0/3.0)*x;
			int c=0;
			for(int i=0; i<m; i++){
				for(int j=0; j<n; j++)	{
											if(arr[i][j]==0)
											c++;	}	}
			if((c==y)||(c>y))
				cout<<"sparse"<<endl;
			else
				cout<<"not"<<endl;	
		}
};
int main()
{
	int arr[50][50];
	int m,n;
	cout<<"Enter no. of rows and cols:"<<endl;
	cin>>m;
	cin>>n;
	cout<<"Enter elements"<<endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)	{
									cin>>arr[i][j];		}	}
	sp gu;
	gu.sparse(arr,m,n);
	return 0;
}
