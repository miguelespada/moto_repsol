
#ifndef __running__state__
#define __running__state__

#include "baseState.h"
#include "app.h"

class runningState: public BaseState
{
public:
    runningState(App *a);
    ~runningState();
    string toString() { return "runnning"; }
    void update();
    void draw();
    void next();
    void keypressed(int key);
};

#endif