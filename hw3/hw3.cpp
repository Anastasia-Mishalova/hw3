// hw3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <ctype.h>
#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <typeinfo>
#include <fstream>
#include <malloc.h>
#include <cstring>.
using namespace std;

//Разработать класс String, который в дальнейшем будет использоваться для работы со строками.Класс должен содержать:
//Конструктор по умолчанию, позволяющий создать строку длиной 80 символов; Конструктор, позволяющий создавать строку произвольного размера;
//Конструктор, который создаёт строку и инициализирует её строкой, полученной от пользователя. Необходимо создать деструктор, а также использовать
//механизмы делегирования конструкторов, если это возможно. должен содержать методы для ввода строк с клавиатуры и вывода строк на экран.
// Также нужно реализовать статическую функцию - член, которая будет возвращать количество созданных объектов строк.

class String {
private:
    char* str;
    int l;      
    static inline unsigned count{};

public:

    String()
    {
        ++count;
        l = 80;
        str = new char[l+1];
    }

    String(int num)
    {     
        ++count;
        l = num;
        str = new char[l + 1];
    }

    String(const char* text)
    {
        ++count;
        l = strlen(text);
        str = new char[l + 1];
        strcpy(str, text);
    }

    ~String()
    {
        delete[] str;
    }

    void input()
    {

        cin.getline(str, l);
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    }

    void show()
    {
        cout << str << endl;
    }

    void print_count()
    {
        cout << "Создано объектов: " << count << endl;
    }
};


int main()
{
    setlocale(LC_ALL, "ru");

    String str_l80;
    str_l80.input();
    str_l80.show();

    cout << endl;

    String str_fixl(10);
    str_fixl.input();
    str_fixl.show();

    cout << endl;

    String str_replstr("Изначальный текст");
    str_replstr.show();
    str_replstr.input();
    str_replstr.show();
    str_replstr.print_count();
}