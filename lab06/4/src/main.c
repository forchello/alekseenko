int main() 
{
        int words = 0;          // количество слов
        int n = 0;              // количество символов в массиве 
        char m[] = "Hi there";  // переменная, в которую мы пишем предложение

        while (m[n] != '\0') 
        {
            n++;                // ищу количество символов  в массиве
        }

        for (int i = 0; i < n; i++)        // цикл для определения количества слов
        {

            if (m[i] != ' ' && m[i + 1] <= ' ')     // здесь мы игнорируем пробелы и правильно считаем слова
            {
                words++;
            }
        }

     	return 0;
}