#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Money.h"
using namespace std;


void Money::money()
{
	cout << "					******************************************" << endl;
	cout << "					*  WELCOME TO OUR MONEY CHANGER PROGRAM  *" << endl;
	cout << "					******************************************" << endl;
}

void Money::money2()
{
	cout << "			   ***************************************************************" << endl;
	cout << "		 	   *      SELAMAT DATANG KE PANGATURCARRAN PERTUKARAN MATAWANG  *" << endl;
	cout << "			   ***************************************************************" << endl;
}


void Money::Rm() {
	ofstream out;
	ifstream in;
	out.open("resit.txt");
	
	/*if (out.is_open())
	{
		cout << "exist\n";
	}
	else
	{
		cout << "not exist\n";
	}

	if (in.is_open())
	{
		cout << "exist\n";
	}
	else
	{
		cout << "not exist\n";
	}
*/
	string curren = "Malaysia-Ringgit";//file
	out << curren << endl;
	
tryagain:
	cout << " What is the currency that you want to convert to " << endl;
	cout << " 1: USD " << endl;
	cout << " 2: RM " << endl;
	cout << " 3: Bhat " << endl;
	cout << " Choice:";
	int name;
	cin >> name;
	cout << endl;
	
	if (name == 1) {

		string matawang = "USD";//file
		out << "USD" << endl;
	trynext1:
		cout << " The money you want to convert is from Malaysian Ringgit to "<< matawang << endl;
		cout << " What is the total amount of money that you want to convert " << endl;
		cout << " ( Amount can up to 1000 Malaysian Ringgit per convert )" << endl;
		cout << " Amount:";
		double amount;
		cin >> amount;
		cout << endl;
		cout << endl;
		if (amount >= 100 && amount <= 1000) {

			cout << "Please insert " << amount << " " << "of Malaysian Ringgit that you want to convert" << endl;
			double cvr = 0.24;
			double output = amount * cvr;
			
			cout << "Your conversion money should be: " << output << " " << "USD" << endl;
			out << amount << endl;//file
			out << output << endl;//file

		}
		else if (amount <= 100 || amount >= 1000) {

			cout << "The amount you insert is too small or exceed the maximum amount that you want to convert " << endl;
			cout << endl;
			cout << "please try again with correct amount " << endl;
			cout << endl;
			goto trynext1;
		}
	
		
	}
	else if (name == 2) {

		cout << "You cannot convert the same currency " << endl;
		cout << endl;
		cout << "Please try again " << endl;
		cout << endl;
		goto tryagain;

	}

	else if (name == 3) {

	
		string matawang = "Bhat";
		out << "Bhat" << endl;//file
	trynext2:
		cout << " The money you want to convert is from Malaysian Ringgit to" << " " << matawang << endl;
		cout << " What is the total amount of money that you want to convert " << endl;
		cout << " ( Amount can up to 1000 Malaysian Ringgit per convert )" << endl;
		cout << " Amount:";
		int amount;
		cin >> amount;

		cout << endl;
		if (amount >= 100 && amount <= 1000) {

			cout << "Please insert " << amount << " " << "of Malaysian Ringgit that you want to convert" << endl;
			double cvr = 7.61;
			double output = amount * cvr;
			
			cout << "Your conversion money should be: " << output << " " << "Bhat" << endl;
			out << amount << endl;//file
			out << output << endl;//file
		}
		else if (amount <= 100 || amount >= 1000) {

			cout << "The amount you insert is too small or exceed the maximum amount that you want to convert " << endl;
			cout << endl;
			cout << "please try again with correct amount " << endl;
			cout << endl;
			goto trynext2;
		}

	}
	else {

		cout << "Please select available currency only " << endl;
		cout << endl;
		cout << "Please try again " << endl;
		cout << endl;
		goto tryagain;
	}

	out.close();
}

