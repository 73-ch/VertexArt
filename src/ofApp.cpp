#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    // 頂点数初期化
    vertex_num = 1000000;
    
    // shaderを/bin/data/vs/から読み出す部分
    dir.open("vs");
    dir.allowExt("vert");
    dir.listDir();
//    cout << dir.size() << endl;
    selected_shader = dir.size() - 1;
    shader.load(dir.getPath(selected_shader), "frag.glsl");
    
    // vertexのpositionの設定
    vector<vec3> positions;
    positions.reserve(vertex_num);
    for (int i = 0; i < vertex_num; i++) vbo.addVertex(vec3(0));
    
    // r_seed初期化
    for (int i = 0; i < r_seeds.size(); i++) r_seeds[i] = vec4(ofRandom(1), ofRandom(1), ofRandom(1), ofRandom(1));
    
    // cameraの初期化
    cam.setNearClip(0.00001);
    cam.setFarClip(10000);
    
    
    // 書き出し設定
//    exp.setup(2560, 1440, 60);
//    exp.setOutputDir("out");
//    exp.setOverwriteSequence(true);
//    exp.setAutoExit(true);
//    exp.startExport();
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    // 書き出し
//    exp.begin();
    
    ofClear(0);
    cam.begin();
    
    shader.begin();
    shader.setUniform1f("time", ofGetElapsedTimef());
    shader.setUniform1i("vertex_num", vertex_num);
    shader.setUniform4f("r_seed0", r_seeds[0]);
    shader.setUniform4f("r_seed1", r_seeds[1]);
    shader.setUniform4f("r_seed2", r_seeds[2]);
    shader.setUniform2f("mouse_pos", mouse_pos);
    vbo.setMode(OF_PRIMITIVE_POINTS);
    vbo.draw();
    shader.end();
    cam.end();
    
    // 書き出し
//    exp.end();
//    exp.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'r':
            ofResetElapsedTimeCounter();
            shader.load(dir.getPath(selected_shader), "frag.glsl");
            break;
            
        case 'n':
            dir.open("vs");
            dir.allowExt("vert");
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
            dir.open("vs");
            dir.allowExt("vert");
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
    mouse_pos = vec2(x / ofGetWidth(), y / ofGetHeight());
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
