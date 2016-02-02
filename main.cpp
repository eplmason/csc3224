#include "Renderer.h"
#include "RenderObject.h"

#pragma comment(lib, "nclgl.lib")

void main(void) {
	Window w = Window(800, 600);
	Renderer r(w);

	Mesh*	m = Mesh::LoadMeshFile("cube.asciimesh");

	// Creates shader with basic vert and basic frag shaders
	Shader* s = new Shader("basicvert.glsl", "basicFrag.glsl");

	if (s->UsingDefaultShader()) {
		cout << "Warning: Using default shader! Your shader probably hasn't worked..." << endl;
		cout << "Press any key to continue." << endl;
		std::cin.get();
	}


	// Creates a render object of a cube mesh and the shader
	RenderObject o(m, s);

	// This moves the cube down the z axis by 1-=0
	o.SetModelMatrix(Matrix4::Translation(Vector3(0, 0, -10)) * Matrix4::Scale(Vector3(1, 1, 1)));

	// Add the cube to the scene
	r.AddRenderObject(o);

	// Set the projection and view matrixes for the scene
	r.SetProjectionMatrix(Matrix4::Perspective(1, 100, 1.33f, 45.0f));
	r.SetViewMatrix(Matrix4::BuildViewMatrix(Vector3(0, 0, 0), Vector3(0, 0, -10)));

	while (w.UpdateWindow()) {
		float msec = w.GetTimer()->GetTimedMS();
		
		// Adds 1 to the time variable, used in shaders to adjust the vertices
		r.time += 1.0f;

		// BlendTime also increases each time, but stops at 1
		if (r.blendTime < 1.0f){
			r.blendTime += 0.01f;
		}

		// If the keys are pressed, different shaders are activated
		if (Keyboard::KeyDown(KEY_0)) {
			// All the shaders follow a simple pattern: 
			// Delete previous shader
			delete s;
			// Create new shader with different shader components
			s = new Shader("basicVert.glsl", "basicFrag.glsl");
			// Set type of mesh (comes into play for tesselation shaders);
			m->type = GL_TRIANGLES;
			// Change the RenderObject to use the new shader and mesh type
			o = RenderObject(m, s);
			// Reset the time variable to 0
			r.time = 0;
			// Reset the position of the cube
			o.SetModelMatrix(Matrix4::Translation(Vector3(0, 0, -10)) * Matrix4::Scale(Vector3(1, 1, 1)));
		}
		if (Keyboard::KeyDown(KEY_1)) {
			delete s;
			s = new Shader("shrinkVert.glsl", "basicFrag.glsl");
			m->type = GL_TRIANGLES;
			o = RenderObject(m, s);
			r.time = 0;
			r.blendTime = 0.01f;
			o.SetModelMatrix(Matrix4::Translation(Vector3(0, 0, -10)) * Matrix4::Scale(Vector3(1, 1, 1)));
		}
		if (Keyboard::KeyDown(KEY_2)) {
			delete s;
			s = new Shader("basicVert.glsl", "blendFrag.glsl");
			m->type = GL_TRIANGLES;
			o = RenderObject(m, s);
			r.time = 0;
			r.blendTime = 0.01f;
			o.SetModelMatrix(Matrix4::Translation(Vector3(0, 0, -10)) * Matrix4::Scale(Vector3(1, 1, 1)));
		}
		if (Keyboard::KeyDown(KEY_3)) {
			delete s;
			s = new Shader("basicVert.glsl", "transFrag.glsl");
			m->type = GL_TRIANGLES;
			o = RenderObject(m, s);
			r.time = 0;
			r.blendTime = 0.01f;
			o.SetModelMatrix(Matrix4::Translation(Vector3(0, 0, -10)) * Matrix4::Scale(Vector3(1, 1, 1)));
		}
		if (Keyboard::KeyDown(KEY_4)) {
			delete s;
			s = new Shader("basicVert.glsl", "basicFrag.glsl","basicGeo.glsl");
			m->type = GL_TRIANGLES;
			o = RenderObject(m, s);
			r.time = 0;
			r.blendTime = 0.01f;
			o.SetModelMatrix(Matrix4::Translation(Vector3(0, 0, -10)) * Matrix4::Scale(Vector3(1, 1, 1)));
		}
		if (Keyboard::KeyDown(KEY_5)) {
			delete s;
			s = new Shader("tessVert.glsl", "basicFrag.glsl", "explodeGeo.glsl", "displaceTCS.glsl","displaceTES.glsl");
			m->type = GL_PATCHES;
			o = RenderObject(m, s);
			r.time = 0;
			r.blendTime = 0.01f;
			o.SetModelMatrix(Matrix4::Translation(Vector3(0, 0, -10)) * Matrix4::Scale(Vector3(1, 1, 1)));
		}
		if (Keyboard::KeyDown(KEY_6)) {
			delete s;
			s = new Shader("bholeVert.glsl", "basicFrag.glsl", "bholeGeo.glsl", "displaceTCS.glsl", "displaceTES.glsl");
			// Tesselation shaders use GL_PATCHES instead of GL_TRIANGlES in order to work, hence why the mesh type is declared for each shader
			m->type = GL_PATCHES;
			o = RenderObject(m, s);
			r.time = 0;
			r.blendTime = 0.01f;
			o.SetModelMatrix(Matrix4::Translation(Vector3(0, 0, -10)) * Matrix4::Scale(Vector3(1, 1, 1)));
		}
		// This causes the cube to rotate constantly
		o.SetModelMatrix(o.GetModelMatrix() * Matrix4::Rotation(0.1f * msec, Vector3(1, 1, 1)));

		r.UpdateScene(msec);
		r.ClearBuffers();
		r.RenderScene();
		r.SwapBuffers();
	}
	delete m;
	delete s;
}