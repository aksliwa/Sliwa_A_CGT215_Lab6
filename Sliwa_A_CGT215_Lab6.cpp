// Sliwa_A_CGT215_Lab6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
int main() {
	string background = "image/backgrounds/winter.png";
	string foreground = "image/characters/yoda.png";
	Texture backgroundTex;
	if (!backgroundTex.loadFromFile(background)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Texture foregroundTex;
	if (!foregroundTex.loadFromFile(foreground)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Image backgroundImage;
	backgroundImage = backgroundTex.copyToImage();
	Image foregroundImage;
	foregroundImage = foregroundTex.copyToImage();
	Vector2u sz = backgroundImage.getSize();
	for (int y = 0; y < sz.y; y++) {
		for (int x = 0; x < sz.x; x++) {

			Color o = foregroundImage.getPixel(1023, 767); //getting bottom right most pixel
			Color c = foregroundImage.getPixel(x, y); //each pixel location
			Color gone(0, 0, 0, 0); //transparent
			if (c == o) { //setting it up  to go through the pixels to change
				foregroundImage.setPixel(x, y, gone); //makes pixel transparent
			}
			
		}
	}
	// By default, just show the foreground image
	RenderWindow window(VideoMode(1024, 768), "Here's the output");
	Sprite sprite1;
	Sprite sprite2;
	Texture tex1;
	Texture text2;
	text2.loadFromImage(backgroundImage);
	sprite2.setTexture(text2);
	tex1.loadFromImage(foregroundImage);
	sprite1.setTexture(tex1);
	window.clear();
	window.draw(sprite2);
	window.draw(sprite1);
	window.display();
	while (true);
}