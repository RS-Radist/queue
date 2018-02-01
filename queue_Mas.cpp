#include <iostream>
using namespace std;
class CircleQueue
{
private:
    
    int size;
    int arr[10];
    int end,begin;
public:
    CircleQueue():size(0)
    {}
    void Push(int x)
    {
        if (size==0){
            arr[0]=x;
            size++;
        }
        else
        {
            int temp[size];
            int k=1;
            for (int i=0;i<size;++i)
            {
                temp[k]=arr[i];
                k++;
            }
            temp[0]=x;
            for (int i=0;i<size+1;++i)
            {
                arr[i]=temp[i];
            }
            size++;
        }
    }
    void Show()
    {
        for (int i=0;i<size;++i)
        {
            cout<<arr[i]<<" ";
        }
    }
    void End()
    {
        int max=-1;
        for (int i=0;i<size;++i)
        {
            if (max<i)
            {
                end=arr[i];
            }
        }
        cout<<end;
    }
    void Begin()
    {
        begin=arr[0];
        cout<<begin;
    }
    void Pop()
    {
        if (size==0)
        {
            cout<<"Очередь пустая";
            return;
        }
        int temp[size-1];
        int k=0;
        for (int i=0;i<size;++i)
        {
            temp[k]=arr[i+1];
            k++;
        }
        size--;
        for (int i=0;i<size;++i)
        {
            arr[i]=temp[i];
        }
    }
    int ClearQueue()
    {
        //Нужно сдедать
        return 0;
    }
};


int main() {
    CircleQueue Cqu;
    cout<<"Очередь-";
    Cqu.Push(50);
    Cqu.Push(51);
    Cqu.Push(52);
    Cqu.Push(53);
    Cqu.Show();
    cout<<endl;
    cout<<"Начало-";
    Cqu.Begin();
    cout<<endl;
    cout<<"Конец-";
    Cqu.End();
    cout<<endl;
    cout<<"Удаление-";
    Cqu.Pop();
    Cqu.Pop();
    Cqu.Pop();
    Cqu.Show();
    cout<<endl;
    cout<<"Удаляем все элементы-";
    //cout<<ClearQueue();
    return 0;
}