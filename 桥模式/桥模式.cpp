#include <iostream>
#include <string>
using namespace std;
class Graphics 
{
public:
	virtual void drawCircle() = 0;
};

class WindowsGraphics :public Graphics 
{
public:
	void drawCircle() override {
		cout<<"Windows drawCircle" << endl;
	}
};

class LinuxGraphics :public Graphics
{
public:
	void drawCircle() override {
		cout << "Linux drawCircle" << endl;
	}
};

class Circleshape 
{
private:
	Graphics* m_graphics;
public:
	Circleshape(Graphics* graphics) :m_graphics(graphics) {};
	void draw() {
		m_graphics->drawCircle();
	}
};
int main()
{
	Graphics* windowsGraphics = new WindowsGraphics();
	Circleshape* c1 = new Circleshape(windowsGraphics);
	c1->draw();

	Graphics* linuxGraphics = new LinuxGraphics();
	Circleshape* c2 = new Circleshape(linuxGraphics);
	c2->draw();

	delete windowsGraphics;
	delete c1;
	delete linuxGraphics;
	delete c2;
	return 0;
}