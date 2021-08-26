#include<iostream>
#include<io.h>
#include <fstream>

#include <fcntl.h>
#include <clocale>
#include <windows.h>
#include <codecvt>
#include <ctime>
#include<cmath>
#include <string>
#include "modulesivanenko.h"

using namespace std;

void dev_information()
{
    cout << " ----------------------------------------------------------------------------" << endl;
    cout << "| Даний застосунок розроблено студентом центральноукраїнського нацiонального |" << endl;
    cout << "| технiчного унiверситету Іваненко Максимом Олеговтчем.                      |" << endl;
    cout << " ---------------------------©ALL_RIGHTS_ARE_RESERVED-------------------------" << endl;
}
int main()
{
    system("chcp 1251 & cls");
    dev_information();
    string vowels;
    string word;
    string str;
    char check;
    while(true) {
        cout << "Щоб дiзнатися чи є буква iз вхiдного файлу у вихiдному , натиснiть t; " << endl;
        cout << "Щоб дозаписати у файл, натиснiть l; " << endl;
        cout << "Щоб перевести число у двiйкову систему, натиснiть g; " << endl;
        cout << "Щоб викликати функцiю s_calculation, натиснiть j; " << endl;
        cout << "Щоб завершити роботу, натиснiть f. " << endl;
        cout << "Ваша команда --> ";
        cin >> check;

        switch(check) {
        case 't': {
            checkingFile();
            ifstream op;
            string line = "";

            op.open("inputText.txt");
            op>>line;
            op.close();
            string text = "До щастя не пускає лінощів орава\nУ чім воно - ніхто не знає до пуття.\nНавчитись радісно робити кожну справу -\nНайперше правило щасливого життя.\n";
            ofstream output;
            string vowels;
            for (int i = 0; text[i]; i++) {
                if (text[i] == 224 || text[i] == '229' || text[i] == 232 || text[i] == 179 || text[i] == 238 || text[i] == 243 || text[i] == 255 || text[i] == 254 || text[i] == 186 || text[i] == 191) {
                    vowels += text[i];
                }
            }


            output.open("outputText.txt");
            if(strstr(text.c_str(),line.c_str())){
               output <<"Слово знайдено\n";
            }
            else {
               output << "Слова не має\n";
            }
            output  << "Перевірка на голосні букви: " << vowels;
            output.close();
            break;
        }
        case 'l': {
            ofstream entr;
            string str = "Життя";

            entr.open("inputText.txt", ios_base::app);
            time_t currentTime;
            currentTime = time(NULL);
            tm *tm_local = localtime(&currentTime);
            for (int i = 0; str[i]; i++) {
                if (int(str[i]) >= 192 && int(str[i]) <= 223) {
                    str[i] = rand();
                }
            }
            entr << "\nЧас: " << tm_local -> tm_hour << ":" << tm_local -> tm_min << endl << "Замiнено велику букву на випадковий символ: " << str;
            entr.close();
            break;
        }
        case 'g':
            binarySystem();
            break;
        case 'j':
            int x,y,z;
            while(true)
            {
                cout << "Введiть х: ";
                if(!scanf("%d", &x)){
                    scanf("%*[^\n]");
                    cout << "Ви ввели символ, введіть число." << endl;
                }
                else
                    break;
            }
            while(true)
            {
                cout << "Введiть y: ";
                if(!scanf("%d", &y)){
                    scanf("%*[^\n]");
                    cout << "Ви ввели символ, введіть число." << endl;
                }
                else
                    break;
            }
                while(true)
            {
                cout << "Введiть z: ";
                if(!scanf("%d", &z)){
                    scanf("%*[^\n]");
                    cout << "Ви ввели символ, введіть число." << endl;
                }
                else
                    break;
            }
        cout << "s_calculation(): " << s_calculation(x,y,z) << endl;
            break;
        case 'f':
            break;
        default:

            break;
        }

    }
    return 0;
}
