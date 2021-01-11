#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next, *prev;
};

class List
{
    Node *Head, *Tail;
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

    void Insert(int pos,int data); // Вставка элемента в произвольное место
    void insert_after(Node* node,int value); // Вставка после
    void insert_before(Node* node, int value); // Вставка до

    void push_back(int data);// Добавление в конец списка
    void push_front(int data);// Добавление в начало списка

    void pop_front();//удаление из начала
    void pop_back();//удаление из конца
    void remove(int value);//удаление по значению

    void Print();// Печать всего списка

    bool empty();//проверка на то,пустой ли список

    void sort();
};

List::List()
{
    Head = Tail = NULL;
    size = 0;
}

List::~List()
{
    destroy();
}

void List::push_front(int data)
{
    Node* temp = new Node;

    temp->prev = 0;
    temp->data = data;
    temp->next = Head;

    if (Head != 0)
        Head->prev = temp;

    if (size == 0)
        Head = Tail = temp;
    else
        Head = temp;

    size++;
}

void List::push_back(int data)
{
    Node* temp = new Node;

    temp->next = 0;
    temp->data = data;
    temp->prev = Tail;

    if (Tail != 0)
        Tail->next = temp;

    if (size == 0)
        Head = Tail = temp;
    else
        Tail = temp;

    size++;
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

    // Доходим до элемента,который предшествует
    Node* PrevIns = Ins->prev;

    // Создаем новый элемент
    Node* temp = new Node;
    temp->data = data;

    // настройка связей
    if (PrevIns != 0 && size != 1)
        PrevIns->next = temp;

    temp->next = Ins;
    temp->prev = PrevIns;
    Ins->prev = temp;

    size++;
}

void List::insert_after(Node* node, int value)
{
    Node* Ins = node->next;
    Node* PrevIns = node;

    Node* temp = new Node;
    temp->data = value;

    if (PrevIns != 0 && size != 1)
        PrevIns->next = temp;

    temp->next = Ins;
    temp->prev = PrevIns;
    Ins->prev = temp;

    size++;
}

void List::insert_before(Node* node, int value)
{
    Node* Ins = node->prev;
    Node* NextIns = node;

    Node* temp = new Node;
    temp->data = value;

    if (NextIns != 0 && size != 1)
        NextIns->prev = temp;

    temp->next = NextIns;
    temp->prev = Ins;
    Ins->next = temp;

    size++;
}

void List::erase(int pos)
{
    int i = 1;

    Node* Del = Head;

    while (i < pos)
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

    if (pos == 1)
        Head = AfterDel;
    if (pos == size)
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
    erase(1);
}

void List::pop_back()
{
    erase(size);
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
        erase(1);
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

