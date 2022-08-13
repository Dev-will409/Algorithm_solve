#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    string temp;
    
    for(int i = 0; i < s.size(); ++i){
        if(int(s[i]) >= 48 && int(s[i]) <= 57) temp.append(s,i,1);
        else{
            if(s[i] == 'z'){
                string zero = "0";
                temp += zero;
                i += 3;
            }
            else if(i != s.size() - 1 && s[i] == 'o' && s[i+1] == 'n'){
                string one = "1";
                temp += one;
                i += 2;
            }
            else if(i != s.size() - 1 && s[i] == 't'){
                if(s[i+1] == 'w'){
                    string two = "2";
                    temp += two;
                    i += 2;
                }
                else if(s[i+1] == 'h'){
                    string three = "3";
                    temp += three;
                    i += 4;
                }
            }
            else if(s[i] == 'f'){
                if(s[i+1] == 'o'){
                    string four = "4";
                    temp += four;
                    i += 3;
                }
                else if(s[i+1] == 'i'){
                    string five = "5";
                    temp += five;
                    i += 3;
                }
            }
            else if(s[i] == 's'){
                if(s[i+1] == 'i'){
                    string six = "6";
                    temp += six;
                    i += 2;
                }
                else {
                    string seven = "7";
                    temp += seven;
                    i += 4;
                }
            }
            else if(i != s.size() - 1 && s[i] == 'e'){
                if(s[i+1] == 'i'){
                    string eight = "8";
                    temp += eight;
                    i += 4;
                }
            }
            else if(i != s.size() - 1 && s[i] == 'n'){
                if(s[i+1] == 'i'){
                    string nine = "9";
                    temp += nine;
                    i += 3;
                }
            }
        }
    }
    
    answer = stoi(temp);
    
    
    return answer;
}