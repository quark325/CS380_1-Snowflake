// STL
#include <iostream>

// include opengl extension and application library
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

// include Engine
#include <Camera.hpp>
#include <Mesh.hpp>
#include <Material.hpp>
#include <RenderObject.hpp>

// include application headers
#include <Fractal.hpp>
#include <DefaultMaterial.hpp>
#include <PerVertexColorMaterial.hpp>
#include <Snowflake.hpp>
#include <Animation.hpp>
#include <math.h>

#define PI 3.1415926535

// TODO: Implement gradient rectangle mesh generator for background
void GenerateGradientRectangle(Engine::Mesh* mesh)
{
	mesh->AddAttribute(4); //Location
	mesh->AddAttribute(4); //Color

	glm::vec3 postion_data[] = {
		glm::vec3(-12.0f, -9.0f, -5.0f),
		glm::vec3(12.0f, -9.0f, -5.0f),
		glm::vec3(12.0f, 9.0f, -5.0f),
		glm::vec3(-12.0f, 9.0f, -5.0f)
	};

	glm::vec4 position_color[] = {
		glm::vec4(10.570f / 255.0f, 16.767f / 255.0f, 33.968f / 255.0f, 1.0f),
		glm::vec4(10.570f / 255.0f, 16.767f / 255.0f, 33.968f / 255.0f, 1.0f),
		glm::vec4(0.842f / 255.0f, 2.135f / 255.0f, 4.538f / 255.0f, 1.0f),
		glm::vec4(0.842f / 255.0f, 2.135f / 255.0f, 4.538f / 255.0f, 1.0f)

		/*
		glm::vec4(12.0f / 255.0f, 29.0f / 255.0f, 39.5f / 255.0f, 1.0f),
		glm::vec4(12.0f / 255.0f, 29.0f / 255.0f, 39.5f / 255.0f, 1.0f),
		glm::vec4(61.0f / 255.0f, 103.0f / 255.0f, 228.0f / 255.0f, 1.0f),
		glm::vec4(61.0f / 255.0f, 103.0f / 255.0f, 228.0f / 255.0f, 1.0f)
		*/
	};

	for (int i = 0; i < 4; i++) {
		mesh->AddVertexData(postion_data[i]);
		mesh->AddVertexData(1.0f);//transparent value
		mesh->AddVertexData(position_color[i]);
	}
	
	mesh->SetNumElements(4);
	mesh->CreateMesh();
	//layout 0: vec4 pos := (x,y,z,w)
	//layout 1: vec4 color := (r,g,b,a)

    return;
}

