#include <iostream>
#include <vector>
using namespace std;

void naiveAlgorthm(vector<char> text, vector<char> pattern)
{
   int i, j;
   bool valid;
   int textSize = text.size();    
   int pattSize = pattern.size(); 

   vector<int> M;
   for (i = 0; i < (textSize - pattSize); i++)
   {
      valid = true;
      for (j = 0; j < (pattSize - 1); j++)
      {
         if (pattern[j] != '*' && pattern[j] != text[i + j])
            valid = false;
      }
      if (valid)
      {
         M.push_back(i);
      }
   }
   cout << endl << "--------------------------------" << endl;
   for (i = 0; i < M.size(); i++)
   {
      cout << "Pattern found at index: " << M[i] << endl;
   }
}

int main()
{
   int sizeText, sizePattern;
   char temp, temp1;
   vector<char> text;
   vector<char> pattern;

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

   naiveAlgorthm(text, pattern);
   return 0;
}

