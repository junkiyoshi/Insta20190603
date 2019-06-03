#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	auto size = 144;
	auto len = size * 0.95;
	for (int x = size * 0.5; x < ofGetWidth(); x += size) {

		for (int y = size * 0.5; y < ofGetHeight(); y += size) {

			for (int i = 0; i < 4; i++) {

				int start_param = ofNoise(ofRandom(10000), ofGetFrameNum() * 0.005) * 100;
				int end_param = start_param + ofMap(ofNoise(ofRandom(10000), ofGetFrameNum() * 0.005), 0, 1, 20, 100);

				vector<glm::vec2> vertices, sub_vertices;
				for (int param = start_param; param <= end_param; param++) {

					vertices.push_back(this->make_point(len, param) + glm::vec2(x, y));
					sub_vertices.push_back((this->make_point(len * 0.2 * (i + 1), param) + glm::vec2(x, y)));
				}

				reverse(sub_vertices.begin(), sub_vertices.end());

				ofFill();
				ofSetColor(39);
				ofBeginShape();
				ofVertices(vertices);
				ofVertices(sub_vertices);
				ofEndShape(true);

				ofNoFill();
				ofSetColor(239);
				ofBeginShape();
				ofVertices(vertices);
				ofVertices(sub_vertices);
				ofEndShape(true);
			}
		}
	}
	
}

//--------------------------------------------------------------
glm::vec2 ofApp::make_point(int len, int param) {

	param = param % 100;
	if (param < 25) {

		return glm::vec2(ofMap(param, 0, 25, -len * 0.5, len * 0.5), -len * 0.5);
	}
	else if (param < 50) {

		return glm::vec2(len * 0.5, ofMap(param, 25, 50, -len * 0.5, len * 0.5));
	}
	else if (param < 75) {

		return glm::vec2(ofMap(param, 50, 75, len * 0.5, -len * 0.5), len * 0.5);
	}
	else {

		return glm::vec2(-len * 0.5, ofMap(param, 75, 100, len * 0.5, -len * 0.5));
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}