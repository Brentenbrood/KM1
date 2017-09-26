#include "ofApp.h"
void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(ofColor::black);
	ofEnableLighting();
}

void ofApp::update(){
	std::stringstream strm;
	strm << "fps: " << ofGetFrameRate();
	ofSetWindowTitle(strm.str());
	rotateX = rotateX + 1;
	rotateY = rotateY + 2;
	rotateZ = rotateZ + 3;
}

void ofApp::draw(){
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);

	if (rotate) {
		ofRotateX(rotateX);
		ofRotateY(rotateY);
		ofRotateZ(rotateZ);
	}
	if (drawGrid) {
		ofDrawGrid(200);
	}
	ofDrawSphere(100, 100, 100, 50);
	light.enable();
}

void ofApp::keyPressed(int key){
	if (key == 'g') {
		drawGrid = !drawGrid;
	}
	if (key == ' ') {
		rotate = !rotate;
	}
}

