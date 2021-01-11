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
    // Конструктор
    List();
    // Деструктор
    ~List();

    int GetSize();//количество элементов в списке

    int find(int value);

    void destroy();// Удалить весь список

    void erase(int index);// Удаление элемента по индексу
    void eraseNext(Node* node);// Удаление элемента по индексу
    void erasePrev(Node* node);// Удаление элемента по индексу

    void Insert(int pos, int data); // Вставка элемента, если параметр не указывается

    void push_back(int data);// Добавление в конец списка
    void push_front(int data);// Добавление в начало списка

    void pop_front();//удаление из начала
    void pop_back();//удаление из конца
    void remove(int value);

    void Print();// Печать всего списка

    bool empty();//проверка на то,пустой ли список

    void sort();
};