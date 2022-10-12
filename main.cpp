#include<iostream>
using namespace std;
#define MAX 8

struct Antrian {
    int data[MAX];
    int head;
    int tail;
};

Antrian antre;
void clearQ();
bool isEmpty();
bool isFull();
void enqueue();
int dequeue();
void tampil();
void menu();

int main(){
    menu();
    return 0;
}

void menu(){
int menu;
    cout << "==============================" << endl;
    cout << "1. Masukan data pada queue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Tampil data data pada queue" << endl;
    cout << "4. Hapus queue" << endl;
    cout << "==============================" << endl;
    cin >> menu;
    if(menu == 1){
        enqueue();
    }
    else if(menu == 2){
        cout << dequeue();
    }
    else if (menu == 3) {
        tampil();
    }
    else if (menu == 4){
        clearQ();
    }
}

void clearQ(){
    antre.head = antre.tail =-1;
    menu();
}

bool isEmpty(){
    if(antre.tail == -1){
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(){
    if(antre.tail == MAX - 1){
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(){
    int data;

    if(isEmpty()){
        cin >> data;
        antre.tail = antre.head = 0;
        antre.data[antre.tail] = data;
        antre.head = data;
    }
    else
    {
        cin >> data;
        antre.tail++;
        antre.data[antre.tail] = data;
        antre.head = antre.data[antre.head];
    }
    cout<< data <<" dimasukkan ke antrian" << endl;
    menu();
}

int dequeue(){
    int i;
    int e = antre.data[antre.head+1];
    for(i = antre.head;i < antre.tail;i++){
        antre.data[i] = antre.data[i+1];
    }
    for (i = antre.head+1; i < antre.tail; i++){
        cout << antre.data[i] << " ";
    }
    antre.tail--;
    cout << "Angka yang keluar adalah " << e << endl;;
    menu();
}

void tampil(){
    if(!isEmpty()){
        for(int i = antre.head+1;i <= antre.tail;i++){
            cout<<antre.data[i] << " ";
        }
        cout << endl;
        menu();
    }
    else{
        cout<<"data kosong";
    }
}
