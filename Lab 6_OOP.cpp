/* 17.Створити шаблонний клас – чергу на основі зв’язного списку у динамічній пам’яті. 
Тип елементів черги визначається параметром шаблона (цілі числа, дійсні числа, символи або символьні рядки). 
Передбачити функції для виконання таких операцій: занесення елемента у чергу, вилучення елемента з черги, 
виведення усіх елементів черги на екран, визначення кількості елементів черги. */

#include <iostream>
#include <string>

using namespace std;

// Структура, що описує вузол
template <typename T>
struct Node
{
    T item;
    Node<T>* next;
};

// Шаблонний клас Черга на основі однозв'язного списку
template <typename T>
class Turn
{
private:
    Node<T>* first, * last;			// покажчик на вершину та останній елемент черги

public:
    // конструктор за замовчуванням
    Turn() { first = NULL; last = NULL; }

    // помістити елемент у чергу
    // елемент поміщається у кінець списку
    void Add_an_item(T item)
    {
        Node<T>* p;
        try 
        {
            p = new Node<T>; // спроба виділити пам'ять
        }
        catch (bad_alloc e)
        {
            // якщо пам'ять не виділилась, то вихід
            cout << e.what() << endl;
            return;
        }
        p->item = item;
        p->next = NULL;
        if (first != NULL)
        {
            last->next = p;
            last = p;
        }
        else
            first = last = p;
    }
    // видалення елементу із черги
    T Delete_an_item()
    {
        if (first == NULL)
            return 0;
        Node<T>* p2; 
        T item;
        item = first->item;
        p2 = first;
        first = first->next;
        delete p2;
        return item;
    }
    // вивід черги
    void Print(const char* objName)
    {
        cout << endl << "Object: " << objName << endl;
        if (first == NULL)
            cout << "Turn is empty." << endl;
        else
        {
            Node<T>* p; 
            p = first;
            while (p != NULL)
            {
                cout << p->item << "\t";
                p = p->next;
            }
            cout << endl;
        }
    }
    // кількість елементів у черзі
    int Amount()
    {
        if (first == NULL)
            return 0;
        else
        {
            Node<T>* p = first;
            int count = 0;
            while (p != NULL)
            {
                count++;
                p = p->next;
            }
            return count;
        }
        
    }
    // деструктор
    ~Turn()
    {
        Node<T>* p; 
        Node<T>* p2;
        p = first;
        while (p != NULL)
        {
            p2 = p;         // робимо копію з p
            p = p->next;    // переходимо на наступний елемент черги
            delete p2;      // видаляємо пам'ять, виділену під попередній елемент
        }
        first = NULL;    // поправляємо вершину черги
    }
};

int main(void)
{
    Turn<int> chysl;
    Turn<string> sentence;
    int x = 0;
    string p;
    for (int i = 0; i < 100; i++)
    {
        cout << "\t" << "Enter item: ";
        cin >> x;
        if (x == 0)
            break;
        chysl.Add_an_item(x);
    }
    chysl.Print("int data");
    cout << "Number of turn elements: " << chysl.Amount();
    int d;
    d = chysl.Delete_an_item();
    cout << endl << "Deleted item : " << d;
    chysl.Print("int data after delete: ");
    chysl.~Turn();
    chysl.Print("turn after deleting items");
    cout << endl;
    for (int i = 0; i < 100; i++)
    {
        cout << "\t" << "Enter item: ";
        cin >> p;
        if (p[0] == '\\')
            break;
        sentence.Add_an_item(p);
    }
    sentence.Print("string data");
    cout << "Number of turn elements: " << sentence.Amount();
    string d1;
    d1 = sentence.Delete_an_item();
    cout << endl << "Deleted item : " << d1;
    sentence.Print("string data after delete: ");
    sentence.~Turn();
    sentence.Print("turn after deleting items");
    system("pause");
    return 0;
}