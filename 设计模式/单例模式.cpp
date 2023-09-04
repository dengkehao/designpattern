using namespace std;
#include <iostream>
#include <set>
#include <string>
 class Logger 
{
public:
	static Logger* getInstance()
	{
		static Logger *instance;
		return instance;
	}
	void log(const std::string& message)
	{
		std::cout << "Logging:" << message<<std::endl;
	}
private:
	Logger() {}
	~Logger() {}
};


int main()
{
	Logger *logger = Logger::getInstance();
	logger->log("单例模式");
	logger->log("hello");
	getchar();
}



