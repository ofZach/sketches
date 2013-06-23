#pragma once

#include "baseScene.h"





class recordPointsScene : public baseScene {

	public:
    
		virtual void setup();
		virtual void update();
		virtual void draw();

		virtual void mouseDragged(int x, int y, int button);
		virtual void mousePressed(int x, int y, int button);
		virtual void mouseReleased(int x, int y, int button);

        ofPolyline line;
        vector < ofPolyline > olderLines;
    
        void clear();
    
		
};
