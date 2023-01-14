#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
using namespace std;

struct lexem1 {
    int type;    //номер операции из таблицы
    int value; // значение константы
    string name; //имя переменной
    int numLine;   //номер строки, в котором находится элемент (для ошибки)
    lexem1* next;
    lexem1* prev;
};

string mass[6] = {
    "if", "while", "read", "write", "array", "int"
};

void lexicalAnalyzer(string C, int& i, lexem1& L) //i по ссылке
{
    int state = 0;      //переменная состояния
    string name;        //строка в которой текущяя лексема
    int n, type = -1;        //n - число - константа, type - тип текущей лексемы
    while (state < 7) {
        // cout << C[i] << endl;
        switch (C[i])
        {
        case '+':
            switch (state)
            {
            case 0:                 //7
                type = 3;
                state = 7;
                break;
            case 1:                //3
                state = 7;
                i--;
                break;
            case 2:                //10
                state = 7;
                i--;
                break;
            case 3:                //13
                cout << "1 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 4:                //13
                cout << "2 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 5:                //13
                cout << "3 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 6:                //13
                cout << "4 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            }

        case '-':
            switch (state)
            {
            case 0:                 //7
                type = 4;
                state = 7;
                break;
            case 1:                //3
                state = 7;
                i--;
                break;
            case 2:                //10
                state = 7;
                i--;
                break;
            case 3:                //3
                state = 7;
                i--;
                break;
            case 4:                //3
                state = 7;
                i--;
                break;
            case 5:                //3
                state = 7;
                i--;
                break;
            case 6:                //3
                state = 7;
                i--;
                break;
            }

        case '/':
            switch (state)
            {
            case 0:                 //7
                type = 5;
                state = 7;
                break;
            case 1:                //3
                state = 7;
                i--;
                break;
            case 2:                //10
                state = 7;
                i--;
                break;
            case 3:                //13
                cout << "5 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 4:                //13
                cout << "6 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 5:                //13
                cout << "7 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 6:                //13
                cout << "8 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            }

        case '*':
            switch (state)
            {
            case 0:                 //7
                type = 6;
                state = 7;
                break;
            case 1:                //3
                state = 7;
                i--;
                break;
            case 2:                //10
                state = 7;
                i--;
                break;
            case 3:                //13
                cout << "9 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 4:                //13
                cout << "10 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 5:                //13
                cout << "11 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 6:                //13
                cout << "12 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            }

        case '<':
            switch (state)
            {
            case 0:                 //12
                state = 4;
                type = 7;
                break;
            case 1:                //3
                state = 7;
                i--;
                break;
            case 2:                //10
                state = 7;
                i--;
                break;
            case 3:                //13
                cout << "13 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 4:                //13
                cout << "14 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 5:                //13
                cout << "15 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 6:                //13
                cout << "16 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            }

        case '>':
            switch (state)
            {
            case 0:                 //12
                state = 5;
                type = 8;
                break;
            case 1:                //3
                state = 7;
                i--;
                break;
            case 2:                //10
                state = 7;
                i--;
                break;
            case 3:                //13
                cout << "17 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 4:                //13
                cout << "18 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 5:                //13
                cout << "19 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 6:                //13
                cout << "20 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            }


        case '=':
            switch (state)
            {
            case 0:                 //12
                state = 3;
                type = 2;
                break;
            case 1:                //3
                state = 7;
                i--;
                break;
            case 2:                //10
                state = 7;
                i--;
                break;
            case 3:                //6
                type = 9;
                state = 7;
                break;
            case 4:                //6
                type = 10;
                state = 7;
                break;
            case 5:                //6
                type = 11;
                state = 7;
                break;
            case 6:                //
                type = 12;
                state = 7;
                break;
            }


        case '!':
            switch (state)
            {
            case 0:                 //12
                state = 6;
                break;
            case 1:                //3
                state = 7;
                i--;
                break;
            case 2:                //10
                state = 7;
                i--;
                break;
            case 3:                //13
                cout << "21 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 4:                //13
                cout << "22 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 5:                //13
                cout << "23 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 6:                //13
                cout << "24 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            }


        case '(':
            switch (state)
            {
            case 0:                 //7
                type = 13;
                state = 7;
                break;
            case 1:                //3
                state = 7;
                i--;
                break;
            case 2:                //10
                state = 7;
                i--;
                break;
            case 3:                //3
                state = 7;
                i--;
                break;
            case 4:                //3
                state = 7;
                i--;
                break;
            case 5:                //3
                state = 7;
                i--;
                break;
            case 6:                //3
                state = 7;
                i--;
                break;
            }

        case ')':
            switch (state)
            {
            case 0:                 //7
                type = 14;
                state = 7;
                break;
            case 1:                //3
                state = 7;
                i--;
                break;
            case 2:                //10
                state = 7;
                i--;
                break;
            case 3:                //3
                state = 7;
                i--;
                break;
            case 4:                //3
                state = 7;
                i--;
                break;
            case 5:                //3
                state = 7;
                i--;
                break;
            case 6:                //3
                state = 7;
                i--;
                break;
            }

        case '[':
            switch (state)
            {
            case 0:                 //7
                type = 15;
                state = 7;
                break;
            case 1:                //3
                state = 7;
                i--;
                break;
            case 2:                //10
                state = 7;
                i--;
                break;
            case 3:                //13
                cout << "25 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 4:                //13
                cout << "26 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 5:                //13
                cout << "27 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 6:                //13
                cout << "28 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            }

        case ']':
            switch (state)
            {
            case 0:                 //7
                type = 16;
                state = 7;
                break;
            case 1:                //3
                state = 7;
                i--;
                break;
            case 2:                //10
                state = 7;
                i--;
                break;
            case 3:                //13
                cout << "29 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 4:                //13
                cout << "30 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 5:                //13
                cout << "31 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 6:                //13
                cout << "32 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            }

        case '{':
            switch (state)
            {
            case 0:                 //7
                type = 17;
                state = 7;
                break;
            case 1:                //3
                state = 7;
                i--;
                break;
            case 2:                //10
                state = 7;
                i--;
                break;
            case 3:                //13
                cout << "33 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 4:                //13
                cout << "34 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 5:                //13
                cout << "35 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 6:                //13
                cout << "36 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            }

        case '}':
            switch (state)
            {
            case 0:                 //7
                type = 18;
                state = 7;
                break;
            case 1:                //3
                state = 7;
                i--;
                break;
            case 2:                //10
                state = 7;
                i--;
                break;
            case 3:                //13
                cout << "37 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 4:                //13
                cout << "38 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 5:                //13
                cout << "39 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 6:                //13
                cout << "40 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            }

        case ';':
            switch (state)
            {
            case 0:                 //7
                type = 19;
                state = 7;
                break;
            case 1:                //3
                state = 7;
                i--;
                break;
            case 2:                //10
                state = 7;
                i--;
                break;
            case 3:                //13
                cout << "41 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 4:                //13
                cout << "42 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 5:                //13
                cout << "43 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            case 6:                //13
                cout << "44 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            }

        case ' ':
            switch (state)
            {
            case 0:                 //5
                break;
            case 1:                //4
                state = 7;
                break;
            case 2:                //11
                state = 7;
                break;
            case 3:                //4
                state = 7;
                break;
            case 4:                //4
                state = 7;
                break;
            case 5:                //4
                state = 7;
                break;
            case 6:                //13
                cout << "45 Ошибка при лексическом анализе." << endl;
                state = 8;
                break;
            }

        default:
            if ((C[i] >= 'a') and (C[i] <= 'z'))
            {
                switch (state)
                {
                case 0:                 //1
                    name = C[i];
                    state = 1;
                    //cout << "маленькое имя" << name << endl;
                    type = 0;
                    break;
                case 1:                //2
                    state = 1;
                    name += C[i];
                    //cout << "большое имя" << name << endl;
                    break;
                case 2:                //13
                    cout << "46) Ошибка при лексическом анализе." << endl;
                    state = 8;
                    break;
                case 3:                //3
                    i--;
                    state = 7;
                    break;
                case 4:                //3
                    i--;
                    state = 7;
                    break;
                case 5:                //3
                    i--;
                    state = 7;
                    break;
                case 6:                //3
                    i--;
                    state = 7;
                    break;
                }
            }
            else if ((C[i] >= '0') and (C[i] <= '9'))
            {
                switch (state)
                {
                case 0:                 //8
                    state = 2;
                    n = (int)C[i] - 48;
                    //cout << "первая цифра: " << n << endl;
                    type = 1;
                    break;
                case 1:                //2
                    state = 1;
                    name += C[i];
                    //cout << "большое имя" << name << endl;
                    break;
                case 2:                //9
                    state = 2;
                    n = n * 10 + (int)C[i] - 48;
                    //cout << "другие цифры: " << n << endl;
                    break;
                case 3:                //3
                    i--;
                    state = 7;
                    break;
                case 4:                //3
                    i--;
                    state = 7;
                    break;
                case 5:                //3
                    i--;
                    state = 7;
                    break;
                case 6:                //3
                    i--;
                    state = 7;
                    break;
                }
            }
            else
            {
                //cout << "47) Ошибка при лексическом анализе. Недопустимый символ" << endl;
                state = 8;
            }

        }
        i++;
    }

    if (type == 0) {
        for (int j = 0; j < 6; j++)
        {
            if (name == mass[j]) {
                type = j + 20;
            }
        }
    }
    if (type >= 0) {

    }
    L.type = type;
    if (type == 0) L.name = name;
    if (type == 1) L.value = n;

}







/*
 на вход получаю список лексем, на выходе опс
в коде то же самое, что в файле тюк тюк

1. массив двумерный / трехмерный(таблица семантических действий)

создать объекты, из которого будет состоять магазин, генератор - 4 новых типа данных
(один на вход, скинула диана, для магазина у алины - переделать, генератор !!!!!!!и опс есть у алины)

типы данных : для генератора на стр 6 отчета

каждый элемент в генераторе должен содержать 1 тип(цифра из таблицы 6), если в нем 2 константа(значение константы)  
или 3 переменная(ссылка на переменную появляется), адрес на предыдущий

магазин - то же самое, только другие цифры

1. записать в магазин(цифру - A - взять из таблицы семантических действий), применить правило - 
переходим к таблице семантических действий
сравнить не совпадает ли первый символ магазина с первым символом входа, если не равны, 
то правило(из массива, который делаю я)

*/


struct pattern {
    int type;    //номер операции из таблицы
    int value; // значение константы или метки
    int nom; //элемент массива S...
    int numLine;
    pattern* next;
    pattern* prev;
};


pattern magazin[13][26];
pattern generator[13][26];

//двумерный массив, у которого список внутри ячейки

void fillInMagazin() {
    pattern a;
    pattern* b;
    pattern* c;

    a.type = -1;
    for (int i = 0; i < 13; i++)
        for (int j = 0; j < 26; j++)
            magazin[i][j] = a;

    //объявление массива
    //aH=SZ
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //a
    b = new pattern;
    b->type = 36;    //H
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 2;  //=
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 30;  //S
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 37;  //Z
    b->prev = c;
    c = b;
    magazin[1][0] = *c;

    //aHVUD
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //a
    b = new pattern;
    b->type = 36;    //H
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 33;  //V
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 31;  //U
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 29;  //D
    b->prev = c;
    c = b;
    magazin[2][0] = *c;

    //aHVU
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //a
    b = new pattern;
    b->type = 36;    //H
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 33;  //V
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 31;  //U
    b->prev = c;
    c = b;
    magazin[4][0] = *c;

    //aHV
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //a
    b = new pattern;
    b->type = 36;    //H
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 33;  //V
    b->prev = c;
    c = b;
    magazin[6][0] = *c;

    //aH
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //a
    b = new pattern;
    b->type = 36;    //H
    b->prev = c;
    c = b;
    magazin[8][0] = *c;

    //aH
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //a
    b = new pattern;
    b->type = 36;    //H
    b->prev = c;
    c = b;
    magazin[9][0] = *c;

    //kVUD
    c = new pattern;
    c->prev = nullptr;
    c->type = 1;   //k
    b = new pattern;
    b->type = 33;    //V
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 31;  //U
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 29;  //D
    b->prev = c;
    c = b;
    magazin[2][1] = *c;

    //kVU
    c = new pattern;
    c->prev = nullptr;
    c->type = 1;   //k
    b = new pattern;
    b->type = 33;    //V
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 31;  //U
    b->prev = c;
    c = b;
    magazin[4][1] = *c;

    //kV
    c = new pattern;
    c->prev = nullptr;
    c->type = 1;   //k
    b = new pattern;
    b->type = 33;    //V
    b->prev = c;
    c = b;
    magazin[6][1] = *c;

    //k
    c = new pattern;
    c->prev = nullptr;
    c->type = 1;   //k
    magazin[8][1] = *c;

    //k
    c = new pattern;
    c->prev = nullptr;
    c->type = 1;   //k
    magazin[9][1] = *c;
    
    //+GVUD
    c = new pattern;
    c->prev = nullptr;
    c->type = 3;   //+
    b = new pattern;
    b->type = 35;    //G
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 33;  //V
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 31;  //U
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 29;  //D
    b->prev = c;
    c = b;
    magazin[2][3] = *c;

    //+GVU
    c = new pattern;
    c->prev = nullptr;
    c->type = 3;   //+
    b = new pattern;
    b->type = 35;    //G
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 33;  //V
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 31;  //U
    b->prev = c;
    c = b;
    magazin[4][3] = *c;

    //+TU
    c = new pattern;
    c->prev = nullptr;
    c->type = 3;   //+
    b = new pattern;
    b->type = 32;    //T
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 31;  //U
    b->prev = c;
    c = b;
    magazin[5][3] = *c;

    //+GV
    c = new pattern;
    c->prev = nullptr;
    c->type = 3;   //+
    b = new pattern;
    b->type = 35;    //G
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 33;  //V
    b->prev = c;
    c = b;
    magazin[6][3] = *c;

    //+G
    c = new pattern;
    c->prev = nullptr;
    c->type = 3;   //+
    b = new pattern;
    b->type = 35;    //G
    b->prev = c;
    c = b;
    magazin[8][3] = *c;

    //-GVUD
    c = new pattern;
    c->prev = nullptr;
    c->type = 4;   //-
    b = new pattern;
    b->type = 35;    //G
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 33;  //V
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 31;  //U
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 29;  //D
    b->prev = c;
    c = b;
    magazin[2][4] = *c;

    //-GPVU
    c = new pattern;
    c->prev = nullptr;
    c->type = 4;   //-
    b = new pattern;
    b->type = 35;    //G
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 38;  //P
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 33;  //V
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 31;  //U
    b->prev = c;
    c = b;
    magazin[4][4] = *c;

    //-TU
    c = new pattern;
    c->prev = nullptr;
    c->type = 4;   //-
    b = new pattern;
    b->type = 32;    //T
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 31;  //U
    b->prev = c;
    c = b;
    magazin[5][4] = *c;

    //-GPV
    c = new pattern;
    c->prev = nullptr;
    c->type = 4;   //-
    b = new pattern;
    b->type = 35;    //G
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 38;  //P
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 33;  //V
    b->prev = c;
    c = b;
    magazin[6][4] = *c;

    //-GP
    c = new pattern;
    c->prev = nullptr;
    c->type = 4;   //-
    b = new pattern;
    b->type = 35;    //G
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 38;  //P
    b->prev = c;
    c = b;
    magazin[8][4] = *c;

    // /FV
    c = new pattern;
    c->prev = nullptr;
    c->type = 5;   //  /
    b = new pattern;
    b->type = 34;    //F
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 33;  //V
    b->prev = c;
    c = b;
    magazin[7][5] = *c;

    // *FV
    c = new pattern;
    c->prev = nullptr;
    c->type = 6;   //  *
    b = new pattern;
    b->type = 34;    //F
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 33;  //V
    b->prev = c;
    c = b;
    magazin[7][6] = *c;

    // <SP
    c = new pattern;
    c->prev = nullptr;
    c->type = 7;   //  <
    b = new pattern;
    b->type = 30;    //S
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 38;  //P
    b->prev = c;
    c = b;
    magazin[3][7] = *c;

    // >SP
    c = new pattern;
    c->prev = nullptr;
    c->type = 8;   //  >
    b = new pattern;
    b->type = 30;    //S
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 38;  //P
    b->prev = c;
    c = b;
    magazin[3][8] = *c;

    // ==SP
    c = new pattern;
    c->prev = nullptr;
    c->type = 9;   //  ==
    b = new pattern;
    b->type = 30;    //S
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 38;  //P
    b->prev = c;
    c = b;
    magazin[3][9] = *c;

    // <=SP
    c = new pattern;
    c->prev = nullptr;
    c->type = 10;   //  <=
    b = new pattern;
    b->type = 30;    //S
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 38;  //P
    b->prev = c;
    c = b;
    magazin[3][10] = *c;

    // >=SP
    c = new pattern;
    c->prev = nullptr;
    c->type = 11;   //  >=
    b = new pattern;
    b->type = 30;    //S
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 38;  //P
    b->prev = c;
    c = b;
    magazin[3][11] = *c;

    // !=SP
    c = new pattern;
    c->prev = nullptr;
    c->type = 12;   //  !=
    b = new pattern;
    b->type = 30;    //S
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 38;  //P
    b->prev = c;
    c = b;
    magazin[3][12] = *c;

    //(S)VUD
    c = new pattern;
    c->prev = nullptr;
    c->type = 13;   //(
    b = new pattern;
    b->type = 30;    //S
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 14;  //)
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 33;  //V
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 31;  //U
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 29;  //D
    b->prev = c;
    c = b;
    magazin[2][13] = *c;

    //(S)VU
    c = new pattern;
    c->prev = nullptr;
    c->type = 13;   //(
    b = new pattern;
    b->type = 30;    //S
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 14;  //)
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 33;  //V
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 31;  //U
    b->prev = c;
    c = b;
    magazin[4][13] = *c;

    //(S)V
    c = new pattern;
    c->prev = nullptr;
    c->type = 13;   //(
    b = new pattern;
    b->type = 30;    //S
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 14;  //)
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 33;  //V
    b->prev = c;
    c = b;
    magazin[6][13] = *c;

    //(S)
    c = new pattern;
    c->prev = nullptr;
    c->type = 13;   //(
    b = new pattern;
    b->type = 30;    //S
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 14;  //)
    b->prev = c;
    c = b;
    magazin[8][13] = *c;

    //(S)
    c = new pattern;
    c->prev = nullptr;
    c->type = 13;   //(
    b = new pattern;
    b->type = 30;    //S
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 14;  //)
    b->prev = c;
    c = b;
    magazin[9][13] = *c;

    //[S]
    c = new pattern;
    c->prev = nullptr;
    c->type = 15;   //[
    b = new pattern;
    b->type = 30;    //S
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 16;  //]
    b->prev = c;
    c = b;
    magazin[10][15] = *c;

    //{B}
    c = new pattern;
    c->prev = nullptr;
    c->type = 17;   //{
    b = new pattern;
    b->type = 27;    //B
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 18;  //}
    b->prev = c;
    c = b;
    magazin[0][17] = *c;

    //;B
    c = new pattern;
    c->prev = nullptr;
    c->type = 19;   //;
    b = new pattern;
    b->type = 27;    //B
    b->prev = c;
    c = b;
    magazin[11][19] = *c;

    //if(C){BZ}
    c = new pattern;
    c->prev = nullptr;
    c->type = 20;      //if
    b = new pattern;
    b->type = 13;    //(
    b->prev = c;
    c = b;  
    b = new pattern;
    b->type = 28;    //C
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 14;  //)
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 17;  //{
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 27;  //B
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 37;  //Z
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 18;  //}
    b->prev = c;
    c = b;
    magazin[1][20] = *c;

    //while(C){BZ}
    c = new pattern;
    c->prev = nullptr;
    c->type = 21;      //while
    b = new pattern;
    b->type = 13;    //(
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 28;    //C
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 14;  //)
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 17;  //{
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 27;  //B
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 37;  //Z
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 18;  //}
    b->prev = c;
    c = b;
    magazin[1][21] = *c;

    //read(aH)Z
    c = new pattern;
    c->prev = nullptr;
    c->type = 22;      //read
    b = new pattern;
    b->type = 13;    //(
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;    //a
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 36;    //H
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 14;  //)
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 37;  //Z
    b->prev = c;
    c = b;
    magazin[1][22] = *c;

    //write(S)Z
    c = new pattern;
    c->prev = nullptr;
    c->type = 23;      //write
    b = new pattern;
    b->type = 13;    //(
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 30;    //S
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 14;  //)
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 37;  //Z
    b->prev = c;
    c = b;
    magazin[1][23] = *c;

    //arraya[k]A
    c = new pattern;
    c->prev = nullptr;
    c->type = 24;      //array
    b = new pattern;
    b->type = 0;    //a
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 15;    //[
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 1;  //k
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 16;  //]
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 26;  //A
    b->prev = c;
    c = b;
    magazin[0][24] = *c;

    //intaA
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;      //int
    b = new pattern;
    b->type = 0;    //a
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 26;  //A
    b->prev = c;
    c = b;
    magazin[0][25] = *c;
}

void fillInGenerator() {
    pattern a;
    pattern* b;
    pattern* c;

    a.type = -1;
    for (int i = 0; i < 13; i++)
        for (int j = 0; j < 26; j++)
            generator[i][j] = a;

    //объявление массива
    //aH=SZ
    c = new pattern;
    c->prev = nullptr;
    c->type = 20;        //a
    b = new pattern;
    b->type = 0;        //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;       //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;       //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 26;      //=
    b->prev = c;
    generator[1][0] = *b;

    //aHVUD
    c = new pattern;
    c->prev = nullptr;
    c->type = 20;   //a
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    generator[2][0] = *c;

    //aHVU
    c = new pattern;
    c->prev = nullptr;
    c->type = 20;   //a
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    generator[4][0] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][0] = *c;

    //aHV
    c = new pattern;
    c->prev = nullptr;
    c->type = 20;   //a
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    generator[6][0] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[7][0] = *c;

    //aH
    c = new pattern;
    c->prev = nullptr;
    c->type = 20;   //a
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    generator[8][0] = *c;

    //aH
    c = new pattern;
    c->prev = nullptr;
    c->type = 20;   //a
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    generator[9][0] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][0] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][0] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[1][1] = *c;

    //kVUD
    c = new pattern;
    c->prev = nullptr;
    c->type = 21;   //k
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    generator[2][1] = *c;

    //kVU
    c = new pattern;
    c->prev = nullptr;
    c->type = 21;   //k
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    generator[4][1] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][1] = *c;

    //kV
    c = new pattern;
    c->prev = nullptr;
    c->type = 21;   //k
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    generator[6][1] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[7][1] = *c;

    //k
    c = new pattern;
    c->prev = nullptr;
    c->type = 21;   //k
    generator[8][1] = *c;

    //k
    c = new pattern;
    c->prev = nullptr;
    c->type = 21;   //k
    generator[9][1] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][1] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][1] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[1][2] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][2] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[7][2] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][2] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][2] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[1][3] = *c;

    //+GVUD
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    generator[2][3] = *c;

    //+GVU
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    generator[4][3] = *c;

    //+TU
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 9;  //+
    b->prev = c;
    c = b;
    generator[5][3] = *c;

    //+GV
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    generator[6][3] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[7][3] = *c;

    //+G
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    generator[8][3] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][3] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][3] = *c;

    //-GVUD
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 13;  //-'
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    generator[2][4] = *c;

    //-GPVU
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 13;  //-'
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    generator[4][4] = *c;

    //-TU
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 10;  //-
    b->prev = c;
    c = b;
    generator[5][4] = *c;

    //-GPV
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 13;  //-'
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    generator[6][4] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[7][4] = *c;

    //-GP
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 13;  //-'
    b->prev = c;
    c = b;
    generator[8][4] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][4] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][4] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[1][5] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][5] = *c;

    // /FV
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //  ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 12;  //   /
    b->prev = c;
    c = b;
    generator[7][5] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][5] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][5] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[1][6] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][6] = *c;

    // *FV
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //  ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 1;  //*
    b->prev = c;
    c = b;
    generator[7][6] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][6] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][6] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[1][7] = *c;

    // <SP
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 14;  //<
    b->prev = c;
    c = b;
    generator[3][7] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][7] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[7][7] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][7] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][7] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[1][8] = *c;

    // >SP
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 15;  //>
    b->prev = c;
    c = b;
    generator[3][8] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][8] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[7][8] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][8] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][8] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[1][9] = *c;

    // ==SP
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 18;  //==
    b->prev = c;
    c = b;
    generator[3][9] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][9] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[7][9] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][9] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][9] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[1][10] = *c;

    // <=SP
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 16;  //<=
    b->prev = c;
    c = b;
    generator[3][10] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][10] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[7][10] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][10] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][10] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[1][11] = *c;

    // >=SP
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 17;  //>=
    b->prev = c;
    c = b;
    generator[3][11] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][11] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[7][11] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][11] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][11] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[1][12] = *c;

    // !=SP
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 19;  //!=
    b->prev = c;
    c = b;
    generator[3][12] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][12] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[7][12] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][12] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][12] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[1][13] = *c;

    //(S)VUD
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    generator[2][13] = *c;

    //(S)VU
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    generator[4][13] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][13] = *c;

    //(S)V
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    generator[6][13] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[7][13] = *c;

    //(S)
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    generator[8][13] = *c;

    //(S)
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    generator[9][13] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][13] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][13] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[1][14] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][14] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][14] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][14] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[1][15] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][15] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[7][15] = *c;

    //[S]
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 24;  //i
    b->prev = c;
    c = b;
    generator[10][15] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][15] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[1][16] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][16] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[7][16] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][16] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][16] = *c;

    //{B}
    c = new pattern;
    c->prev = nullptr;
    c->type = 27;   //9
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 28;  //10
    b->prev = c;
    c = b;
    generator[0][17] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[1][17] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][17] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[7][17] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][17] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][17] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[1][18] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][18] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[7][18] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][18] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][18] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[1][19] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][19] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[7][19] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][19] = *c;

    //[S]
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;   //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    generator[11][19] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][19] = *c;

    //if(C){BZ}
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;      //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 1;  //1
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //2
    b->prev = c;
    c = b;
    generator[1][20] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][20] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[7][20] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][20] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][20] = *c;

    //while(C){BZ}
    c = new pattern;
    c->prev = nullptr;
    c->type = 3;      //3
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 1;  //1
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 4;  //4
    b->prev = c;
    c = b;
    generator[1][21] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][21] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[7][21] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][21] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][21] = *c;

    //read(aH)Z
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;      //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 20;    //a
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 22;  //r
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    generator[1][22] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][22] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[7][22] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][22] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][22] = *c;

    //write(S)Z
    c = new pattern;
    c->prev = nullptr;
    c->type = 0;      //ㅁ
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 23;  //w
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    generator[1][23] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][23] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[7][23] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][23] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][23] = *c;

    //arraya[k]A
    c = new pattern;
    c->prev = nullptr;
    c->type = 5;      //5
    b = new pattern;
    b->type = 6;    //6
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;    //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 7;  //7
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    generator[0][24] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][24] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[7][24] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][24] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][24] = *c;

    //intaA
    c = new pattern;
    c->prev = nullptr;
    c->type = 8;      //8
    b = new pattern;
    b->type = 6;    //6
    b->prev = c;
    c = b;
    b = new pattern;
    b->type = 0;  //ㅁ
    b->prev = c;
    c = b;
    generator[0][25] = *c;

    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[5][25] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[7][25] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[10][25] = *c;
    //λ
    c = new pattern;
    c->prev = nullptr;
    c->type = 25;   //λ
    generator[12][25] = *c;
}


