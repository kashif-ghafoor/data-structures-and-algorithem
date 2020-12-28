// Lab08.cpp : Defines the entry point for the console application.
//Lab08_Kashif_Ghafoor

/*
The Monk is trying to explain to its users that even a single unit of time can be extremely important and to demonstrate this particular 
fact he gives them a challenging task.

There are N processes to be completed by you, the chosen one, since you're Monk's favorite student. All the processes have a unique number
assigned to them from 1 to N.

Now, you are given two things:

The calling order in which all the processes are called.
The ideal order in which all the processes should have been executed.
Now, let us demonstrate this by an example. Let's say that there are 3 processes, the calling order of the processes is: 3 - 2 - 1. The ideal
order is: 1 - 3 - 2, i.e., process number 3 will only be executed after process number 1 has been completed; process number 2 will only be 
executed after process number 3 has been executed.

Iteration #1: Since the ideal order has process #1 to be executed firstly, the calling ordered is changed, i.e., the first element has to be
pushed to the last place. Changing the position of the element takes 1 unit of time. The new calling order is: 2 - 1 - 3. Time taken in step
#1: 1.

Iteration #2: Since the ideal order has process #1 to be executed firstly, the calling ordered has to be changed again, i.e., the first 
element has to be pushed to the last place. The new calling order is: 1 - 3 - 2. Time taken in step #2: 1.

Iteration #3: Since the first element of the calling order is same as the ideal order, that process will be executed. And it will be thus 
popped out. Time taken in step #3: 1.

Iteration #4: Since the new first element of the calling order is same as the ideal order, that process will be executed. Time taken in step
#4: 1.

Iteration #5: Since the last element of the calling order is same as the ideal order, that process will be executed. Time taken in step #5:
1.

Total time taken: 5 units.

PS: Executing a process takes 1 unit of time. Changing the position takes 1 unit of time.

Input format:
The first line a number N, denoting the number of processes. The second line contains the calling order of the processes. The third line 
contains the ideal order of the processes.

Output format:
Print the total time taken for the entire queue of processes to be executed.

Constraints: 
1<=N<=100

SAMPLE INPUT 
3
3 2 1
1 3 2
SAMPLE OUTPUT 
5

*/

#include "stdafx.h"
#include <iostream>
using namespace std;

class Queue {
private:
	int size;
	int *arr;
	int front;
	int rear;
public:
	Queue(int n) {
		size=n;
		arr=new int[size];
		front = -1;
		rear = -1;
	}
	bool isEmpty() {
		if(front == -1) 
			return true;
		else 
			return false;
	}
	bool isFull() {
		if((front == 0 && rear== size-1) || (front==rear+1) )
			return true;
		else
			return false;
	}
	void push(int el) {
		if(!isFull()) {
			if(front==-1)
				front =0;
			rear = (rear+1)%size;
			arr[rear]=el;
		}
		else
			cout<<"overflow\n";
	}
	int pop() {
		int temp;
		if(!isEmpty()) {
			temp = arr[front];
			if(front == rear) 
				front=rear=-1;
			else
				front = (front+1)%size;
			return temp;
		}
		else {
			cout<<"underflow\n";
			return -1;
		}

	}
	void display() {
		int i;
		if(!isEmpty()) {
			for(i=front;i!=rear;i=(i+1)%size) {
				cout<<arr[i]<<"  ";
			}
			cout<<arr[i]<<endl;
		}
		else
			cout<<"list is empty\n"<<endl;
	}
	int ffront() {
		return arr[front];
	}
};




int _tmain(int argc, _TCHAR* argv[])
{
	int time=0;
	int size,temp;
	cin>>size;
	Queue q(size);
	int *idealOrder= new int[size];
	for(int i=0;i<size;i++) {
		cin>>temp;
		q.push(temp);
	}
	for(int i=0;i<size;i++) {
		cin>>idealOrder[i];
	}
	for(int i=0;i<size;i++) {
		while(q.ffront()!=idealOrder[i]) {
			temp=q.pop();
			q.push(temp);
			time++;
		}
		time++;
		q.pop();
	}
		
	cout<<time<<endl;

	system("pause");
	return 0;
}

