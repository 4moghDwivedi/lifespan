#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	bAlpha = 255;
	frameCount = 0;
	
	ofBackground(0);
	ofSetBackgroundAuto(false);
	ofSetFrameRate(20);
	ofHideCursor();
	
	gui.setup();
	
	emitter.setup(numParticles);
	emitter.setColor(1);
	attractor.setup(ofGetMouseX(), ofGetMouseY(), 100);
}

//--------------------------------------------------------------
void ofApp::update(){

	attractor.mass = gui_attractorMass;
	attractor.setPos(ofGetMouseX(), ofGetMouseY());
	emitter.applyAttractor(attractor);
	
	// checking whether to pause scene or not
	if (bAlpha <= 0){
		pauseScene = true;
		printf("pauseScene: %d\n", pauseScene);
	}
	else {
		pauseScene = false;
		printf("pauseScene: %d\n", pauseScene);
	}
	
	//performing pause sequences
	if (pauseScene){
		frameCount++;
		printf("seconds in duration: %d\n", frameCount);
		emitter.setColor(1); // 0 is normal colors. 1 is grayscale mode.
		bAlpha = -5;
		
		if (frameCount >= 60){
			pauseScene = false;
			bAlpha = 255;
		}
	}
	else{
		emitter.setColor(0);
		frameCount = 0;
		bAlpha -= 1;
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofSetColor(255, bAlpha);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	
	ofPushMatrix();
	
	ofTranslate(ofGetMouseX(), ofGetMouseY());
	emitter.run();
	
	ofPopMatrix();
	
	attractor.display();

}


//--------------------------------------------------------------
void ofApp::exit(){

}
