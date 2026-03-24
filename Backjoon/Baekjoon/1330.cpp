#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    cin >> A >> B;
    if (A > B)
        cout << ">" << endl;
    else if (A < B)
        cout << "<" << endl;
    else
        cout << "==" << endl;

    return 0;
}

