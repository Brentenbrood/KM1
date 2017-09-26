#include "ofApp.h"

void ofApp::setup(){
	gui.setup();
	gui.add(drawGrid.set("Grid", false));
	gui.add(useLight.set("Light", false));
	ofBackground(ofColor::black);
	light.setDirectional();
	light.setPosition(-200, -200, -200);
	light.lookAt(ofVec3f(0, 0, 0), ofVec3f(0, 0, 0));
	light.setDiffuseColor(ofColor::white);
	light.enable();
}

void ofApp::update(){

}

void ofApp::draw(){
	ofEnableDepthTest();
	cam.begin();
	ofSetColor(ofColor::yellow);
	ofDrawSphere(0, 0, 0, 100);
	ofSetColor(ofColor::red);
	ofDrawSphere(100, 0, 0, 50);
	

	if (drawGrid) ofDrawGrid(200);

	if (useLight) {
			ofEnableLighting();
		}
	else {
			ofDisableLighting();
		}
	cam.end();
	ofDisableDepthTest();
	gui.draw();
}

void ofApp::keyPressed(int key){

}
