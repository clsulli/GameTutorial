#include <iostream>
#include "Engine/Engine.h"

using namespace std;

int main() {
	cout << "Hello, World!" << endl;
	
	Engine engine;
	engine.Initialize("Game Tutorial");
	
	while (true)
	{
		engine.Update();
		engine.Render();
	}


	return 0;
}