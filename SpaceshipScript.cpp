#include "SpaceshipScript.h"

void SpaceshipScript::startScript() {
}

void SpaceshipScript::tickScript(float deltaTime) {

	CheckCollisions();

	ComponentHandle<CircleCollider> collider = entity->get<CircleCollider>();

	if (collider->collidedWith) {
		hp--;
		collider->collidedWith = false;

		if (hp <= 0) {
			destroyed = true;
			world->destroy(entity);
		}
	}

	ComponentHandle<Transform> transform = entity->get<Transform>();
	
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		transform->position += glm::vec2(2, 0.) * deltaTime / 2.f;
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		transform->position += glm::vec2(-2, 0.) * deltaTime / 2.f;
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		transform->position += glm::vec2(0., 2) * deltaTime / 2.f;
	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		transform->position += glm::vec2(0., -2) * deltaTime / 2.f;
	}

	if (transform->position.x >= (800)) {
		transform->position.x = 1;
		
	}

	if (transform->position.x <= (0)) {
		transform->position.x = 799;
	}

	if (transform->position.y <= (0)) {
		transform->position.y = 799;
	}

	if (transform->position.y >= (800)) {
		transform->position.y = 1;
	}



}



void SpaceshipScript::CheckCollisions() {

	ComponentHandle<Transform> transform = entity->get<Transform>();
	ComponentHandle<CircleCollider> collider = entity->get<CircleCollider>();

	world->each<CircleCollider>([&](Entity* other_ent, ComponentHandle<CircleCollider> other_collider) {

		if (other_ent->getEntityId() == entity->getEntityId()) {
			//cout << other_collider->radius << endl;
			//cout << collider->radius << endl;
			cout << other_ent->getEntityId() << endl;
			//cout << entity->getEntityId() << endl;
			return;
		}

		ComponentHandle<Transform> other_transform = other_ent->get<Transform>();

		glm::vec2 p1 = transform->position;
		glm::vec2 p2 = other_transform->position;

		if (p1.x - collider->radius < p2.x + other_collider->radius &&
			p1.x + collider->radius > p2.x - other_collider->radius &&
			p1.y - collider->radius < p2.y + other_collider->radius &&
			p1.y + collider->radius > p2.y - other_collider->radius)
		{
			collider->collidedWith = 1;
		}

	});

}
