#include "List.h"
#include <iostream>
using namespace std;

int main()
{
    //������� ������ �� int
    List list1;

    //��������� ��������
    for (int i = 0; i < 10; i++)
        list1.push_front(i);//� ������

    if (list1.empty())//�������� ������ �� �������
        cout << "List is empty" << endl;
    else cout << "List is not empty" << endl;

    list1.Insert(1, 10);//��������� ������� �� ������� 1

    list1.Print();

    list1.erase(5);

    list1.pop_front();
    list1.pop_back();

    list1.Print();

    list1.remove(1);

    list1.Print();
    cout << "position of 3 is " << list1.find(3) << endl;//���� ������� ������

    list1.sort();
    list1.Print();

    list1.destroy();

    return 0;
}