// TODO: Implement custom type mesh generator for background object
// House object
void GenerateBackgroundMeshType1(Engine::Mesh* mesh)
{	
	mesh->AddAttribute(4); //Location
	mesh->AddAttribute(4);

	glm::vec3 postion_data[] = {
		//color brown
		glm::vec3(-0.5f, -3.5f, 0.01f),
		glm::vec3(1.5f, -3.2f, 0.01f),
		glm::vec3(1.5f, -2.2f, 0.01f),
		//color brown
		glm::vec3(-0.5f, -2.5f, 0.01f),
		glm::vec3(-0.5f, -3.5f, 0.01f),
		glm::vec3(1.5f, -2.2f, 0.01f),
		//color brown
		glm::vec3(-0.5f, -2.5f, 0.01f),
		glm::vec3(1.5f, -2.2f, 0.01f),
		glm::vec3(0.5f, -1.8f, 0.01f),
		//color dark brown
		glm::vec3(-1.5f, -2.2f, 0.01f),
		glm::vec3(-1.5f, -3.0f, 0.01f),
		glm::vec3(-0.5f, -3.5f, 0.01f),
		//color dark brown
		glm::vec3(-1.5f, -2.2f, 0.01f),
		glm::vec3(-0.5f, -3.5f, 0.01f),
		glm::vec3(-0.5f, -2.5f, 0.01f),
		//color white
		glm::vec3(-0.5f, -2.5f, 0.01f),
		glm::vec3(0.5f, -1.8f, 0.01f),
		glm::vec3(-1.8f, -2.11f, 0.01f),
		//color white
		glm::vec3(-1.8f, -2.11f, 0.01f),
		glm::vec3(0.5f, -1.8f, 0.01f),
		glm::vec3(-1.1f, -1.5f, 0.01f),
		//color white
		glm::vec3(-1.1f, -1.5f, 0.01f),
		glm::vec3(0.5f, -1.8f, 0.01f),
		glm::vec3(0.5f, -1.5f, 0.01f),
		//color white
		glm::vec3(0.5f, -1.5f, 0.01f),
		glm::vec3(0.5f, -1.8f, 0.01f),
		glm::vec3(1.7f, -2.0f, 0.01f),
		//color white
		glm::vec3(1.7f, -2.0f, 0.01f),
		glm::vec3(0.5f, -1.8f, 0.01f),
		glm::vec3(1.5f, -2.2f, 0.01f),
		//color black
		glm::vec3(-0.2f, -1.8f, 0.02f),
		glm::vec3(0.0f, -1.8f, 0.02f),
		glm::vec3(0.0f, -0.8f, 0.02f),
		//color black
		glm::vec3(-0.2f, -0.8f, 0.02f),
		glm::vec3(-0.2f, -1.8f, 0.02f),
		glm::vec3(0.0f, -0.8f, 0.02f),
		//color black
		glm::vec3(-0.2f, -1.8f, 0.02f),
		glm::vec3(-0.1f, -1.85f, 0.02f),
		glm::vec3(0.0f, -1.8f, 0.02f),
		//color yellow
		glm::vec3(0.4f, -2.4f, 0.02f),
		glm::vec3(0.4f, -2.8f, 0.02f),
		glm::vec3(0.65f, -2.76f, 0.02f),
		//color yellow
		glm::vec3(0.4f, -2.4f, 0.02f),
		glm::vec3(0.65f, -2.76f, 0.02f),
		glm::vec3(0.65f, -2.36f, 0.02f),
	};

	for (int i = 0; i < 45; i++) {
		mesh->AddVertexData(postion_data[i].x-2.5f);
		mesh->AddVertexData(postion_data[i].y);
		mesh->AddVertexData(postion_data[i].z);
		mesh->AddVertexData(1.0f);//transparent value
		if (i < 9) {//brown
			mesh->AddVertexData(glm::vec4(178.798f / 255.0f, 62.934f / 255.0f, 19.361f / 255.0f, 1.0f));
		}
		else if (i < 15) {
			mesh->AddVertexData(glm::vec4(17.270f / 255.0f, 9.442f / 255.0f, 5.079f / 255.0f, 1.0f));
		}
		else if (i < 30){
			mesh->AddVertexData(glm::vec4(151.072f / 255.0f, 152.730f / 255.0f, 157.765f / 255.0f, 1.0f));
		}
		else if (i < 39){
			mesh->AddVertexData(glm::vec4(0.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f, 1.0f));
		}
		else if (i < 45) {
			mesh->AddVertexData(glm::vec4(255.0f / 255.0f, 195.520f / 255.0f, 57.920f / 255.0f, 1.0f));
		}
	}

	mesh->SetNumElements(45);
	mesh->CreateMesh();
    return;
}

// white ground
void GenerateBackgroundMeshType2(Engine::Mesh* mesh)
{
	mesh->AddAttribute(4); //Location

	glm::vec3 postion_data[] = {
		glm::vec3(0.0f, -4.5f, 0.00f),

		glm::vec3(6.0f, -4.5f, 0.00f),
		glm::vec3(6.0f, -2.8f, 0.00f),
		glm::vec3(4.5f, -2.6f, 0.00f),
		glm::vec3(2.0f, -2.4f, 0.00f),
		glm::vec3(-2.0f, -2.4f, 0.00f),
		glm::vec3(-4.5f, -2.6f, 0.00f),
		glm::vec3(-6.0f, -2.8f, 0.00f),
		glm::vec3(-6.0f, -4.5f, 0.00f),
	};

	for (int i = 0; i < 9; i++) {
		mesh->AddVertexData(postion_data[i]);
		mesh->AddVertexData(1.0f);//transparent value
	}

	mesh->SetNumElements(9);
	mesh->CreateMesh();
	return;
}

