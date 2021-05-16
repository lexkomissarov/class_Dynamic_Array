#include <iostream>

using namespace std;

class List
{
private:
    int dSize; // На сколько меняется вместимость
    int size; // Число элементов в списке
    int capacity; // Вместимость списка (<= size)
    int* buffer; // Внутренний буфер

    void extendBuff(); // Расширить внутренний буфер на dSize

public:
    List(); // Создать
    List(int capacity, int dSize = 1); // Указатели
    void add(int n); // Добавить в список элемент n
    int getAt(int i); // Получить элемент списка по индексу i
    int indexOf(int n); // Найти индекс элемента n в списке. -1 если его нет
    void remove(int n); // Удалить первое найденное вхождение элемента n в списке
    void removeAt(int i); // Удалить элемент по индексу i
    int getSize(); // Получить размер списка
    int operator [](int i); // Определение оператора индексации []
    void print(); // Вывод
};

List::List() : List(0) {} // Создать

List::List(int capacity, int dSize) // Указатели
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

void List::print() // Вывод
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

    cout << "Элемент с индексом 0: " << dmas.getAt(0) << endl;
    cout << "Элемент с индексом 3: " << dmas[3] << endl;
    cout << endl;

    cout << "Размер массива: " << dmas.getSize() << endl;
    cout << endl;

    cout << "Индекс элемента 16: " << dmas.indexOf(16) << endl;
    cout << endl;

    cout << "Удалить элемент 16" << endl;
    dmas.remove(16);
    dmas.print();
    cout << endl;

    cout << "Удалить элемент с индексом 5" << endl;
    dmas.removeAt(5);
    dmas.print();
    cout << endl;

    cout << "Размер массива: " << dmas.getSize() << endl;

    return 0;
}