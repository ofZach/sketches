#include "thicknessScene.h"




//--------------------------------------------------------------
void thicknessScene::setup(){

    ofBackground(255,255,255);
}

//--------------------------------------------------------------
void thicknessScene::update(){

    ofBackground(255, 255, 255);
}

//--------------------------------------------------------------
void thicknessScene::draw(){

    
    line.draw();
    
    for (int i = 0; i < olderLines.size(); i++){
        olderLines[i].draw();
    }
        
    
        
}

//--------------------------------------------------------------
void thicknessScene::keyPressed(int key){
    if (key == 'f') ofToggleFullscreen();
    

}

//--------------------------------------------------------------
void thicknessScene::keyReleased(int key){

}

//--------------------------------------------------------------
void thicknessScene::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void thicknessScene::mouseDragged(int x, int y, int button){

    line.line.addVertex(ofPoint(x,y));
}

//--------------------------------------------------------------
void thicknessScene::mousePressed(int x, int y, int button){

    //line.clear();
}

//--------------------------------------------------------------
void thicknessScene::mouseReleased(int x, int y, int button){

    olderLines.push_back(line);
    line.line.clear();
}

//--------------------------------------------------------------
void thicknessScene::windowResized(int w, int h){

}

//--------------------------------------------------------------
void thicknessScene::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void thicknessScene::dragEvent(ofDragInfo dragInfo){ 

}