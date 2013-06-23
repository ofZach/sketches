#include "recordPointsOffsetAccelScene.h"

//--------------------------------------------------------------
void recordPointsOffsetAccelScene::update(){

    ofBackground(0,0,0);

    
    float dx = -info->rawAccel.y / 5.0;
    float dy = info->rawAccel.x / 5.0;
    
    
    for (int i = 0; i < line.size(); i++){
        line.getVertices()[i] -= ofPoint(dx, dy);
    }
    
    for (int i = 0; i < olderLines.size(); i++){
        for (int j = 0; j  < olderLines[i].getVertices().size(); j++){
            olderLines[i].getVertices()[j] -= ofPoint(dx, dy);
        }
    }


}


//--------------------------------------------------------------
void recordPointsOffsetAccelScene::mouseDragged(int x, int y, int button){
    
    if (button != 0) return;

    float dx = -info->rawAccel.y / 5.0;
    float dy = info->rawAccel.x / 5.0;
    
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
    
    
    
    // then add it to the line.
    line.addVertex(pt);
}

//--------------------------------------------------------------
void recordPointsOffsetAccelScene::mousePressed(int x, int y, int button){
    
    if (button != 0) return;
    
    px = x;
    py = y;
    
    //line.clear();
}