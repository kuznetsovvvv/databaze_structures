#include"Functions.h"

void DataEntry(Data* (&d), int& n) {
	cout << "Enter number of data: ";
	cin >> n;
	d = new Data[n];

	for (size_t i = 0; i < n; i++)
	{
		cout << "Enter surname: ";
		cin >> d[i]._initial.surname;
		cout << "Enter patronymic: ";
		cin >> d[i]._initial.patronymic;
		cout << "Enter name: ";
		cin >> d[i]._initial.name;

		cout << "Enter day: ";
		cin >> d[i]._date.day;
		cout << "Enter month: ";
		cin >> d[i]._date.month;
		cout << "Enter year: ";
		cin >> d[i]._date.year;

		cout << "Enter city: ";
		cin >> d[i]._address.city;
		cout << "Enter number of home: ";
		cin >> d[i]._address.home;

		cout << "___________________________________" << endl;
	}
}


void ReadingData(Data* (&d), int& n, string filename) {
	ifstream reading(filename);

	if (reading) {
		reading >> n;

		d = new Data[n];

		for (int i = 0; i < n; i++)
		{
			reading >> d[i]._initial.surname;
			reading >> d[i]._initial.patronymic;
			reading >> d[i]._initial.name;

			reading >> d[i]._date.day;
			reading >> d[i]._date.month;
			reading >> d[i]._date.year;

			reading >> d[i]._address.city;
			reading >> d[i]._address.home;
		}
		cout << "Data read!" << endl;
	}
	else {
		cout << "Error wirh opening file!" << endl;
	}

	reading.close();

}


void Print(Data* d, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "Data about №" << i + 1 << ":" << endl;

		cout << "FIO: " << d[i]._initial.surname << " " << d[i]._initial.name << " " << d[i]._initial.patronymic << endl;
		cout << "Date: " << d[i]._date.day << " " << d[i]._date.month << " " << d[i]._date.year << endl;
		cout << "Adress: " << d[i]._address.city << " " << d[i]._address.home<< endl;

		cout << "___________________________________" << endl;
	}

}


void DataChange(Data* (&d), int n) {
	int _n;
	cout << "Enter number of element (from 2 to " << n << "):";
	cin >> _n;
	_n--;
	system("cls");
	if (_n >= 0 && _n < n) {
		cout << "Enter FIO: ";
		cin >> d[_n]._initial.surname;
		cin >> d[_n]._initial.patronymic;
		cin >> d[_n]._initial.name;

		cout << "Enter Date: ";
		cin >> d[_n]._date.day;
		cin >> d[_n]._date.month;
		cin >> d[_n]._date.year;

		cout<< "Enter Adress: ";
		cin >> d[_n]._address.city;
		cin >> d[_n]._address.home;

		system("cls");
		cout << "The data has changed!" << endl;
	}
	else {
		cout << "Number has writen incorrectly!\n";
	}
}



void DeleteData(Data* (&d), int& n) {
	int _n;
	cout << "Enter number of element (from 2 to " << n << "):";
	cin >> _n;
	_n--;
	system("cls");

	if (_n >= 0 && _n < n) {
		Data* buf = new Data[n];

		Copy(buf, d, n);// копируем из d в buf
		--n;
		d = new Data[n];
		int q = 0;
		for (int i = 0; i < n; i++)
		{
			if (i != _n) {
				d[q] = buf[i];
				q++;
			}
		}
		system("cls");
		delete[] buf;
		cout << "Number " << _n << " has deleted from data!\n";
	}
	else {
		cout << "Number has written incorrectly!" << endl;
	}

}


void Copy(Data* (&d_n), Data* (&d_o), int n) {
	for (int i = 0; i < n; i++)
	{
		d_n[i] = d_o[i];
	}


}

void Copy(Data& d_n, Data& d_o) { // copy 1 element
	d_n._initial.surname = d_o._initial.surname;
	d_n._initial.patronymic = d_o._initial.patronymic;
	d_n._initial.name = d_o._initial.name;

	d_n._date.day = d_o._date.day;
	d_n._date.month = d_o._date.month;
	d_n._date.year = d_o._date.year;

	d_n._address.city = d_o._address.city;
	d_n._address.home = d_o._address.home;
}


void AddDate(Data* (&d), int& n) {
	Data* buf = new Data[n];
	Copy(buf, d, n);// копируем из d в buf

	n++;
	d = new Data[n];
	Copy(d, buf, --n);
	cout << "Enter surname: ";
	cin >> d[n]._initial.surname; 
	cout << "Enter patronymic: ";
	cin >> d[n]._initial.patronymic;
	cout << "Enter name: ";
	cin >> d[n]._initial.name;

	cout << "Enter day: ";
	cin >> d[n]._date.day;
	cout << "Enter month: ";
	cin >> d[n]._date.month;
	cout << "Enter year: ";
	cin >> d[n]._date.year;

	cout << "Enter city: ";
	cin >> d[n]._address.city;
	cout << "Enter number of home: ";
	cin >> d[n]._address.home;

	system("cls");

	cout << "Data added!\n";
	delete[] buf;

}


void DataSorting(Data* d, int n) {
	Data buf;

	for (int i = 0; i < n; i++)
	{
		for (int j =i+1; i < n; i++)
		{
			if (d[i]._initial.surname>d[j]._initial.surname) {
				Copy(buf, d[j]);
				Copy(d[j], d[i]);
				Copy(d[i],buf);
			}
		}
	}
	cout << "Data sorted!\n";
}


void SavingData(Data* d, int n, string filename) {
	ofstream record(filename, ios::out);
	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++)
		{
			record << d[i]._initial.surname << endl;
			record << d[i]._initial.name << endl;
			record << d[i]._initial.patronymic << endl;

			record << d[i]._date.day << " ";
			record << d[i]._date.month << " ";
			record << d[i]._date.year <<endl;

			record << d[i]._address.city << " ";
			if (i < n - 1)
				record << d[i]._address.home << endl;
			else
				record << d[i]._address.home;
		}


	}
	else 
		cout << "Error with opening file!" << endl;
	
	
		record.close();

}