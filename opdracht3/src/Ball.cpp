#include "Ball.h"

Ball::Ball()
{
}

void Ball::setup(int r, float sX, float sY, ofColor c) {
	x = ofRandom(0, ofGetWidth());
	y = ofRandom(0, ofGetHeight());

	speedx = ofRandom(-2, 2);
	speedy = ofRandom(-2, 2);
	radius = 20;
	if (r)
		radius = r;
	if (sX)
		speedx = sX;
	if (sY)
		speedy = sY;

	color = c;
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
	ofSetColor(color);
	ofDrawCircle(x, y, radius);
}


