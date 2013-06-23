#pragma once

#include "baseScene.h"
#include "recordPointsScene.h"




class recordPointsOffsetAccelScene : public recordPointsScene {

	public:
    
        void setup(){
            sceneName = "record points offset acceleromter scene";
        }

    
        void update();
        virtual void mouseDragged(int x, int y, int button);
        virtual void mousePressed(int x, int y, int button);
    
        float px, py;
    
    
		
};
