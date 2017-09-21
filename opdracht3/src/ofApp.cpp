#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
	arduino.connect("COM3");
	arduino.sendFirmwareVersionRequest();
	value = "analog pin:";
	dvalue = "digital pin:";

	gui.setup("Instellingen", "settings.xml");
	gui.add(radius.set("Radius", 20, 0, 40));
	gui.add(speedX.set("speedX", 1.0, -2.0, 2.0));
	gui.add(speedY.set("speedY", 1.0, -2.0, 2.0));
	gui.add(color.set("color", ofColor::black, 0, 200));
}

//--------------------------------------------------------------
void ofApp::update(){
	arduino.update();
	for (int i = 0; i<balls.size(); i++) {
		balls[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i<balls.size(); i++) {
		balls[i].draw();
	}
	gui.draw();
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
	if (pin == 0) {
		if (arduino.getAnalog(pin) >= 510 && arduino.getAnalog(pin) <= 514) {
			//
		}
		else {
			radius = arduino.getAnalog(pin)/20;
		}
	}
	if (pin == 1) {
		if (arduino.getAnalog(pin) >= 510 && arduino.getAnalog(pin) <= 514) {
			//
		}
	}
	//ofLog() << "analog pin: " + ofToString(pin) + " = " + ofToString(arduino.getAnalog(pin));
}
void ofApp::digitalPinChanged(const int& pin) {
	if (pin == 8) {
		if (!arduino.getDigital(8)) {
			Ball myBall;
			myBall.setup(radius, speedX, speedY, color);
			balls.push_back(myBall);

			ofLog() << "ball created" << endl;
		}
	}
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
