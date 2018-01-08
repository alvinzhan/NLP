#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

string w1, w2;
map<string, int> map1, map2;
int window, mode = 0;

double cossimilarity()
{
    double dot = 0, length1 = 0, length2 = 0, temp = 0, ans;
    for (map<string, int> ::iterator iter1 = map1.begin(); iter1 != map1.end(); iter1++)
    {
        temp += (iter1 -> second)*(iter1 -> second);
    }
    length1 = sqrt(temp);
    temp = 0;
    for (map<string, int> ::iterator iter2 = map2.begin(); iter2 != map2.end(); iter2++)
    {
        temp += (iter2 -> second)*(iter2 -> second);
    }
    length2 = sqrt(temp);
    for (map<string, int> ::iterator iter1 = map1.begin(); iter1 != map1.end(); iter1++)
    {
        for (map<string, int> ::iterator iter2 = map2.begin(); iter2 != map2.end(); iter2++)
        {
            if(iter1 -> first == iter2 -> first)
            {
                dot += (iter1 -> second)*(iter2 -> second);
                break;
            }
        }
    }
    ans = dot/(length1*length2);
    return ans;
}

void BuildContext (string s, int m)
{
    string w_temp, sentence[10000];
    istringstream iss;
    iss.str(s);
    int counter = 0;
    while (iss >> w_temp)
    {
        if (mode == 1 && (w_temp == "in" || w_temp == "at" || w_temp == "on" || w_temp == "under" || w_temp == "to" || w_temp == "for" || w_temp == "across" || w_temp == "by" || w_temp == "between" || w_temp == "about" || w_temp == "of" || w_temp == "before" || w_temp == "after"));
        else if (mode == 2 && (w_temp == "will" || w_temp == "would" || w_temp == "shall" || w_temp == "should" || w_temp == "can" || w_temp == "could" || w_temp == "may" || w_temp == "might" || w_temp == "must" || w_temp == "ought to" || w_temp == "is" || w_temp == "was" || w_temp == "have" || w_temp == "does" || w_temp == "do"));
        else if (mode == 3 && (w_temp == "in" || w_temp == "at" || w_temp == "on" || w_temp == "under" || w_temp == "to" || w_temp == "for" || w_temp == "across" || w_temp == "by" || w_temp == "between" || w_temp == "about" || w_temp == "of" || w_temp == "before" || w_temp == "after" || w_temp == "will" || w_temp == "would" || w_temp == "shall" || w_temp == "should" || w_temp == "can" || w_temp == "could" || w_temp == "may" || w_temp == "might" || w_temp == "must" || w_temp == "ought to" || w_temp == "is" || w_temp == "was" || w_temp == "have" || w_temp == "does" || w_temp == "do"));
        else if (mode == 4)
        {
            if (w_temp[0] == ' ' || w_temp[0] == '(' || w_temp[0] == '*' || w_temp[0] == '%' || w_temp[0] == '.' || w_temp[0] == ',' || w_temp[0] == '!' || w_temp[0] == ':' || w_temp[0] == '?' || w_temp[0] == ';' || w_temp[0] == '"')
                w_temp = w_temp.erase(0, 1);
            if (w_temp[0] == ' ' || w_temp[0] == '(' || w_temp[0] == '*' || w_temp[0] == '%' || w_temp[0] == '.' || w_temp[0] == ',' || w_temp[0] == '!' || w_temp[0] == ':' || w_temp[0] == '?' || w_temp[0] == ';' || w_temp[0] == '"')
                w_temp = w_temp.erase(0, 1);
            if (w_temp[w_temp.length()-1] == ')' || w_temp[w_temp.length()-1] == '.' || w_temp[w_temp.length()-1] == ',' || w_temp[w_temp.length()-1] == '!' || w_temp[w_temp.length()-1] == ':' || w_temp[w_temp.length()-1] == '?' || w_temp[w_temp.length()-1] == ';' || w_temp[w_temp.length()-1] == '"')
                w_temp = w_temp.erase(w_temp.length()-1);
            if (w_temp[w_temp.length()-1] == ')' || w_temp[w_temp.length()-1] == '.' || w_temp[w_temp.length()-1] == ',' || w_temp[w_temp.length()-1] == '!' || w_temp[w_temp.length()-1] == ':' || w_temp[w_temp.length()-1] == '?' || w_temp[w_temp.length()-1] == ';' || w_temp[w_temp.length()-1] == '"')
                w_temp = w_temp.erase(w_temp.length()-1);
            sentence[counter] = w_temp;
            counter++;
        }
        else
        {
            if (w_temp[0] == ' ' || w_temp[0] == '(' || w_temp[0] == '*' || w_temp[0] == '%' || w_temp[0] == '.' || w_temp[0] == ',' || w_temp[0] == '!' || w_temp[0] == ':' || w_temp[0] == '?' || w_temp[0] == ';' || w_temp[0] == '"')
                w_temp = w_temp.erase(0, 1);
            if (w_temp[0] == ' ' || w_temp[0] == '(' || w_temp[0] == '*' || w_temp[0] == '%' || w_temp[0] == '.' || w_temp[0] == ',' || w_temp[0] == '!' || w_temp[0] == ':' || w_temp[0] == '?' || w_temp[0] == ';' || w_temp[0] == '"')
                w_temp = w_temp.erase(0, 1);
            if (w_temp[w_temp.length()-1] == ')' || w_temp[w_temp.length()-1] == '.' || w_temp[w_temp.length()-1] == ',' || w_temp[w_temp.length()-1] == '!' || w_temp[w_temp.length()-1] == ':' || w_temp[w_temp.length()-1] == '?' || w_temp[w_temp.length()-1] == ';' || w_temp[w_temp.length()-1] == '"')
                w_temp = w_temp.erase(w_temp.length()-1);
            if (w_temp[w_temp.length()-1] == ')' || w_temp[w_temp.length()-1] == '.' || w_temp[w_temp.length()-1] == ',' || w_temp[w_temp.length()-1] == '!' || w_temp[w_temp.length()-1] == ':' || w_temp[w_temp.length()-1] == '?' || w_temp[w_temp.length()-1] == ';' || w_temp[w_temp.length()-1] == '"')
                w_temp = w_temp.erase(w_temp.length()-1);
            sentence[counter] = w_temp;
            counter++;
        }
    }
    if (m == 1)
    {
        for (int i = 0; i < counter; i++)
        {
            if (sentence[i] == w1)
            {
                for (int j = 1; j <= window; j++)
                {
                    if (i-j < 0) break;
                    else
                    {
                        if (sentence[i-j] == "");
                        else map1[sentence[i-j]]++;
                    }

                    if(i+j > counter) break;
                    else
                    {
                        if (sentence[i+j] == "");
                        else map1[sentence[i+j]]++;
                    }

                }
            }
        }
    }
    if (m == 2)
    {
        for (int i = 0; i < counter; i++)
        {
            if (sentence[i] == w2)
            {
                for (int j = 1; j <= window; j++)
                {
                    if (i-j < 0) break;
                    else
                    {
                        if (sentence[i-j] == "");
                        else map2[sentence[i-j]]++;
                    }
                    if(i+j > counter) break;
                    else
                    {
                        if (sentence[i+j] == "");
                        else map2[sentence[i+j]]++;
                    }
                }
            }
        }
    }
}

