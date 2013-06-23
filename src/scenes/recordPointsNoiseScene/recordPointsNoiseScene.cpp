#include "recordPointsNoiseScene.h"



//--------------------------------------------------------------
void recordPointsNoiseScene::update(){
    
    
    ofBackground(0,0,0);


    
    int counter = 0;
    
    for (int i = 0; i < line.size(); i++){
        
        float x = line.getVertices()[i].x;
        float y = line.getVertices()[i].y;
        line.getVertices()[i] += 4 * ofPoint( ofSignedNoise(  x/1000.0, y/1000.0, ofGetElapsedTimef() - counter * 0.0001 ), ofSignedNoise(  x/1000.0, y/1000.0, ofGetElapsedTimef()/10.0 + 1000000 + counter * 0.0001 ));
        
        counter++;
    }
    
    for (int i = 0; i < olderLines.size(); i++){
        
        
        counter = 0;
        
        for (int j = 0; j  < olderLines[i].getVertices().size(); j++){
            
            
            float x = olderLines[i].getVertices()[j].x;
            float y = olderLines[i].getVertices()[j].y;
            
            olderLines[i].getVertices()[j] += 4 * ofPoint( ofSignedNoise(  x/1000.0, y/1000.0, ofGetElapsedTimef()/10.0 - counter * 0.0001), ofSignedNoise(  x/1000.0, y/1000.0, ofGetElapsedTimef()/10.0 + 1000000  + counter * 0.0001));
            
            counter++;
        }
    }
    
    
    
}