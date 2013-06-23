#include "angleLineScene.h"

//--------------------------------------------------------------
void angleLineScene::setup(){

    ofBackground(0,0,0);
}

//--------------------------------------------------------------
void angleLineScene::update(){

    ofBackground(0);
}

//--------------------------------------------------------------
void angleLineScene::draw(){

    
    ofSetColor(255);
    line.draw();
    
    
    ofEnableAlphaBlending();
    ofSetColor(255,255,255, 40);
    ofSetLineWidth(13);
    
    for (int i = 0; i < alines.size(); i++){
        alines[i].draw();
    }
    
    ofSetColor(255);
    ofSetLineWidth(1);
    
    for (int i = 0; i < alines.size(); i++){
        alines[i].draw();
    }
    
}

//--------------------------------------------------------------
void angleLineScene::keyPressed(int key){
    
    if (key == 'f') ofToggleFullscreen();
    
    else  alines.clear();
    
}

//--------------------------------------------------------------
void angleLineScene::keyReleased(int key){

}

//--------------------------------------------------------------
void angleLineScene::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void angleLineScene::mouseDragged(int x, int y, int button){

    if (button != 0) return;
    
    line.addVertex(ofPoint(x,y));
    

}

//--------------------------------------------------------------
void angleLineScene::mousePressed(int x, int y, int button){

    if (button != 0) return;
    
    line.clear();
}

//--------------------------------------------------------------
void angleLineScene::mouseReleased(int x, int y, int button){
    
    if (button != 0) return;
    
    angleLine.convertFrom(line);
    alines.push_back(angleLine);
    line.clear();
    
}

//--------------------------------------------------------------
void angleLineScene::windowResized(int w, int h){

}

//--------------------------------------------------------------
void angleLineScene::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void angleLineScene::dragEvent(ofDragInfo dragInfo){ 

}