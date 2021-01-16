#include <iostream>
#include "List.h"
using namespace std;

List::List()
{
    Head = Tail = nullptr;
    size = 0;
}

List::~List()
{
    destroy();
}

void List::push_front(int data)
{
    Node* temp = createNewNode(data);

    temp->prev = 0;
    temp->next = Head;

    if (Head != nullptr)
        Head->prev = temp;

    if (size == 0)
        Head = Tail = temp;
    else
        Head = temp;
}

void List::push_back(int data)
{
    Node* temp = createNewNode(data);

    temp->next = 0;
    temp->prev = Tail;

    if (Tail != nullptr)
        Tail->next = temp;

    if (size == 0)
        Head = Tail = temp;
    else
        Tail = temp;
}

void List::setLinks(Node* prevIns,Node* nextIns,Node* Ins,Node* temp)
{
    if (prevIns != nullptr)
    {
        if (prevIns != 0 && size != 1)
            prevIns->next = temp;

        temp->next = Ins;
        temp->prev = prevIns;
        Ins->prev = temp;
    }
    if (nextIns != nullptr)
    {
        if (nextIns != 0 && size != 1)
            nextIns->prev = temp;

        temp->next = nextIns;
        temp->prev = Ins;
        Ins->next = temp;
    }
}

Node* List::createNewNode(int data)
{
    // Создаем новый элемент
    Node* temp = new Node;
    temp->data = data;

    size++;
    return temp;
}

void List::Insert(int index,int data)
{
    if (index == size +1) // Добавление в конец списка
    {
        push_back(data);
        return;
    }
    else if (index == 0) // Добавление в начало списка
    {
        push_front(data);
        return;
    }

    int i = 0;

    Node* Ins = Head;

    while (i < index)
    {
        Ins = Ins->next;
        i++;
    }

    Node* PrevIns = Ins->prev;// Доходим до элемента,который предшествует

    Node* temp = createNewNode(data);//создаем новый элемент

    setLinks(PrevIns, nullptr, Ins, temp);//настраиваем связи
}

void List::insert_after(Node* node, int value)
{
    Node* Ins = node->next;
    Node* PrevIns = node;

    Node* temp = createNewNode(value);//создаем новый элемент

    setLinks(PrevIns, nullptr, Ins, temp);//настраиваем связи
}

void List::insert_before(Node* node, int value)
{
    Node* Ins = node->prev;
    Node* NextIns = node;

    Node* temp = createNewNode(value);

    setLinks(nullptr, NextIns, Ins, temp);//настраиваем связи
}

void List::erase(int index)
{
    int i = 0;

    Node* Del = Head;

    while (i < index)
    {
        Del = Del->next;
        i++;
    }
    Node* PrevDel = Del->prev;
    Node* AfterDel = Del->next;

    // Если удаляем не голову
    if (PrevDel != 0 && size != 1)
        PrevDel->next = AfterDel;
    // Если удаляем не хвост
    if (AfterDel != 0 && size != 1)
        AfterDel->prev = PrevDel;

    if (index == 0)
        Head = AfterDel;
    if (index == size-1)
        Tail = PrevDel;

    delete Del;

    size--;
}

void List::eraseNext(Node* node)
{
    Node* Prev = node;
    Node* After = node->next->next;

    Prev->next = After;
    After->prev = Prev;
    delete node->next;

    size--;
}

void List::erasePrev(Node* node)
{
    Node* Prev = node->prev->prev;
    Node* After = node;

    Prev->next = After;
    After->prev = Prev;
    delete node->prev;

    size--;
}

void List::pop_front()
{
    erase(0);
}

void List::pop_back()
{
    erase(size-1);
}

void List::remove(int value)
{
    int i = 1;

    Node* Del = Head;

    while (i <=  size)
    {
        if (Del->data == value)
        {
            Node* PrevDel = Del->prev;
            Node* AfterDel = Del->next;

            // Если удаляем не голову
            if (PrevDel != 0 && size != 1)
                PrevDel->next = AfterDel;
            // Если удаляем не хвост
            if (AfterDel != 0 && size != 1)
                AfterDel->prev = PrevDel;

            if (i == 1)
                Head = AfterDel;

            delete Del;

            size--;
            break;
        }
        Del = Del->next;
        i++;
    }
}

void List::Print()
{
    if (size != 0)
    {
        cout << "List:\n";

        Node* temp = Head;
        while (temp->next != 0)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }

        cout << temp->data << endl;
    }
}

void List::destroy()
{
    while (size != 0)
        erase(0);
}

int List::GetSize()
{
    return size;
}

bool List::empty()
{
    return size == 0;
}

int List::find(int value)
{
    int i = 0;

    Node* node = Head;

    while (i <= size)
    {
        if (node->data == value)
        {
            return i;
        }
        node = node->next;
        i++;
    }
    return -1;
}

void List::sort()
{
    Node* temp = Head;
    while (temp->next)
    {
        if ((temp->data) > (temp->next->data))
        {
            int temp2 = temp->next->data;
            temp->next->data = temp->data;
            temp->data = temp2;

            temp = temp->next;
            sort();
        }
        else temp = temp->next;
    }
}