int main()
{
    char yn;
    while(yn != 'n')
    {
        cout << "Mode1: without prep.\nMode2: without aux.\nMode3: without prep. and aux.\nMode4: original corpus\n";
        cout << "Please choose a mode: ";
        cin >> mode;
        cout << "Please input two target words: ";
        cin >> w1 >> w2;
        cout << "Please input window: ";
        cin >> window;
        for(int i=0; i<w1.length(); i++)
            w1[i] = tolower(w1[i]);
        for(int i=0; i<w2.length(); i++)
            w2[i] = tolower(w2[i]);
        ifstream fin;
        fin.open("Train.txt");
        if (!fin)
            cout << "Dataset not found!";
        else
        {
            string s, w;
            istringstream iss;
            while (getline(fin,s))
            {
                for(int i=0; i<s.length(); i++)
                    s[i] = tolower(s[i]);
                iss.clear();
                iss.str(s);
                while (iss >> w)
                {
                    if (w[w.length()-1] == '.' || w[w.length()-1] == ',' || w[w.length()-1] == '!' || w[w.length()-1] == ':' || w[w.length()-1] == '?' || w[w.length()-1] == ';' || w[w.length()-1] == '"')
                        w = w.erase(w.length()-1);
                    if (w[w.length()-1] == '.' || w[w.length()-1] == ',' || w[w.length()-1] == '!' || w[w.length()-1] == ':' || w[w.length()-1] == '?' || w[w.length()-1] == ';' || w[w.length()-1] == '"')
                        w = w.erase(w.length()-1);
                    if (w == w1)
                        BuildContext(s, 1);
                    if (w == w2)
                        BuildContext(s, 2);
                }
            }
        }
        fin.close();
        map1[w1] = 0;
        map2[w2] = 0;

        /*cout << w1 << ":" << endl;
        for (map<string, int> ::iterator iter = map1.begin(); iter != map1.end(); iter++)
            cout << iter -> first << " " << iter -> second << endl;
        cout << endl << w2 << ":" << endl;
        for (map<string, int> ::iterator iter = map2.begin(); iter != map2.end(); iter++)
            cout << iter -> first << " " << iter -> second << endl;
        */

        cout << endl << "The Cosine Similarity of these two words is: " << cossimilarity() << endl;
        cout << "Do you want to continue(y/n): ";
        cin >> yn;
        cout << endl << endl;
        map1.clear();
        map2.clear();
    }

    return 0;

}
