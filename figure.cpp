#include "figure.h"

void figure::move(float x, float y) {this->x = x; this->y = y;}
void figure::set_colour(int colour) {this->colour = colour;}
bool figure::cmp(primitive *other) {return false;}

circle::circle(float radius, float x, float y) {this->radius = radius; this->x = x; this->y = y;}
void circle::resize(float radius) {this->radius = radius;}
void circle::draw() {
	std::cout << "Circle:" << std::endl;
	std::cout << "  coordinates " << x << ":" << y << std::endl; 
	std::cout << "  radius " << radius << std::endl;
	std::cout << "  colour " << colour << std::endl;
}