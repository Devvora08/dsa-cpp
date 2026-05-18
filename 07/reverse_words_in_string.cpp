#include <iostream>
#include <vector>

#include <string>

using namespace std;

// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"

string reverseSingleWord(string word, int s, int e)
{
    // reverse entire string
    while (s < e)
    {
        swap(word[s++], word[e--]);
    }
    return word;
}

string removeTrailing(string s)
{
    // run this in start to remove all trailing spaces from left and right
    int i = 0;
    while (i < s.length() && s[i] == ' ')
    {
        s.erase(i, 1);
    }

    int j = s.length() - 1;
    while (j >= 0 && s[j] == ' ')
    {
        s.erase(j, 1);
        j--;
    }

    return s;
}

string reverseWords(string s)
{
    // remove trailing spaces from start, end
    s = removeTrailing(s);

    int st = 0, end = s.length() - 1;
    // reverse entire string
    while (st < end)
    {
        swap(s[st++], s[end--]);
    }

    for (int i = 0; i < s.length(); i++)
    {
        int count = 0;
        if (s[i] == ' ')
        {

            while (i + 1 < s.length() && s[i + 1] == ' ')
            {
                s.erase(i + 1, 1);
            }

            continue;
        }
        while (i < s.length() && s[i] != ' ')
        {
            count++;
            i++;
        }
        s = reverseSingleWord(s, i - count, i - 1);

        i--; // to balance
    }

    return s;
}

int main()
{
    string s = "  the sky is blue     ";
    cout << s << endl;
    cout << removeTrailing(s) << endl;
    // cout << reverseWords(s) << endl;

    return 0;
}