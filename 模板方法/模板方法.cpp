#include <iostream>

// 抽象基类，定义了游戏的主要流程
/*class Game {
public:
    void play() {
        initialize();
        startGame();
        endGame();
    }

protected:
    virtual void initialize() {
        std::cout << "Initializing the game" << std::endl;
    }

    virtual void startGame() = 0;  // 延迟到子类实现

    virtual void endGame() {
        std::cout << "Ending the game" << std::endl;
    }
};

// 具体游戏类，实现了具体的游戏细节
class ChessGame : public Game {
protected:
    void startGame() override {
        std::cout << "Starting the chess game" << std::endl;
        // 实际的国际象棋游戏逻辑
    }
};

class SoccerGame : public Game {
protected:
    void startGame() override {
        std::cout << "Starting the soccer game" << std::endl;
        // 实际的足球游戏逻辑
    }
};

int main() {
    ChessGame chess;
    SoccerGame soccer;

    std::cout << "Playing chess:" << std::endl;
    chess.play();

    std::cout << "\nPlaying soccer:" << std::endl;
    soccer.play();

    return 0;
}*/
using namespace std;
class Frame {
public:
    void alg() {
        step1();
        step2();
        step3();
    }
protected:
    virtual void step1() 
    { 
        cout << "step1" << endl;
    }
    virtual void step2() = 0;
    virtual void step3() 
    { 
        cout << "step3" << endl; 
    }
};

class derive1 :public Frame{
    virtual void step2() override {
        cout << "derive1 : step2" << endl;
    }

};
class derive2 :public Frame {
    virtual void step2() override {
        cout << "derive2 : step2" << endl;
    }

};

int main() 
{
    derive1 dr1;
    derive2 dr2;
    dr1.alg();
    dr2.alg();
    return 0;
}