void Money::Rm1() {
	ofstream out;
	ifstream in;
	out.open("resit.txt");
	string curren = " Ringgit Malaysia ";//
	out << curren;
	cout << endl;
tryagain:
	cout << " Pilih Perturkaran Matawang " << endl;
	cout << " 1: USD " << endl;
	cout << " 2: RM " << endl;
	cout << " 3: Bhat " << endl;
	cout << " Pilihan:";
	int name;
	cin >> name;
	
	string matawang;
	if (name == 1) {

		string matawang = "USD";
		out << "USD" << endl;//
	trynext1:
		cout << "  Matawang yang ingin diktukar: " << matawang << endl;
		cout << " Bilangan Matawang yang ingin ditukar " << endl;
		cout << " ( Mininun 100 dan Maksimun 1000 setiap pertukaran )" << endl;
		cout << " Jumlah:";
		int amount;
		cin >> amount;
		
		cout << endl;
		cout << endl;
		if (amount >= 100 && amount <= 1000) {

			cout << " Masukkan  " << amount << " " << " Ringgit Malaysia yang ingin ditukar" << endl;
			double cvr = 0.24;
			double output = amount * cvr;
			cout << " Jumlah penukaran ialah : " << output << " " << "USD" << endl;
			out << amount << endl;//file
			out << output << endl;//file
		}
		else if (amount <= 100 || amount >= 1000) {

			cout << "Jumlah terlalu kecil or besar " << endl;
			cout << endl;
			cout << " Cuba sekali lagi " << endl;
			cout << endl;
			goto trynext1;
		}

	}
	else if (name == 2) {

		cout << "Penukaran Gagal.... Nilai Matawang sama " << endl;
		cout << endl;
		cout << "Cuba sekali lagi " << endl;
		cout << endl;
		goto tryagain;

	}

	else if (name == 3) {

	
		string matawang = "Bhat";
		out << "Bhat" << endl;//
	trynext2:
		cout << "  Matawang yang ingin diktukar: " << " " << matawang << endl;
		cout << " Bilangan Matawang yang ingin ditukar " << endl;
		cout << " ( Mininun 100 dan Maksimun 1000 setiap pertukaran )" << endl;
		cout << "Jumlah:";
		int amount;
		cin >> amount;
		
		cout << endl;
		if (amount >= 100 && amount <= 1000) {

			cout << " Masukkan " << amount << " " << " Ringgit Malaysia yang ingin ditukar" << endl;
			double cvr = 7.61;
			double output = amount * cvr;
			
			cout << " Jumlah penukaran ialah " << output << " " << "Bhat" << endl;
			out << amount << endl;//file
			out << output << endl;//file
		}
		else if (amount <= 100 || amount >= 1000) {

			cout << "Jumlah terlalu kecil or besar " << endl;
			cout << endl;
			cout << "Cuba sekali lag " << endl;
			cout << endl;
			goto trynext2;
		}

	}
	else {

		cout << "Penukaran Gagal.... Tiada dalam pilihan " << endl;
		cout << endl;
		cout << "Cuba sekali lagi " << endl;
		cout << endl;
		goto tryagain;
	}

	out.close();
}

void Money::USD() {
	ofstream out;
	ifstream in;
	out.open("resit.txt");
	string curren = " Dollar-America ";
	out << curren << ',';
	cout << endl;
tryagain:
	cout << " What is the currency that you want to convert to " << endl;
	cout << " 1: USD " << endl;
	cout << " 2: RM " << endl;
	cout << " 3: Bhat " << endl;
	cout << " Choice:";
	int name;
	cin >> name;
	
	string matawang;
	if (name == 1) {

		cout << "Please select available currency only " << endl;
		cout << endl;
		cout << "Please try again " << endl;
		cout << endl;
		goto tryagain;
	}
	else if (name == 2) {

	
		string matawang = "RM";
		out << "RM" << endl;//
	trynext3:
		cout << " The money you want to convert is from American Dollar to" << " " << matawang << endl;
		cout << " What is the total amount of money that you want to convert " << endl;
		cout << " ( Amount can up to 1000 American Dollar per convert )" << endl;
		cout << " Amount:";
		int amount;
		cin >> amount;
		cout << endl;
		if (amount >= 100 && amount <= 1000) {

			cout << "Please insert " << amount << " " << "of American Dollar that you want to convert" << endl;
			double cvr = 4.19;
			double output = amount * cvr;
			
			cout << "Your conversion money should be: " << "RM" << " " << output << endl;
			out << amount << endl;//file
			out << output << endl;//file
		}
		else if (amount <= 100 || amount >= 1000) {

			cout << "The amount you insert is too small or exceed the maximum amount that you want to convert " << endl;
			cout << endl;
			cout << "please try again with correct amount " << endl;
			cout << endl;
			goto trynext3;
		}

	}

	else if (name == 3) {

	
		string matawang = "Bhat";
		out << "Bhat" << endl;//
	trynext4:
		cout << " The money you want to convert is from American Dollar to" << " " << matawang << endl;
		cout << " What is the total amount of money that you want to convert " << endl;
		cout << " ( Amount can up to 1000 American Dollar per convert )" << endl;
		cout << " Amount:";
		int amount;
		cin >> amount;
		
		cout << endl;
		if (amount >= 100 && amount <= 1000) {

			cout << "Please insert " << amount << " " << "of American Dollar that you want to convert" << endl;
			double cvr = 31.87;
			double output = amount * cvr;
			
			cout << "Your conversion money should be: " << output << " " << "Bhat" << endl;
			out << amount << endl;//file
			out << output << endl;//file
		}
		else if (amount <= 100 || amount >= 1000) {

			cout << "The amount you insert is too small or exceed the maximum amount that you want to convert " << endl;
			cout << endl;
			cout << "please try again with correct amount " << endl;
			cout << endl;
			goto trynext4;
		}
	}
	else {

		cout << "Please select available currency only " << endl;
		cout << endl;
		cout << "Please try again " << endl;
		cout << endl;
		goto tryagain;
	}

	out.close();
}

