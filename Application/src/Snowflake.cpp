#include <Snowflake.hpp>
#include <cstdlib>
#include <ctime>
#define _USE_MATH_DEFINES
#include <math.h>

#define PI 3.1415926535

/*
 * TODO: Inherit RenderObject class to implement animation
 */
Snowflake::Snowflake(Engine::Mesh* mesh, Engine::Material* material) : Engine::RenderObject(mesh, material)
{
	glm::vec3 initPos = Snowflake::SetInitPos();
	float initOri = Snowflake::SetInitOri();
	glm::vec3 initScale = Snowflake::SetInitScale();
	glm::mat4 identity = glm::mat4(1.0f);
	glm::mat4 initOriMat = glm::rotate(identity, initOri, glm::vec3(0, 0, 1));
	RenderObject::SetPosition(initPos);
	RenderObject::SetOrientation(initOriMat);
	RenderObject::SetScale(initScale);

	_rotSpeed = Snowflake::SetInitOri();
	_dropSpeed = Snowflake::SetInitDrop();
	_initX = initPos.x;
	_initOri = initOri;
	_rotTime = 0.0f;

	float amplitude = static_cast <float> (rand()) / static_cast <float> (RAND_MAX) / 2.0f;
	amplitude += 1.0f;
	_amplitude = amplitude;
}

glm::vec3 Snowflake::SetInitPos()
{	
	//set Snowflake genration point
	float posX = static_cast <float> (rand()) / static_cast <float> (RAND_MAX)-0.5;
	float posY = 5.0f;
	posX *= 10;
	
	return glm::vec3(posX, posY, 0.05f);
}

float Snowflake::SetInitOri()
{	
	float radian = static_cast <float> (rand()) / static_cast <float> (RAND_MAX) * PI * 2.0f / 3.0f;
	return radian;
	//set Snowflake initial angle
	/*
	float radian = static_cast <float> (rand()) / static_cast <float> (RAND_MAX)/500.0f;
	glm::mat4 identity = glm::mat4(1.0f);
	glm::mat4 rotate = glm::rotate(identity, radian, glm::vec3(0,0,1));
	return rotate;
	*/
}

glm::vec3 Snowflake::SetInitDrop()
{
	//set Snowflake initial drop spped
	/*
	float posY = static_cast <float> (rand()) / static_cast <float> (RAND_MAX) / 4000.0f;
	posY += 0.00025f;
	glm::mat4 result = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -posY, 0.0f));

	return result;
	*/
	float posY = static_cast <float> (rand()) / static_cast <float> (RAND_MAX)/2.0f;
	posY += 1.0f;
	return glm::vec3(0.0f, -posY, 0.0f);
}

glm::vec3 Snowflake::SetInitScale()
{
	float size = static_cast <float> (rand()) / static_cast <float> (RAND_MAX) / 4.0f;
	size += 0.2f;
	return glm::vec3(size, size, size);
}