void output(pattern* p2m, pattern* p2g) {
    //для магазина
    pattern* help;
    /*help = &magazin[1][0];
    cout << help->type << " ";
    help = help->prev;
    cout << help->type << " ";
    help = help->prev;
    cout << help->type << " ";
    help = help->prev;
    cout << help->type << " ";
    help = help->prev;
    cout << help->type << " ";
    help = help->prev;*/

    //cout << magazin[1][0].type;

   /* help = &magazin[1][0];
    do {
        cout << help->type << " ";
        help = help->prev;
    } while (help != nullptr);*/

    /*for (int i = 0; i < 13; i++) 
        for (int j = 0; j < 26; j++) {
            cout << i << j;
            help = &magazin[i][j];
            while (help != nullptr) {
                cout << help->type << " ";
                help = help->prev;
            }
            
        }*/

    cout << "Магазин";
    do {
        cout << p2m->type << " ";
        p2m = p2m->prev;
    } while (p2m != nullptr);

    cout << "Генератор";    
}


//для инетпретатора
fstream read("hello.txt"); // окрываем файл для чтения

//a=a+b aab+=
//a=a+b+c aabc++=
pattern* M[2]; //OPS
pattern* Magazin[2];
int S[2];
int Metka[2];
int j = 0;
string help;
void justdoit() {
    int tail = 0;
    for (int i = 0; i < 2; i++) {
        while (M[i]->type > 19) {//до 19 номера в таблице на стр 7 идут операции
            Magazin[j]->value = M[i]->value;//считали в магазин константы/переменные из опс
            Magazin[j]->type = M[i]->type;
            Magazin[j]->nom = M[i]->nom;
            j++;
            i++;
        }//вышли, если пришла операция
        tail = j - 1;
        switch (M[i]->type)
        {
        case 3:// =
            if (Magazin[tail - 1]->type == 20) {//a -если это переменная
                if (Magazin[tail]->type == 20) {
                    S[Magazin[tail - 1]->nom] = S[Magazin[tail]->nom];
                    Magazin[tail - 1]->value = S[Magazin[tail - 1]->nom];
                }
                else {
                    S[Magazin[tail - 1]->nom] = Magazin[tail]->value;
                    Magazin[tail - 1]->value = Magazin[tail]->value;
                }
            }
            else Magazin[tail - 1]->value = Magazin[tail]->value;
            tail = tail - 1;
            j = j - 1;
            //cout << Magazin[j - 2]->value << 2222<<endl;
            break;
        case 4:// r
            //read >> Magazin[j - 1]->value;
            read.open("hello.txt.txt");
            if (Magazin[tail]->type == 20) {//a -если это переменная
                if (read.is_open()) {
                    read >> help;
                }
                S[Magazin[tail]->nom] = stoi(help);
                Magazin[tail - 1]->value = S[Magazin[tail]->nom];
            }
            else cout << "ERROR";
            tail = tail - 1;
            j = j - 1;
            break;
        case 5:// w
            //read<<Magazin[j - 1]->value;
            read.open("hello.txt.txt");
            if (Magazin[tail]->type == 20) {//a -если это переменная
                if (read.is_open()) {
                    read << Magazin[tail]->type;
                }
            }
            else cout << "ERROR";
            tail = tail - 1;
            j = j - 1;
            break;
        case 6:// i 
            cout << Magazin[j - 1]->value;
            break;
        case 7:// j
            i = i + Metka[Magazin[tail]->nom];//счетчику, который содержит текущий номер исполняемого элемента ОПС, присваивается значение метки

            break;
        case 8:// jf
            if (Magazin[tail - 1]->type == 24) {//если false
                i = i + Metka[Magazin[tail]->nom]; //счетчику, который содержит текущий номер исполняемого элемента ОПС, присваивается значение 2-го операнда 
                cout << "m1";
                cout << "  Magazin[tail]->value " << Magazin[tail]->value << endl << endl;
                cout << "  Metka[Magazin[tail]->value] " << Metka[Magazin[tail]->nom] << endl << endl;
                cout << "  i" << i << endl << endl;
            }
            cout << "  i" << i << endl << endl;
            cout << "  j" << j << endl << endl;
            j = j + 1;
            tail = j - 1;
            break;
        case 9://+
            if (Magazin[tail - 1]->type == 20) {//a -если это переменная
                if (Magazin[tail]->type == 20) {
                    S[Magazin[tail - 1]->nom] = S[Magazin[tail - 1]->nom] + S[Magazin[tail]->nom];
                }
                else {
                    S[Magazin[tail - 1]->nom] = S[Magazin[tail - 1]->nom] + Magazin[tail]->value;
                }
                Magazin[tail - 1]->value = S[Magazin[tail - 1]->nom];
            }
            else {
                Magazin[tail - 1]->value = Magazin[tail - 1]->value + Magazin[tail]->value;
            }
            Magazin[tail - 1]->type = 21;
            Magazin[tail - 1]->nom = -1;
            //cout << Magazin[tail - 1]->value << "magaz" << endl;
            cout << "  i" << i << endl << endl;
            cout << "  j" << j << endl << endl;
            j = j - 1;
            tail = tail - 1;
            //cout << tail << "tail1";
            break;
        case 10://-
            if (Magazin[tail - 1]->type == 20) {//a -если это переменная
                if (Magazin[tail]->type == 20) {
                    S[Magazin[tail - 1]->nom] = S[Magazin[tail - 1]->nom] - S[Magazin[tail]->nom];
                }
                else {
                    S[Magazin[tail - 1]->nom] = S[Magazin[tail - 1]->nom] - Magazin[tail]->value;
                }
                Magazin[tail - 1]->value = S[Magazin[tail - 1]->nom];
            }
            else {
                Magazin[tail - 1]->value = Magazin[tail - 1]->value - Magazin[tail]->value;
            }
            Magazin[tail - 1]->type = 21;
            Magazin[tail - 1]->nom = -1;
            j = j - 1;
            tail = tail - 1;
            break;
        case 11://*
            if (Magazin[tail - 1]->type == 20) {//a -если это переменная
                if (Magazin[tail]->type == 20) {
                    S[Magazin[tail - 1]->nom] = S[Magazin[tail - 1]->nom] * S[Magazin[tail]->nom];
                }
                else {
                    S[Magazin[tail - 1]->nom] = S[Magazin[tail - 1]->nom] * Magazin[tail]->value;
                }
                Magazin[tail - 1]->value = S[Magazin[tail - 1]->nom];
            }
            else {
                Magazin[tail - 1]->value = Magazin[tail - 1]->value * Magazin[tail]->value;
            }
            Magazin[tail - 1]->type = 21;
            Magazin[tail - 1]->nom = -1;
            j = j - 1;
            tail = tail - 1;
            break;
        case 12:// :
            if (Magazin[tail - 1]->type == 20) {//a -если это переменная
                if (Magazin[tail]->type == 20) {
                    S[Magazin[tail - 1]->nom] = S[Magazin[tail - 1]->nom] / S[Magazin[tail]->nom];
                }
                else {
                    S[Magazin[tail - 1]->nom] = S[Magazin[tail - 1]->nom] / Magazin[tail]->value;
                    cout << "  S[Magazin[tail - 1]->nom]" << S[Magazin[tail - 1]->nom] << endl << endl;
                    cout << "  tail" << tail << endl << endl;
                    cout << "  i" << i << endl << endl;
                    cout << "  j" << j << endl << endl;
                }
                Magazin[tail - 1]->value = S[Magazin[tail - 1]->nom];
            }
            else {
                Magazin[tail - 1]->value = Magazin[tail - 1]->value / Magazin[tail]->value;
            }
            Magazin[tail - 1]->type = 21;
            Magazin[tail - 1]->nom = -1;
            j = j - 1;
            tail = tail - 1;
            cout << "  :tail" << tail << endl;
            cout << "  :i" << i << endl;
            cout << "  j" << j << endl << endl;
            break;
        case 13:// '-
            if (Magazin[tail - 1]->type == 20) {//a -если это переменная
                S[Magazin[tail - 1]->nom] = S[Magazin[tail - 1]->nom] * (-1);
            }
            else {
                Magazin[tail - 1]->value = Magazin[tail - 1]->value * (-1);
            }
            Magazin[tail - 1]->type = 21;
            Magazin[tail - 1]->nom = -1;
            j = j - 1;
            tail = tail - 1;

            break;
        case 14:// <
            /*if (Magazin[j - 2]->value < Magazin[j - 1]->value){//a<b
                Magazin[j - 2]->type = 23; //записываем true в магазин
                Magazin[j - 2]->value = 1;
            }
            else {
                Magazin[j - 2]->type = 24;//если false
                Magazin[j - 2]->value = 0;
            }
            j = j - 2;*/
            if (Magazin[tail - 1]->type == 20) {//a -если это переменная
                if (Magazin[tail]->type == 20) {
                    if (S[Magazin[tail - 1]->nom] < S[Magazin[tail]->nom]) {
                        Magazin[tail - 1]->type = 23;//записываем true в магазин
                        Magazin[tail - 1]->nom = -1;
                        //cout << "true" << endl << endl;
                    }
                    else {
                        Magazin[tail - 1]->type = 24;//если false
                        Magazin[tail - 1]->nom = -1;
                    }
                }
                else {
                    if (S[Magazin[tail - 1]->nom] < Magazin[tail]->nom) {
                        Magazin[tail - 1]->type = 23;//записываем true в магазин
                        Magazin[tail - 1]->nom = -1;
                    }
                    else {
                        Magazin[tail - 1]->type = 24;//если false
                        Magazin[tail - 1]->nom = -1;
                    }
                }
                Magazin[tail - 1]->value = S[Magazin[tail - 1]->nom];
            }
            else {
                if (Magazin[tail - 1]->nom < Magazin[tail]->nom) {
                    Magazin[tail - 1]->type = 23;//записываем true в магазин
                    Magazin[tail - 1]->nom = -1;
                }
                else {
                    Magazin[tail - 1]->type = 24;//если false
                    Magazin[tail - 1]->nom = -1;
                }
            }
            cout << "  i<" << j << endl << endl;
            cout << "  j<" << j << endl << endl;
            //j = j - 1;
            //tail = tail - 1;
            break;
        case 15:// >
            /*if (Magazin[j - 2]->value > Magazin[j - 1]->value) {//a<b
                Magazin[j - 2]->type = 23; //записываем true в магазин
                Magazin[j - 2]->value = 1;
            }
            else {
                Magazin[j - 2]->type = 24;//если false
                Magazin[j - 2]->value = 0;
            }
            j = j - 2;*/
            if (Magazin[tail - 1]->type == 20) {//a -если это переменная
                if (Magazin[tail]->type == 20) {
                    if (S[Magazin[tail - 1]->nom] > S[Magazin[tail]->nom]) {
                        Magazin[tail - 1]->type = 23;//записываем true в магазин
                        Magazin[tail - 1]->nom = -1;
                    }
                    else {
                        Magazin[tail - 1]->type = 24;//если false
                        Magazin[tail - 1]->nom = -1;
                    }
                }
                else {
                    if (S[Magazin[tail - 1]->nom] > Magazin[tail]->nom) {
                        Magazin[tail - 1]->type = 23;//записываем true в магазин
                        Magazin[tail - 1]->nom = -1;
                    }
                    else {
                        Magazin[tail - 1]->type = 24;//если false
                        Magazin[tail - 1]->nom = -1;
                    }
                }
                Magazin[tail - 1]->value = S[Magazin[tail - 1]->nom];
            }
            else {
                if (Magazin[tail - 1]->nom > Magazin[tail]->nom) {
                    Magazin[tail - 1]->type = 23;//записываем true в магазин
                    Magazin[tail - 1]->nom = -1;
                }
                else {
                    Magazin[tail - 1]->type = 24;//если false
                    Magazin[tail - 1]->nom = -1;
                }
            }
            j = j - 1;
            tail = tail - 1;
            break;
        case 16:// <=
            if (Magazin[tail - 1]->type == 20) {//a -если это переменная
                if (Magazin[tail]->type == 20) {
                    if (S[Magazin[tail - 1]->nom] <= S[Magazin[tail]->nom]) {
                        Magazin[tail - 1]->type = 23;//записываем true в магазин
                        Magazin[tail - 1]->nom = -1;
                    }
                    else {
                        Magazin[tail - 1]->type = 24;//если false
                        Magazin[tail - 1]->nom = -1;
                    }
                }
                else {
                    if (S[Magazin[tail - 1]->nom] <= Magazin[tail]->nom) {
                        Magazin[tail - 1]->type = 23;//записываем true в магазин
                        Magazin[tail - 1]->nom = -1;
                    }
                    else {
                        Magazin[tail - 1]->type = 24;//если false
                        Magazin[tail - 1]->nom = -1;
                    }
                }
                Magazin[tail - 1]->value = S[Magazin[tail - 1]->nom];
            }
            else {
                if (Magazin[tail - 1]->nom <= Magazin[tail]->nom) {
                    Magazin[tail - 1]->type = 23;//записываем true в магазин
                    Magazin[tail - 1]->nom = -1;
                }
                else {
                    Magazin[tail - 1]->type = 24;//если false
                    Magazin[tail - 1]->nom = -1;
                }
            }
            j = j - 1;
            tail = tail - 1;
            break;
        case 17:// >=
            /*if (Magazin[j - 2]->value >= Magazin[j - 1]->value) {//a<b
                Magazin[j - 2]->type = 23; //записываем true в магазин
                Magazin[j - 2]->value = 1;
            }
            else {
                Magazin[j - 2]->type = 24;//если false
                Magazin[j - 2]->value = 0;
            }
            j = j - 2;*/
            if (Magazin[tail - 1]->type == 20) {//a -если это переменная
                if (Magazin[tail]->type == 20) {
                    if (S[Magazin[tail - 1]->nom] >= S[Magazin[tail]->nom]) {
                        Magazin[tail - 1]->type = 23;//записываем true в магазин
                        Magazin[tail - 1]->nom = -1;
                    }
                    else {
                        Magazin[tail - 1]->type = 24;//если false
                        Magazin[tail - 1]->nom = -1;
                    }
                }
                else {
                    if (S[Magazin[tail - 1]->nom] >= Magazin[tail]->nom) {
                        Magazin[tail - 1]->type = 23;//записываем true в магазин
                        Magazin[tail - 1]->nom = -1;
                    }
                    else {
                        Magazin[tail - 1]->type = 24;//если false
                        Magazin[tail - 1]->nom = -1;
                    }
                }
                Magazin[tail - 1]->value = S[Magazin[tail - 1]->nom];
            }
            else {
                if (Magazin[tail - 1]->nom >= Magazin[tail]->nom) {
                    Magazin[tail - 1]->type = 23;//записываем true в магазин
                    Magazin[tail - 1]->nom = -1;
                }
                else {
                    Magazin[tail - 1]->type = 24;//если false
                    Magazin[tail - 1]->nom = -1;
                }
            }
            j = j - 1;
            tail = tail - 1;
            break;
        case 18:// ==
            if (Magazin[tail - 1]->type == 20) {//a -если это переменная
                if (Magazin[tail]->type == 20) {
                    if (S[Magazin[tail - 1]->nom] == S[Magazin[tail]->nom]) {
                        Magazin[tail - 1]->type = 23;//записываем true в магазин
                        Magazin[tail - 1]->nom = -1;
                    }
                    else {
                        Magazin[tail - 1]->type = 24;//если false
                        Magazin[tail - 1]->nom = -1;
                    }
                }
                else {
                    if (S[Magazin[tail - 1]->nom] == Magazin[tail]->nom) {
                        Magazin[tail - 1]->type = 23;//записываем true в магазин
                        Magazin[tail - 1]->nom = -1;
                    }
                    else {
                        Magazin[tail - 1]->type = 24;//если false
                        Magazin[tail - 1]->nom = -1;
                    }
                }
                Magazin[tail - 1]->value = S[Magazin[tail - 1]->nom];
            }
            else {
                if (Magazin[tail - 1]->nom == Magazin[tail]->nom) {
                    Magazin[tail - 1]->type = 23;//записываем true в магазин
                    Magazin[tail - 1]->nom = -1;
                }
                else {
                    Magazin[tail - 1]->type = 24;//если false
                    Magazin[tail - 1]->nom = -1;
                }
            }
            j = j - 1;
            tail = tail - 1;
            break;
        case 19:// !=
            if (Magazin[tail - 1]->type == 20) {//a -если это переменная
                if (Magazin[tail]->type == 20) {
                    if (S[Magazin[tail - 1]->nom] != S[Magazin[tail]->nom]) {
                        Magazin[tail - 1]->type = 23;//записываем true в магазин
                        Magazin[tail - 1]->nom = -1;
                    }
                    else {
                        Magazin[tail - 1]->type = 24;//если false
                        Magazin[tail - 1]->nom = -1;
                    }
                }
                else {
                    if (S[Magazin[tail - 1]->nom] != Magazin[tail]->nom) {
                        Magazin[tail - 1]->type = 23;//записываем true в магазин
                        Magazin[tail - 1]->nom = -1;
                    }
                    else {
                        Magazin[tail - 1]->type = 24;//если false
                        Magazin[tail - 1]->nom = -1;
                    }
                }
                Magazin[tail - 1]->value = S[Magazin[tail - 1]->nom];
            }
            else {
                if (Magazin[tail - 1]->nom != Magazin[tail]->nom) {
                    Magazin[tail - 1]->type = 23;//записываем true в магазин
                    Magazin[tail - 1]->nom = -1;
                }
                else {
                    Magazin[tail - 1]->type = 24;//если false
                    Magazin[tail - 1]->nom = -1;
                }
            }
            j = j - 1;
            tail = tail - 1;
            break;
        }
    }
}


