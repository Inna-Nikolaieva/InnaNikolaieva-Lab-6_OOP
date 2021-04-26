/* 17.�������� ��������� ���� � ����� �� ����� �������� ������ � �������� �����. 
��� �������� ����� ����������� ���������� ������� (��� �����, ���� �����, ������� ��� �������� �����). 
����������� ������� ��� ��������� ����� ��������: ��������� �������� � �����, ��������� �������� � �����, 
��������� ��� �������� ����� �� �����, ���������� ������� �������� �����. */

#include <iostream>
#include <string>

using namespace std;

// ���������, �� ����� �����
template <typename T>
struct Node
{
    T item;
    Node<T>* next;
};

// ��������� ���� ����� �� ����� ������'������ ������
template <typename T>
class Turn
{
private:
    Node<T>* first, * last;			// �������� �� ������� �� ������� ������� �����

public:
    // ����������� �� �������������
    Turn() { first = NULL; last = NULL; }

    // �������� ������� � �����
    // ������� ��������� � ����� ������
    void Add_an_item(T item)
    {
        Node<T>* p;
        try 
        {
            p = new Node<T>; // ������ ������� ���'���
        }
        catch (bad_alloc e)
        {
            // ���� ���'��� �� ���������, �� �����
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
    // ��������� �������� �� �����
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
    // ���� �����
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
    // ������� �������� � ����
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
    // ����������
    ~Turn()
    {
        Node<T>* p; 
        Node<T>* p2;
        p = first;
        while (p != NULL)
        {
            p2 = p;         // ������ ���� � p
            p = p->next;    // ���������� �� ��������� ������� �����
            delete p2;      // ��������� ���'���, ������� �� ��������� �������
        }
        first = NULL;    // ����������� ������� �����
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