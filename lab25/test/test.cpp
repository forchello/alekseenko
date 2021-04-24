#include "../src/book_array_class.h"

void test()
{
    BOOK_ARRAY test_collection(6);

    string path = "files/read.txt";

    ifstream test(path);
    test >> test_collection;

    if ( test_collection[1] > test_collection[2] )
    {
        cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "┃    Функция " << __FUNCTION__ <<" сработала успешно!   ┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    }
    else
    {
        cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "┃   Функция " << __FUNCTION__ <<" сработала с ошибкой!  ┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    }
   
};

int main()
{
    test();
    return 0;
}