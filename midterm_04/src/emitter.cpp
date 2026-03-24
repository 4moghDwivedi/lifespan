//
//  emitter.cpp
//  midterm_04
//
//  Created by Amogh Dwivedi on 3/23/26.
//

#include "emitter.hpp"


Emitter::Emitter() {
	
}

void Emitter::setup(int numParticles) {
	brushes.clear();
	
//	printf("hi");
	
	for (int i = 0; i < numParticles; i++) {
		Brush b;
		float orbitRadius = ofRandom(0.1, 5);
		float startAngle = ofRandom(TWO_PI);
		b.setup(orbitRadius, startAngle);
		brushes.push_back(b);
		
	}
}

void Emitter::applyAttractor(Attractor& attractor){
	for (int i = 0; i < brushes.size(); i++) {
		ofVec2f force = attractor.attract(brushes[i]);
		brushes[i].applyForce(force);
	}
}

void Emitter::run(){
	for (int i = brushes.size() - 1; i>= 0; i--) {
		brushes[i].update();
		brushes[i].display();
		
		if(brushes[i].isDead()) {
			//printf("just respawned");
			brushes[i].respawn();
		}
	}
}

void Emitter::setColor(int mode){
	for (int i = 0; i < brushes.size(); i++){
		brushes[i].setColor(mode);
	}
}
