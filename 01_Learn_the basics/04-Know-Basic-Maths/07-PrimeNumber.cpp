#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    int start, end;

    cout << "Enter start of range: "<<endl;
    cin >> start;
    cout << "Enter end of range: "<<endl;
    cin >> end;

    cout << "Prime numbers between " << start << " and " << end << " are:\n";

    for (int i = start; i <= end; ++i) {
        if (isPrime(i))
            cout << i << " ";
    }

    cout << endl;
    return 0;
}
