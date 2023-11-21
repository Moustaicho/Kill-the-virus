#include "ModelHolder.h"

ModelHolder* ModelHolder::instance = NULL;
ModelHolder::ModelHolder()
{
}

ModelHolder* ModelHolder::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new ModelHolder();
	}
	return instance;
}

void ModelHolder::AddModel(std::string name, Model* model)
{
	models.insert(std::pair<std::string, Model*>(name, model));
}

Model* ModelHolder::GetModel(std::string name)
{
	return models.find(name)->second;
}

void ModelHolder::AddMesh(std::string name, Mesh* mesh)
{
	meshes.insert(std::pair<std::string, Mesh*>(name, mesh));
}

Mesh* ModelHolder::GetMesh(std::string name)
{
	return meshes.find(name)->second;
}
