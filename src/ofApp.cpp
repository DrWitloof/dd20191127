#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(255);

  ofDirectory dir(".");
  //only show png files
  dir.allowExt("png");
  dir.allowExt("jpg");
  dir.allowExt("gif");
  //populate the directory object
  dir.listDir();

  for(int i = 0; i < dir.size(); i++){
    ofImage image;
    image.load(dir.getPath(i));
    images.push_back(image);
  }

  ofSetDepthTest(true);
  ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){

}

#define STEPS 80
#define DEGREES_PER_STEP 1

//--------------------------------------------------------------
void ofApp::draw()
{
  static float w = ofGetWidth()/2, h = ofGetHeight()/2;
  ofTranslate( w, h);

  static float degrees_per_image = 360.0/images.size();
  static float drift_per_iteration = (STEPS * DEGREES_PER_STEP) - degrees_per_image;

  int iteration = ofGetFrameNum()/STEPS;
  int iteration_steps = ofGetFrameNum()%STEPS;

  float d1 = (ofGetWidth()
              * std::pow(2, (float)1.5)
              * std::pow(2, (float)iteration_steps/STEPS)
              )
              / std::pow(2, images.size());

  ofRotateDeg( (drift_per_iteration * iteration) + (DEGREES_PER_STEP * iteration_steps));
  for( int i = 0; i<images.size(); i++)
  {
    int ii = (iteration-i)%images.size();
    float iw = d1, ih = images[ii].getHeight() * (d1 / images[ii].getWidth());
    images[ii].draw( - iw / 2, -ih / 2, 1, iw, ih );

    ofRotateDeg( degrees_per_image);
    d1 *= 2;
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
