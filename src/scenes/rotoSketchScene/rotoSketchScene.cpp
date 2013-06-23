#include "rotoSketchScene.h"

//--------------------------------------------------------------
void rotoSketchScene::setup(){

    ofBackground(255,255,255);
}

//--------------------------------------------------------------
void rotoSketchScene::update(){

}

//--------------------------------------------------------------
void rotoSketchScene::draw(){

   
    
    float timeT = ofGetElapsedTimef();
    while (timeT > 5) timeT -= 5.0;
    ofDrawBitmapStringHighlight(ofToString(timeT), 30,30);
    
    
    
    ofSetColor(0,0,0, 10);
     ofSetLineWidth(13);
    
    stroke.draw(timeT, 1, 5);
    for (int i = 0; i < strokes.size(); i++){
        strokes[i].draw(timeT, 1, 5);
    }
    
    ofSetColor(0,0,0, 200);
    ofSetLineWidth(1);
    
    stroke.draw(timeT, 1, 5);
    for (int i = 0; i < strokes.size(); i++){
        strokes[i].draw(timeT, 1, 5);
    }
    
    
    ofSetLineWidth(1);
}

//--------------------------------------------------------------
void rotoSketchScene::keyPressed(int key){

    strokes.clear();
    stroke.clear();
}

//--------------------------------------------------------------
void rotoSketchScene::keyReleased(int key){

}

//--------------------------------------------------------------
void rotoSketchScene::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void rotoSketchScene::mouseDragged(int x, int y, int button){
    float timeT = ofGetElapsedTimef();
    while (timeT > 5) timeT -= 5.0;
    stroke.addVertex(ofPoint(x,y), timeT);
}

//--------------------------------------------------------------
void rotoSketchScene::mousePressed(int x, int y, int button){
    strokes.push_back(stroke);
    stroke.clear();
}

//--------------------------------------------------------------
void rotoSketchScene::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void rotoSketchScene::windowResized(int w, int h){

}

//--------------------------------------------------------------
void rotoSketchScene::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void rotoSketchScene::dragEvent(ofDragInfo dragInfo){ 

}