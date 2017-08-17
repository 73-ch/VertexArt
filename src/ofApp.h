#pragma once

#include "ofMain.h"
#include "ofxExportImageSequence.h"

using namespace glm;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofVboMesh vbo;
    ofShader shader;
    ofEasyCam cam;
    ofDirectory dir;
    int selected_shader;
    
    int vertex_num;
    array<vec4, 3> r_seeds;
    vec2 mouse_pos;
    
    // ビデオのエクスポート
    ofxExportImageSequence exp;
};
