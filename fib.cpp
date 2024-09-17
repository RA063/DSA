#include<iostream>
using namespace std;
void fib(int n)
{
	cout<<"elements are:"<<n<<endl;
	int _1st=0,_2nd=1,next;
	for (int i = 0; i < n; i++) {
        if (i <= 1)
            next = i;
		else
		{
		next= _1st+_2nd;
		_1st=_2nd;
		_2nd=next;
		}
		cout<<next<<endl;
	}
	cout<<endl;
}
int main()
{
	int n;
	cout<<"enter no. of terms"<<endl;
	cin>>n;
	fib(n);
	return 0;
}
