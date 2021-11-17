#include <iostream>
#include <stdio.h>
#include "Vec3.h"
#include "Ray.h"
#include "Camera.h"


int main()
{		
	//Create a camera in our scene
	Camera cam = Camera();

	//Render the scene with our camera
	cam.Render();

}

