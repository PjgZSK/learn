#include <glad/glad.h>
#include <glfw3/include/glfw3.h>
#include <iostream>
#include "src/shader/shader.h"
#define STB_IMAGE_IMPLEMENTATION
#include "src/stb/stb_image.h"
#include "src/platform/platform_config.h"
#include "src/platform/platform_macro.h"
#include "src/log/log.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/common.hpp"

const float WindowWidth = 800.0f;
const float WindowHeight = 600.0f;

float mixValue = 0.0f;
void processInput(GLFWwindow* window);
unsigned int loadTexture(const char* path);

int main()
{
	// glfw : initialize and configure
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#if TARGET_PLATFORM == PLATFORM_MAC
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
#endif
	// glfw window creation
	GLFWwindow* window = glfwCreateWindow(WindowWidth, WindowHeight, "LearningOpenGL", NULL, NULL);
	if (NULL == window)
	{
		log("Failed to initialize GLFW");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	});

	// glad : load all opengl function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		log("Failed to initialize GLAD");
		return -1;
	}

	// set vertices and indices data
	float vertices[] = {
		// positions          // colors           // texture coords
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   2.0f, 2.0f, // top right
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   2.0f, -1.0f, // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   -1.0f, -1.0f, // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   -1.0f, 2.0f  // top left 
	};
	unsigned int indices[] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};

	// vetex array
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);	
	glBindVertexArray(VAO);
	
	// vertex buffer
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// element buffer
	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// set vertex attribute array
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	// load texture1
	unsigned int texture1 = loadTexture("resource/container.jpg");
	
	// load texture2
	unsigned int texture2 = loadTexture("resource/awesomeface.png");

	// compile and link shader
	Shader shader("shader/shader.vs", "shader/shader.fs");
	shader.use();
	shader.setInt("texture1", 0);
	shader.setInt("texture2", 1);

	/*glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));
	vec = trans * vec;
	std::cout << vec.x << vec.y << vec.z << std::endl;*/

	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::rotate(trans, 90.0f, glm::vec3(0.0, 0.0, 1.0));
	trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
	unsigned int transformLoc = glGetUniformLocation(shader.GetID(), "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

	// render loop
	while (!glfwWindowShouldClose(window))
	{
		// input
		processInput(window);

		// render
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		// set gl data
		// set uniform "percent" data
		shader.setFloat("percent", mixValue);
		// bind texture0 data
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1);
		// bind texture1 data
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);
		// apply shader program
		shader.use();
		// bind vertex array data
		glBindVertexArray(VAO);

		// draw call
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		// swap frame buffer
		glfwSwapBuffers(window);
		// epoll io event
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &VAO);

	glfwTerminate();
	return 0;
}

unsigned int loadTexture(const char* path)
{
	unsigned int texture = -1;
	stbi_set_flip_vertically_on_load(true);
	int width, height, nrChannels;
	unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);
	if (data)
	{		
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		unsigned l = strlen(path);
		GLenum format = l > 3 && path[l - 4] == '.' && path[l - 3] == 'p' && path[l - 2] == 'n' && path[l - 1] == 'g' ? GL_RGBA : GL_RGB;
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		log("ERROR::TEXTURE::FAILED_LOADING_IMAGE : %s", path);
	}
	stbi_image_free(data);
	return texture;
}

void processInput(GLFWwindow * window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		mixValue += 0.001f;
		if (mixValue > 1.0f)
		{
			mixValue = 1.0f;
		}
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		mixValue -= 0.001f;
		if (mixValue < 0.0f)
		{
			mixValue = 0.0f;
		}
	}
}
