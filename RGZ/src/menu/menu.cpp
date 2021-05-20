#include "menu.h" 

MENU::~MENU()
{
    library.clear();
}

void MENU::start()
{   
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃          ВЫБИРЕТЕ ДЕЙСТВИЕ         ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl << endl;

    cout << "━  Чтение с файла        [1]" << endl;
    cout << "━  Запись в файл         [2]" << endl;
    cout << "━  Вывести в консоль     [3]" << endl;
    cout << "━  Сортировка элементов  [4]" << endl;
    cout << "━  Методы коллекции      [5]" << endl;
    cout << "━  Добавить книгу        [6]" << endl;
    cout << "━  Удалить книгу         [7]" << endl;
    cout << "━  Выход                 [8]" << endl;
    cout << endl << "━  ";

    short int n;
    cin >> n;

    cout << endl << endl;
    
    switch ( n )
    {
        case 1:
        {
            string path;

            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
            cout << "━     ЧТЕНИЕ ИЗ ФАЙЛА    ━" << endl;
            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
            cout << "━  Введите путь к файлу:" << endl << endl << "━  ";

            cin >> path;
            
            cout << endl << endl;

            library.read_from_file( path );

            break;
        }
            
        case 2:
        {   
            string path;
            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
            cout << "━      ЗАПИСЬ В ФАЙЛ     ━" << endl;
            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
            cout << "━  Введите путь к файлу: ━" << endl << endl << "━  ";

            cin >> path;

            cout << endl << endl;

            library.write_to_file( path );

            break;
        }

        case 3:
        {
            library.print_library();
            break;
        }
            
        case 4:
        {
            library.sorting();
            break;
        }
           
        case 5:
        {
            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
            cout << "━      МЕТОДЫ РАБОТЫ С КОЛЛЕКЦИЕЙ   ━" << endl;
            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl << endl;

            cout << "━  Найти самую большую книгу       [1]" << endl;
            cout << "━  Найти детектив с эл.версией     [2]" << endl;
            cout << "━  Найти книги издательства РАНОК  [3]" << endl;
            cout << endl << "━  ";
            short int n;
            cin >> n;

            cout << endl << endl;

            switch ( n )
            {
                case 1:
                {
                    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
                    cout << "┃              Cамая большая книга - №" << library.biggest_book() << "                  ┃" << endl;
                    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

                    break;
                }

                case 2:
                {
                    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
                    cout << "┃     Программа нашла " << library.find_detective() << " детектив (а/ов) с эл.версией     ┃" << endl;
                    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

                    break;
                }

                case 3:
                {
                    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
                    cout << "┃    Программа нашла " << library.find_ranok_book() << " книг(и/у) издательства 'РАНОК'    ┃" << endl;
                    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

                    break;
                }
            } 

            cout << endl << endl;

            break;
        }       

        case 6:
        {
            SCIENTIFIC_BOOK* book = new SCIENTIFIC_BOOK;
            book->from_string("true ADDED_BOOK 25 небо 34 myaka programming true");

            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
            cout << "━     В КАКУЮ ПОЗИЦИЮ ПОЛОЖИТЬ КНИГУ?    ━" << endl;
            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl << endl << "━  ";

            short int index;
            cin >> index;

            library.add_book( book, index );

            cout << endl << endl;

            break;
        }

        case 7:
        {
            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
            cout << "━     С КАКОЙ ПОЗИЦИИ УДАЛИТЬ КНИГУ?     ━" << endl;
            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl << endl << "━  ";

            short int index;
            cin >> index;

            library.delete_book( index );

            cout << endl << endl;
            
            break;
        }

        case 8:
            return;
    }

    cout << endl << endl;
    start();

}