/*
1. '(', '[' push into stack
2. ')', ']' pop from stack is correct mapping(  '(','[' . ) and stack isn't empty
   o.w. print false
Date: 2019/03/01
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num;
    
    while (cin>>num) {
        getchar();
        string in_str;
        while(num--) {
            //cin >> in_str;
            getline(cin, in_str);
            vector<char> stack; 
            bool flag=true;
            
            for (int i=0; i<in_str.size(); i++) {
                if(in_str[i]=='[' || in_str[i]=='(') {
                    stack.push_back(in_str[i]);
                }
                
                else {
                    if (in_str[i]==']') {
                        if (!stack.empty() && stack.back() == '[') {
                            stack.pop_back();
                        }
                        else {
                            flag = false;
                            break;
                        }
                    }
                    else if(in_str[i]==')') {
                        if (!stack.empty() && stack.back() == '(') {
                            stack.pop_back();
                        }
                        else {
                            flag = false;
                            break;
                        }
                    }
                }
            }
            if (flag && stack.empty()) 
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
   return 0;
}