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

    void SetSize(int s){
		size = s;
		arr = new int[size];
	}

    int GetSize()const
    {
        return size;
    }

	void SetArr(int* a) {
        arr = a;

	}

    int* GetArr() {
		return arr;
    }

    int& operator[](int index)
    {
        if (index >= 0 && index < size)
        {
            return arr[index];
        }
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

        if (arr != nullptr) {
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

    operator int() {
        return size;
    }

    void operator() () {
        cout << "Array: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }


    Myvector operator+=(int num) {
        int* newArr = new int[size + num];

        for (size_t i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        for (size_t i = 0; i < num; i++) {
            newArr[size + i] = rand() % 50;
        }

        delete[] arr;
        arr = newArr;
        size += num;
        return *this;

    }

    Myvector operator-=(int num) {
        int* newArr = new int[size + num];

        for (size_t i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        for (size_t i = 0; i < num; i++) {
            newArr[size - i] = rand() % 50;
        }

        delete[] arr;
        arr = newArr;
        size -= num;
        return *this;

    }

    Myvector operator*=(int num) {
        int* newArr = new int[size + num];

        for (size_t i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        for (size_t i = 0; i < num; i++) {
            newArr[i] *= 5;
        }

        delete[] arr;
        arr = newArr;
        size -= num;
        return *this;

    }

    Myvector operator = (Myvector&& vec) {
        size = vec.size;
        arr = vec.arr;
        vec.size = 0;
        vec.arr = nullptr;
        return *this;   


    }




};

    Myvector operator+ (int b, Myvector& obj)
    {
        Myvector newSize = obj;
        for (size_t i = 0; i < newSize.GetSize(); i++)
        {
			newSize[i] += b;
        }
		return Myvector(newSize);
    }

    Myvector operator-- (Myvector& obj) {
		Myvector newSize(obj.GetSize() - 1);
        for (size_t i = 1; i < obj.GetSize(); i++) {
			newSize[i - 1] = obj[i];
        }
		obj = newSize;
        return obj;
    }


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

        int size = vec1;
        cout << "Size = " << size << endl;

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

        cout << endl;
        cout << "+=" << endl;
        Myvector vec5(10);
        vec5.Init();
        vec5 += 5;
        vec5.Print();

        cout << endl;
        cout << "-=" << endl;
        Myvector vec6(10);
        vec6.Init();
        vec6 -= 5;
        vec6.Print();

        cout << endl;
        cout << "*=" << endl;
        Myvector vec7(10);
        vec7.Init();
        vec7 *= 5;
        vec7.Print();

		cout << endl;   

        Myvector vec8 = 5 + vec1;
		vec8.Print();

        Myvector vec9(10);
        vec9.Init();
		--vec9;
        vec9.Print();
}