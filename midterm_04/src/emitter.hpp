//
//  emitter.hpp
//  midterm_04
//
//  Created by Amogh Dwivedi on 3/23/26.
//

#ifndef emitter_hpp
#define emitter_hpp

#include <stdio.h>
#include "ofMain.h"
#include "brush.hpp"
#include "attractor.hpp"

class Emitter {
public:
	Emitter();
	
	void setup(int numParticles);
	void applyAttractor(Attractor& attractor);
	void run();
	void setColor(int mode);
	
	vector<Brush> brushes;
};

#endif /* emitter_hpp */
