#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "brush.hpp"
#include "attractor.hpp"
#include "emitter.hpp"

class ofApp : public ofBaseApp{

public:
	   void setup() override;
	   void update() override;
	   void draw() override;
	   void exit() override;
	

   int numParticles = 14;
	
	
	
	Emitter emitter;
	Attractor attractor;
//   std::vector<Brush> brushes;
	
	int bAlpha;
	int frameCount;
	bool pauseScene;
   
   ofxPanel gui;
   ofxFloatSlider gui_bgAlpha;
   ofxFloatSlider gui_brushMass;
   ofxFloatSlider gui_attractorMass;
	   
//   Attractor attractor;
};
