#include "ofApp.h"
#include "standbyState.h"

//--------------------------------------------------------------
void ofApp::setup(){
    app = new App();
    app->setCurrentState(new standbyState(app));
    osc = new OscAdapter(app);
    gui = new Gui(app, osc);
    
    ofSetFrameRate(30);
    ofEnableSmoothing();
    
    ofEnableAntiAliasing();
    ofTrueTypeFont::setGlobalDpi(72);
    
    mainOutputSyphonServer.setName("MOTOS");
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0);
    app->draw();
    mainOutputSyphonServer.publishScreen();
    
    ////    gui->draw();
}