// Moon object
void GenerateBackgroundMeshType3(Engine::Mesh* mesh) {
	mesh->AddAttribute(4); //Location

	int num = 20;
	float radius = 0.8f;
	float center_x = 3.0f;
	float center_y = 3.0f;
	//mesh->AddVertexData(glm::vec3(0.0f, 0.0f, 0.0f));
	//mesh->AddVertexData(1.0f);

	for (int i = 0; i < num; i++) {
		glm::vec3 position = glm::vec3(radius * cos(2 * PI / num * i), radius* sin(2 * PI / num * i), 0.0f);
		mesh->AddVertexData(position.x + center_x);
		mesh->AddVertexData(position.y + center_y);
		mesh->AddVertexData(position.z);
		mesh->AddVertexData(1.0f);//transparent value
	}

	mesh->SetNumElements(num);
	mesh->CreateMesh();
}

void GenerateBackgroundMeshType4(Engine::Mesh* mesh)
{
	mesh->AddAttribute(4); //Location

	glm::vec3 postion_data[] = {
		glm::vec3(0.0f, -4.6f, -0.01f),
		glm::vec3(6.1f, -4.6f, -0.01f),
		glm::vec3(6.1f, 0.0f, -0.01f),
		glm::vec3(-2.0f, 2.4f, -0.01f),
		glm::vec3(-6.1f, 0.0f, -0.01f),
		glm::vec3(-6.1f, -4.6f, -0.01f),
	};

	for (int i = 0; i < 6; i++) {
		mesh->AddVertexData(postion_data[i]);
		mesh->AddVertexData(1.0f);//transparent value
	}

	mesh->SetNumElements(6);
	mesh->CreateMesh();
	return;
}

