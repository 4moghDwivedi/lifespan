//
//  attractor.hpp
//  midterm_04
//
//  Created by Amogh Dwivedi on 3/23/26.
//

#ifndef attractor_hpp
#define attractor_hpp

#include <stdio.h>

#include "ofMain.h"
#include "brush.hpp"


class Attractor {
public:
	Attractor();
	
	void setup (float x, float y, float m);
	void setPos(float x, float y);
	
	ofVec2f attract (Brush brush);
	
	void display();
	
	ofVec2f position;
	float mass;
	float G;
	
};


#endif /* attractor_hpp */
