#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
	arduino.connect("COM4");
	arduino.sendFirmwareVersionRequest();
	value = "analog pin:";
	dvalue = "digital pin:";
}

//--------------------------------------------------------------
void ofApp::update(){
	arduino.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

void ofApp::setupArduino(const int& version)
{
	ofLog() << "Arduino firmware found" << arduino.getFirmwareName() << arduino.getMajorFirmwareVersion() << arduino.getMinorFirmwareVersion() << endl;

	//arduino.sendDigitalPinMode(9, ARD_OUTPUT);
	arduino.sendDigitalPinMode(8, ARD_INPUT);
	arduino.sendAnalogPinReporting(0, ARD_ANALOG);
	arduino.sendAnalogPinReporting(1, ARD_ANALOG);

	ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
}

void ofApp::analogPinChanged(const int& pin) {
	ofLog() << "analog pin: " + ofToString(pin) + " = " + ofToString(arduino.getAnalog(pin));
}
void ofApp::digitalPinChanged(const int& pin) {
	ofLog() << "digital pin: " + ofToString(pin) + " = " + ofToString(arduino.getDigital(pin));
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
