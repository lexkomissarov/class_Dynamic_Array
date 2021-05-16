#include <iostream>

using namespace std;

class List
{
private:
    int dSize; // �� ������� �������� �����������
    int size; // ����� ��������� � ������
    int capacity; // ����������� ������ (<= size)
    int* buffer; // ���������� �����

    void extendBuff(); // ��������� ���������� ����� �� dSize

public:
    List(); // �������
    List(int capacity, int dSize = 1); // ���������
    void add(int n); // �������� � ������ ������� n
    int getAt(int i); // �������� ������� ������ �� ������� i
    int indexOf(int n); // ����� ������ �������� n � ������. -1 ���� ��� ���
    void remove(int n); // ������� ������ ��������� ��������� �������� n � ������
    void removeAt(int i); // ������� ������� �� ������� i
    int getSize(); // �������� ������ ������
    int operator [](int i); // ����������� ��������� ���������� []
    void print(); // �����
};

List::List() : List(0) {} // �������

List::List(int capacity, int dSize) // ���������
{
    this->size = 0;
    this->capacity = capacity;
    this->dSize = dSize;
    this->buffer = new int[capacity];
}

void List::extendBuff()
{
    int* buff = new int[this->capacity + this->dSize];

    for (int i = 0; i < this->size; ++i)
    {
        buff[i] = this->buffer[i];
    }

    delete[] this->buffer;
    this->buffer = buff;
    this->capacity += this->dSize;
}

void List::add(int n)
{
    if (this->size == this->capacity)
    {
        this->extendBuff();
    }

    this->buffer[this->size++] = n;
}

int List::getAt(int i)
{
    return this->buffer[i];
}

int List::indexOf(int n) {
    for (int i = 0; i < this->size; ++i)
    {
        if (this->buffer[i] == n)
        {
            return i;
        }
    }

    return -1;
}

void List::remove(int n)
{
    int i = this->indexOf(n);

    if (i != -1)
    {
        this->removeAt(i);
    }
}

void List::removeAt(int i)
{
    if (i < 0 || i >= this->size)
    {
        return;
    }

    for (int j = i; j < this->size - 1; ++j)
    {
        this->buffer[j] = this->buffer[j + 1];
    }

    this->size--;
}

int List::getSize()
{
    return this->size;
}

int List::operator[](int i)
{
    return this->buffer[i];
}

void List::print() // �����
{
    for (int i = 0; i < this->size; ++i)
    {
        cout << this->buffer[i] << " ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    List dmas;

    dmas.add(14);
    dmas.add(15);
    dmas.add(16);
    dmas.add(17);
    dmas.add(18);
    dmas.add(19);
    dmas.add(20);
    dmas.add(21);
    dmas.add(22);
    dmas.print();
    cout << endl;

    cout << "������� � �������� 0: " << dmas.getAt(0) << endl;
    cout << "������� � �������� 3: " << dmas[3] << endl;
    cout << endl;

    cout << "������ �������: " << dmas.getSize() << endl;
    cout << endl;

    cout << "������ �������� 16: " << dmas.indexOf(16) << endl;
    cout << endl;

    cout << "������� ������� 16" << endl;
    dmas.remove(16);
    dmas.print();
    cout << endl;

    cout << "������� ������� � �������� 5" << endl;
    dmas.removeAt(5);
    dmas.print();
    cout << endl;

    cout << "������ �������: " << dmas.getSize() << endl;

    return 0;
}