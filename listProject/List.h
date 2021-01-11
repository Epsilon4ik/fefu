#pragma once

struct Node
{
    int data;
    Node* next, * prev;
};

class List
{
    Node* Head, * Tail;
    int size;

public:
    // �����������
    List();
    // ����������
    ~List();

    int GetSize();//���������� ��������� � ������

    int find(int value);

    void destroy();// ������� ���� ������

    void erase(int index);// �������� �������� �� �������
    void eraseNext(Node* node);// �������� �������� �� �������
    void erasePrev(Node* node);// �������� �������� �� �������

    void Insert(int pos, int data); // ������� ��������, ���� �������� �� �����������

    void push_back(int data);// ���������� � ����� ������
    void push_front(int data);// ���������� � ������ ������

    void pop_front();//�������� �� ������
    void pop_back();//�������� �� �����
    void remove(int value);

    void Print();// ������ ����� ������

    bool empty();//�������� �� ��,������ �� ������

    void sort();
};