#include <iostream>
#include <time.h>
using namespace std;

class Myvector
{
    int size;
    int* arr;
public:
    Myvector() :arr(nullptr), size(0) {}
    Myvector(int s) :size(s), arr(new int[size]) {}
    void Init()
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 50;
        }
    }
    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
    ~Myvector()
    {
        delete[]arr;
        size = 0;
    }

    int GetSize()const
    {
        return size;
    }
    int operator[](int index)
    {
        if (index >= 0 && index < size)
        {
            return arr[index];
        }
        return -1;
    }
    // конструктор копирования, 
    Myvector(const Myvector& obj2) {
        size = obj2.size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = obj2.arr[i];
		}
    }
    // конструктор переноса, 

    Myvector(Myvector&& obj2) {
        size = obj2.size;
        arr = obj2.arr;
        obj2.size = 0;
        obj2.arr = nullptr;
    }

    // = с копированием.
    Myvector operator = (const Myvector& obj2) {
        if (this == &obj2) {
            return *this;
        }

        if(arr != nullptr) {
            delete[] arr;
		}

        size = obj2.size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = obj2.arr[i];
        }

		return *this;
	}

    // ++ (добавляет 1 элемент в конец массива, значение = 0),
    Myvector operator++(int) {
        Myvector temp = *this;
        int* newArr = new int[size + 1];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        newArr[size] = 0;
        delete[] arr;
        arr = newArr;
        size++;
		return temp;

    }

    // -- удаляет последний элемент массива
    Myvector operator--(int) {
        Myvector temp = *this;
        int* newArr = new int[size - 1];
        for (int i = 0; i < size - 1; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
		size--;
		return temp;
    }

};

int main() {
    srand(time(NULL));

    Myvector vec1(10);
    vec1.Init();
    vec1.Print();

    for (int i = 0; i < vec1.GetSize(); i++)
    {
        cout << vec1[i] << "\t";
    }
    cout << endl;

    cout << "Constructor copy" << endl;
	Myvector vec2 = vec1;
    vec2.Print();

	cout << endl;
    cout << "Constructor ++" << endl;
	Myvector vec3(10);
	vec3.Init();
    vec3++;
    vec3.Print();

    cout << endl;
	cout << "Constructor --" << endl;
	Myvector vec4(10);
    vec4.Init();
    vec4--;
	vec4.Print();
    










}