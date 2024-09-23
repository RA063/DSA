# include <iostream>
using namespace std;
class Linear_Queue
{ 
	#define max 10
	public:
		int front=-1,rear=-1;
		int arr[max];
		bool IsEmpty(){
		return front==-1;
}
bool IsFull()
{
	return rear==max-1;
}
void enqueue(int val)
{
	if(IsEmpty())
		front =0;
	if(IsFull())
		cout<<"can not insert ...queue is full ..."<<endl;
	else
		rear++;
	arr[rear]=val;
}
void dequeue()
{
	if(IsEmpty())
	{
		cout<<"can not delete ...queue is empty ..."<<endl;
		return;
	}
	cout<<"THE DEQUEUE ELEMENT IS : "<<arr[front]<<endl;
	if(rear==front)
	{
		front=-1;
		rear=-1;
	}
	else
		front++;
}
void display()
{
	cout<<" Linear Queue : ";
	if(IsEmpty())
	{
		cout<<"EMPTY QUEUE"<<endl;
		return;
	}
	else
	{
		for(int i=front;i!=rear;i++){
			cout<< arr[i]<< " ";
		}
	cout<<arr[rear] <<endl;
	} 
} 
};
int main() {
    Linear_Queue queue;
    int choice, value;

    do {
        cout << "\nQueue Operations:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;

            case 2:
                queue.dequeue();
                break;

            case 3:
                queue.display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
