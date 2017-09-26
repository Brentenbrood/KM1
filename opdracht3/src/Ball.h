#pragma once
#include "ofMain.h" // we need to include this to have a reference to the openFrameworks framework

class Ball
{
public:
	void setup(int radius, float speedX, float speedY, ofColor color);
	void update();
	void draw();
	float x;
	float y;
	float speedx;
	float speedy;
	int radius;
	ofColor color;

	Ball();
};

