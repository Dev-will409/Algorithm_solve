#include <iostream>

using namespace std;

int main() {
    string doc , word;
    int max = 0;
    int count = 0;

    getline(cin,doc);
    getline(cin,word);

    if(word.size() > doc.size()) cout << 0;
    else{
        for (int j = 0; j <= doc.size() - word.size(); ++j) {
            int i = j;
            count = 0;
            while (i <= doc.size() - word.size())
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
        }
        cout << max;
    }





    return 0;
}
