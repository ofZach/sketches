#include "recordPointsRandomScene.h"


//--------------------------------------------------------------
void recordPointsRandomScene::update(){
    
    
    ofBackground(0,0,0);

    
    for (int i = 0; i < line.size(); i++){
        line.getVertices()[i] += ofPoint(ofRandom(-1,1), ofRandom(-1,1));
    }
    
    for (int i = 0; i < olderLines.size(); i++){
        for (int j = 0; j  < olderLines[i].getVertices().size(); j++){
            olderLines[i].getVertices()[j] += ofPoint(ofRandom(-1,1), ofRandom(-1,1));
        }
    }
    
    
    
}