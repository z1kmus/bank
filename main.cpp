#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
using namespace std;

class Bolim{
	set<string> bolimlar = {"Kassa", "Hisob-kitob", "Kredit", "Depozit", "Valyuta ayirboshlash"};
public:
	Bolim(){}

	void print(){
		int i = 1;
		cout<<"Bolimlar:"<<endl;
		for(string b : bolimlar){
			cout<<setw(4)<<i<<". "<<b<<endl;
			i++;
		}
	}

	map<string, int> getMap(){
		map<string, int> mBolimlar;
		int t = 1;
		for(string b : bolimlar){
			mBolimlar[b] = t;
			t++;
		}
		return mBolimlar;
	}
};

class Client{
	string name;
	int bolim;
public:
	Client(string name, int bolim){
		this->name = name;
		this->bolim = bolim;
	}
};

class Bank{
	queue<Client> dN;
	queue<Client> hN;
	queue<Client> kaN;
	queue<Client> krN;
	queue<Client> vN;
	
	public:
	Bank(){}

	void add(string name, int bolim){
		switch (bolim){
		case 1:
			dN.push(Client(name, bolim));
			break;
		case 2:
			hN.push(Client(name, bolim));
			break;
		case 3:
			kaN.push(Client(name, bolim));
			break;
		case 4:
			krN.push(Client(name, bolim));
			break;
		case 5:
			vN.push(Client(name, bolim));
			break;
		default:
			break;
		}
	}
};

void printM(map<string, int> bolimlar){
	for(auto bolim : bolimlar){
		cout<<bolim.first<<setw(3)<<bolim.second<<endl;
	}
}

int main(){
	Bolim bank;
	bank.print();
	Bank agrobank;
	agrobank.add("Mustafo", 1);
}