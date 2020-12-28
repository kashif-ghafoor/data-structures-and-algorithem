// Lab08.cpp : Defines the entry point for the console application.
//Lab08_Kashif_Ghafoor

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

