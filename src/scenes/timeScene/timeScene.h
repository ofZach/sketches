


#pragma once

#include "baseScene.h"
#include "ofMain.h"
#include "timePoint.h"
#include "timePointRecorder.h"



class timeScene : public baseScene {

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
        
	
		timePointRecorder		TPR;
		float					playbackStartTime;
	
		ofSoundPlayer			loopingSound;
	
        int mouseX, mouseY;
    
        bool bGetMousePressed;
    
        ofPoint prevPos;    // prev mouseX/mouseY

	void clear(){
        //printf("here!");
        loopingSound.setVolume(0);
        //loopingSound.stop();
        TPR.clear();
        
    }
    
};
