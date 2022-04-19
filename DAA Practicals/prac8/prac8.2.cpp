#include <iostream>
#include <vector>
#define MAXCHAR 256
using namespace std;

void rabinKarp(vector<char> text, vector<char> pattern, int q)
{
    int j;
    int textSize = text.size();    
    int pattSize = pattern.size(); 
    int patternHash = 0, textHash = 0, h = 1;

    //calculating h = {d^(M-1)} mod prime
    for (int i = 0; i < pattSize - 1; i++)
    {
        h = (MAXCHAR * h) % q;
    }
    for (int i = 0; i < pattSize; i++)
    {
        //pattern hash value
        patternHash = (MAXCHAR * patternHash + pattern[i]) % q;
        
        //hash for first window
        textHash = (MAXCHAR * textHash + text[i]) % q;
    }
    cout << "--------------------------------" << endl;
    for (int i = 0; i <= (textSize - pattSize); i++)
    {
        //when hash values are same check for matching
        if (patternHash == textHash)
        {
            int flag = 1;
            for (j = 0; j < pattSize; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    flag = 0;
                    break;
                }
            }
            //the pattern is found
            if (j == pattSize)
                cout << endl << "Pattern found at index: " << i << endl;
        }
        // find hash value for next window
        if (i < textSize - pattSize)
        {
            textHash = (MAXCHAR * (textHash - text[i] * h) + text[i + pattSize]) % q;

            //when hash value is negative, make it positive
            if (textHash < 0)
                textHash += q;
        }
    }
}

int main()
{
    int sizeText, sizePattern;
    char temp, temp1;
    vector<char> text;
    vector<char> pattern;
    int q;

    cout << "Enter Size of Text: ";
    cin >> sizeText;

    cout << "\nEnter Text: ";
    for (int i = 0; i < sizeText; i++)
    {
        cin >> temp;
        text.push_back(temp);
    }

    cout << "\nEnter Size of Pattern: ";
    cin >> sizePattern;

    cout << "\nEnter Pattern: ";
    for (int i = 0; i < sizePattern; i++)
    {
        cin >> temp1;
        pattern.push_back(temp1);
    }

    cout << "\nEnter value of q: ";
    cin >> q;

    rabinKarp(text, pattern, q);
    return 0;
}

