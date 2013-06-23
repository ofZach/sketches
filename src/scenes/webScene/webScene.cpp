#include "webScene.h"

//--------------------------------------------------------------
void webScene::setup(){

    ofBackground(255,255,255);
}

//--------------------------------------------------------------
void webScene::update(){

    ofBackground(255,255,255);
}

void webScene::clear(){
    
    drawnPoints.clear();
    lines.clear();
    
}
//--------------------------------------------------------------
void webScene::draw(){

    ofEnableAlphaBlending();
    ofSetColor(30,30,30,30);
    
    for (int i = 0; i < lines.size(); i++){
        ofLine( lines[i].a.x, lines[i].a.y, lines[i].b.x, lines[i].b.y);
    }
}

//--------------------------------------------------------------
void webScene::keyPressed(int key){
    if (key == 'f') ofToggleFullscreen();
    

}

//--------------------------------------------------------------
void webScene::keyReleased(int key){

}

//--------------------------------------------------------------
void webScene::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void webScene::mouseDragged(int x, int y, int button){

    for (int i = 0; i < drawnPoints.size(); i++){
        ofPoint mouse;
        mouse.set(x,y);
        float dist = (mouse - drawnPoints[i]).length();
        if (dist < 80){
            line lineTemp;
            lineTemp.a = mouse;
            lineTemp.b = drawnPoints[i];
            lines.push_back(lineTemp);
        }
    }
    
    drawnPoints.push_back(ofPoint(x,y));
    
    
}

//--------------------------------------------------------------
void webScene::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void webScene::mouseReleased(int x, int y, int button){

}
