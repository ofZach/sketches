#pragma once

#include "baseScene.h"
#include "recordPointsScene.h"




class recordPointsNoiseScene : public recordPointsScene {

	public:
    
        void setup(){
            sceneName = "record points + noise scene";
        }
    
        void update();
    
    
		
};
