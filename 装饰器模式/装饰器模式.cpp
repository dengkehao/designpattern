#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Component
{
public:
	virtual void operation() = 0;
};

class ConcreteComponent : public Component
{
public:
	void operation() override {
		cout << "具体组件operation" << endl;
	}
};

class Decorator : public Component
{
protected:
	Component* m_component;
public:
	Decorator(Component* component) {
		m_component = component;
		cout << "2" << endl;
	}
	void operation() override {
		if (m_component) {
			m_component->operation();
		}
	}
};

class ConcreteDecoratorA :public Decorator 
{
public:
	ConcreteDecoratorA(Component* component) :Decorator(component) { 
		cout << "1" << endl; 
	}
	void operation() override {
		Decorator::operation();
		cout<<"具体装饰器A：operation" << endl;
	}
};
class ConcreteDecoratorB :public Decorator
{
public:
	ConcreteDecoratorB(Component* component) :Decorator(component) {}
	void operation() override {
		Decorator::operation();
		cout << "具体装饰器B：operation" << endl;
	}
};


int main() {
	// 创建具体组件对象
	Component* component = new ConcreteComponent();

	// 使用具体装饰器A对组件进行修饰
	Decorator* decoratorA = new ConcreteDecoratorA(component);
	decoratorA->operation();

	// 使用具体装饰器B对组件进行修饰
	//Decorator* decoratorB = new ConcreteDecoratorB(component);
	//decoratorB->operation();

	// 使用具体装饰器A和具体装饰器B对组件进行多重修饰
	//Decorator* decoratorAB = new ConcreteDecoratorA(new ConcreteDecoratorB(component));
	//decoratorAB->operation();

	delete component;
	delete decoratorA;
	//delete decoratorB;
	//delete decoratorAB;
	getchar();
	return 0;
}