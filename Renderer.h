#pragma once
#include "../nclgl/OGLRenderer.h"

#include "RenderObject.h"

#include <vector>

using std::vector;

class Renderer : public OGLRenderer	{
public:
	Renderer(Window &parent);
	~Renderer(void);

	virtual void	RenderScene();

	virtual void	Render(const RenderObject &o);

	virtual void	UpdateScene(float msec);

	void	AddRenderObject(RenderObject &r) {
		renderObjects.push_back(&r);
	}
	const GLuint loadTexture(const char* filename);

	// Global variables to measure time
	float time;
	float blendTime;

protected:
	RenderObject triObject;
	Mesh* triangle;
	Shader* simpleShader;
	RenderObject(root);
	vector<RenderObject*> renderObjects;

	// This method will load a texture
	GLuint LoadTexture(GLuint name);

	// Stores the various textures
	GLuint tex0;
	GLuint tex1;
	GLuint tex2;
};

