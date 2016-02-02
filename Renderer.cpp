#include "Renderer.h"

Renderer::Renderer(Window &parent) : OGLRenderer(parent)	{
	glEnable(GL_DEPTH_TEST);
	// GL_BLEND is enabled for transparency
	glEnable(GL_BLEND);

	// Loads in 3 textures
	tex0 = loadTexture("smiley.png");
	tex1 = loadTexture("noise.png");
	tex2 = loadTexture("perlin.png");
}

Renderer::~Renderer(void)	{

}

void	Renderer::RenderScene() {
	Render(root);
	//ClearBuffers();
	for (vector<RenderObject*>::iterator i = renderObjects.begin(); i != renderObjects.end(); ++i) {
		Render(*(*i));
	}
}

void	Renderer::Render(const RenderObject &o) {
	modelMatrix = o.GetWorldTransform();

	if (o.GetShader() && o.GetMesh()) {
		// Returns the program of the shader
		GLuint program = o.GetShader()->GetShaderProgram();

		// Sends time to any shader that contains uniform float time
		glUniform1f(glGetUniformLocation(program, "time"), time);

		// Any shader with blendTime may need to be transparent, hence enabling the blend function
		if (glGetUniformLocation(program, "blendTime") != 1){
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}

		// The following do the same as time, sending these variables to the shaders where applicable
		glUniform1f(glGetUniformLocation(program, "blendTime"), blendTime);

		glUniform1i(glGetUniformLocation(program, "tex0"), 0);

		glUniform1i(glGetUniformLocation(program, "tex1"), 1);

		// Sets the active texture, before binding it to a texture GLuint
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, tex0);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, tex2);

		glUseProgram(program);

		UpdateShaderMatrices(program);

		o.Draw();
	}

	for (vector<RenderObject*>::const_iterator i = o.GetChildren().begin(); i != o.GetChildren().end(); ++i) {
		Render(*(*i));
	}
}

void	Renderer::UpdateScene(float msec) {
	for (vector<RenderObject*>::iterator i = renderObjects.begin(); i != renderObjects.end(); ++i) {
		(*i)->Update(msec);
	}
}


const GLuint Renderer::loadTexture(const char* filename){
	// Returns a GLuint of a texture loaded in
	return (GLuint)SOIL_load_OGL_texture(
		filename,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
}