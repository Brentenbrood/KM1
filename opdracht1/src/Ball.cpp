#include "Ball.h"

Ball::Ball()
{
}

void Ball::setup() {
	x = ofRandom(0, ofGetWidth());
	y = ofRandom(0, ofGetHeight());

	speedx = ofRandom(-2, 2);
	speedy = ofRandom(-2, 2);

	radius = 20;
	color.set(ofRandom(255), ofRandom(255), ofRandom(255));
}

void Ball::update() {
	if (x + radius / 2 >= ofGetWidth() || x - radius / 2 <= 0) {
		speedx = -speedx;
	}
	if (y + radius / 2 >= ofGetHeight() || y - radius / 2 <= 0) {
		speedy = -speedy;
	}

	x += speedx;
	y += speedy;
}

void Ball::draw() {
	ofSetColor(ofColor::red);
	ofDrawCircle(x, y, radius);
}


