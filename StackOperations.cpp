//------PUSH-------POP---------DISPLAY
#include<iostream>
using namespace std;
const int max_s=5;
class stack{
	private:
		int arr[max_s];
		int top;
	public:
		stack()
		{
			top=-1;
		}
		//push
		void push(int val)
		{
			if(top==max_s-1)
				cout<<"overflow";
			else
				{
						top++;
					arr[top]=val;
				}
		}
		//pop
		void pop()
		{
			if(top==-1)
				cout<<"underflow";
			else
				top--;
		}
		//display
		void display()
		{
			if(top==-1)
				cout<<"stack empty";
			else
				{for(int i=0; i<=top;i++)
				cout<<arr[i]<<" ";
				}
		}
};
int main()
{
	stack st;
	int ch,val;
	do{
	cout<<"\n--------------Menu-------------- \n1.push \n2.pop \n3.display \n4.Exit \nEnter your choice:"<<endl;
	cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Enter ele for push"<<endl;
					cin>>val;
					st.	push(val);
					break;
			case 2: st.pop();
					break;
			case 3: st.display();
					break;
			case 4: cout<<"Exiting"<<endl;
					break;
			default: cout<<"Invalid choice !!"<<endl;
		}
	}
	while(ch!=4);
	return 0;
}
