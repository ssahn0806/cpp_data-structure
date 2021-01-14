#include "evaluator.h"
#include "Stack.h"

int main(void)
{
	evaluator e;
	string input_in;
	string input_post;
	bool isbalanced;
	double calc;

	do
	{
		cout << "Input a valid infix Expression : ";
		cin >> input_in;

		isbalanced = e.isbalanced(input_in);
	} while (!isbalanced);

	input_post = e.infixToPostfix(input_in);

	cout << input_post << endl;
	//cout << "operators :" << e.get_op() << ", numbers :" << e.get_num() << ", variables :" << e.get_var() << endl;
	calc = e.evaluate(input_post);
	cout << "result = " << calc << endl;

	return 0;
}