#include "Scene.h"
#include <iostream>

Scene::Scene() { }

void Scene::draw() {
	std::cout << "Draw";
}

void Scene::update() {
	std::cout << "Update";
}