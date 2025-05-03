#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

class Bolim{
	set<string> bolimlar = {"Kredit", "Depozit", "Valyuta ayirboshlash", "Hisob-kitob", "Moliyaviy maslahat"};
	
	public:
	Bolim(){}

	void add(string bolim){
		if(!bolimlar.count(bolim)){
			bolimlar.insert(bolim);
		}
		else{
			cout<<"Bunday bo'lim mavjud."<<endl;
		}
	}

	void print(){
		int i = 1;
		cout<<"Bolimlar:"<<endl;
		for(string b : bolimlar){
			cout<<setw(3)<<i<<". "<<b<<endl;
			i++;
		}
	}

	int getSize(){
		return bolimlar.size();
	}

	map<int, string> getAsMap(){
		map<int, string> result;
		int i = 1;
		for(string b : bolimlar){
			result[i] = b;
			i++;
		}
		return result;
	}
};

class Client{
	string name;
	int bolim_id;
	public:
	Client(string name, int id){
		this->name = name;
		this->bolim_id = id;
	}

	
};

class Bank{
	Bolim bank;
	vector<queue<Client>> navbat;
	public:
	Bank(){
		for(int i=0;i<10;i++){
			navbat.push_back({});
		}
	}

	void addClient(string name, int id){
		navbat.at(id-1).push(Client(name, id));
	}

	void printBolim(){
		bank.print();
	}

	void addBolim(string bolim){
		bank.add(bolim);
	}

	
	void getSize(){
		cout<<navbat.size()<<endl;
	}
	void getInfo();
};



int main(){
	// Bolim bank;
	// bank.add("Kassa");
	// bank.print();
	// cout<<endl;
	Bank tbc;
	tbc.addBolim("Kassa");
	tbc.printBolim();
	tbc.addClient("Mustafo", 1);
	tbc.addClient("Mustafo", 3);
	tbc.getInfo();


	// while (true)1
	// {
	// 	bool sorov;
	// 	cout<<"Navbatga yozilashni xohlaysizmi? (1/0): ";
	// 	cin>>sorov;
	// 	if(sorov){
	// 		// string name; cout<<"Ism: "; getline(cin, name);
	// 		// int id; cout<<"Bolim (index): "; cin>>id;
	// 		tbc.addClient("Mustafo", 1);
	// 	}
	// 	else{
	// 		break;
	// 	}
	// }
	
	
	return 0;
}

void Bank::getInfo(){
	int id = 0;
		cout<<"Navbatlar: "<<endl;
		for(auto b : bank.getAsMap()){
			cout<<setw(3)<<id+1<<". "<<b.second<<": "<<navbat.at(id).size()<<endl;
			id++;
		}
}
