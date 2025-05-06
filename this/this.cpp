//#include <iostream>
//using namespace std;
//
//class Array {
//    int* data;
//    int size;
//
//public:
//    Array()
//        : data(nullptr), size(0)
//    {
//    }
//
//    Array(int sizeP)
//        : data(new int[sizeP]), size(sizeP)
//    {
//        for (int i = 0; i < size; ++i)
//        {
//            data[i] = 0;
//        }
//    }
//
//    Array(const Array& other)
//        : data(new int[other.size]), size(other.size)
//    {
//        for (int i = 0; i < size; ++i)
//        {
//            data[i] = other.data[i];
//        }
//    }
//
//    ~Array()
//    {
//        delete[] data;
//    }
//
//    void fill()
//    {
//        for (int i = 0; i < size; ++i)
//        {
//            cout << "element [" << i << "]: ";
//            cin >> data[i];
//        }
//    }
//
//    void print() const
//    {
//        for (int i = 0; i < size; ++i)
//        {
//            cout << data[i] << ' ';
//        }
//        cout << '\n';
//    }
//
//    void resize(int newSize)
//    {
//        int* newData = new int[newSize];
//        int minSize = (size < newSize) ? size : newSize;
//        for (int i = 0; i < minSize; ++i)
//        {
//            newData[i] = data[i];
//        }
//        for (int i = minSize; i < newSize; ++i)
//        {
//            newData[i] = 0;
//        }
//        delete[] data;
//        data = newData;
//        size = newSize;
//    }
//
//    void sort()
//    {
//        for (int i = 0; i < size - 1; ++i)
//        {
//            for (int j = 0; j < size - i - 1; ++j)
//            {
//                if (data[j] > data[j + 1])
//                {
//                    int temp = data[j];
//                    data[j] = data[j + 1];
//                    data[j + 1] = temp;
//                }
//            }
//        }
//    }
//
//    int getMin() const
//    {
//        if (size == 0) return 0;
//        int min = data[0];
//        for (int i = 1; i < size; ++i)
//        {
//            if (data[i] < min)
//            {
//                min = data[i];
//            }
//        }
//        return min;
//    }
//
//    int getMax() const
//    {
//        if (size == 0) return 0;
//        int max = data[0];
//        for (int i = 1; i < size; ++i)
//        {
//            if (data[i] > max)
//            {
//                max = data[i];
//            }
//        }
//        return max;
//    }
//
//    Array* self()
//    {
//        return this;
//    }
//
//    int& operator[](int index)
//    {
//        if (index < 0 || index >= size)
//        {
//            cout << "Index out of bounds!\n";
//            exit(1);
//        }
//        return data[index];
//    }
//
//    void operator()(int value)
//    {
//        for (int i = 0; i < size; ++i)
//        {
//            data[i] = data[i] + value;
//        }
//    }
//
//    operator int() const
//    {
//        int sum = 0;
//        for (int i = 0; i < size; ++i)
//        {
//            sum = sum + data[i];
//        }
//        return sum;
//    }
//
//    operator char* () const
//    {
//        int totalLength = 0;
//        for (int i = 0; i < size; ++i)
//        {
//            int number = data[i];
//            int digitCount = 0;
//            if (number == 0)
//            {
//                digitCount = 1;
//            }
//            else
//            {
//                if (number < 0)
//                {
//                    digitCount = 1;
//                    number = -number;
//                }
//                while (number > 0)
//                {
//                    digitCount = digitCount + 1;
//                    number = number / 10;
//                }
//            }
//            totalLength = totalLength + digitCount;
//            if (i != size - 1)
//            {
//                totalLength = totalLength + 1;
//            }
//        }
//
//        totalLength = totalLength + 1;
//
//        char* str = new char[totalLength];
//        int pos = 0;
//
//        for (int i = 0; i < size; ++i)
//        {
//            int number = data[i];
//            char buffer[12];
//            int bufferSize = 0;
//
//            if (number == 0)
//            {
//                buffer[0] = '0';
//                bufferSize = 1;
//            }
//            else
//            {
//                bool isNegative = false;
//                if (number < 0)
//                {
//                    isNegative = true;
//                    number = -number;
//                }
//                while (number > 0)
//                {
//                    buffer[bufferSize] = (char)('0' + (number % 10));
//                    bufferSize = bufferSize + 1;
//                    number = number / 10;
//                }
//                if (isNegative)
//                {
//                    buffer[bufferSize] = '-';
//                    bufferSize = bufferSize + 1;
//                }
//            }
//
//            for (int j = bufferSize - 1; j >= 0; --j)
//            {
//                str[pos] = buffer[j];
//                pos = pos + 1;
//            }
//
//            if (i != size - 1)
//            {
//                str[pos] = ' ';
//                pos = pos + 1;
//            }
//        }
//
//        str[pos] = '\0';
//        return str;
//    }
//};
//
//int main()
//{
//    Array arr(5);
//    arr.fill();
//
//    cout << "\nMassive: ";
//    arr.print();
//
//    cout << "Minimum: " << arr.getMin() << endl;
//    cout << "Maximum: " << arr.getMax() << endl;
//
//    cout << "\nSorting...\n";
//    arr.sort();
//    arr.print();
//
//    cout << "\nChanging size to 7:\n";
//    arr.resize(7);
//    arr.print();
//
//    cout << "\nCopying massive:\n";
//    Array copy = arr;
//    copy.print();
//
//    cout << "\nTesting operator []:\n";
//    cout << "arr[2] = " << arr[2] << endl;
//    arr[2] = 100;
//    arr.print();
//
//    cout << "\nTesting operator ():\n";
//    arr(5);
//    arr.print();
//
//    cout << "\nTesting conversion to int:\n";
//    int total = arr;
//    cout << "Sum = " << total << endl;
//
//    cout << "\nTesting conversion to char*:\n";
//    char* s = arr;
//    cout << "Array as string: \"" << s << "\"\n";
//    delete[] s;
//
//    return 0;
//}
