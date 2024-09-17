#include<iostream>
using namespace std;
int main()
{
    int n1,n2;
    cout<<"Enter no of elements in the 1st array"<<endl;
    cin>>n1;
    int a[n1],b[n2],c[100];
    cout<<"1st array elements are :"<<endl;
    for(int i=0; i<n1;i++)
        cin>>a[i];
    cout<<"Enter no of elements in the 2nd array"<<endl;
    cin>>n2;
    cout<<"2nd array elements are :"<<endl;
    for(int i=0; i<n2;i++)
        cin>>b[i];
    //merging
    for(int i=0; i<n1; i++)
        c[i]=a[i];
    for(int i=0; i<n2;i++)
        c[n1+i]=b[i];
    cout << "Merged array elements are:" << endl;
    for (int i = 0; i < n1 + n2; i++)
        cout << c[i] << " ";
    return 0;
}
