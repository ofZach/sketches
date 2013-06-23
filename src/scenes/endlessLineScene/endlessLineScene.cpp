#include "endlessLineScene.h"

//--------------------------------------------------------------
void endlessLineScene::setup(){

    //ofBackground(0,0,0);
    //ofSetFrameRate(30);
    total.addVertex(0,0);
    angle = 0;
    angleSmooth = 0;
}

//--------------------------------------------------------------
void endlessLineScene::update(){

    ofBackground(0);
    
    if (angleDiffs.size() > 0){
        
        for (int i = 0; i < total.getVertices().size(); i++){
            total.getVertices()[i].z -= 0.5;
        }
        
        angle += angleDiffs[0];
        float dist = distances[0];
        ofPoint lastVertex = total.getVertices()[ total.getVertices().size() - 1 ];
        ofPoint newVeretx = lastVertex + ofPoint( cos(angle) * dist, sin(angle) * dist);
        angleDiffs.erase(angleDiffs.begin());
        total.addVertex(newVeretx.x, newVeretx.y);
        distances.erase(distances.begin());
        
        
        
    }
    
    
    
    catchPoint = 0.9f * catchPoint + 0.1f * total.getVertices()[total.getVertices().size()-1];
}

//--------------------------------------------------------------
void endlessLineScene::draw(){

    
    ofEnableAlphaBlending();
    
    //line.draw();
    if (ofGetMousePressed() == true){
        ofSetColor(255,255,255,100);
        line.draw();
    }
    
    if (total.getVertices().size() > 150){
        total.getVertices().erase(total.getVertices().begin());
    }
    
    if (total.getVertices().size() > 0){
        
    
        
    ofPushMatrix();
    ofTranslate(-catchPoint.x + ofGetWidth()/2, -catchPoint.y + ofGetHeight()/2);
    
        ofSetLineWidth(5);
        
        ofMesh mesh;
        
        mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    //glBegin(GL_LINE_STRIP);
    for (int i = 0; i < total.getVertices().size(); i++){
        float pct = ofMap(i, 0, total.getVertices().size()-1, 0,1);
        //ofSetColor(255,255,255,255*pct);
        mesh.addColor(ofColor(255,255,255,255*pct));
        mesh.addVertex(ofPoint(total.getVertices()[i].x, total.getVertices()[i].y, total.getVertices()[i].z));
     //   glVertex3f(total.getVertices()[i].x, total.getVertices()[i].y, total.getVertices()[i].z);
    }
    //glEnd();
    //ofEndShape();
        //mesh.end();
        mesh.draw();
    //total.draw();
    ofPopMatrix();
    
        ofSetLineWidth(1);
    
    }
    
    
    
}

//--------------------------------------------------------------
void endlessLineScene::keyPressed(int key){

    if (key == 'f') ofToggleFullscreen();
    
}

//--------------------------------------------------------------
void endlessLineScene::keyReleased(int key){

}

//--------------------------------------------------------------
void endlessLineScene::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void endlessLineScene::mouseDragged(int x, int y, int button){

    line.addVertex(ofPoint(x,y));

}

//--------------------------------------------------------------
void endlessLineScene::mousePressed(int x, int y, int button){

    line.clear();
}

//--------------------------------------------------------------
void endlessLineScene::mouseReleased(int x, int y, int button){
    
    //line = line.getResampledByCount(100);
    
    
    oldLines.push_back(line);
    
    
    if (oldLines.size() > 8) oldLines.erase(oldLines.begin());
    angleLine.convertFrom(line);

    
    
    for (int i = 0; i < angleLine.angleDiffs.size(); i++){
        angleDiffs.push_back(angleLine.angleDiffs[i]);
        distances.push_back(angleLine.distances[i]);
    }
}

//--------------------------------------------------------------
void endlessLineScene::windowResized(int w, int h){

}

//--------------------------------------------------------------
void endlessLineScene::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void endlessLineScene::dragEvent(ofDragInfo dragInfo){ 

}