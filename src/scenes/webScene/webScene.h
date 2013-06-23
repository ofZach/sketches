#pragma once

#include "baseScene.h"

class line {
public: 
    ofPoint a;
    ofPoint b;
};

class webScene : public baseScene{

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
		
        vector < ofPoint > drawnPoints;
        vector < line > lines;

        void clear();
    
    
};
