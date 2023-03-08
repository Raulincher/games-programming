#include "AsteroidScript.h"

void AsteroidScript::startScript() {

}

void AsteroidScript::tickScript(float deltaTime) {

	int selector = 0;

	ComponentHandle<Transform> transform = entity->get<Transform>();
	ComponentHandle<CircleCollider> collider = entity->get<CircleCollider>();

	//cout << collider->radius << endl;
	//cout << entity->getEntityId()<< endl;

	transform->position += currDir * deltaTime / 2.f;

	//velocity = transform->position.x / clock() * 0.001;


	if (transform->position.x < 0 && currDir.x < 0)
		if (clock() * 0.001 < 20.0) {
			selector = rand() % 4;

			if (selector == 1) {
				currDir.y = -0.5;
			}
			else if (selector == 2) {
				currDir.y = 1;
			}
			else if (selector == 3) {
				currDir.y = 0.5;
			}
			else {
				currDir.y = -1;
			}
			currDir.x = 0.5;
		}
		else if ((clock() * 0.001 > 20.0) && (clock() * 0.001 < 40.0)) {
			selector = rand() % 4;

			if (selector == 1) {
				currDir.y = -1.25;
			}
			else if (selector == 2) {
				currDir.y = 0.75;
			}
			else if (selector == 3) {
				currDir.y = 1.25;
			}
			else {
				currDir.y = -0.75;
			}
			currDir.x = 0.75;
		}
		else if ((clock() * 0.001 < 60.0) && (clock() * 0.001 > 40.0)) {
			selector = rand() % 4;

			if (selector == 1) {
				currDir.y = -1;
			}
			else if (selector == 2) {
				currDir.y = 1.5;
			}
			else if (selector == 3) {
				currDir.y = 1;
			}
			else {
				currDir.y = -1.5;
			}
			currDir.x = 1;
		}
		else if ((clock() * 0.001 > 60.0) && (clock() * 0.001 < 120.0)) {
			selector = rand() % 4;

			if (selector == 1) {
				currDir.y = -1.75;
			}
			else if (selector == 2) {
				currDir.y = 1.5;
			}
			else if (selector == 3) {
				currDir.y = 1.75;
			}
			else {
				currDir.y = -1.5;
			}
			currDir.x = 1.5;
		}
		else {
			selector = rand() % 4;

			if (selector == 1) {
				currDir.y = -3;
			}
			else if (selector == 2) {
				currDir.y = 1;
			}
			else if (selector == 3) {
				currDir.y = 3;
			}
			else {
				currDir.y = -1;
			}
			currDir.x = 2;
		}
	if (transform->position.x > limits.x && currDir.x > 0)
		if (clock() * 0.001 < 20.0) {
			selector = rand() % 4;

			if (selector == 1) {
				currDir.y = -0.5;
			}
			else if (selector == 2) {
				currDir.y = 1;
			}
			else if (selector == 3) {
				currDir.y = 0.5;
			}
			else {
				currDir.y = -1;
			}
			currDir.x = -0.5;
		}
		else if ((clock() * 0.001 > 20.0) && (clock() * 0.001 < 40.0)) {
			selector = rand() % 4;

			if (selector == 1) {
				currDir.y = -1.25;
			}
			else if (selector == 2) {
				currDir.y = 0.75;
			}
			else if (selector == 3) {
				currDir.y = 1.25;
			}
			else {
				currDir.y = -0.75;
			}
			currDir.x = -0.75;
		}
		else if ((clock() * 0.001 < 60.0) && (clock() * 0.001 > 40.0)) {
			selector = rand() % 4;

			if (selector == 1) {
				currDir.y = -1;
			}
			else if (selector == 2) {
				currDir.y = 1.5;
			}
			else if (selector == 3) {
				currDir.y = 1;
			}
			else {
				currDir.y = -1.5;
			}
			currDir.x = -1;
		}
		else if ((clock() * 0.001 > 60.0) && (clock() * 0.001 < 120.0)) {
			selector = rand() % 4;

			if (selector == 1) {
				currDir.y = -1.75;
			}
			else if (selector == 2) {
				currDir.y = 1.5;
			}
			else if (selector == 3) {
				currDir.y = 1.75;
			}
			else {
				currDir.y = -1.5;
			}
			currDir.x = -1.5;
		}
		else {
			selector = rand() % 4;

			if (selector == 1) {
				currDir.y = -3;
			}
			else if (selector == 2) {
				currDir.y = 1;
			}
			else if (selector == 3) {
				currDir.y = 3;
			}
			else {
				currDir.y = -1;
			}
			currDir.x = -2;
		}
	if (transform->position.y < 0 && currDir.y < 0)
		if (clock() * 0.001 < 20.0) {
			currDir.y = 0.5;
			selector = rand() % 4;

			if (selector == 1) {
				currDir.x = -0.75;
			}
			else if (selector == 2) {
				currDir.x = 0.5;
			}
			else if (selector == 3) {
				currDir.x = 0.75;
			}
			else {
				currDir.x = -0.5;
			}

		}
		else if ((clock() * 0.001 > 20.0) && (clock() * 0.001 < 40.0)) {
			currDir.y = 0.75;
			selector = rand() % 4;

			if (selector == 1) {
				currDir.x = -1.25;
			}
			else if (selector == 2) {
				currDir.x = 0.75;
			}
			else if (selector == 3) {
				currDir.x = 1.25;
			}
			else {
				currDir.x = -0.75;
			}
		}
		else if ((clock() * 0.001 < 60.0) && (clock() * 0.001 > 40.0)) {
			currDir.y = 1;
			selector = rand() % 4;

			if (selector == 1) {
				currDir.x = -1.5;
			}
			else if (selector == 2) {
				currDir.x = 1;
			}
			else if (selector == 3) {
				currDir.x = 1.5;
			}
			else {
				currDir.x = -1;
			}
		}
		else if ((clock() * 0.001 > 60.0) && (clock() * 0.001 < 120.0)) {
			currDir.y = 1.5;
			selector = rand() % 4;

			if (selector == 1) {
				currDir.x = -1.5;
			}
			else if (selector == 2) {
				currDir.x = 1.5;
			}
			else if (selector == 3) {
				currDir.x = 1.75;
			}
			else {
				currDir.x = -1.75;
			}
		}
		else {
			currDir.y = 2;
			selector = rand() % 4;

			if (selector == 1) {
				currDir.x = -3;
			}
			else if (selector == 2) {
				currDir.x = 1;
			}
			else if (selector == 3) {
				currDir.x = 3;
			}
			else {
				currDir.x = -1;
			}
		}
	if (transform->position.y > limits.y && currDir.y > 0)
		if (clock() * 0.001 < 20.0) {
			currDir.y = -0.5;
			selector = rand() % 4;

			if (selector == 1) {
				currDir.x = -0.75;
			}
			else if (selector == 2) {
				currDir.x = 0.5;
			}
			else if (selector == 3) {
				currDir.x = 0.75;
			}
			else {
				currDir.x = -0.5;
			}

		}
		else if ((clock() * 0.001 > 20.0) && (clock() * 0.001 < 40.0)) {
			currDir.y = -0.75;
			selector = rand() % 4;

			if (selector == 1) {
				currDir.x = -1.25;
			}
			else if (selector == 2) {
				currDir.x = 0.75;
			}
			else if (selector == 3) {
				currDir.x = 1.25;
			}
			else {
				currDir.x = -0.75;
			}
		}
		else if ((clock() * 0.001 < 60.0) && (clock() * 0.001 > 40.0)) {
			currDir.y = -1;
			selector = rand() % 4;

			if (selector == 1) {
				currDir.x = -1.5;
			}
			else if (selector == 2) {
				currDir.x = 1;
			}
			else if (selector == 3) {
				currDir.x = 1.5;
			}
			else {
				currDir.x = -1;
			}
		}
		else if ((clock() * 0.001 > 60.0) && (clock() * 0.001 < 120.0)) {
			currDir.y = -1.5;
			selector = rand() % 4;

			if (selector == 1) {
				currDir.x = -1.5;
			}
			else if (selector == 2) {
				currDir.x = 1.5;
			}
			else if (selector == 3) {
				currDir.x = 1.75;
			}
			else {
				currDir.x = -1.75;
			}
		}
		else {
			currDir.y = -2;
			selector = rand() % 4;

			if (selector == 1) {
				currDir.x = -3;
			}
			else if (selector == 2) {
				currDir.x = 1;
			}
			else if (selector == 3) {
				currDir.x = 3;
			}
			else {
				currDir.x = -1;
			}
		}

}
