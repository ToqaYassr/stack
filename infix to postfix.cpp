#include <iostream>
#include "stack.cpp"
using namespace std;

//return the priority of the operator
int priority(char o){
    if(o=='+' || o=='-')
        return 1;
    else if(o=='*' || o=='/')
        return 2;
    else if(o=='^')
        return 3;
    else
        return 0;

}

string InfixToPostfix(string exp){

    string output ="";
    stack<char> operation;

    for(int i=0;i<exp.length();i++){

//        skip the spaces (defensive programming)
        if(exp[i]==' ')
            continue;

//       if the character is a digit or a letter
// put it in the output string
        else if(isalpha(exp[i]) || isdigit(exp[i]))
            output+=exp[i];

//       if the character is an opening bracket
// push it in the stack
        else if(exp[i]=='('){
            operation.push(exp[i]);
        }
//       if the character is a closing bracket
// pop all the operators from the stack
        else if(exp[i]==')'){

//         pop all the operators from the stack
            while(operation.Top()!='('){
                output+=operation.pop();
            }
//           pop the opening bracket
            operation.pop();
        }

//       if the character is an operator which is not a bracket
        else{
//           pop all the operators from the stack
//           which have a lower or equal priority than the current operator
//           and then push the output
            while(!operation.isEmpty()&&priority(exp[i]) <= priority(operation.Top())){
                output+=operation.pop();
            }
            operation.push(exp[i]);
        }

    }
//    pop all the remaining operators from the stack
//    and then push the output
    while(!operation.isEmpty()){
        output+=operation.pop();
    }

    return output;
}

