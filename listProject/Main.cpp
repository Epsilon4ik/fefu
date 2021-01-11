#include "List.h"
#include <iostream>
using namespace std;

int main()
{
    //создаем список из int
    List list1;

    //добавляем элементы
    for (int i = 0; i < 10; i++)
        list1.push_front(i);//в начало

    if (list1.empty())//проверка списка на пустоту
        cout << "List is empty" << endl;
    else cout << "List is not empty" << endl;

    list1.Insert(1, 10);//добавляем десятку по индексу 1

    list1.Print();

    list1.erase(5);

    list1.pop_front();
    list1.pop_back();

    list1.Print();

    list1.remove(1);

    list1.Print();
    cout << "position of 3 is " << list1.find(3) << endl;//ищем позицию тройки

    list1.sort();
    list1.Print();

    list1.destroy();

    return 0;
}