//Считываем весь текст в массив строк  С, записать количество символов в каждой строке I[], количество строк J 
// Создаем массив if while       read       write       array       int
//создать массив, где 
int main()
{
    setlocale(LC_ALL, "Russian");
    /*  lexem L1(5, 1), L2(10, 3, &L1);        //создаем 2 объекта
      lexem* L;
      L = L1.p;
      cout << L->TypeLex;*/

      //============================Считываем программу с файла======================================
    ifstream enter_file("text.txt");
    string C, c;
    char str[512];
    int countLine = 0, allSymb = 0;
    while (!enter_file.eof())
    {
        enter_file.getline(str, 512);
        countLine++;
    }
    cout << countLine << endl << endl;
    enter_file.seekg(0);
    int* countSymb = new int[countLine];

    int i = 0;

    while (getline(enter_file, c))
    {
        if (i > 0) { countSymb[i] = countSymb[i - 1]; }
        C += c;
        countSymb[i] += size(c);
        allSymb += size(c);
        //cout << c << "  " << countSymb[i] << endl;
        i++;
    }

    //==================================Вызов фнкции лексического анализатора==============================
    i = 0;
    int j = 0;
    lexem1 header, * p1, * p2, * head;

    head = new lexem1;
    p1 = head;
    head->next = nullptr;
    lexicalAnalyzer(C, i, *p1);
    header = *p1;

    while (i < allSymb)
    {
        if (p1->type >= 0)
        {
            p1->next = new lexem1;
            p1 = p1->next;
            cout << p1->next;
        }p1->next = nullptr;
        lexicalAnalyzer(C, i, *p1);
        

    }


    enter_file.close();

    ///////////////////////////////////////////////////////////////для генератора
    pattern a;
    pattern* b;
    pattern* c;
    fillInMagazin();
    fillInGenerator();

    /// //

    int condition = 0;
    //в генератор 2 кубика, в магазин начальное состояние 
    pattern* p1m, * p2m, * p1g, * p2g;
    p1m = new pattern;
    p1m->type = 39;        //a
    p2m = new pattern;
    p2m->type = 26;        //квадратик
    p2m->prev = p1m;
    p1m = p2m;

    p1g = new pattern;
    p1g->type = 0;        //a
    p2g = new pattern;
    p2g->type = 0;        //квадратик
    p2g->prev = p1g;
    p1g = p2g;


    pattern* mag1, * gen1, * gen2;
    p1 = head;
    int mas1[100][3];
    string mas2[100];

    while (p1->next != nullptr) {
        pattern mag;
        lexem1 input;
        mag = *p2m;
        //delete p2m;
        p2m = p2m->prev;
        p1m = p1m->prev;
        input = *head;
        //header = header->next;
        if (input.type != mag.type) {
            p2m = p1m;
            p1m = new pattern;
            mag1 = &magazin[mag.type - 26][input.type];
            p1m = mag1;
            p1m->prev = p2m;
            while (mag1->prev != nullptr) {
                mag1 = mag1->prev;
                p2m = p1m;
                p1m = new pattern;
                p1m = mag1;
                p1m->prev = p2m;
            }
            p2g = p1g;
            p1g = new pattern;
            gen1 = &generator[mag.type - 26][input.type];
            p1g = gen1;
            p1g->prev = p2g;
            while (gen1->prev != nullptr) {
                gen1 = gen1->prev;
                p2g = p1g;
                p1g = new pattern;
                p1g = gen1;
                p1g->prev = p2g;
            }
        }
        else {
            head = head->next;
        }
        //убрать один элемент из генератора 
        pattern generTale;
        generTale = *p1g;
        p2g = p2g->prev;
        p1g = p1g->prev;
        p1 = p1->next;

        if (generTale.type == 1) {
            
        }
        else {
            if () {

            }
            else {

            }
        }
    }

    ///////////////////////////////////////////////////////////////////////////для интерпретатора
    read.open("hello.txt");
    //ops_list ourOPS; // Динамический список
    //constr_list(ourOPS);
    for (int i = 0; i < 2; i++) {
        M[i] = new pattern;
        Magazin[i] = new pattern;
    }
    Metka[0] = 5;
    Metka[1] = 1;
    S[0] = 1;
    S[1] = 2;
    /*
    //a
    M[0]->type = 20;
    M[0]->value = 3;
    M[0]->nom = 0;
    //b
    M[1]->type = 20;
    M[1]->value = 2;
    M[1]->nom = 1;
    //=
    M[2]->type = 3;
    M[2]->value = -100;
    M[2]->nom = -100;
    //a
    M[3]->type = 20;
    M[3]->value = 3;
    M[3]->nom = 0;
    //a
    M[4]->type = 20;
    M[4]->value = 3;
    M[4]->nom = 0;
    //2
    M[5]->type = 21;
    M[5]->value = 2;
    M[5]->nom = -1;
    ////-'
    //M[4]->type = 13;
    //M[4]->value = -100;
    //M[4]->nom = -100;
    ////+
    //M[5]->type = 12;
    //M[5]->value = -100;
    //M[5]->nom = -100;
    //+
    M[6]->type = 9;
    M[6]->value = -100;
    M[6]->nom = -100;
    //=
    M[7]->type = 3;
    M[7]->value = -100;
    M[7]->nom = -100;*/
    /*
    //a
    M[0]->type = 20;
    M[0]->value = 3;
    M[0]->nom = 0;
    //b
    M[1]->type = 20;
    M[1]->value = 4;
    M[1]->nom = 1;
    //>
    M[2]->type = 15;
    M[2]->value = -100;
    M[2]->nom = -100;
    //m1
    M[3]->type = 22;
    M[3]->value = 5;
    M[3]->nom = 0;
    //jf
    M[4]->type = 8;
    M[4]->value = -1;
    M[4]->nom = -1;
    //a
    M[5]->type = 20;
    M[5]->value = 3;
    M[5]->nom = 0;
    //b
    M[6]->type = 20;
    M[6]->value = 4;
    M[6]->nom = 1;
    //=
    M[7]->type = 3;
    M[7]->value = -100;
    M[7]->nom = -100;
    //m2
    M[8]->type = 22;
    M[8]->value = 1;
    M[8]->nom = 1;
    //j
    M[9]->type = 7;
    M[9]->value = -1;
    M[9]->nom = -1;*/
    /*
    //a
    M[0]->type = 20;
    M[0]->value = 1;
    M[0]->nom = 0;
    //b
    M[1]->type = 20;
    M[1]->value = 2;
    M[1]->nom = 1;
    //<
    M[2]->type = 14;
    M[2]->value = -100;
    M[2]->nom = -100;
    //m1
    M[3]->type = 22;
    M[3]->value = 9;
    M[3]->nom = 0;
    //jf
    M[4]->type = 8;
    M[4]->value = -1;
    M[4]->nom = -1;
    //a
    M[5]->type = 20;
    M[5]->value = 1;
    M[5]->nom = 0;
    //a
    M[6]->type = 20;
    M[6]->value = 1;
    M[6]->nom = 0;
    //b
    M[7]->type = 20;
    M[7]->value = 2;
    M[7]->nom = 1;
    //2
    M[8]->type = 21;
    M[8]->value = 2;
    M[8]->nom = -1;
    //:
    M[9]->type = 12;
    M[9]->value = -100;
    M[9]->nom = -100;
    //+
    M[10]->type = 9;
    M[10]->value = -100;
    M[10]->nom = -100;
    //=
    M[11]->type = 3;
    M[11]->value = -100;
    M[11]->nom = -100;
    //m2
    M[12]->type = 22;
    M[12]->value = 1;
    M[12]->nom = 1;
    //j
    M[13]->type = 7;
    M[13]->value = -1;
    M[13]->nom = -1;*/
    ////a
    //M[0]->type = 20;
    //M[0]->value = -1;
    //M[0]->nom = 0;
    ////r
    //M[1]->type = 4;
    //M[1]->value = -1;
    //M[1]->nom = -1;


    justdoit();
    //cout << S[0];
}