void Money::USD1() {
	ofstream out;
	ifstream in;
	out.open("resit.txt");
	string curren = " Dollar-America ";//
	out << curren ;
	cout << endl;
tryagain:
	cout << " Pilih Perturkaran Matawang " << endl;
	cout << " 1: RM " << endl;
	cout << " 2: USD " << endl;
	cout << " 3: Bhat " << endl;
	cout << " Pilihan:";
	int name;
	cin >> name;
	
	string matawang;
	if (name == 1) {

	
		string matawang = "RM";
		out << "RM" << endl;//
	trynext1:
		cout << "  Matawang yang ingin diktukar: " << matawang << endl;
		cout << " Bilangan Matawang yang ingin ditukar " << endl;
		cout << " ( Mininun 100 dan Maksimun 1000 setiap pertukaran )" << endl;
		cout << " Jumlah:";
		int amount;
		cin >> amount;
		
		cout << endl;
		cout << endl;
		if (amount >= 100 && amount <= 1000) {

			cout << " Masukkan  " << amount << " " << " USD yang ingin ditukar" << endl;
			double cvr = 0.24;
			double output = amount * cvr;
			
			cout << " Jumlah penukaran ialah : " << "RM" << output << endl;
			out << amount << endl;//file
			out << output << endl;//file
		}
		else if (amount <= 100 || amount >= 1000) {

			cout << "Jumlah terlalu kecil or besar " << endl;
			cout << endl;
			cout << " Cuba sekali lagi " << endl;
			cout << endl;
			goto trynext1;
		}

	}
	else if (name == 2) {

		cout << "Penukaran Gagal.... Nilai Matawang sama " << endl;
		cout << endl;
		cout << "Cuba sekali lagi " << endl;
		cout << endl;
		goto tryagain;

	}

	else if (name == 3) {

	
		string matawang = "Bhat";
		out << "Bhat" << endl;//
	trynext2:
		cout << "  Matawang yang ingin diktukar: " << " " << matawang << endl;
		cout << " Bilangan Matawang yang ingin ditukar " << endl;
		cout << " ( Mininun 100 dan Maksimun 1000 setiap pertukaran )" << endl;
		cout << "Jumlah:";
		int amount;
		cin >> amount;
		
		cout << endl;
		if (amount >= 100 && amount <= 1000) {

			cout << " Masukkan " << amount << " " << " USD yang ingin ditukar" << endl;
			double cvr = 7.61;
			double output = amount * cvr;
			
			cout << " Jumlah penukaran ialah " << output << " " << "Bhat" << endl;
			out << amount << endl;//file
			out << output << endl;//file
		}
		else if (amount <= 100 || amount >= 1000) {

			cout << "Jumlah terlalu kecil or besar " << endl;
			cout << endl;
			cout << "Cuba sekali lag " << endl;
			cout << endl;
			goto trynext2;
		}

	}
	else {

		cout << "Penukaran Gagal.... Tiada dalam pilihan " << endl;
		cout << endl;
		cout << "Cuba sekali lagi " << endl;
		cout << endl;
		goto tryagain;
	}

	out.close();
}

