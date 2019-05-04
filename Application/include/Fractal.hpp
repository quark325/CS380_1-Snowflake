#pragma once

#include <vector>

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Mesh.hpp>

/*
 * Implement Fractal class to generate Koch snowflakes mesh (generate snowflake mesh using triangle list).
 * Koch snowflake: https://en.wikipedia.org/wiki/Koch_snowflake
 */
class Fractal
{
private:
	void MakeVertex(Engine::Mesh* mesh, glm::vec4 pos1, glm::vec4 pos2, glm::vec4 pos3, int iter);
public:
    Fractal();
    ~Fractal();
    void GenerateSnowflake(Engine::Mesh* mesh);
};