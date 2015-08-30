#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    font.loadFont(OF_TTF_SANS, 15);
    
    avs.setup("ofxStringShuffler is an tiny addon for yugop style text effect in openFrameworks.");
    avs.play(0, 1000, 1000);
}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);
    font.drawString(avs, 10, ofGetHeight() * 0.5);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    avs.play(5, 1000);
}