void Money::Bhat() {
	ofstream out;
	ifstream in;
	out.open("resit.txt");
	string curren = " Thai-Bhat ";//
	out << curren << ',';
	cout << endl;
tryagain:
	cout << " What is the currency that you want to convert to " << endl;
	cout << " 1: USD " << endl;
	cout << " 2: RM " << endl;
	cout << " 3: Bhat " << endl;
	cout << " Choice:";
	int name;
	cin >> name;
	string matawang;
	if (name == 3) {

		cout << "You cannot convert the same currency " << endl;
		cout << endl;
		cout << "Please try again " << endl;
		cout << endl;
		goto tryagain;
	}
	else if (name == 2) {

	
		string matawang = "RM";
		out << "RM" << endl;//
	trynext5:
		cout << " The money you want to convert is from Thai Bhat to" << " " << matawang << endl;
		cout << " What is the total amount of money that you want to convert " << endl;
		cout << " ( Amount can up to 1000 Thai Bhat per convert )" << endl;
		cout << " Amount:";
		int amount;
		cin >> amount;
		
		cout << endl;
		if (amount >= 100 && amount <= 1000) {

			cout << "Please insert " << amount << " " << "of Thai Bhat that you want to convert" << endl;
			double cvr = 0.13;
			double output = amount * cvr;
			
			cout << "Your conversion money should be: " << "RM" << " " << output << endl;
			out << amount << endl;//file
			out << output << endl;//file
		}
		else if (amount <= 100 || amount >= 1000) {

			cout << "The amount you insert is too small or exceed the maximum amount that you want to convert " << endl;
			cout << endl;
			cout << "please try again with correct amount " << endl;
			cout << endl;
			goto trynext5;
		}

	}

	else if (name == 1) {

	
		string matawang = "USD";
		out << "USD" << endl;//
	trynext6:
		cout << " The money you want to convert is from Thai Bhat to" << " " << matawang << endl;
		cout << " What is the total amount of money that you want to convert " << endl;
		cout << " ( Amount can up to 1000 Thai Bhat per convert )" << endl;
		cout << " Amount:";
		int amount;
		cin >> amount;
		
		cout << endl;
		if (amount >= 100 && amount <= 1000) {

			cout << "Please insert " << amount << " " << "of Thai Bhat that you want to convert" << endl;
			double cvr = 0.031;
			double output = amount * cvr;
			
			cout << "Your conversion money should be: " << output << " " << "USD" << endl;
			out << amount << endl;//file
			out << output << endl;//file
		}
		else if (amount <= 100 || amount >= 1000) {

			cout << "The amount you insert is too small or exceed the maximum amount that you want to convert " << endl;
			cout << endl;
			cout << "please try again with correct amount " << endl;
			cout << endl;
			goto trynext6;
		}
	}
	else {

		cout << "Please select available currency only " << endl;
		cout << endl;
		cout << "Please try again " << endl;
		cout << endl;
		goto tryagain;
	}
	out.close();
}

void Money::Bhat1() {
	ofstream out;
	ifstream in;
	out.open("resit.txt");
	string curren = " Thai-Bhat ";//
	out << curren << ',';
	cout << endl;
tryagain:
	cout << " Pilih Perturkaran Matawang " << endl;
	cout << " 1: RM " << endl;
	cout << " 2: Bhat " << endl;
	cout << " 3: USD " << endl;
	cout << " Pilihan:";
	int name;
	cin >> name;
	string matawang;
	if (name == 1) {

	
		string matawang = "Bhat";
		out << "RM" << endl;//
	trynext1:
		cout << "  Matawang yang ingin diktukar: " << matawang << endl;
		cout << " Bilangan Matawang yang ingin ditukar " << endl;
		cout << " ( Mininun 100 dan Maksimun 1000 setiap pertukaran )" << endl;
		cout << " Jumlah:";
		int amount;
		cin >> amount;
		
		cout << endl;
		cout << endl;
		if (amount >= 100 && amount <= 1000) {

			cout << " Masukkan  " << amount << " " << " Bhat yang ingin ditukar" << endl;
			double cvr = 0.24;
			double output = amount * cvr;
			
			cout << " Jumlah penukaran ialah : " << "RM " << output  << endl;
			out << amount << endl;//file
			out << output << endl;//file
		}
		else if (amount <= 100 || amount >= 1000) {

			cout << "Jumlah terlalu kecil or besar " << endl;
			cout << endl;
			cout << " Cuba sekali lagi " << endl;
			cout << endl;
			goto trynext1;
		}

	}
	else if (name == 2) {

		cout << "Penukaran Gagal.... Nilai Matawang sama " << endl;
		cout << endl;
		cout << "Cuba sekali lagi " << endl;
		cout << endl;
		goto tryagain;

	}

	else if (name == 3) {

	
		string matawang = "USD";
		out << "USD" << endl;//
	trynext2:
		cout << "  Matawang yang ingin diktukar: " << " " << matawang << endl;
		cout << " Bilangan Matawang yang ingin ditukar " << endl;
		cout << " ( Mininun 100 dan Maksimun 1000 setiap pertukaran )" << endl;
		cout << "Jumlah:";
		int amount;
		cin >> amount;
		
		cout << endl;
		if (amount >= 100 && amount <= 1000) {

			cout << " Masukkan " << amount << " " << " Bhat yang ingin ditukar" << endl;
			double cvr = 7.61;
			double output = amount * cvr;
			
			cout << " Jumlah penukaran ialah " << output << " " << "USD" << endl;
			out << amount << endl;//file
			out << output << endl;//file
		}
		else if (amount <= 100 || amount >= 1000) {

			cout << "Jumlah terlalu kecil or besar " << endl;
			cout << endl;
			cout << "Cuba sekali lag " << endl;
			cout << endl;
			goto trynext2;
		}

	}
	else {

		cout << "Penukaran Gagal.... Tiada dalam pilihan " << endl;
		cout << endl;
		cout << "Cuba sekali lagi " << endl;
		cout << endl;
		goto tryagain;
	}

	out.close();
}