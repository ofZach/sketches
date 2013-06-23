

#pragma once 

#include "ofMain.h"


class appInfo {
    public: 
    bool bFingerDown [10];
    ofPoint fingerPt[10];
    ofPoint rawAccel;
};



class baseScene {
    
public:
    
    baseScene(){

    }
    
    virtual void setup(){};
    virtual void update(){};
    virtual void draw(){};
    
    virtual void keyPressed  (int key){};
    virtual void keyReleased(int key){};
    virtual void mouseDragged(int x, int y, int button){};
    virtual void mousePressed(int x, int y, int button){};
    virtual void mouseReleased(int x, int y, int button){};
    
    string sceneName;
    int sceneId;
    
    appInfo * info;
    
    virtual void clear(){};
    
    
    
};