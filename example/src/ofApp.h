#pragma once

#include "ofMain.h"
#include "ofxStringShuffler.h"

class ofApp : public ofBaseApp
{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
		
    ofxStringShuffler ss;
    ofTrueTypeFont font;
};
