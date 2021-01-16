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

    int find(int value);//найти звено по значению

    void destroy();// Удалить весь список

    void erase(int index);// Удаление элемента по индексу
    void eraseNext(Node* node);// Удаление элемента по индексу
    void erasePrev(Node* node);// Удаление элемента по индексу

    void Insert(int index, int data); // Вставка элемента в произвольное место
    void insert_after(Node* node, int value); // Вставка после
    void insert_before(Node* node, int value); // Вставка до

    void push_back(int data);// Добавление в конец списка
    void push_front(int data);// Добавление в начало списка

    void pop_front();//удаление из начала
    void pop_back();//удаление из конца
    void remove(int value);//удаление по значению

    void Print();// Печать всего списка

    bool empty();//проверка на то,пустой ли список

    void sort();

    void setLinks(Node* prevIns, Node* Ins2, Node* Ins, Node* temp);

    Node* createNewNode(int data);
};