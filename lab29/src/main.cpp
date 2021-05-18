#include "Array.h"
#include "Class.h"
#include "Class1.h"

int main()
{
    srand(time(0));

    cout<<"----------------------------------------Работа с Классами----------------------------------------"<<endl;
    Array<Class*> a;

    Class c(5.15);
    a.AddEl(&c);

    Class c1(3.15);
    a.AddEl(&c1);

    Class c2(2.1);
    a.AddEl(&c2);

    Class c3(9.99);
    a.AddEl(&c3);

    cout << "Массив заполнен" << endl;
    a.PrintArray();

    cout<<"\nДобавление класса-наследника " <<endl;
    Class1 cc(3.1, 2);

    a.AddEl(&cc);

    a.PrintArray();

    cout<<"\nУдаление 2 элемента " << endl;
    a.DeleteEl(2);
    a.PrintArray();

    cout << "\nМинимальный элемент в массиве: " << a.FindMin() << endl;

    cout << "\nПоиск элемента `2.1`" <<endl;
    a.Finder(2.1);

    cout << "\nСортировка массива" << endl;

    a.SortArray();
    a.PrintArray();

    return 0;
}