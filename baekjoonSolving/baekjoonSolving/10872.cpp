#include <iostream>
using namespace std;

int pactorial(int num) {
    switch (num) {
    case 0:
        return 1;
    case 1:
        return 1;
    default:
        return num * pactorial(num - 1);
    }
}

int main() {
    int num;
    cin >> num;
    cout << pactorial(num);
}