#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    font.loadFont(OF_TTF_SANS, 15);
    
    ss.setup("ofxStringShuffler is an tiny addon for yugop style text effect in openFrameworks.");
    ss.play(0, 1000, 1000);
}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);
    font.drawString(ss.get(), 10, ofGetHeight() * 0.5);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    ss.play(5, 1000);
}