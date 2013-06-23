#include "ribbonScene.h"




//--------------------------------------------------------------
void ribbonScene::setup(){

    ofSetVerticalSync(true);
    ofBackground(255,255,255);
}

//--------------------------------------------------------------
void ribbonScene::update(){

    ofBackground(255,255,255);
}

//--------------------------------------------------------------
void ribbonScene::draw(){

    
    
    
    line.draw();
        
}

//--------------------------------------------------------------
void ribbonScene::keyPressed(int key){

    if (key == 'f') ofToggleFullscreen();
    

}

//--------------------------------------------------------------
void ribbonScene::keyReleased(int key){

}

//--------------------------------------------------------------
void ribbonScene::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ribbonScene::mouseDragged(int x, int y, int button){

    line.line.addVertex(ofPoint(x,y));
}

//--------------------------------------------------------------
void ribbonScene::mousePressed(int x, int y, int button){

    line.line.clear();
}

//--------------------------------------------------------------
void ribbonScene::mouseReleased(int x, int y, int button){

    
    ///olderLines.push_back(line);
    
}

//--------------------------------------------------------------
void ribbonScene::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ribbonScene::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ribbonScene::dragEvent(ofDragInfo dragInfo){ 

}