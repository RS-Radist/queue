//Создать класс, реализующую очередь целых чисел типа FIFO.
//Данные класса: массив очереди, указатели на начало очереди и на конец очереди.
//Открытые функции: запись в начало очереди, чтение конца очереди.

#include <iostream>
using namespace std;
class Queue
{
private:
    int* arr;
    int* first,end;
    
    int size;
public:
    Queue():size(0)
    {}
    void Push(int x)
    {
        if (size==0)
        {
            arr=new int[size];
            arr[0]=x;
            /*
            arr[size]=x;
            int* temp=new int[size];
            memcpy(temp, arr, sizeof(int)*size);
            delete[] arr;
            arr=temp;
            first=arr;
            delete[] temp;
             */ // доделать через динамический массив
            first=arr;
            end=arr[0];
            size++;
        }
        else
        {
            int* temp=new int[size];
            for (int i=0;i<size+1;++i)
            {
                temp[i+1]=arr[i];
            }
            temp[0]=x;
            for (int i=0;i<size+1;++i)
            {
                arr[i]=temp[i];
            }
            delete[] temp;
            first=arr;
            size++;
            
        }
    }
    void Show()
    {
        for (int i=0;i<size;++i)
        {
            cout<<*(arr+i)<<" ";
        }
    }
    void Begin()
    {
        cout<<*first;
    }
    void End()
    {
        cout<<*first;
    }
    
};


int main()
{
    Queue queue;
    queue.Push(10);
    queue.Push(11);
    queue.Push(12);
    queue.Push(13);
    queue.Push(14);
    queue.Show();
    cout<<endl;
    queue.Begin();
    cout<<endl;
    queue.End();
    
}
