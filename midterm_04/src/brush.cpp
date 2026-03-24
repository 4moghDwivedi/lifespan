//
//  brush.cpp
//  midterm_04
//
//  Created by Amogh Dwivedi on 3/23/26.
//

#include "brush.hpp"

Brush::Brush(){
	
}

void Brush::setup(float orbitRadius, float startAngle){
	mass = ofRandom(1, 5);
	
	radius = orbitRadius;
	initRadius = orbitRadius;
	theta = startAngle;
	
	angularVelocity = 2.0 / radius;
	
	position.x = r * cos(theta);
	position.y = r * sin(theta);
	
	velocity = ofVec2f(0, 0);
	acceleration = ofVec2f(0, 0);
	
	brushDir = floor(ofRandom(0, 2));
	
	for (int i = 0; i < 3; i++){
		
		finalX[i] = position.x + ofRandom(-10, 10);
		finalY[i] = position.y + ofRandom(-10, 10);
		
		finalW[i] = w + ofRandom(-3, 3);
		finalH[i] = h + ofRandom(-3, 3);
	}
	
	r = floor(ofRandom(0, 255));
	g = floor(ofRandom(0, 255));
	b = floor(ofRandom(0, 255));
	
	for (int i = 0; i < 3; i ++){
		a[i] = ofRandom(1, 100);
	}
	
	rPos = ofRandom(500);
	gPos = ofRandom(500);
	bPos = ofRandom(500);
	
	lifespan = ofRandom(100, 255);
	
}

void Brush::applyForce(ofVec2f force){
	ofVec2f a = force / mass;
	acceleration += a;
}

void Brush::update(){
	
	angularVelocity = 2.0 / radius;
	
	
	if (brushDir == 0)
		theta += angularVelocity;
	else
		theta -= angularVelocity;
	
	position.x = r * cos(theta);
	position.y = r * sin(theta);
	
	acceleration *= 0;
	
	float radiusTemp = ofNoise(radiusPos += radiusSpeed);
	float radiusVal = ofMap(radiusTemp, 0, 1, radius * 0.5, radius * 2);
	
	radius = ofClamp(radiusVal, initRadius * 0.5, initRadius * 2);
	
	for (int i = 0; i < 3; i++){
		finalX[i] = position.x + ofRandom(-5, 5);
		finalY[i] = position.y + ofRandom(-5, 5);
	
		finalW[i] = w * ofRandom(0.00001, 0.5);
		finalH[i] = h * ofRandom(0.5, ofRandom(5.0, 10.0));
		
	}
	
	float massTemp = ofNoise(massPos += massSpeed);
	

	
	mass = ofMap(massTemp, 0, 1, 1, 10) + ofRandom(-0.1, 0.1);
	
	lifespan -= ofRandom(1, 5);
		
}

void Brush::display(){
	for (int i = 0; i < 3; i++){
		ofSetColor(r, g, b, a[i]);
		ofFill();
		ofDrawEllipse(finalX[i], finalY[i], finalW[i] * mass, finalH[i] / mass);


		int numLines = floor(ofRandom(5, 10));

		if (colorMode == 0){
			
			//outer line
			ofPushMatrix();
			
			ofSetColor(0, lifespan);
			ofNoFill();
			ofDrawEllipse(finalX[i], finalY[i], finalW[i] * mass, finalH[i] / mass);
			
			ofPopMatrix();

			
			for (int j = 0; j < numLines; j++){

				ofPushMatrix();

				float xOffset1 = ofRandom(-1 * lifespan/8, lifespan/8);
				float yOffset1 = ofRandom(-1 * lifespan/8, lifespan/8);
				
				float xOffset2 = ofRandom(-1 * lifespan/8, lifespan/8);
				float yOffset2 = ofRandom(-1 * lifespan/8, lifespan/8);

				ofSetColor(r, g, b, lifespan);
				ofDrawLine(finalX[i] + xOffset1 , finalY[i] + yOffset1, finalX[i] + xOffset2 , finalY[i] + yOffset2);

				ofPopMatrix();
			}
		}
	}
	

	

}


bool Brush::isDead() {
	return lifespan < 0;
}

void Brush::respawn() {
	radius = ofRandom(0.1, 5);
	theta = ofRandom(TWO_PI);
	angularVelocity = 2.0 / r;
	lifespan = ofRandom(100, 255);
	
	position.x = r * cos(theta);
	position.y = r * sin(theta);
}


void Brush::setColor(int mode) {
	
	colorMode = mode;
	
	if (mode == 0) {
		for (int i = 0; i < 3; i ++){
			a[i] = ofRandom(1, lifespan);
		}
		
		float rTemp = ofNoise(rPos += rSpeed);
		float gTemp = ofNoise(gPos += gSpeed);
		float bTemp = ofNoise(bPos += bSpeed);
		
		float rVal = ofMap(rTemp, 0, 1, 0, 255);
		float gVal = ofMap(gTemp, 0, 1, 0, 255);
		float bVal = ofMap(bTemp, 0, 1, 0, 255);
		
		r = floor(rVal);
		g = floor(gVal);
		b = floor(bVal);
	}
	if (mode == 1) {
		for (int i = 0; i < 3; i ++){
			a[i] = ofRandom(200, 255);
		}
		
		int gray = ofRandom(0, 125);
		
		r = gray;
		g = gray;
		b = gray;
	}

}
