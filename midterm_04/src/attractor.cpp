//
//  attractor.cpp
//  midterm_04
//
//  Created by Amogh Dwivedi on 3/23/26.
//

#include "attractor.hpp"
#include "brush.hpp"


Attractor::Attractor() {
	
}

void Attractor::setup(float x, float y, float m){
	position = ofVec2f(x, y);
	mass = m;
	G = 5.0;
}

void Attractor::setPos(float x, float y){
	position.x = x;
	position.y = y;
}

ofVec2f Attractor::attract(Brush brush) {
	
	ofVec2f direction = position - brush.position;
	
	float distance = direction.length();
	
	distance = ofClamp(distance, 1, 30);
	
	float strength = (G * mass * brush.mass) / (distance * distance);
	
	direction.normalize();
	
	ofVec2f force = direction * strength;
	
	return force;
}

void Attractor::display(){
	ofSetColor(255, 0, 0);
	ofFill();
	
	float radius = sqrt(mass) * 2;
//	ofDrawLine(position.x - radius, position.y, position.x + radius, position.y);
//	ofDrawLine(position.x, position.y + radius, position.x, position.y - radius);
}
