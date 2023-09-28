#include <iostream>
using namespace std;

template <typename T>
struct Elem
{
    T data;
    Elem* next, * prev;
};

template <class T>
class Stack
{
    Elem<T>* Head, * Tail;
    int Count;

public:
    Stack();
    ~Stack();
    int GetCount();
    void DelAll();
    void Extract();
    void Add(T n);
    void Print();
};
template <class T>
Stack<T>::Stack()
{
    Head = Tail = NULL;
    Count = 0;
}

template <class T>
void Stack<T>::Extract()
{
    Elem<T>* temp = Tail;
    if (Count == 0)
        return;
    else
    {
        Tail = Tail->prev;
        if (Tail != NULL)
            Tail->next = NULL;
        else
            Head = NULL;
        delete temp;
        Count--;
    }
}
template <class T>
void Stack<T>::Add(T n)
{
    Elem<T>* t = new Elem<T>;
    t->data = n;
    t->prev = NULL;
    t->next = NULL;
    if (Count == 0)
        Tail = Head = t;
    else
    {
        t->prev = Tail;
        Tail->next = t;
        Tail = t;
    }
    Count++;
}
template <class T>
Stack<T>::~Stack()
{
    while (Count != 0)
        Extract();
}

template <class T>
void Stack<T>::Print()
{
    if (Count != 0)
    {
        Elem<T>* temp = Head;
        cout << "( ";
        while (temp != 0)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << ") ";
        cout << endl;
    }
}
template <class T>
void Stack<T>::DelAll()
{
    // Пока остаются элементы, удаляем по одному с головы
    while (Head != NULL)
        Extract();
}
template <class T>
int Stack<T>::GetCount()
{
    return Count;
}

void main()
{
    Stack<int> a;
    a.Add(1);
    a.Add(2);
    a.Add(3);
    a.Print();
    a.Extract();
    a.Extract();
    a.Print();
}

