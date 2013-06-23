#pragma once

#include "ofMain.h"
#include "baseScene.h"


class thickLine {
    
    
public: 
    
    ofPolyline line;
    
    void draw(){
        
        ofMesh meshy;
        meshy.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        
        
        float widthSmooth = 10;
        float angleSmooth;
        
        for (int i = 0;  i < line.getVertices().size(); i++){
            
            
            int me_m_one = i-1;
            int me_p_one = i+1;
            if (me_m_one < 0) me_m_one = 0;
            if (me_p_one ==  line.getVertices().size()) me_p_one =  line.getVertices().size()-1;
            
            ofPoint diff = line.getVertices()[me_p_one] - line.getVertices()[me_m_one];
            float angle = atan2(diff.y, diff.x);
            
            if (i == 0) angleSmooth = angle;
            else {
                
                angleSmooth = ofLerpDegrees(angleSmooth, angle, 1.0);
                
            }
            
            
            float dist = diff.length();
            
            float w = ofMap(dist, 0, 20, 30, 2, true);
            
            w +=  (sin(ofGetElapsedTimef() * 3 + i / 4.0) * 0.5 + 0.5) * 30;
            
            widthSmooth = 0.97f * widthSmooth + 0.03f * w;
            
            ofPoint offset;
            offset.x = cos(angleSmooth + PI/2) * widthSmooth;
            offset.y = sin(angleSmooth + PI/2) * widthSmooth;
            
            
            
            meshy.addVertex(  line.getVertices()[i] +  offset );
            meshy.addVertex(  line.getVertices()[i] -  offset );
            
            
            
        }
        
        ofSetColor(0,0,0);
        meshy.draw();
        ofSetColor(100,100,100);
        meshy.drawWireframe();

    }
    
};

class thicknessScene : public  baseScene {

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
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    

        thickLine line;
        
		vector < thickLine > olderLines;
    
    void clear(){
        line.line.clear();
        olderLines.clear();
    }
};
