/**
 * @mainpage
 * # Загальне завдання
 * 3. **Визначити** об'єм запитаного каталогу
 * @author Alekseenko N.
 * @date 17-jan-2021
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи структури та методів
 * оперування ним.
 *
 * @author Alekseenko N.
 * @date 17-jan-2021
 * @version 1.0
 */

#include <stdio.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


//static                                    // статическая переменная для определения размерности директории

/**
 * *Функція tree_result*
 *
 * Послідовність дій:
 * - оголошеня змінних 
 *  \param mb_size - розмір директорії
 *  \param end - параметр для очищення адреси файлу
 *  \param struct stat statbuf - структура stat
 *  \param struct dirent *dp - структура dirent
 *  \param DIR *d - показчик на назву директорії
 * - Спочатку вписуємо назву директорії, яку потрібно прочитати
 * - Перевіряємо можливість відкриття директорії
 * - Рахуємо об'єм директорії і передаємо його в основну функцію для виведення результату
 *  @return об'єм директорії (mb_size)
 */

double tree_result( char *t, int l )
{

    double mb_size = 0.0;

    size_t end;
    

    struct stat statbuf;

    DIR *d = opendir( t );

    struct dirent *dp;

    int ddd, fff;

    if ((d = fdopendir((ddd = open( t, O_RDONLY)))) == NULL)    // вариант невозможности открытия директории
    {
        fprintf(stderr, "Cannot open %s directory\n", t);
        return 1;
    }


    while ((dp = readdir(d)) != NULL)                           // цикл для считывания содержимого директории 
    {
        if (dp->d_name[0] == '.')
            continue;


        if ((fff = openat(ddd, dp->d_name, O_RDONLY)) == -1)    
        {
            perror(dp->d_name);
            continue;
        }

        if (fstat(fff, &statbuf) == 0 && (statbuf.st_mode & S_IFDIR)) 
        {          
            end = strlen(t);

            strcat ( t, "/" );                                              // образование адреса файла
            strcat ( t, dp->d_name );                           

            mb_size += tree_result( t, l + 1 );

            t[end] = 0;
        }
        else 
        {
            mb_size += ( double ) statbuf.st_size / 1000 ;                  // вычисляем размерность директории
        }

        close(fff);
    
    
    }

    closedir(d);

    return mb_size;

}

/**
 * *Функція main*
 *
 * Послідовність дій:
 * - оголошеня змінних 
 * \param text - вхідна назва папки
 *  @return успішний код повернення з програми (0)
 */

int main () 
{   
    

    char text[100];

    scanf("%s", text );

    printf("\nSize of the '%s' directory is: %.2f kB\n", text, tree_result(text, 0));


    return 0;
}





