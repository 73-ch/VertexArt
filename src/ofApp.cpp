#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    vertex_num = 100000;
    
    vector<vec3> positions;
    positions.reserve(vertex_num);
    for (int i = 0; i < vertex_num; i++) vbo.addVertex(vec3(0));
    
    dir.open("");
    dir.allowExt("vert");
    dir.listDir();
    selected_shader = dir.size() - 1;
    shader.load(dir.getPath(selected_shader), "frag.glsl");
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();

    shader.begin();
    shader.setUniform1f("time", ofGetElapsedTimef());
    vbo.setMode(OF_PRIMITIVE_POINTS);
    vbo.draw();
    shader.end();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'r':
            ofSetWindowShape(1024, 1024);
            ofResetElapsedTimeCounter();
            break;
            
        case 'n':
            dir.open("");
            dir.allowExt("frag");
            dir.listDir();
            if (selected_shader >= dir.size() - 1){
                selected_shader = 0;
            }else{
                selected_shader++;
            }
            cout << dir.getPath(selected_shader) << " selected" << endl;
            shader.load(dir.getPath(selected_shader), "frag.glsl");
            break;
            
        case 'b':
            dir.open("");
            dir.allowExt("frag");
            dir.listDir();
            if (selected_shader <= 0){
                selected_shader = dir.size() - 1;
            }else{
                selected_shader--;
            }
            cout << dir.getPath(selected_shader) << " selected" << endl;
    
            shader.load(dir.getPath(selected_shader), "frag.glsl");
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
