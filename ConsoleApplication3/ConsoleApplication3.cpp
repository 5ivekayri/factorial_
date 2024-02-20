#include <iostream>
#include <fstream>

using namespace std;

class BigInt {
public:
    BigInt() : value("1") {}

    void multiply(int n) {
        for (int i = 1; i <= n; i++) {
            multiplyBySingleDigit(i);
        }
    }

    friend ostream& operator<<(ostream& os, const BigInt& bi) {
        os << bi.value;
        return os;
    }

private:
    string value;

    void multiplyBySingleDigit(int n) {
        int carry = 0;
        for (int i = value.size() - 1; i >= 0; i--) {
            int digit = value[i] - '0';
            int product = digit * n + carry;
            value[i] = (product % 10) + '0';
            carry = product / 10;
        }
        while (carry) {
            value = char(carry % 10 + '0') + value;
            carry /= 10;
        }
    }
};

int main(void) {
    setlocale(LC_CTYPE, "rus");

    int n;

    cout << "Введите значение факториала: ";
    cin >> n;

    BigInt fact;
    fact.multiply(n);

    ofstream out("output.txt");
    if (out) {
        out << "Факториал числа n: " << fact << endl;
        cout << "Факториал числа " << n << ": " << fact << endl;
    }
    else {
        cerr << "Не удалось открыть файл." << endl;
    }

    return 0;
}
