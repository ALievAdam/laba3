

#include <iostream>
#include<Windows.h>
#include<string>

using namespace std;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int i = 0, k;
    char ABC[] =
    {
                'а','б','в','г','д','е','ё','ж','з','и',
                'й','к','л','м','н','о','п','р','с',
                'т','у','ф','х','ц','ч','ш','щ','ъ',
                'ы','ь','э','ю','я' 
    };
    char msg[150];
    cout << "Введите сообщение строчными буквами, которое будет закодировано: " << endl;
    cin.getline(msg, 150);
    cout << "\nВведите сдвиг:" << endl;
    cin >> k;
    cout << endl;
    char* begin = ABC;
    char* end = ABC + sizeof(ABC);
    for (; msg[i]; ++i)
    {
        char* ch = find(begin, end, msg[i]);
        if (ch != end) msg[i] = *(begin + (ch - begin + k) % sizeof(ABC));
    }
    cout << "Полученное закодированное сообщение: " << endl;
    cout << msg << endl;
    return 0;
}

