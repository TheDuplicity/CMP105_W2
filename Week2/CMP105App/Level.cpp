#include "Level.h"
#include "cmath"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	bool key;

	textFont.loadFromFile("font/arial.ttf");

	// initialise game objects
	outPutText.setCharacterSize(50);
	outPutText.setFillColor(sf::Color::Red);
	outPutText.setOrigin(0,0);
	outPutText.setString("hello");
	outPutText.setFont(textFont);

	circle.setRadius(50);
	circle.setFillColor(sf::Color::Red);

}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	if (input->isKeyDown(sf::Keyboard::J)) {
		if (input->isKeyDown(sf::Keyboard::K)) {
			if (input->isKeyDown(sf::Keyboard::L)) {
				//outPutText.setString("Success!");
			}
		}
	}
	if (input->isKeyDown(sf::Keyboard::Escape)) {
		window->close();
	}

	//outPutText.setString("X coord: " + std::to_string(input->getMouseX()) + ", Y coord: " + std::to_string(input->getMouseY()));

	if (input->isMouseLDown()) {
		if (!lmousePressedAlready) {
			mouseOriginPosX = input->getMouseX();
			mouseOriginPosY = input->getMouseY();
			lmousePressedAlready = true;
		}
	}
	else if(lmousePressedAlready) {
		lmousePressedAlready = false;
		outPutText.setString(std::to_string(sqrt((pow((mouseOriginPosX - input->getMouseX()), 2) + pow((mouseOriginPosY - input->getMouseY()), 2)))));
	}
	
	if (input->isMouseRDown()) {
		if (!rmousePressedAlready) {
			circle.setPosition(input->getMouseX() - 25,input->getMouseY() - 25);
			rmousePressedAlready = true;
		}
	}
	else if (rmousePressedAlready) {
		rmousePressedAlready = false;
	}

}

// Update game objects
void Level::update()
{

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(outPutText);
	window->draw(circle);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}