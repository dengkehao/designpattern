#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*class istrategy {
public:
	virtual double discount(double total) = 0;
	virtual ~istrategy() {}
};
class basicdiscount :public istrategy {
public:
	virtual double discount(double total) override
	{
		return total * 0.4;
	}
};
class silverdiscount :public istrategy {
	
public:
	virtual double discount(double total) override
	{
		return total * 0.25;
	}
};
class cashier {
	istrategy* m_discount;
public:
	void setdiscount(istrategy* discountmethod)
	{
		m_discount = discountmethod;
	}
	double calculatetotal(double amount)
	{
		double total = amount;
		if (m_discount != nullptr) {
			total = m_discount->discount(amount);
		}
		return total;
	}
};
int main() {
	cashier cash;
	basicdiscount basic;
	silverdiscount silver;
	cash.setdiscount(&basic);
	double totalwithbasic = cash.calculatetotal(100);
	cash.setdiscount(&silver);
	double totalwithsilver = cash.calculatetotal(100);
	cout<<totalwithbasic<<endl;
	cout << totalwithsilver << endl;
	getchar();
	return 0;
}*/


class sort_alg {
public:
	virtual void sortalg() {};
};

class bub_sort :public sort_alg {
	virtual void sortalg() override
	{	
		cout << "冒泡"<<endl;
	}
};

class quick_sort :public sort_alg {
	virtual void sortalg() override
	{
		cout << "快速" << endl;
	}
};

class context {

private:
	sort_alg* sta;
public:
	context(sort_alg* st) :sta(st) {}
	void printName() {
		cout << "using the:" << endl;
		sta->sortalg();
	}
};

int main() 
{
	bub_sort bs;
	quick_sort qs;
	context ct1(&bs);
	context ct2(&qs);
	ct1.printName();
	ct2.printName();
	return 0;
}