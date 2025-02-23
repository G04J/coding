#include <iostream>
using namespace std;

int main()
{
    // a = 5 (00000101 in 8-bit binary)
    // b = 9 (00001001 in 8-bit binary)

    unsigned int a, b;
    cout << "Enter value of a: " << endl;
    cin >> a;
    cout << "Enter value of b: " << endl;
    cin >> b;

    // 1. & (bitwise AND)
    // The result is 00000001 (1)
    cout << "a = " << a << ", b = " << b << endl;
    cout << "a & b = " << (a & b) << endl;

    // 2. | (bitwise OR)
    // The result is 00001101 (13)
    cout << "a | b = " << (a | b) << endl;

    // 3. ^ (bitwise XOR)
    // The result is 00001100 (12)
    cout << "a ^ b = " << (a ^ b) << endl;

    // 4. ~ (bitwise NOT)
    // The result depends on system architecture (two's complement representation)
    cout << "~a = " << ~a << endl;

    // 5. << (left shift)
    // Shifts bits to the left, effectively multiplying by 2
    cout << "b << 1 = " << (b << 1) << endl;

    // 6. >> (right shift)
    // Shifts bits to the right, effectively dividing by 2
    cout << "b >> 1 = " << (b >> 1) << endl;

    return 0;
}
