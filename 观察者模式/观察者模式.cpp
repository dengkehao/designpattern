#include <iostream>
#include <vector>
#include <string>
using namespace std;
// 观察者接口
/*class Observer {
public:
    virtual ~Observer() {}
    virtual void update() = 0; // 更新方法
};

// 主题接口
class Subject {
public:
    virtual ~Subject() {}
    virtual void attach(Observer* observer) = 0; // 添加观察者
    virtual void detach(Observer* observer) = 0; // 移除观察者
    virtual void notify() = 0; // 通知观察者
};

// 具体观察者类
class ConcreteObserver : public Observer {
public:
    ConcreteObserver(std::string name) : name_(name) {}

    void update() override {
        std::cout << "观察者 " << name_ << " 收到更新通知。" << std::endl;
    }

private:
    std::string name_;
};

// 具体主题类
class ConcreteSubject : public Subject {
public:
    void attach(Observer* observer) override {
        observers_.push_back(observer); // 将观察者添加到列表
    }

    void detach(Observer* observer) override {
        auto it = std::find(observers_.begin(), observers_.end(), observer);
        if (it != observers_.end()) {
            observers_.erase(it); // 从列表中移除观察者
        }
    }

    void notify() override {
        for (auto observer : observers_) {
            observer->update(); // 通知观察者更新
        }
    }

private:
    std::vector<Observer*> observers_;
};

int main() {
    ConcreteObserver observer1("A");
    ConcreteObserver observer2("B");
    ConcreteObserver observer3("C");

    ConcreteSubject subject;
    subject.attach(&observer1); // 将观察者1添加到主题
    subject.attach(&observer2); // 将观察者2添加到主题

    subject.notify(); // 通知观察者

    subject.attach(&observer3); // 将观察者3添加到主题
    subject.detach(&observer1); // 移除观察者1

    subject.notify(); // 再次通知观察者

    //getchar(); // 等待用户按下回车键
    return 0;
}*/
class Observer {
public:
    Observer(string str) : m_name(str) {}
    virtual void update()=0;
    virtual ~Observer() {};

    string m_name;
};
class Subscriber {
public:
    void attach(Observer* ob)
    {
        m_list.push_back(ob);
    }
    void detach(Observer* ob)
    {
        auto it = find(m_list.begin(), m_list.end(), ob);
        if (it != m_list.end())
        {
            m_list.erase(it);
        }
    }
    void notify() 
    {
        for (auto obs : m_list)
        {
            obs->update();
        }
    }
    virtual ~Subscriber() {};
private: 
    vector<Observer*>m_list;

};
class ConcreteObserver :public Observer{
public:
    ConcreteObserver(string str) :Observer(str) {}
    virtual void update()override
    {
        cout << m_name << "收到通知" << endl;
    }
};



int main()
{
    Observer* ob1 = new ConcreteObserver("ob");
    Observer* ob2 = new ConcreteObserver("ob22");
    Subscriber s1;
    s1.attach(ob1);
    s1.attach(ob2);
    s1.notify();
    s1.detach(ob1);
    s1.notify();
    return 0;
}