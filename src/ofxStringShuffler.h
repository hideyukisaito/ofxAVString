#pragma once

#include "ofEvents.h"

class ofxStringShuffler
{
public:
    ofxStringShuffler():
    mTargetStr(""),
    mCurrentStr(""),
    mStrIndex(0),
    mRange(0),
    mLastStoppedTimeMillis(0)
    {}
    
    ofxStringShuffler(const ofxStringShuffler &mom)
    {
        assign(mom);
    }
    
    ofxStringShuffler & operator=(const ofxStringShuffler &mom)
    {
        assign(mom);
    }
    
    void assign(const ofxStringShuffler &mom)
    {
        mTargetStr = mom.mTargetStr;
        mCurrentStr = mom.mCurrentStr;
        mStrIndex = mom.mStrIndex;
        mRange = mom.mRange;
        mIntervalMillis = mom.mIntervalMillis;
        mLastStoppedTimeMillis = mom.mLastStoppedTimeMillis;
    }
    
    ~ofxStringShuffler()
    {
        mTargetStr.clear();
        mCurrentStr.clear();
    }
    
    void setup(const string target)
    {
        mTargetStr = target;
        mCurrentStr.resize(mTargetStr.length(), ' ');
    }
    
    void update(ofEventArgs &e)
    {
        for (size_t i = mStrIndex; i < min(mStrIndex + mRange, mCurrentStr.length()); ++i) {
            mCurrentStr[i] = static_cast<char>(floor(ofRandom(33, 127)));
        }
        
        if (mIntervalMillis < ofGetElapsedTimeMillis() - mLastStoppedTimeMillis) {
            mCurrentStr[mStrIndex] = mTargetStr[mStrIndex];
            mLastStoppedTimeMillis = ofGetElapsedTimeMillis();
            
            if (++mStrIndex > mTargetStr.length()) {
                ofRemoveListener(ofEvents().update, this, &ofxStringShuffler::update);
                mRange = 0;
            }
        }
    }
    
    void play(const size_t range = 0, const double durationMillis = 1000, const double delayMillis = 0)
    {
        mRange = 0 == range ? mTargetStr.length() : range;
        mIntervalMillis = durationMillis / mTargetStr.length();ofLog() << mIntervalMillis;
        mLastStoppedTimeMillis = ofGetElapsedTimeMillis() + delayMillis;
        mCurrentStr.clear();
        mCurrentStr.resize(mTargetStr.length(), ' ');
        mStrIndex = 0;
        
        ofAddListener(ofEvents().update, this, &ofxStringShuffler::update);
    }
    
    const string & get()
    {
        return mCurrentStr;
    }
    
private:
    string mTargetStr, mCurrentStr;
    size_t mStrIndex, mRange;
    double mIntervalMillis, mLastStoppedTimeMillis;
};