#include<iostream>

class Operator
{
public:
	virtual double getResult(double num1, double num2)=0;
};

class AddOperator : public Operator
{
public:
	double getResult(double num1, double num2)
	{
		return num1 + num2;
	}
};

class SubOperator : public Operator
{
public:
	double getResult(double num1, double num2)
	{
		return num1 - num2;
	}
};
class MulOperator : public Operator
{
public:
	double getResult(double num1, double num2)
	{
		return num1 * num2;
	}
};

class OperatorFactory
{
public:
	static Operator* createOperator(char op)
	{
		switch (op)
		{
		case '+':
			return new AddOperator();
		case '-':
			return new SubOperator();
		case '*':
			return new MulOperator();
		default:
			return nullptr;
		}
	}
};

int main()
{
	double num1, num2;
	char op;
	std::cout << "请输入两个数字和一个运算符：";
	std::cin >> num1 >> num2 >> op;
	Operator* oper = OperatorFactory::createOperator(op);
	double result = oper->getResult(num1, num2);
	std::cout << "结果为：" <<result<< std::endl;
	delete oper;
	system("pause");
	return 0;
}