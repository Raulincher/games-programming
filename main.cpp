#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <math.h>
#include <ctime>
#include <chrono>
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <irrKlang/irrKlang.h>

#include "Shader.h"
#include "VBO.h"
#include "VAO.h"
#include "EBO.h"
#include "Texture.h"
#include "SpriteRenderer.h"
#include "RenderSystem.h"
#include "ScriptSystem.h"
#include "ScriptManager.h"
#include "AsteroidScript.h"
#include "SpaceshipScript.h"
#include "Script.h"

#include "ECS.h"

using std::cout; 
using std::endl;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;

using namespace chrono;
using namespace ECS;
using namespace irrklang;

GLFWwindow* window; // Game window
const unsigned int width = 800;
const unsigned int height = 800;

float t = 0;
time_t current_time;

World* world;

void SetupGLFW() {

	glfwInit();

	// Tell GLFW we are using OpenGL 3.3 and the CORE profile (only the modern functions)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

}

bool SetupWindow() {
	//Create a GLFWwindow with size 800x800
	window = glfwCreateWindow(800, 800, "ProgramacioVideojocs", NULL, NULL);
	if (window == NULL) {

		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}

	// Make window part of the current context
	glfwMakeContextCurrent(window);

	//Load GLAD and specify the viewport
	gladLoadGL();
	glViewport(0, 0, width, height);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return true;
}

Entity* CreateEntity(glm::vec2 position, float rotation, float scale, const char* filepath, glm::vec3 color, 
	bool autoSize = true, glm::vec2 size = glm::vec2(1.0, 1.0), const char* shaderName = "default") {
	Entity* ent = world->create();
	ent->assign<Transform>(position, rotation, scale);
	ent->assign<Sprite>(filepath, color, autoSize, size, shaderName);

	return ent;
}

void SetupWorld() {

	world = World::createWorld();
	world->registerSystem(new RenderSystem(width, height));
	ScriptSystem* scriptSystem = new ScriptSystem();
	world->registerSystem(scriptSystem);

	ScriptManager* scriptManager = scriptSystem->getScriptManager();

	Entity* bg_ent = CreateEntity(glm::vec2(400.f, 400.f), 0.f, 1.f, "Textures/star_background.png", glm::vec3(1., 1., 1.), false, glm::vec2(2000, 800));


	Entity* spaceship_ent = CreateEntity(glm::vec2(400.f, 200.f), 0.f, 1.f, "Textures/astronaut.png", glm::vec3(1., 1., 1.), false, glm::vec2(75, 75));
	spaceship_ent->assign<CircleCollider>(15.f);

	SpaceshipScript* spaceship_script = new SpaceshipScript(window, world, spaceship_ent);
	spaceship_ent->assign<ScriptComponent>(scriptManager->AddScript(spaceship_script));

	scriptManager->tickScript(0, 0);

	for (int i = 0; i < 3; i++) {
		Entity* asteroid_ent = CreateEntity(glm::vec2(206 *(1+i), 206 * (1 + i)), 0.f, 1.f, "Textures/a pedra.png", glm::vec3(1., 1., 1.), false, glm::vec2(40 * (i + 1), 40 * (i + 1)));
		asteroid_ent->assign<CircleCollider>(25 * (i + 1));

		AsteroidScript* asteroid_script = new AsteroidScript(window, world, asteroid_ent);
		asteroid_ent->assign<ScriptComponent>(scriptManager->AddScript(asteroid_script));
	}



}

void SetupWorld2() {

	world = World::createWorld();
	world->registerSystem(new RenderSystem(width, height));
	ScriptSystem* scriptSystem = new ScriptSystem();
	world->registerSystem(scriptSystem);

	ScriptManager* scriptManager = scriptSystem->getScriptManager();

	Entity* bg_ent = CreateEntity(glm::vec2(400.f, 400.f), 0.f, 1.f, "Textures/sans3.png", glm::vec3(1., 1., 1.), false, glm::vec2(1000, 800));


	Entity* spaceship_ent = CreateEntity(glm::vec2(400.f, 200.f), 0.f, 1.f, "Textures/heart.png", glm::vec3(1., 1., 1.), false, glm::vec2(35, 35));
	spaceship_ent->assign<CircleCollider>(5.f);

	SpaceshipScript* spaceship_script = new SpaceshipScript(window, world, spaceship_ent);
	spaceship_ent->assign<ScriptComponent>(scriptManager->AddScript(spaceship_script));

	scriptManager->tickScript(0, 0);

	for (int i = 0; i < 3; i++) {
		Entity* asteroid_ent = CreateEntity(glm::vec2(206 * (1 + i), 206 * (1 + i)), 0.f, 1.f, "Textures/gaster_blaster.png", glm::vec3(1., 1., 1.), false, glm::vec2(60 * (i + 1), 60 * (i + 1)));
		asteroid_ent->assign<CircleCollider>(25 * (i + 1));

		AsteroidScript* asteroid_script = new AsteroidScript(window, world, asteroid_ent);
		asteroid_ent->assign<ScriptComponent>(scriptManager->AddScript(asteroid_script));
	}

}


int main() {

		SetupGLFW();

		if (!SetupWindow()) {
			return -1;
		}

		SetupWorld();


		float dt = 0;
		float time = clock();


		ISoundEngine* engine1 = createIrrKlangDevice();
		engine1->play2D("../VideogameProgramming/audios/resurrect.mp3", true, false, true);
		engine1->setSoundVolume(0.5);
		//Program core loop
		while (!glfwWindowShouldClose(window)) {
			// Specify the color of the background
			glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
				SetupWorld();
				engine1->removeAllSoundSources();
				engine1->play2D("../VideogameProgramming/audios/resurrect.mp3", true, false, true);
				engine1->setSoundVolume(0.5);
			}
			if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS) {
				SetupWorld2();
				engine1->removeAllSoundSources();
				engine1->play2D("../VideogameProgramming/audios/mega.mp3", true, false, true);
				engine1->setSoundVolume(0.5);
			}
			if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {

				SetupWorld();
				engine1->removeAllSoundSources();
				engine1->play2D("../VideogameProgramming/audios/resurrect.mp3", true, false, true);
				engine1->setSoundVolume(0.5);
			}
			//std::cout << time;

			dt = clock() - time;
			time = clock();
			if (dt < 50) {
				world->tick(dt);
			}

			//std::cout << "tick" << std::endl;

			glfwSwapBuffers(window); //Swap buffers

			// Take care of GLFW events
			glfwPollEvents();
			

		}
		engine1->drop();
		glfwDestroyWindow(window);
		glfwTerminate();


		world->destroyWorld();

	return 0;

}