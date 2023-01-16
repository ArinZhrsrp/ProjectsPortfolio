
#include <iostream>
#include <string>
#include <fstream>
#include "Money.h"
using namespace std;


struct language
{
	int language;
	int currency;
};

struct resit

{
	char nama[50];
	char matawang[10];
	double jumlah;
	double kuar;
};

resit receiptE()
{
	system("cls");
	resit rE;
	ifstream in;
	in.open("resit.txt");
	
		in >> rE.nama >> rE.matawang >> rE.jumlah >> rE.kuar;

		cout << "Currency selected: " << rE.nama << endl;
		cout << "Convert money to: " << rE.matawang << endl;
		cout << "Initial amount: " << rE.jumlah << endl;
		cout << "Converted money: " << rE.kuar << endl;
	
		return rE;
	in.close();
	
}

resit receiptM()
{	
	system("cls");
	resit rM;
	ifstream in;
	in.open("resit.txt");
	
	in >> rM.nama >> rM.matawang >> rM.jumlah >> rM.kuar;

	cout << "Matawang dipilih: " << rM.nama << endl;
	cout << "Tukar matawang ke: " << rM.matawang << endl;
	cout << "Nilai asal: " << rM.jumlah << endl;
	cout << "Nilai yang telah ditukar: " << rM.kuar << endl;

	return rM;
}
 
language show();

int main() {
	Money mon;
	
	 language l;
	
	 l = show();
	
		if (l.language == 1)
		{	
			system("cls");
;
			mon.money();
			cout << "Please select your currency : " << endl;
		tryagain:
			cout << " 1: if Malaysian Ringgit " << endl;
			cout << " 2: if American Dollar " << endl;
			cout << " 3: if Thai Bhat " << endl;
			cout << " Choice:";
			cin >> l.currency;

			cout << endl;
			if (l.currency == 1) {
				system("cls");
				cout << "					******************************************" << endl;
				cout << "					*     You Have Chosen Malaysian Ringgit  *" << endl;
				cout << "					******************************************" << endl;
				cout << endl;
				mon.Rm();
			}
			else if (l.currency == 2) {
				system("cls");
				cout << "					******************************************" << endl;
				cout << "					*     You Have Chosen American Dollar    *" << endl;
				cout << "					******************************************" << endl;
				cout << endl;
				mon.USD();
			}
			else if (l.currency == 3) {
				system("cls");
				cout << "					******************************************" << endl;
				cout << "					*          You Have Chosen Thai Bhat     *" << endl;
				cout << "					******************************************" << endl;
				cout << endl;
				mon.Bhat();
			}
			else
			{
				cout << endl;
				cout << "Please select availabe currency only " << endl;
				cout << endl;
				goto tryagain;

			}
			
		}
		else if (l.language == 2)
		{
			system("cls");
			mon.money2();
			cout << "Pilih Mata Wang : " << endl;
		again:
			cout << " 1: Jika Malaysia Ringgit " << endl;
			cout << " 2: Jika America Dollar " << endl;
			cout << " 3: Jika Thai Bhat " << endl;
			cout << " Pilih:";
			cin >> l.currency;
			cout << endl;
			if (l.currency == 1) {
				system("cls");
				cout << "					******************************************" << endl;
				cout << "					*     Anda Telah Pilih Malaysia Ringgit  *" << endl;
				cout << "					******************************************" << endl;
				cout << endl;
				mon.Rm1();
			}
			else if (l.currency == 2) {
				system("cls");
				cout << "					******************************************" << endl;
				cout << "					*     Anda Telah Pilih America Dollar    *" << endl;
				cout << "					******************************************" << endl;
				cout << endl;
				mon.USD1();
			}
			else if (l.currency == 3) {
				system("cls");
				cout << "					******************************************" << endl;
				cout << "					*          Anda Telah Pilih Thai Bhat     *" << endl;
				cout << "					******************************************" << endl;
				cout << endl;
				mon.Bhat1();
			}
			else
			{
				cout << endl;
				cout << "Sila masukkan nombor yang diberi " << endl;
				cout << endl;
				goto again;

			}
		}
		
	char yes_no;
    cout << "Do you have any other transaction(Y/N) : ";
    cin >> yes_no;

    if(yes_no == 'Y' || yes_no == 'y')
    {
        goto tryagain;
    }
    else if (yes_no == 'N' || yes_no == 'n')
    {
        if (l.language == 1)
		{
			resit r;
			r = receiptE();
		}
		else if (l.language == 2)
		{
			resit r;
			r = receiptM();
		}
	}
	
	return 0;
}

language show()
{
	language l;
	cout << "					Please select your language." << endl;
	cout << "					1.Bahasa Inggeris \n					2.Bahasa Melayu " << endl << endl;
	cout << "					LANGUAGE:";
	cin >> l.language;
	return l;
}


