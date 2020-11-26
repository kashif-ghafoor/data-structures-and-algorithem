
#include <stack>
#include <iostream> 
using namespace std;

void HeightOfCylinder(int *h,stack<int> s[]) {//to calculate the height of towers
	
	for(int i=0;i<3;i++) {
		int sum=0;
		stack<int> temp=s[i];//temporary stack 
		while(!temp.empty()) {
			sum+=temp.top();
			temp.pop();
		}
		*(h+i)=sum;//assigning the caluclted height of respected tower
	}

}
int main() {
	stack<int> s[3];//store towers
	int h[3];//store the heights of three towers
	int n[3];//store the number of cylinder in each tower
	cout<<"enter the input with same pattern given in problem"<<endl;
	int input;
	cin>>n[0]>>n[1]>>n[2];
	for (int i = 0; i < n[0]; i++){//filling tower1 with cylinders
		cin>>input;
		s[0].push(input);
	}
	for (int i = 0; i < n[1]; i++)	{//filling tower2 with cylinders
		cin>>input;
		s[1].push(input);
	}
	for (int i = 0; i < n[2]; i++)	{//filling tower3 with cylinders
		cin>>input;
		s[2].push(input);
	}
	for (int i = 0; i < 3; i++) {//this loop is to reverse the three stacks 
		//for the purpose to maintain the pattern of input in given probem
		stack<int> temp=s[i];
		while(!s[i].empty()) {
			s[i].pop();
		}
		for (int j = 0; j < n[i]; j++) {
			s[i].push(temp.top());
			temp.pop();
		}
	}
	HeightOfCylinder(h,s);//calculating the height of each tower
	while(!(h[0]==h[1]&&h[0]==h[2])) {//logic to solve the given problem is in this loop
			if(h[0]>=h[1]&&h[0]>=h[2]) {
				h[0]=h[0]-s[0].top();
				s[0].pop();
			}
			 else if(h[1]>=h[0]&&h[1]>=h[2]) {
				h[1]=h[1]-s[1].top();
				s[1].pop();
			}
			else if(h[2]>=h[0]&&h[2]>=h[1]) {
				h[2]=h[2]-s[2].top();
				s[2].pop();
			}
	}
	cout<<"output"<<endl;
	cout<<h[0]<<endl;//showing output at console
	return 0;
}

