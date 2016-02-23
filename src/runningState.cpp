#include "runningState.h"
#include "standbyState.h"


runningState::runningState(App *a):BaseState(a){
    BaseState::initialize();
};

runningState::~runningState(){
};

void runningState::draw(){
};

void runningState::update(){};

void runningState::next(){
    app->setCurrentState(new standbyState(app));
    delete this;
};

void runningState::keypressed(int key){
    switch (key) {
        case ' ':
            next();
            break;
        case 13:
            next();
            break;
        default:
            break;
    }
}