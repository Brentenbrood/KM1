#pragma once

#include "ofMain.h"
#include "Ball.h"
#define NBALLS 10

Ball myBall[NBALLS];

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		
private:

	

};
