#include <iostream>
using namespace std;

class grEngine {
 public:
  void render(){
    cout << "Rendering graphics.... " << endl;
  }
};

class inputHandler {
  public:
  void process(){
    cout << "Processing input.... " << endl;
  }
};

class physicsEngine {
  public:
  void update(){
    cout << "Updating physics.... " << endl;
  }
};

class gameEngine{
    grEngine graphics;
    inputHandler input;
    physicsEngine physics;

  public:
     void start(){
        cout << "Starting game engine.... " << endl;
        graphics.render();
        input.process();
        physics.update();
        cout << "Game Over! Thanks for playing!" << endl;
     }

};

int main(){
    gameEngine game;
    game.start();

    return 0;
}