#include "OscAdapter.h"

OscAdapter::OscAdapter(App *a){
    app = a;
    int localPort = a->getAssets()->getLocalPort();
    
    receiver = new ofxOscReceiver;
    sender = new ofxOscSender;
    
    receiver->setup(localPort);
    
    ofLogNotice() << "listening for osc messages on port " << localPort;
    bOnline = false;
    
    host = a->getAssets()->getRemoteIp();
    port = a->getAssets()->getRemotePort();
    
    sender->setup(host, port);
    cout << "Sending to "<< host << " " << port << endl;
    
    ofAddListener(ofEvents().update, this, &OscAdapter::update);
}

OscAdapter::~OscAdapter(){
    delete receiver;
    delete sender;
}

void OscAdapter::update(ofEventArgs &args){
    while(receiver->hasWaitingMessages()){
        bOnline = true;
        ofxOscMessage m;
        receiver->getNextMessage(&m);
        processOscMessage(m);
    }
}

void OscAdapter::sendAction(string msg, int param){
    ofxOscMessage m;
    m.setAddress(msg);
    m.addIntArg(param);
    sender->sendMessage(m);
}

void OscAdapter::sendAction(string msg, int param, int param2){
    ofxOscMessage m;
    m.setAddress(msg);
    m.addIntArg(param);
    m.addIntArg(param2);
    sender->sendMessage(m);
}

void OscAdapter::processOscMessage(ofxOscMessage msg){
    
    if(msg.getAddress() == "/"){
    }
    
}
