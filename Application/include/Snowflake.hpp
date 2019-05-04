#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include <RenderObject.hpp>
#include <Mesh.hpp>
#include <Material.hpp>

/*
 * TODO: Inherit RenderObject class to implement animation
 */
class Snowflake: public Engine::RenderObject
{
private:
	float _initX;
	float _amplitude;
	float _initOri;
	float _rotSpeed;
	float _rotTime;
	glm::vec3 _dropSpeed;
	
	glm::vec3 SetInitPos();
	float SetInitOri();
	glm::vec3 SetInitDrop();
	glm::vec3 SetInitScale();
public:
    Snowflake(Engine::Mesh* mesh, Engine::Material* material);

	float GetInitX() { return _initX; }
	float GetAmplitude() { return _amplitude; }
	float GetInitOri() { return _initOri; }
	
	float GetRotTime() { return _rotTime; }
	void SetRotTime(float rotTime) { _rotTime = rotTime;}
	float GetRotSpeed() { return _rotSpeed; }
	void SetRotSpeed(float rotSpeed) { _rotSpeed = rotSpeed;}
	void SetDropSpeed(glm::vec3 dropSpeed) { _dropSpeed = dropSpeed; }
	glm::vec3 GetDropSpeed() { return _dropSpeed; }
	
	glm::vec3 GetPosition() { return RenderObject::GetPosition(); }
	glm::mat4 GetOrientation() { return RenderObject::GetOrientation(); }
	void SetPosition(glm::vec3 position) { RenderObject::SetPosition(position); }
	void SetOrientation(glm::mat4 Orientation) { RenderObject::SetOrientation(Orientation); }
	// Add more functions
};