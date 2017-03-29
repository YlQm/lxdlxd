#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_
#include <string>

class Controller
{
	Model *mymodel;
	View *myview;
public:
	void draw();
	void end();
	void quit();
	void attack();
	void use();
	void inspect();
	void play();
	void help();
	void discard();
	void hand();
	void board();
	void describe();

	 Controller();
	~ Controller();
	
};