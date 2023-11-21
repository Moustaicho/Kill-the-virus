#pragma once
#include "raylib.h"
#include <map>
#include <string>
class ModelHolder
{
private:
	static ModelHolder* instance;

	std::map<std::string, Model*> models;
	std::map<std::string, Mesh*> meshes;
private:
	ModelHolder();
public:
	ModelHolder(ModelHolder& other) = delete;
	void operator=(const ModelHolder&) = delete;

	static ModelHolder* GetInstance();

	//Get model
	void AddModel(std::string name, Model* model);
	Model* GetModel(std::string name);
	//GetMesh
	void AddMesh(std::string name, Mesh* mesh);
	Mesh* GetMesh(std::string name);
};

