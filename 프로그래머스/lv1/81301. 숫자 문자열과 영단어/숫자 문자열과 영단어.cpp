#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    
    s = regex_replace(s, regex("zero"), "0");
    s = regex_replace(s, regex("one"), "1");
    s = regex_replace(s, regex("two"), "2");
    s = regex_replace(s, regex("three"), "3");
    s = regex_replace(s, regex("four"), "4");
    s = regex_replace(s, regex("five"), "5");
    s = regex_replace(s, regex("six"), "6");
    s = regex_replace(s, regex("seven"), "7");
    s = regex_replace(s, regex("eight"), "8");
    s = regex_replace(s, regex("nine"), "9");
    
    // string temp;
    // for(int i = 0; i < s.size(); ++i){
    //     if(int(s[i]) >= 48 && int(s[i]) <= 57) temp.append(s,i,1);
    //     else{
    //         if(s[i] == 'z'){
    //             string zero = "0";
    //             temp += zero;
    //             i += 3;
    //         }
    //         else if(i != s.size() - 1 && s[i] == 'o' && s[i+1] == 'n'){
    //             string one = "1";
    //             temp += one;
    //             i += 2;
    //         }
    //         else if(i != s.size() - 1 && s[i] == 't'){
    //             if(s[i+1] == 'w'){
    //                 string two = "2";
    //                 temp += two;
    //                 i += 2;
    //             }
    //             else if(s[i+1] == 'h'){
    //                 string three = "3";
    //                 temp += three;
    //                 i += 4;
    //             }
    //         }
    //         else if(s[i] == 'f'){
    //             if(s[i+1] == 'o'){
    //                 string four = "4";
    //                 temp += four;
    //                 i += 3;
    //             }
    //             else if(s[i+1] == 'i'){
    //                 string five = "5";
    //                 temp += five;
    //                 i += 3;
    //             }
    //         }
    //         else if(s[i] == 's'){
    //             if(s[i+1] == 'i'){
    //                 string six = "6";
    //                 temp += six;
    //                 i += 2;
    //             }
    //             else {
    //                 string seven = "7";
    //                 temp += seven;
    //                 i += 4;
    //             }
    //         }
    //         else if(i != s.size() - 1 && s[i] == 'e'){
    //             if(s[i+1] == 'i'){
    //                 string eight = "8";
    //                 temp += eight;
    //                 i += 4;
    //             }
    //         }
    //         else if(i != s.size() - 1 && s[i] == 'n'){
    //             if(s[i+1] == 'i'){
    //                 string nine = "9";
    //                 temp += nine;
    //                 i += 3;
    //             }
    //         }
    //     }
    // }
    
    answer = stoi(s);
    
    
    return answer;
}