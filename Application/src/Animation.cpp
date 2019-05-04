#include <Animation.hpp>
#include <ctime>
#include <iostream>
#include <math.h>

#define PI 3.1415926535

Animation::Animation()
{
    _snowflakes = std::vector<Snowflake*>();
}

Animation::~Animation()
{
    _snowflakes.clear();
}

void Animation::AddSnowflake(Snowflake* snowflake)
{
    _snowflakes.push_back(snowflake);
}

void Animation::Animate1(float deltaTime)
{	
	for (int i=0; i < _snowflakes.size(); i++) {
		//about setPostion
		Snowflake current = *_snowflakes[i];

		//move down
		glm::vec4 curPos = glm::vec4(current.GetPosition(), 1.0f);
		glm::vec3 dropSpeed = current.GetDropSpeed() ;
		dropSpeed.y = dropSpeed.y * deltaTime;
		glm::vec4 resPos = curPos + glm::vec4(dropSpeed, 1.0f);
		
		//move left-right
		float initX = current.GetInitX();
		float amplitude = current.GetAmplitude();
		float initOri = current.GetInitOri();
		float rotTime = current.GetRotTime();
		rotTime += deltaTime;
		current.SetRotTime(rotTime);
		resPos.x = initX + amplitude * sin(PI*1/2*rotTime+ initOri);
		current.SetPosition(glm::vec3(resPos));
		
		//about rotation
		glm::mat4 curRot = current.GetOrientation();
		float rotSpeed = current.GetRotSpeed();
		glm::mat4 rotSpeedMat = glm::rotate(glm::mat4(1.0f), rotSpeed * deltaTime, glm::vec3(0, 0, 1));
		glm::mat4 resRot = rotSpeedMat * curRot;
		current.SetOrientation(resRot);

		*_snowflakes[i] = current;

	}
}