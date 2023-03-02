#include <iostream>
#include <string>
using namespace std;

struct Info{
	string name;
	string term;
	string oper;
	string caiss;
	string valid;
	string cardnum;
	string trad;
	string costs;
};

int main()
{
	int t;
	cin >> t;
	Info infos[10];
	for(int i=0;i<t;i++)
	{
		cin >> infos[i].name >> infos[i].term >> infos[i].oper >> infos[i].caiss;
		cin >> infos[i].valid >> infos[i].cardnum;
		cin >> infos[i].trad >> infos[i].costs;
	}
	for(int i=0;i<t;i++)
	{
		cout << "Name: " << infos[i].name << endl;
		cout <<	"Terminal: " << infos[i].term << ' ' << "operator: " << infos[i].oper << endl;
		cout << "Card Issuers: " << infos[i].caiss << " ";
		cout << "Validity: " << infos[i].valid << endl;
		cout << "CardNumber: ";
		cout << infos[i].cardnum.substr(0,4) << "********" << infos[i].cardnum.substr(12,4) << endl;
		cout << "Traded: " << infos[i].trad << endl;
		cout << "Costs: $" << infos[i].costs << endl;
		cout << endl;
	}
	
	
	return 0;
}
