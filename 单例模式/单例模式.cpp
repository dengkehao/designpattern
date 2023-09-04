// 单例模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
/*class Singleton {
public:               //饿汉式
	Singleton(const Singleton& obj) = delete;
	Singleton& operator=(const Singleton& obj) = delete;
	static Singleton* getInstance()
	{
		return m_obj;
	}
private:
	Singleton() {}
	static Singleton* m_obj;
};
Singleton* Singleton::m_obj = new Singleton;*/
class Singleton {
public:
	Singleton(const Singleton& obj) = delete;
	Singleton operator=(const Singleton& obj) = delete;
	static Singleton* getInstance() {
		static Singleton obj;
		return &obj;
	}
private:
	Singleton() = default;
};

int main() 
{
	Singleton* obj = Singleton::getInstance();
	return 0;
}