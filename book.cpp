#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
  
	// Choose the pivot
	int pivot = arr[high];
 
	// Index of smaller element and indicates 
	// the right position of pivot found so far
	int i = low - 1;

	// Traverse arr[low..high] and move all smaller
	// elements on left side. Elements from low to 
	// i are smaller after every iteration
	for (int j = low; j <= high - 1; j++) {
		 if (arr[j] < pivot) {
			  i++;
			  swap(arr[i], arr[j]);
		 }
	}
	
	// Move pivot after smaller elements and
	// return its position
	swap(arr[i + 1], arr[high]);  
	return i + 1;
}

// The QuickSort function implementation
void quickSort(vector<int>& arr, int low, int high) {
 
	if (low < high) {
	  
		 // pi is the partition return index of pivot
		 int pi = partition(arr, low, high);

		 // Recursion calls for smaller elements
		 // and greater or equals elements
		 quickSort(arr, low, pi - 1);
		 quickSort(arr, pi + 1, high);
	}
}

class Book{
	string name, author;
	int year;
	public:
	Book(string name, string author, int year){
		this->name = name;
		this->author = author;
		this->year = year;
	}
	string getName(){return name;}
	string getAuthor(){return author;}
	int getYear(){return year;}

	void print(){
		cout<<"Name: "<<name<<endl;
		cout<<"Author: "<<author<<endl;
		cout<<"Year: "<<year<<endl;
	}
};
class Bookshelf{
	stack<Book> shelf;
	map<int, string> dic;
	vector<int> years;
	public:
	Bookshelf(){}

	void add(string name, string author, int year){
		shelf.push(Book(name, author, year));
		years.push_back(year);
		dic[year] = name;
	}
	void printInfo(){
		if(!shelf.empty()){
			shelf.top().print();
		}
	}

	int getNumOfBooks(){
		return shelf.size();
	}

	bool isEmpty(){
		if(shelf.empty()){
			return true;
		}else{
			return false;
		}
	}

	void getByYear(){
		quickSort(years, 0, years.size()-1);
		for(int y : years){
			cout<<y<<" "<<'"'<<dic.at(y)<<'"'<<endl;
		}
	}
};

int main(){
	Bookshelf a;
	a.add("To Live", "Yu Xua", 1993);
	a.add("One Flew over the Cuckoos Nest", "Ken Kesey", 1965);
	a.add("1984", "Jorg Oruel", 1948);
	a.printInfo();
}
