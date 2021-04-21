#include "../src/book_array_class.h"

void test()
{
    BOOK_ARRAY test_collection(6);

    string path = "files/read.txt";

    test_collection.read_from_file( path );

    int result = test_collection.find_ranok_book();

    if ( result == 3 )
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