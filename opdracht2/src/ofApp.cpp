#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup("Instellingen", "settings.xml");
	gui.add(radius.set("Radius", 20, 0, 40));
	gui.add(speedX.set("speedX", 1.0, -2.0, 2.0));
	gui.add(speedY.set("speedY", 1.0, -2.0, 2.0));
	gui.add(color.set("color", ofColor::black, 0, 200));
}

//--------------------------------------------------------------
void ofApp::update(){
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
	if (key == ' ') {
		Ball myBall;
		myBall.setup(radius,speedX,speedY,color);
		balls.push_back(myBall);
		
		ofLog() << "ball created" << endl;
	}
	else if (key == 'g') {
		if (!toggle) {
			gui.minimizeAll();
			toggle = true;
		}
		else {
			gui.maximizeAll();
			toggle = false;
		}
		ofLog() << "key pressed" << endl;
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
