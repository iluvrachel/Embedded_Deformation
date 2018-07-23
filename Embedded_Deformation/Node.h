#pragma once
#include "glm/vec3.hpp"
#include "glm/mat3x3.hpp"

class Node {
public:
	Node() {};
	glm::vec3 getPosition() {
		return this->position;
	}

private:
	glm::vec3 position;
	glm::mat3 rotation;
	glm::vec3 translation;

};