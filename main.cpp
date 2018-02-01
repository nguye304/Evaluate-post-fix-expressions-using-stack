//=========================================================
//HW#: HW1P1 stack
//Your name: Kevin Nguyen
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
//#include "stack.h"
#include "stack.cpp"
//Purpose of the program: The purpose of this program is to evaluate post-fix expressions using stack.
//Algorithm: **
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  int result;//the result of the arithmetic
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  
  while (expression[i] != '\0')
    {
      // cout<<"inside while loop"<<endl;
      try
	{
	  item = expression[i];  // current char
	  
	  //2.  if it is an operand (number), 
	  //    push it (you might get Overflow exception)
	  if ((item >= 48) && (item <= 57))//if item is a single digit number
	    {
	      if (item == 48)
		{
		  item=0;
		  postfixstack.push(item);
		}
	      else if (item == 49)
                {
		  item=1;
                  postfixstack.push(item);
                }
	      else if (item == 50)
                {
		  item=2;
                  postfixstack.push(item);
                }
	      else if (item == 51)
                {
		  item=3;
                  postfixstack.push(item);
                }
	      else if (item == 52)
                {
		  item=4;
                  postfixstack.push(item);
                }
	      else if (item == 53)
                {
		  item=5;
                  postfixstack.push(item);
                }
	      else if (item == 54)
                {
		  item=6;
                  postfixstack.push(item);
                }
	      else if (item == 55)
                {
                  item=7;
                  postfixstack.push(item);
                }

	      else if (item == 56)
                {
		  item=8;
                  postfixstack.push(item);
                }
	      else if (item == 57)
                {
		  item=9;
                  postfixstack.push(item);
                }
	      else
		;
	      
	    }
	  
	  //3.  else if it is an operator,
	  //    pop the two operands (you might get Underflow exception), and
	  //	apply the operator to the two operands, and
	  //    push the result.
	  else if ( (item == '+') || (item == '-') || (item == '*'))
	    {
	      postfixstack.pop(box1);
	      postfixstack.pop(box2);
	      //cases for different operators follow:
	      if (item == '-') 
		{
		  result = box2-box1;
		}
	      else if(item == '+')
		{
		  result = box2+box1;
		}
	      else if(item == '*')
		{
		  result = box2*box1;
		}
	      else
		{
		  cout<<"Not a valid operand"<<endl;
		}
	      postfixstack.push(result);
	      // ** also do the + and * cases 
	      // ** Finally push the result
	    }
	  else throw "invalid item";
	} // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) //when stack is full
	{cout<<"ERROR: Expression too long!"<<endl;return 0; }
      catch (stack::Underflow) // for too few operands
	{cout<<"ERROR: Too few operands!"<<endl;return 0; }
      catch (char const* errorcode) // for invalid item
	{cout<<"ERROR: Invalid Element detected!"<<endl;return 0; }
      
      // go back to the loop after incrementing i
      i++;
    }// end of while
  
  // After the loop successfully completes: 
  // The result will be at the top of the stack. Pop it and show it.
  int answer;
  postfixstack.pop(answer);
  cout<<"Answer: "<<answer<<endl; 
  // If anything is left on the stack, an incomplete expression was found.
  // Inform the user.
  if (postfixstack.isEmpty()==false)
    {
      cout<<"Incomplete Expression!"<<endl;
    }

  return 0;
}// end of the program
