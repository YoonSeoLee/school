#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(void)
{
    ifstream inStream;
    int numTestCases;

    inStream.open("test3.txt");

    if(inStream.fail())
    {
        cerr << "Input file opening failed.\n";
        exit(1);
    }

    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++)
    {
        int a, b, c;
        int tmp;

        inStream >> a >> b >> c;

        if (a > b && a > c)
        {
            if (b > c)
            {
                tmp = a;
                a = c;
                c = tmp;
            }
            else
            {
                tmp = a;
                a = b;
                b = tmp;

                tmp = b;
                b = c;
                c = tmp;
            }
        }

        else if (b > a && b > c)
        {
            if (a > c)
            {
                tmp = a;
                a = c;
                c = tmp;

                tmp = b;
                b = c;
                c = tmp;
            }
            else
            {
                tmp = a;
                a = c;
                c = tmp;
            }
        }

        else if (c > b && c > a)
        {
            if (a > b)
            {
                tmp = a;
                a = b;
                b = tmp;
            }
        }

        cout << a << b << c << endl;

        if (c >= a + b || b >= a + c || a >= b + c)
            cout << 0 << endl;

        else if (c == a && c == b && a == b)
            cout << 1 << endl;

        else if (c * c == a * a + b * b || b * b == a * a + c * c || a * a == b * b + c * c)
            cout << 2 << endl;

        else if (c == a || c == b || a == b)
            cout << 3 << endl;

        else
            cout << 4 << endl;
    }
    inStream.close();
    return 0;
}