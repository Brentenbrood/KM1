#pragma once
#define _BALL // by using this if statement you prevent the class to be called more than once which would confuse the compiler
#include "ofMain.h" // we need to include this to have a reference to the openFrameworks framework

class Ball
{
public:
	void setup();
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

