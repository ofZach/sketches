#include "testApp.h"
#include "webScene.h"
#include "recordPointsScene.h"
#include "recordPointsRandomScene.h"
#include "recordPointsOffsetScene.h"
#include "recordPointsNoiseScene.h"
#include "recordPointsOffsetAccelScene.h"


#include "angleLineScene.h"
#include "timeScene.h"
#include "thicknessScene.h"
#include "rotoSketch2Scene.h"
#include "endlessLineScene.h"
#include "ribbonScene.h"
#include "thicknessScene.h"
#include "rotoSketchScene.h"


int audioScene = 7;

//--------------------------------------------------------------
void testApp::setup(){	
	// initialize the accelerometer
	ofxAccelerometer.setup();

    //If you want a landscape oreintation 
	//iPhoneSetOrientation(OFXIPHONE_ORIENTATION_LANDSCAPE_RIGHT);
	
	ofBackground(127,127,127);
    
    
    font.loadFont("aprc_font.otf", 20);
    
    scenes.push_back(new recordPointsScene());
    scenes.push_back(new recordPointsRandomScene());
    scenes.push_back(new recordPointsOffsetScene());
    scenes.push_back(new recordPointsOffsetAccelScene());
    scenes.push_back(new angleLineScene());
    
    scenes.push_back(new thicknessScene());
    scenes.push_back(new rotoSketchScene());
    scenes.push_back(new timeScene());
    
    
    scenes.push_back(new ribbonScene());
    scenes.push_back(new webScene());
    
    for (int i = 0; i < scenes.size(); i++){
        
        scenes[i]->setup();
        scenes[i]->info = &info;
        
    }
    
    for (int i = 0; i < 10; i++){
        info.bFingerDown[i] = false;
    }
    
    
    whichScene = 0;
    bPressedControl = false;
    
    control.loadImage("control.png");
}

//--------------------------------------------------------------
void testApp::update(){
    
    info.rawAccel = ofxAccelerometer.getOrientation();
    //cout << ofxAccelerometer.getRawAcceleration() << endl;
    scenes[whichScene]->update();
}

//--------------------------------------------------------------
void testApp::draw(){
    scenes[whichScene]->draw();
    
    
    ofEnableAlphaBlending();
    ofSetColor(100,100,100,220);
    ofFill();
    ofRect(0,0,ofGetWidth(),50);
    ofSetColor(255);
    //control.draw(50,0, control.width/2, control.height/2);
    
    font.drawString( "prev | next | clear    (" + ofToString(whichScene) + ") ", 50,35);
    
}
//--------------------------------------------------------------
void testApp::exit(){

}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs & touch){
    
    
    if (touch.y < 50) bPressedControl = true;
    else bPressedControl = false;
    
    if (bPressedControl){
        float x = touch.x;
        cout << x << endl;
        if (x > 50 && x < 100){
            
            scenes[whichScene]->clear();
            whichScene -= 1;
            if (whichScene < 0) whichScene += scenes.size();
            scenes[whichScene]->clear();
            // if (whichScene == audioScene) ((timeScene*)scenes[whichScene])->loopingSound.play();
            
        } else if (x > 150 && x < 200){
            
            scenes[whichScene]->clear();
            whichScene += 1;
            whichScene %= scenes.size();
            scenes[whichScene]->clear();
            //if (whichScene == audioScene) ((timeScene*)scenes[whichScene])->loopingSound.play();
        } else if (x > 200 && x < 300){
             scenes[whichScene]->clear();
        }
    }
    
    
    info.bFingerDown[touch.id] = true;
    info.fingerPt[touch.id].set(touch.x, touch.y);
    
    if (touch.id == 0)
    scenes[whichScene]->mousePressed(touch.x, touch.y, touch.id);
}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs & touch){
    
    if (bPressedControl) return;
    
    
    info.fingerPt[touch.id].set(touch.x, touch.y);

    if (touch.id == 0)
    scenes[whichScene]->mouseDragged(touch.x, touch.y, touch.id);
}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs & touch){
    
    if (bPressedControl) return;
    
    info.fingerPt[touch.id].set(touch.x, touch.y);
    info.bFingerDown[touch.id] = false;

    
    if (touch.id == 0)
    scenes[whichScene]->mouseReleased(touch.x, touch.y, touch.id);
}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs & touch){

    
}

//--------------------------------------------------------------
void testApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void testApp::lostFocus(){

}

//--------------------------------------------------------------
void testApp::gotFocus(){

}

//--------------------------------------------------------------
void testApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void testApp::deviceOrientationChanged(int newOrientation){

}

