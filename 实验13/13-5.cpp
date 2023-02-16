#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class CXGraph
{
private:
	int n;
public:
	CXGraph(int nn);
	friend ostream& operator<<(ostream& os, const CXGraph& cxg);
	CXGraph& operator++();
	const CXGraph operator++(int);
	CXGraph& operator--();
	const CXGraph operator--(int);	
};

CXGraph::CXGraph(int nn) { n = nn;}

CXGraph& CXGraph::operator++()
{
	if(n<21) n += 2;
	return *this;
}

const CXGraph CXGraph::operator++(int)
{
	CXGraph cxg(n);
	if(n<21) n += 2;
	return cxg;
}

CXGraph& CXGraph::operator--()
{
	if(n>1) n -= 2;
	return *this;
}

const CXGraph CXGraph::operator--(int)
{
	CXGraph cxg(n);
	if(n>1) n -= 2;
	return cxg;
}

ostream& operator<<(ostream& os, const CXGraph& cxg)
{
	for(int i=0;i<cxg.n/2;i++)
	{
		for(int j=0;j<i;j++)
		{
			os << " ";
		}
		for(int j=0;j<cxg.n-2*i;j++)
		{
			os << "X";
		}
		os << endl;
	}
	for(int i=cxg.n/2;i>=0;i--)
	{
		for(int j=0;j<i;j++)
		{
			os << " ";
		}
		for(int j=0;j<cxg.n-2*i;j++)
		{
			os << "X";
		}
		os << endl;
	}
	return os;
}

int main()
{
	int t, n;
	string command;
	cin >> n;
	CXGraph xGraph(n);
	cin >> t;
	while (t--)
	{
		cin >> command;
		if (command == "show++")
		{
			cout << xGraph++ << endl;
		}
		else if(command == "++show")
		{
			cout << ++xGraph << endl;
		}
		else if (command == "show--")
		{
			cout << xGraph-- << endl;
		}
		else if (command == "--show")
		{
			cout << --xGraph << endl;
		}
		else if (command == "show")
		{
			cout << xGraph << endl;
		}
	}
	return 0;
}
