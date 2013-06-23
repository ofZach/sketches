#include "rotoSketch2Scene.h"

//--------------------------------------------------------------
void rotoSketch2Scene::setup(){

    
    pina.loadMovie("pina.mov");
    cout << pina.getHeight() << endl;
    pina.play();
}

//--------------------------------------------------------------
void rotoSketch2Scene::update(){
    
    pina.update();
}

//--------------------------------------------------------------
void rotoSketch2Scene::draw(){

    
    
    ofSetColor(255,255,255);
    pina.draw(0,0);
    
    
    float time = pina.getPosition() * pina.getDuration();
    
    ofDrawBitmapStringHighlight(ofToString(time), 30,30);
    
    
    //stroke.draw();
    
    ofSetColor(0,0,0);
    
    stroke.totalTime = pina.getDuration();
    stroke.draw(time, 1);
    
    for (int i = 0; i < strokes.size(); i++){
        strokes[i].draw(time, 1);
        strokes[i].totalTime = pina.getDuration();
    }
}

//--------------------------------------------------------------
void rotoSketch2Scene::keyPressed(int key){

    strokes.clear();
}

//--------------------------------------------------------------
void rotoSketch2Scene::keyReleased(int key){

}

//--------------------------------------------------------------
void rotoSketch2Scene::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void rotoSketch2Scene::mouseDragged(int x, int y, int button){
    
//    if (mouseY > 600){
//        
//        float speed = ofMap(mouseX, 0, ofGetWidth(), -2, 2);
//        pina.setSpeed(speed);
//        return;
//        
//    }
    
    float time = pina.getPosition() * pina.getDuration();
    stroke.addVertex(ofPoint(x,y), time);
}

//--------------------------------------------------------------
void rotoSketch2Scene::mousePressed(int x, int y, int button){
    strokes.push_back(stroke);
    stroke.clear();
}

//--------------------------------------------------------------
void rotoSketch2Scene::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void rotoSketch2Scene::windowResized(int w, int h){

}

//--------------------------------------------------------------
void rotoSketch2Scene::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void rotoSketch2Scene::dragEvent(ofDragInfo dragInfo){ 

}