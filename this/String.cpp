#include <iostream>
#include <string>

using namespace std;

class String {
private:
    char* str;
    int length;

public:
    String() {
        length = 80;
        str = new char[length + 1];
        str[0] = '\0';
    }

    String(int size) {
        length = size;
        str = new char[length + 1];
        str[0] = '\0';
    }

    String(const string& input) {
        length = input.length();
        str = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            str[i] = input[i];
        }
        str[length] = '\0';
    }

    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        for (int i = 0; i <= length; ++i) {
            str[i] = other.str[i];
        }
    }

    void input() {
        string temp;
        cout << "Введіть рядок: ";
        getline(cin, temp);
        delete[] str;
        length = temp.length();
        str = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            str[i] = temp[i];
        }
        str[length] = '\0';
    }

    void print() const {
        cout << "Рядок: ";
        for (int i = 0; i < length; ++i) {
            cout << str[i];
        }
        cout << endl;
    }

    ~String() {
        delete[] str;
    }
};

int main() {
    String s1;
    s1.input();
    s1.print();

    String s2(50);
    s2.input();
    s2.print();

    String s3("Привіт, світ!");
    s3.print();

    String s4 = s3;
    s4.print();

    return 0;
}
