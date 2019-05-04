#include <Fractal.hpp>
#include <cmath>
/*
 * Implement Fractal class to generate Koch snowflakes mesh (generate snowflake mesh using triangle list).
 * Koch snowflake: https://en.wikipedia.org/wiki/Koch_snowflake
 */

Fractal::Fractal()
{

}

Fractal::~Fractal()
{

}

/*
 * TODO: Implement koch snowflake mesh generator
 */
void Fractal::GenerateSnowflake(Engine::Mesh* mesh)
{
	mesh->AddAttribute(4);

	float sz = 0.5f;
	glm::vec4 szvec4 = glm::vec4(sz, sz, 1.0f, 1.0f);

	glm::vec4 position_data[] = {
		glm::vec4(1.0f, -1.0f / 3.0f*sqrt(3), 0.01f, 1.0f),
		glm::vec4(0.0f, 2.0f / 3.0f*sqrt(3), 0.01f, 1.0f),
		glm::vec4(-1.0f, -1.0f / 3.0f*sqrt(3), 0.01f, 1.0f)
	};

	for (int i = 0; i < 3; i++) {
		position_data[i] *= szvec4;
	}

	int iter = 4;
	
	mesh->AddVertexData(position_data[0]);
	mesh->AddVertexData(position_data[1]);
	mesh->AddVertexData(position_data[2]);
	MakeVertex(mesh, position_data[0], position_data[1], position_data[2], iter);
	MakeVertex(mesh, position_data[1], position_data[2], position_data[0], iter);
	MakeVertex(mesh, position_data[2], position_data[0], position_data[1], iter);

	int num = 3;
	for (int i = 0; i < iter; i++) {
		num *= 4;
	}
	mesh->SetNumElements(num);
	mesh->CreateMesh();
	mesh->SetDrawMode(GL_TRIANGLES);
	
	return;
}

void Fractal::MakeVertex(Engine::Mesh* mesh, glm::vec4 pos1, glm::vec4 pos2, glm::vec4 pos3, int iter){
	int i = 0;
	
	if (iter > 0)
	{
		//pos112, pos122 => for pos1, pos2
		//pos113, pos223 => for pos1 and pos3 / for pos2 and pos3
		glm::vec4 div3 = glm::vec4(1.0f / 3.0f, 1.0f / 3.0f, 1.0f / 3.0f, 1.0f / 3.0f);
		glm::vec4 pos112 = (pos1 + pos1 + pos2)*div3;
		glm::vec4 pos122 = (pos1 + pos2 + pos2)*div3;
		glm::vec4 pos113 = (pos1 + pos1 + pos3)*div3;
		glm::vec4 pos223 = (pos2 + pos2 + pos3)*div3;
		glm::vec4 sharp = (pos1 + pos1 + pos2 + pos2 - pos3)*div3;

		mesh->AddVertexData(pos112);
		mesh->AddVertexData(sharp);
		mesh->AddVertexData(pos122);

		MakeVertex(mesh, pos1, pos112, pos113, iter-1);
		MakeVertex(mesh, pos112, sharp, pos122, iter-1);
		MakeVertex(mesh, sharp, pos122, pos112, iter-1);
		MakeVertex(mesh, pos122, pos2, pos223, iter-1);
	}
}