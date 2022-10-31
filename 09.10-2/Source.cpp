#include <iostream>
using namespace std;

template<class T>
struct Elem
{
    T data;
    Elem<T>* next;
    Elem<T>* prev;
};
template<class T>
class QueueList
{
    Elem<T>* head;
    Elem<T>* tail;
    int Count;

public:
    QueueList();
    void AddTail(T a);
    Elem<T> Extract();
    bool IsEmpty();
    void Print();
    int GetCount();
    T GetFirst();
    ~QueueList();
};

template<class T>
QueueList<T>::QueueList()
{
    head = tail = nullptr;
    Count = 0;
}

template<class T>
void QueueList<T>::AddTail(T a)
{
    Elem<T>* tmp = new Elem<T>;
    tmp->next = 0;
    tmp->data = a;
    tmp->prev = tail;
    if (tail != 0)
        tail->next = tmp;
    if (Count == 0)
        head = tail = tmp;
    else
        tail = tmp;
    Count++;
}

template<class T>
Elem<T> QueueList<T>::Extract()
{
    Elem<T>* tmp = head;
    head->prev = nullptr;
    head = head->next;
    Elem<T> buf;
    buf.data = tmp->data;
    delete[]tmp;

    Count--;
    return buf;
}

template<class T>
bool QueueList<T>::IsEmpty()
{
    if (Count != 0)
        return false;
    else
        return true;
}

template<class T>
void QueueList<T>::Print()
{
    if (Count != 0)
    {
        Elem<T>* temp = head;
        while (temp->next != 0)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << temp->data << ", ";
        cout << "\n";
    }
}

template<class T>
int QueueList<T>::GetCount()
{
    return Count;
}

template<class T>
T QueueList<T>::GetFirst()
{
    return head->data;
}

template<class T>
QueueList<T>::~QueueList()
{
    while (Count != 0)
    {
        Elem<T>* del = head;
        head = head->next;
        delete[]del;
        Count--;
    }
}

int main()
{
    QueueList<int> L;
    const int size = 10;
    int arr[size] = { 0,1,2,3,4,5,6,7,8,9 };
    for (int i = 0; i < size; i++)
        L.AddTail(arr[i]);
    L.Print();
    cout << endl << L.GetFirst();
    cout << endl << L.GetCount();
    cout << endl << L.IsEmpty();
    cout << endl << L.Extract().data;
    cout << endl;
    L.Print();
    cout << endl << L.GetCount();
}