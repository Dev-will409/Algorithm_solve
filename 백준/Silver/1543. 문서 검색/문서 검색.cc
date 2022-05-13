#include <iostream>

using namespace std;

int main() {
    string doc , word;
    int max = 0;
    int count = 0;

    getline(cin,doc);
    getline(cin,word);
    int i = 0;
        while (i < doc.size())
        {
            if(doc.substr(i, word.size()) == word){
                i += word.size();
                count ++;
            }
            else{
                i++;
            }
        }
        if(max < count) max = count;

        cout << max;


    return 0;
}
