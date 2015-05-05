#include <list>
#include <string>
#include <iostream>
using namespace std;
void subsets(const string &s, list<string> &subs) {
    if (s == "") {
        subs.push_back("");
        return;
    }

    subsets(s.substr(1), subs);

    int size = subs.size();
    list<string>::iterator it = subs.begin();
    for (int i = 0; i < size; ++i, ++it)
        subs.push_back(s[0] + *it);
}


void print(const list<string> &lst) {
    list<string>::const_iterator it = lst.begin();
    for (; it != lst.end(); ++it)
        cout << *it << endl;
}


void subsets(const string &s) {
    list<string> subs;
    subsets(s, subs);
    print(subs);
}


int main_subset ()
{
 subsets("ABC");	 
 return 0;
}

