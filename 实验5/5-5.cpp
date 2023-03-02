#include <iostream>
#include <iomanip>

using namespace std;

class CStack
{
private:
	
	int *a;
	int size;
	int top;
	
public:
	
	CStack();
	CStack(int s);
	CStack(CStack &r_s);
	int get(int index);
	void push(int n);
	int isEmpty();
	int isFull();
	int pop();
	~CStack();
	
};

CStack::CStack()
{
	a = new int[10];
	size = 10;
	top = 0;
	cout << "Constructor." << endl;
}

CStack::CStack(int s)
{
	a = new int[s];
	size = s;
	top = 0;
	cout << "Constructor." << endl;
}

CStack::~CStack()
{
	delete[] a;
	cout << "Destructor." << endl;
}

int CStack::get(int index)
{
	return a[index];
}

void CStack::push(int n)
{
	if(!isFull()) a[top++] = n;
}

int CStack::pop()
{
	if(!isEmpty()) return a[--top]; 
}

int CStack::isEmpty()
{
	if(top==0) return 1;
	else return 0;
}

int CStack::isFull()
{
	if(top==size) return 1;
	else return 0;
}

int main()
{
	int t;
	cin >> t;
	
	
	int n, inp;
	for(int i=0;i<t;i++)
	{
		CStack stack;
		cin >> n;
		for(int j=0;j<n;j++){
			cin >> inp;
			stack.push(inp);
		}
		for(int j=0;j<n;j++){
			cout << stack.pop();
			if(stack.isEmpty()) cout << endl;
			else cout << ' ';
		}
	}
	
	return 0;
}
