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

	string getName(){
		return name;
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
		cout<<"Navbatga muvafaqqiyatli qo'shildingiz!"<<endl;
	}

	void printBolim(){
		bank.print();
		cout<<"----------------------------------------------"<<endl;
	}

	void addBolim(string bolim){
		bank.add(bolim);
		cout<<"Bo'lim muvafaqqiyatli qo'shildi!"<<endl;
		
	}

	
	void getSize(){
		cout<<navbat.size()<<endl;
	}

	void servise(){
		for(int i=0;i<navbat.size(); i++){
			if(!navbat.at(i).empty()){
				cout<<bank.getAsMap().at(i+1)<<" => "<<navbat.at(i).front().getName()<<" ga hizmat ko'rsatildi. "<<endl;
				navbat.at(i).pop();
			}
		}
		cout<<"----------------------------------------------"<<endl;
	}

	void getInfo();
	void getInfo(int bolim);
};



int main(){
	Bank tbc;
	map<int, string> data;
	data[1] = "Bank bolimlari ro'yhati";
	data[2] = "Bolim qo'shish";
	data[3] = "Navbatga yozilish";
	data[4] = "Navbat bo'yicha malumot olish";
	data[5] = "Xizmat ko'rsatish";
	data[6] = "Exit";
	cout<<"--------> TBC bankiga xush kelibsiz! <--------"<<endl;
	cout<<"Mavjud hizmatlar:"<<endl;
	for(auto i : data){
		cout<<setw(3)<<i.first<<". "<<i.second<<endl;
	}
	cout<<"----------------------------------------------"<<endl;
	while (true){
		int n;
		cout<<"Hizmatni tanlang: "; cin>>n;
		cout<<"----------------------------------------------"<<endl;
		if(n == 1){
			tbc.printBolim();
		}
		else if(n == 2){
			cin.ignore();
			string name;
			cout<<"Bolim nomi: "; getline(cin, name);
			tbc.addBolim(name);
			cout<<"----------------------------------------------"<<endl;
		}
		else if(n == 3){
			cin.ignore();
			string name;
			int b;
			cout<<"Name: "; getline(cin, name);
			cout<<"Bolim (int): "; cin>>b;
			tbc.addClient(name, b);
			cout<<"----------------------------------------------"<<endl;
		}
		else if(n == 4){
			cin.ignore();
			int b;
			cout<<"Bolim raqami: "; cin>>b;
			tbc.getInfo();
			tbc.getInfo(b);
		}
		else if(n == 5){
			tbc.servise();
		}
		else if(n == 6){
			cout<<"Bankimiz hizmatlaridan foydalanganingiz uchun tashakkur!"<<endl;
			cout<<"----------------------------------------------"<<endl;
			break;
		}
		else {
			cout<<"Bunday bo'lim mavjud emas"<<endl;
			cout<<"----------------------------------------------"<<endl;
		}
	}
	

	
	
	return 0;
}

void Bank::getInfo(){
	int id = 0;
		cout<<"Navbatlar: "<<endl;
		for(auto b : bank.getAsMap()){
			cout<<setw(3)<<id+1<<". "<<b.second<<": "<<navbat.at(id).size()<<endl;
			id++;
		}
		cout<<endl;
}
void Bank::getInfo(int b){
	string bankName = bank.getAsMap().at(b);
	if(!navbat.at(b-1).empty()){
		cout<<bankName<<" => "<<navbat.at(b-1).front().getName()<<" ga hizmat ko'rsatilmoqda..."<<endl;
	}
	else {
		cout<<bankName<<" => "<<"Navbat bosh"<<endl;
	}
	cout<<"----------------------------------------------"<<endl;
	
}
