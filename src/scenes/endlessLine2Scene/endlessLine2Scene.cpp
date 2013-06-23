#include "endlessLine2Scene.h"



void endlessLine2Scene::drawPolylineInRectangle(ofPolyline & line, ofRectangle rect){
    
    
    // find the bounding rectangle of polyline
    ofRectangle box = line.getBoundingBox();
    
    // check the aspect ratio
    float boxRatio = box.width / (float)box.height;
    float rectRatio = rect.width / (float)rect.height;
    
    if (boxRatio > rectRatio){  // I am wider then higher
    
        float scale = rect.width / (float)box.width;
        ofPoint translate;
        translate.set(rect.x, rect.y + (rect.height - box.height*scale) / 2);
        
        ofPushMatrix();
        ofTranslate(translate.x, translate.y,0);
        ofScale(scale, scale, 1);
        ofTranslate(-box.x, -box.y);
        line.draw();
        ofPopMatrix();
        
    } else {
        
        float scale = rect.height / (float)box.height;
        ofPoint translate;
        translate.set(rect.x + (rect.width - box.width*scale) / 2, rect.y);
        
        ofPushMatrix();
        ofTranslate(translate.x, translate.y,0);
        ofScale(scale, scale, 1);
         ofTranslate(-box.x, -box.y);
        line.draw();
        ofPopMatrix();
        
        
    }
    
    
    
}


//--------------------------------------------------------------
void endlessLine2Scene::setup(){

    ofBackground(0,0,0);
    ofSetFrameRate(30);
    total.addVertex(0,0);
    angle = 0;
    angleSmooth = 0;
}

//--------------------------------------------------------------
void endlessLine2Scene::update(){

    
    
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
void endlessLine2Scene::draw(){

    
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
    
    
    }
    
    
    for (int i = 0; i < oldLines.size(); i++){
        
        ofSetColor(50,50,50);
        ofRect(100*i,0,99,99);
        ofSetColor(255,255,255);
        drawPolylineInRectangle(oldLines[i], ofRectangle(100*i,0,99,99));
    }
    
    
    
    
}

//--------------------------------------------------------------
void endlessLine2Scene::keyPressed(int key){

    int which = key - '0';
    if (which >= 0 && which < oldLines.size()){
        angleLine.convertFrom(oldLines[which]);
        for (int i = 0; i < angleLine.angleDiffs.size(); i++){
            angleDiffs.push_back(angleLine.angleDiffs[i]);
            distances.push_back(angleLine.distances[i]);
        }
    }
}

//--------------------------------------------------------------
void endlessLine2Scene::keyReleased(int key){

    if (key == 'f') ofToggleFullscreen();
    
}

//--------------------------------------------------------------
void endlessLine2Scene::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void endlessLine2Scene::mouseDragged(int x, int y, int button){

    line.addVertex(ofPoint(x,y));
       
    

}

//--------------------------------------------------------------
void endlessLine2Scene::mousePressed(int x, int y, int button){

    line.clear();
}

//--------------------------------------------------------------
void endlessLine2Scene::mouseReleased(int x, int y, int button){
    
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
void endlessLine2Scene::windowResized(int w, int h){

}

//--------------------------------------------------------------
void endlessLine2Scene::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void endlessLine2Scene::dragEvent(ofDragInfo dragInfo){ 

}