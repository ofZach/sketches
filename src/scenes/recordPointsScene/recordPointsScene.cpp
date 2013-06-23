#include "recordPointsScene.h"

//--------------------------------------------------------------
void recordPointsScene::setup(){
    ofEnableSmoothing();
    ofBackground(0,0,0);
    
    sceneName = "record points scene";
    
}

//--------------------------------------------------------------
void recordPointsScene::update(){
     ofBackground(0,0,0);
}

//--------------------------------------------------------------
void recordPointsScene::draw(){

    
    ofEnableAlphaBlending();
    ofSetColor(255,255,255, 40);
    ofSetLineWidth(13);

    //ofSetColor(255);
    line.draw();
    for (int i = 0;  i < olderLines.size(); i++){
        olderLines[i].draw();
    }
    ofSetLineWidth(1);
    
    ofSetColor(255);
    line.draw();
    for (int i = 0;  i < olderLines.size(); i++){
        olderLines[i].draw();
    }
}


void recordPointsScene::clear(){
    line.clear();
    olderLines.clear();
}



//--------------------------------------------------------------
void recordPointsScene::mouseDragged(int x, int y, int button){
    
    if (button != 0) return;
    

    // first, make a point
    ofPoint pt;
    pt.set(x,y);
    
    // then add it to the line. 
    line.addVertex(pt);
}

//--------------------------------------------------------------
void recordPointsScene::mousePressed(int x, int y, int button){
    
    if (button != 0) return;
    
    //line.clear();
}

//--------------------------------------------------------------
void recordPointsScene::mouseReleased(int x, int y, int button){
    
    if (button != 0) return;
 olderLines.push_back(line);
    line.clear();
   
}
