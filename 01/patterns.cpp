#include <iostream>
using namespace std;

// pattern 1
void square_pattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << " " << " * " << " "; // print *, A-Z, 1-4, etc
        }
        cout << endl;
    }

    char ch = 'A'; // can write here
    for (int i = 1; i <= n; i++)
    {
        ch = 'A';
        for (int j = 1; j <= n; j++)
        {
            cout << " " << ch << " "; // print *, A-Z, 1-4, etc
            ch++;
        }
        cout << endl;
    }
}

// pattern 2
void triangle_1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << " " << i + 1; // cout << i = 1, 22, 333, ..
        }
        cout << endl;
    }
}

void triangle_3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            cout << " " << j;
        }
        cout << endl;
    }
}

void inverted_triangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        for (int j = 0; j < n - i; j++)
        {
            cout << i + 1;
        }
        cout << endl;
    }
}

void pyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        // spaces = n-i-1
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        // 1st num set
        for (int j = 1; j <= i + 1; j++)
        {
            cout << j;
        }

        // 2nd num set
        for (int j = i; j > 0; j--)
        {
            cout << j;
        }

        cout << endl;
    }
}

void hollow_diamond_pattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space = n-i-1
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        // star (only 1 in first line)
        cout << "*";

        if (i != 0)
        {
            // space 2
            for(int j = 0; j< 2*i-1; j++) {
                cout << " ";
            }
            // star
            cout << "*";
        }
        cout << endl;
    }

    // BOTTOM PART
    for(int i = 0; i < (n-1); i++) {
        // space - 1 = (i+1)
        for(int j = 0; j < i+1; j++) {
            cout << " ";
        }
        // star
        cout << "*";

        if(i != n-2) {
            //spaces
            for(int j = 0; j < 2*(n-i-2)-1; j++) {
                cout << " ";
            }

            cout << "*";
        }

        cout << endl;
    }

}

int main()
{
    // execute all pattern functions here
    // square_pattern(4);
    hollow_diamond_pattern(5);

    return 0;
}