int main(int argc, char** argv)
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    GLFWwindow* window;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1024, 768, "Homework 1 - Snowflake Animation (20150449)", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    GLenum glewError = glewInit();
    if (glewError != GLEW_OK)
    {
        std::cout << "GLEW Error: " << glewGetErrorString(glewError) << std::endl;
        exit(1);
    }


    Engine::Camera* mainCamera = new Engine::Camera();
    // Create snowflake instances

	//Background grad
    Engine::Mesh* mesh = new Engine::Mesh();
	GenerateGradientRectangle(mesh);
	mesh->SetDrawMode(GL_TRIANGLE_FAN);
	PerVertexColorMaterial* pvcMaterial = new PerVertexColorMaterial();
	pvcMaterial->CreateMaterial();
	Engine::RenderObject renderObject = Engine::RenderObject(mesh, pvcMaterial);	
	
	//Background Object house
	Engine::Mesh* meshBack1 = new Engine::Mesh();
	GenerateBackgroundMeshType1(meshBack1);
	PerVertexColorMaterial* Back1Material = new PerVertexColorMaterial();
	Back1Material->CreateMaterial();
	Engine::RenderObject renderObjectBack1 = Engine::RenderObject(meshBack1, Back1Material);
	
	//Background Object ground
	Engine::Mesh* meshBack2 = new Engine::Mesh();
	GenerateBackgroundMeshType2(meshBack2);
	meshBack2->SetDrawMode(GL_TRIANGLE_FAN);
	DefaultMaterial* Back2Material = new DefaultMaterial();
	Back2Material->CreateMaterial();
	Back2Material->UpdateColor(glm::vec3(151.072f / 255.0f, 152.730f / 255.0f, 157.765f / 255.0f));
	Engine::RenderObject renderObjectBack2 = Engine::RenderObject(meshBack2, Back2Material);

	//Background Object Moon
	Engine::Mesh* meshBack3 = new Engine::Mesh();
	GenerateBackgroundMeshType3(meshBack3);
	meshBack3->SetDrawMode(GL_TRIANGLE_FAN);
	DefaultMaterial* Back3Material = new DefaultMaterial();
	Back3Material->CreateMaterial();
	Back3Material->UpdateColor(glm::vec3(255.0f / 255.0f, 195.519f / 255.0f, 57.920f / 255.0f));
	Engine::RenderObject renderObjectBack3 = Engine::RenderObject(meshBack3, Back3Material);

	//Background Object Mountain
	Engine::Mesh* meshBack4 = new Engine::Mesh();
	GenerateBackgroundMeshType4(meshBack4);
	meshBack4->SetDrawMode(GL_TRIANGLE_FAN);
	DefaultMaterial* Back4Material = new DefaultMaterial();
	Back4Material->CreateMaterial();
	Back4Material->UpdateColor(glm::vec3(1.679f / 255.0f, 2.300f / 255.0f, 4.097f / 255.0f));
	Engine::RenderObject renderObjectBack4 = Engine::RenderObject(meshBack4, Back4Material);

	//Prepare Snowflake
	Fractal fractal = Fractal();
	Animation* animation1 = new Animation();
	Animation* animation2 = new Animation();
	std::vector<Snowflake*> snows = std::vector<Snowflake*>();
	std::vector<Snowflake*> disappearSnows = std::vector<Snowflake*>();
	std::vector<float> timeChecker = std::vector<float>();

	Engine::Mesh* meshSnow = new Engine::Mesh();
	fractal.GenerateSnowflake(meshSnow);

    mainCamera->SetPosition(glm::vec3(0.0f, 0.0f, 7.5f));
	float coolTime = glfwGetTime();
	/* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
		//make snow
		float nowTime = glfwGetTime();

		if (snows.size() < 25 && (nowTime-coolTime) > 0.6f) {
			coolTime = glfwGetTime();
			DefaultMaterial* materialSnow = new DefaultMaterial();
			materialSnow->CreateMaterial();
			materialSnow->UpdateColor(glm::vec3(168.102f / 255.0f, 169.860f / 255.0f, 175.193f / 255.0f));
			Snowflake *renderObjSnow = new Snowflake(meshSnow, materialSnow);
			snows.push_back(renderObjSnow);
		}

		//stop snow
		animation1 -> ~Animation();
		animation2 -> ~Animation();
		std::vector<Snowflake*> snowsNew = std::vector<Snowflake*>();
		
		for (int i = 0; i < snows.size(); i++) {
			Snowflake* tempPointer = snows[i];
			Snowflake temp = *tempPointer;
			if (temp.GetPosition().y > -4.0f) {
				animation1-> AddSnowflake(tempPointer);
				snowsNew.push_back(tempPointer);
				
			}
			else {
				disappearSnows.push_back(tempPointer);
				timeChecker.push_back(glfwGetTime());
			}
		}
		snows = snowsNew;
		//delete long run snow
		int size = disappearSnows.size();
		for (int i = 0; i < size; i++) {
			float currentTime = glfwGetTime();
			if (currentTime - timeChecker[i] > 1.0f) {
				disappearSnows.erase(disappearSnows.begin() + i);
				timeChecker.erase(timeChecker.begin()+i);
				i -= 1;
				size -= 1;
			}
		}

		// Enable depth test
        glEnable(GL_DEPTH_TEST);
        // Accept fragment if it closer to the camera than the former one
        glDepthFunc(GL_LESS);

        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK); // Cull back-facing triangles -> draw only front-facing triangles

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//About rendering object
		renderObject.Render(mainCamera);
		renderObjectBack1.Render(mainCamera);
		renderObjectBack2.Render(mainCamera);
		renderObjectBack3.Render(mainCamera);
		renderObjectBack4.Render(mainCamera);
		for (int i = 0; i < snows.size(); i++) {
			Snowflake temp = *snows[i];
			temp.Render(mainCamera);
		}
		for (int i = 0; i < disappearSnows.size(); i++) {
			Snowflake temp = *disappearSnows[i];
			temp.Render(mainCamera);
		}
		
		float loopTime = glfwGetTime()- nowTime;
		animation1->Animate1(loopTime);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    delete mainCamera;

	glfwTerminate();
    return 0;

}