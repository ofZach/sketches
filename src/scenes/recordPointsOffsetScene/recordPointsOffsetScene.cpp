#include "recordPointsOffsetScene.h"


//--------------------------------------------------------------
void recordPointsOffsetScene::update(){

    ofBackground(0,0,0);

    
    

}


//--------------------------------------------------------------
void recordPointsOffsetScene::mouseDragged(int x, int y, int button){
    
    if (button != 0) return;

    float dx = x - px;
    float dy = y - py;
    
    
    // first, make a point
    ofPoint pt;
    pt.set(x,y);
    
    for (int i = 0; i < line.size(); i++){
        line.getVertices()[i] -= ofPoint(dx, dy);
    }
    
    for (int i = 0; i < olderLines.size(); i++){
        for (int j = 0; j  < olderLines[i].getVertices().size(); j++){
            olderLines[i].getVertices()[j] -= ofPoint(dx, dy);
        }
    }
    px = x;
    py = y;
    
    
    // then add it to the line.
    line.addVertex(pt);
}

//--------------------------------------------------------------
void recordPointsOffsetScene::mousePressed(int x, int y, int button){
    
    if (button != 0) return;
    
    px = x;
    py = y;
    
    //line.clear();
}