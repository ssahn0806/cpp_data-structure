#include <iostream>

using namespace std;

class evaluator
{
public:
	//Precondition : expr should be postfix expression
	//Postcondition : return the evaluated result
	evaluator();
	double evaluate(string expr);

	//Precondition : expr should be a valid infix expression
	//Postcondition : return postfix expression
	string infixToPostfix(string expr);
	
	bool isbalanced(string expr);

	int get_op() { return count_op; };
	int get_num() { return count_num; };
	int get_var() { return count_var; };

private:
	int count_op;
	int count_num;
	int count_var;
};