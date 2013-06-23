#pragma once

#include "baseScene.h"
#include "recordPointsScene.h"




class recordPointsRandomScene : public recordPointsScene {

	public:
    
        void setup(){
            sceneName = "record points + random scene";
        }
    
        void update();
    
    
		
};
