# ofxAVString
A utility class for the yugop style text effect in openFrameworks.

## Usage

```cpp
ofTrueTypeFont font;
ofxAVString avs1("openFrameworks");

void ofApp::setup()
{
  font.loadFont("Arial Bold", 16);
  
  
  ofxAVString avs2 = " is awesome";
  avs1 += avs2;
  
  // range, total duration, delay
  avs1.play(0, 1000, 1000);
}

void ofApp::draw()
{
  font.drawString(avs, 10, ofGetHeight() * 0.5);
}
```
