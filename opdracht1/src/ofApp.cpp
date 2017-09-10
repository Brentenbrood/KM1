#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(800, 600);
	Ball myball;
}

//--------------------------------------------------------------
void ofApp::update() {
	if (x+radius/2 >= ofGetWidth() || x-radius/2 <= 0) {
		speedx = -speedx;
	}
	if (y+radius/2 >= ofGetHeight() || y-radius/2 <= 0) {
		speedy = -speedy;
	}

	x += speedx;
	y += speedy;
}

//--------------------------------------------------------------
void ofApp::draw(){
		ofSetColor(ofColor::red);
		ofDrawCircle(x, y, radius);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}
