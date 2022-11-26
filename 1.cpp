#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

void checkValidInput()
{
    if (cin.fail())
        throw "Incorrect input";
}

void checkValidParam(int n)
{
    throw "Incorrect param";
}
double calculate(double x, int n)
{
    double y;
    if (x <= 0) // do if x<=0
    {
        y = 1;
        for (int i = 0; i < n; i++) // calculate y
            y *= pow(i, 3) + i;
    }
    else // do if x>0
    {
        y = 0;
        for (int i = 1; i < n; i++) // calculate y
            for (int j = 1; j < n; j++)
                y += x / (i + j);
    }
    return y;
}
int main()
{
    try
    {
        double a, b, h;
        int n;
        bool fs;

        cout << "Enter a: " << endl;
        cin >> a;
        checkValidInput();
        cout << "Enter b: " << endl;
        cin >> b;
        checkValidInput();
        cout << "Enter h: " << endl;
        cin >> h;
        checkValidInput();
        cout << "Enter n: " << endl;
        cin >> n;
        checkValidInput();
        checkValidParam(n);

        cout << "You want to write results in file?(1 if want, else 0)" << endl;
        cin >> fs;
        checkValidInput();

        ofstream fout("results.txt"); // create writeble stream for writing results in file

        for (double x = a; x <= b; x += h)
        {
            double y = calculate(x, n);
            cout << "x: " << x << "; y: " << y << endl;
            if (fs)
                fout << "x: " << x << "; y: " << y << endl; // add result to file
        }
    }
    catch (char *err)
    {
        cout << err << endl;
        return -1;
    }
    catch (...)
    {
        cout << "Something is going wrong" << endl;
        return -2;
    }
    return 0;
}