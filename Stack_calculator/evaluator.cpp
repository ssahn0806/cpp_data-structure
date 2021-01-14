#include "evaluator.h"
#include "stack.cpp"
#include <string>

evaluator::evaluator()
{
	count_op = 0;
	count_num = 0;
	count_var = 0;
}

double evaluator::evaluate(string expr)
{
	string before_calc="";
	Stack<double> numbers(expr.length());

	const char DECIMAL = '.';
	double op1, op2;
	double result;
	string value;

	if (count_var != 0)
	{
		cout << "You should input values about " << count_var << "variable(s)" << endl;
		for (int i = 0; i < expr.length(); i++)
		{
			char ins = expr[i];
			if (isalpha(ins))
			{
				cout << ins << ":";
				cin >> value;
				before_calc += " ";
				before_calc += value;
				before_calc += " ";
			}
			else
			{
				before_calc += ins;
			}
		}	
	}
	else
	{
		before_calc = expr;
	}
	cout << before_calc << endl;
	for (int i = 0; i < before_calc.length(); i++)
	{
		char ins = before_calc[i];
		if (isdigit(ins))
		{
			numbers.push(ins-48);
		}
		else if (ins == DECIMAL)
		{

		}
		else if (strchr("+-*/", ins) != NULL)
		{
			op2 = numbers.top();
			numbers.pop();
			op1 = numbers.top();
			numbers.pop();
			switch (ins)
			{
			case '+':
				numbers.push(op1 + op2);
				break;
			case '-':
				numbers.push(op1 - op2);
				break;
			case '*':
				numbers.push(op1 * op2);
				break;
			case '/':
				numbers.push(op1 / op2);
				break;
			}
		}
	}
	result = numbers.top();
	numbers.pop();
	return result;
}

string evaluator::infixToPostfix(string expr)
{
	string result = "";
	Stack<char> operators(expr.length());
	const char DECIMAL = '.';
	
	for (int i = 0; i < expr.length(); i++)
	{
		char ins = expr[i];

		if (ins == '(')
		{
			operators.push(ins);
		}
		else if (isdigit(ins) || ins == DECIMAL)
		{
			result += ins;
		}
		else if (isalpha(ins))
		{
			result += ins;
		}
		else if (strchr("+-*/", ins) != NULL)
		{
			while (!operators.empty() && operators.top() != '(')
			{
				if (strchr("*/", ins) != NULL)
				{
					if (strchr("+-", operators.top()) == NULL)
					{
						result += operators.top();
						operators.pop();
					}
					else
						break;
				}
				else
				{
					result += operators.top();
					operators.pop();
				}
			}
			operators.push(ins);
		}
		else if (ins == ')')
		{
			while (operators.top() != '(')
			{
				result += operators.top();
				operators.pop();
			}
			operators.pop();
		}
		/* fully parenthesis expression case */
		//if (ins == '(' || strchr("+-*/", ins) != NULL)
		/*	operators.push(ins);
		else if (isdigit(ins) || ins == DECIMAL || isalpha(ins))
		{
			result += ins;
		}
		else if (ins == ')')
		{
			while (operators.top() != '(')
			{
				result += operators.top();
				operators.pop();
			}
			operators.pop();
		}
		*/
	}
	while (!operators.empty())
	{
		result += operators.top();
		operators.pop();
	}

	return result;
}

bool evaluator::isbalanced(string expr)
{
	Stack<char> parenthesis(expr.length());
	const char DECIMAL = '.';

	for (int i = 0; i < expr.length(); i++)
	{
		char ins = expr[i];
		if (ins == '(')
			parenthesis.push(ins);
		else if (ins == ')')
			parenthesis.pop();
		else if (strchr("+-*/", ins) != NULL)
			count_op++;
		else if (isdigit(ins) || ins == DECIMAL)
			count_num++;
		else if (isalpha(ins))
			count_var++;
	}
	return parenthesis.size() == 0;
}