//
//  brush.hpp
//  midterm_04
//
//  Created by Amogh Dwivedi on 3/23/26.
//

#ifndef brush_hpp
#define brush_hpp

#include <stdio.h>
#include "ofMain.h"

class Brush{
public:
	Brush();
	
	void setup(float orbitRadius, float startAngle);
	void applyForce(ofVec2f force);
	void update();
	void display();
	void setColor(int mode);
	bool isDead();
	void respawn();
	
	ofVec2f position;
	ofVec2f velocity;
	ofVec2f acceleration;
	
	float lifespan;
	
	int colorMode;
	
	float radius;
	float initRadius;
	float theta;
	float angularVelocity;
	
	int brushDir = 0; // 0 is clockwise, 1 is counter clockwise
	
	float mass;
	
	float w = 10;
	float h = 10;
	
	float finalX[3];
	float finalY[3];
	
	float finalW[3];
	float finalH[3];
	
	int r;
	int g;
	int b;
	int a[3];
	
	float rPos;
	float gPos;
	float bPos;
	float radiusPos;
	float massPos;
	
	float rSpeed = 0.03;
	float gSpeed = 0.09;
	float bSpeed = 0.13;

	
	float nSpeed = 0.005;
	float nSpeed2 = 0.02;
	float radiusSpeed = 0.001;
	float massSpeed = 0.5;
	
};

#endif /* brush_hpp */
