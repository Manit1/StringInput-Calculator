#include <bits/stdc++.h>
using namespace std;
int helperFunction(queue<char>&q){
    int sum = 0;
    int prevNum = 0;
    char prevOp = '+';
    int curNum = 0; 
    while(!q.empty()){
        char ch = q.front(); q.pop();
        if(isdigit(ch)){
            curNum = 10*curNum + ch-'0';
        }
        if(ch == '('){
            curNum = helperFunction(q);
        }
        if(ch == ')' || ch == '$' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            if(prevOp == '+'){
                sum += prevNum;
                prevNum = curNum;
            }
            else if(prevOp == '-'){
                sum += prevNum;
                prevNum = -curNum;
            }
            else if(prevOp == '*'){
                prevNum *= curNum;
            }
            else if(prevOp == '/'){
                prevNum /= curNum;
            }
            if(ch == ')'){
                break;
            }
            curNum = 0;
            prevOp = ch;
        }
    }
    return sum + prevNum;
}
    
int calculator(string s) {
    queue<char>q;
    int i = 0;
    while(i != s.size()){
        if(s[i] != ' '){
            q.push(s[i]);
        }
        i++;
    }
    q.push('$');
    return helperFunction(q);
}
int main(){
   string s;
   cin>>s;
   cout<<calculator(s);
    return 0;
}