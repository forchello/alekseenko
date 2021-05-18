#include "stdio.h"
#include <string>
#include "stdlib.h"
#include <iostream>
#include "Class.h"

using namespace std;

template <typename T>

class Array
{
    int size;
    T *arr;

    public:

        Array()
        {
            arr=new T[0];
            size=0;
        }

        Array(const Array &other)
        {
            this->arr = other.arr;

            for( int i = 0; i < Array::size; i++ )
                this->arr[i]=other.arr[i];
        }

        ~Array()
        {
            delete[] arr;
        }

        void AddEl(T el)
        {
            T* temp = new T[size+1];

            for( int i = 0; i < size; i++ )
                temp[i]=arr[i];
            
            temp[size] = el;
            size++;
            arr = temp;
        }

        void DeleteEl(int position)
        {
            if( position >= size )
                position = size-1;
            
            T *temp = new T[size-1];

            for( int i = 0; i < position; i++ )
                temp[i]=arr[i];
            
            for( int i = position; i < size-1; i++ )
                temp[i] = arr[i+1];
            
            size--;
            arr=temp;
        }

        void Finder(T el)
        {
            for( int i = 0; i < size; i++ )
                if( arr[i] == el )
                    cout << "Элемент был найден в ячейке номер: " << i << endl;
            
        }

        void PrintArray()
        {
            for( int i = 0; i < size; i++ )
                cout << arr[i] << " ";
            
            cout << endl;
        }
        
        void SortArray()
        {
            for( int i = 0; i < size; i++ )
            {
                for( int j = 0; j < size-i; j++ )
                {
                    T temp;

                    if( arr[j] > arr[j+1] )
                        swap( arr[j], arr[j+1] );

                }
            }
        }

        T FindMin()
        {
            T min = arr[0];

            for( int i = 1; i < size; i++ )
                if( min > arr[i] )
                    min = arr[i];
            
            return min;
        }
};

template<>

class Array<Class*>
{
    int size;
    Class **arr;

    public:

    Array()
    {
        arr=new Class*[0];
        size=0;
    }

    Array(const Array &other)
    {
        this->arr = other.arr;

        for( int i = 0; i < Array::size; i++ )
            this->arr[i] = other.arr[i];
    }

    ~Array()
    {
        delete[] arr;
    }

    void AddEl(Class* el)
    {
        Class** temp = new Class*[size+1];

        for( int i = 0; i < size; i++ )
            temp[i]=arr[i];

        temp[size] = el;
        size++;
        arr = temp;
    }

    void DeleteEl( int position )
    {
        if( position >= size )
            position = size-1;
        
        Class **temp = new Class*[size-1];

        for( int i = 0; i < position; i++ )
            temp[i]=arr[i];
        
        for( int i = position; i < size-1; i++ )
            temp[i]=arr[i+1];

        size--;
        arr=temp;
    }

    void Finder(double el)
    {
        for( int i = 0; i < size; i++ )
            if( arr[i]->GetValue() == el )
                cout<<"Элемент был найден в ячейке номер: "<< i << endl;
    }

    void PrintArray()
    {
        for( int i = 0; i < size; i++ ) 
            cout << arr[i]->GetValue() << " ";
        cout << endl;
    }
    
    void SortArray()
    {
        for( int i = 0; i < size-1; i++ )
        {
            for( int j = 0; j < size-1-i; j++ )
            {
                Class* temp;

                if( arr[j]->GetValue() > arr[j+1]->GetValue() )
                    swap( arr[j], arr[j+1] );
            }
        }
    }

    double FindMin()
    {
        double min = arr[0]->GetValue();

        for( int i = 1; i < size; i++ )
            if(min>arr[i]->GetValue())
                min=arr[i]->GetValue();
        return min;
    }
};