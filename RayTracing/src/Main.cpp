#include "Camera.h"
#include "World.h"
#include "Sphere.h"

  
int main()
{		
	//Create our world
	World world;

	Sphere* sphere = new Sphere(Vec3(0.0f, 0.0f, -1.0f), 0.5f);
	Sphere* terrain = new Sphere(Vec3(0.0f, -100.5f, -1.0f), 100.0f);
	world.ObjectList.push_back(terrain);
	world.ObjectList.push_back(sphere);

	//Create a camera in our scene
	Camera cam = Camera();

	//Render the scene with our camera
	cam.Render(world);

}

