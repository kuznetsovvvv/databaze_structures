


#include"Functions.h"
int _stateMenu;

void Menu() {
    cout << "Enter the action:" << endl;
    cout<< "(0) Exit program." << endl;
    cout<< "(1) Enter data." << endl;
    cout<< "(2) Output data." << endl;
    cout<< "(3) Change data." << endl;
    cout<< "(4) Delete data." << endl;
    cout<< "(5) Add data." << endl;
    cout<< "(6) Sorting." << endl;
    cout<< "(7) Save data." << endl;
    cout << "Your choice: ";
    cin >> _stateMenu;
} 

int main()
{
    setlocale(LC_ALL, "RU");
    Menu();

    int _actions,
        amountOfData = 0;
    string filename;

    Data* d = new Data[amountOfData];

    while (_stateMenu != 0) {
        switch (_stateMenu) {
        case 1:
            system("cls");

            cout << "Enter data from file or manually?(1-manually;another number - from file): ";
            cin >> _actions;

            system("cls");

            if (_actions == 1) {
                DataEntry(d, amountOfData);
            }
            else {
                ReadingData(d, amountOfData, "Input.txt");
            }


            system("pause");
            system("cls");
            Menu();
            break;

        case 2:
            system("cls");

            if (amountOfData!=0)
            {
                Print(d, amountOfData);
            }
            else {
                cout << "Data is clear!" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;

        case 3:
            system("cls");

            if (amountOfData != 0) {
                DataChange(d, amountOfData);
            }
            else {
                cout << "Data is empty!" << endl;
            }

            system("pause");
            system("cls");
            Menu();
            break;
        case 4:
            system("cls");
            if (amountOfData != 0) {
                DeleteData(d, amountOfData);
            }
            else {
                cout << "Data is empty!" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;

        case 5:
            system("cls");

            if (amountOfData != 0) {
                AddDate(d, amountOfData);
                amountOfData++;
            }
            else {
                cout << "Data is empty!";
            }

            system("pause");
            system("cls");
            Menu();
            break;


        case 6:
            system("cls");

            if (amountOfData != 0) {
                DataSorting(d, amountOfData);
            }
            else {
                cout << "Data is empty!" << endl;
            }

            system("pause");
            system("cls");
            Menu();
            break;
        case 7:
            system("cls");
            cout << "Enter name of file: ";
            cin >> filename;

            if (amountOfData != 0) {
                SavingData(d, amountOfData, filename);

            }
            else
                cout << "Data is empty!" << endl;

            system("pause");
            system("cls");
            Menu();
            break;
        default:
            cout << "Incorrect number of action!" << endl;
            system("pause");
            system("cls");
            Menu();
            break;
        }

    }



    delete[] d;

    return 0;
}


