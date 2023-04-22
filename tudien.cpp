#include<iostream>
#include<fstream>
#include<string>
#include<unistd.h>

using namespace std;

typedef struct Tuvung {
	string english;
	string tieng_viet;
}TuVung;

typedef struct Node {
	TuVung info;
	struct Node* next;
}NODE;
typedef NODE* NODEPTR;

void Init(NODEPTR &pHead);
void Input(TuVung &x, ifstream input);
void Output(TuVung x);
NODEPTR CreateNode(TuVung x);
void Insert_First(NODEPTR &pHead, TuVung x);
void Show_List(NODEPTR pHead);


int main(){
	ifstream input;
	TuVung Tuvung;
	NODEPTR pHead;
	input.open("tudien.txt");
	int chon;
	if (input.is_open()){
		cout << "Mo thanh cong !!!" << endl;
		sleep(1);
		system("cls");
		do {
			Init(pHead);
			Input(Tuvung,input);	
			cin.ignore();
			Insert_First(pHead,Tuvung);
			cout << "Muon nhap tiep chu ?? (so 0 de dung nhap lieu, 1 de tiep tuc) "<< endl;	
			cin >> chon;
		}while(chon != 0);
		Show_List(pHead);
		
	} else {
		cout << "Mo that bai !!!" << endl;
	}
	return 0;
}

void Init(NODEPTR &pHead){
	pHead = NULL;
}

void Input(TuVung &x, ifstream input){
	input >> x.english;
	input >> x.tieng_viet;
}

void Output(TuVung x){
	cout << x.english << ": " << x.tieng_viet << endl;
}

NODEPTR CreateNode(TuVung x){
	NODEPTR newNode = new NODE;
	newNode->info = x;
	newNode->next = NULL;
	return newNode;
}

void Insert_First(NODEPTR &pHead, TuVung x){
	NODEPTR newNode = CreateNode(x);
	newNode->next = pHead;
	pHead = newNode;
}

void Show_List(NODEPTR pHead){
	NODEPTR current;
	while (current != NULL){
		Output(current->info);
		current = current->next;
	}
}
