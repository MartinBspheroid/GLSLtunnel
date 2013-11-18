#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	//ofEnableNormalizedTexCoords();
	texture.loadImage("mini.jpg"); // 512x512px
	
	tunnel.load("tunnel.vert", "tunnel.frag");
	
	projection.setResolution(2,2);
	
	
	//projection.mapTexCoords(0.0, 0.0, 1.0, 1.0);
	
	ofSetTextureWrap(GL_CLAMP, GL_REPEAT);	
}

//--------------------------------------------------------------
void testApp::update(){
	ofSetWindowTitle("X: " + ofToString((float)ofGetMouseX()/640)+ " -> " + ofToString((float)ofGetMouseX()/640* 100) + 
		" ---- Y: " + ofToString((float)ofGetMouseY()/480) + " -> " + ofToString((float)ofGetMouseY()/480* 110));
	projection.set(ofGetWidth(), ofGetHeight());
	projection.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(255);

	if (ofGetKeyPressed('g'))
	{
	
		ofBackground(0, 0, 0);
		texture.bind();
		projection.draw();
		texture.unbind();
		//texture.getTextureReference().unbind();
	}else
	{
		projection.mapTexCoordsFromTexture(texture.getTextureReference());	
		texC= projection.getTexCoords();
		ofBackground(0, 0, 0);
		//texture.getTextureReference().bind();
		tunnel.begin();
		tunnel.setUniform1f("timeE", time/1000);
		tunnel.setUniform2f("resolution", texture.getWidth() ,texture.getHeight());
		tunnel.setUniform2f("mouse", (float)ofGetMouseX()/640, (float)ofGetMouseY()/480);
		tunnel.setUniform2f("t", 0, 512); 
		tunnel.setUniformTexture("tex", texture.getTextureReference(), 0);
		projection.draw();
		
	//	projection.drawWireframe();
		
		tunnel.end();


	}
	
	time = ofGetElapsedTimeMillis();

	ofDrawBitmapStringHighlight(ofToString(texC.x), 10, 20);
	ofDrawBitmapStringHighlight(ofToString(texC.y), 10, 40);
	ofDrawBitmapStringHighlight(ofToString(texC.z), 10, 60);
	ofDrawBitmapStringHighlight(ofToString(texC.w), 10, 80);

}


//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	if(key == ' '){
		tunnel.unload();
		tunnel.load("tunnel.vert", "tunnel.frag");
		time = 0;
	}
	switch (key)
	{
	case 'q':
		texture.loadImage("mini.jpg");
		break;
	case 'w':
		texture.loadImage("Koala.jpg");
		break;
	case 'e':
		texture.loadImage("texture.jpg");
		break;
	case 'r':
		texture.loadImage("noise.bmp");
		break;
	default:
		break;
	}
		


}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
