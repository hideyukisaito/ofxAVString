#pragma once

#include "ofMain.h"
#include "ofxAVString.h"

class ofApp : public ofBaseApp
{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
		
    ofxAVString avs;
    ofTrueTypeFont font;
};
