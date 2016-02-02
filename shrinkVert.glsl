#version 330 core

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projMatrix;
uniform float time;

layout(location = 0) in  vec3 position;
layout(location = 1) in  vec4 colour;
layout(location = 2) in  vec2 texCoord;

out Vertex	{
	smooth vec4 colour;
	smooth vec2 texCoord;
} OUT;

void main(void)	{

	// Take the various matrixes to represent the view
	mat4 mvp	= projMatrix * viewMatrix * modelMatrix;
	vec3 newPos = position;	

	// Output the texture and colours
	OUT.texCoord	= texCoord;
	OUT.colour = colour;
		
	// Vary the positions of the vertices by time
	newPos.x = newPos.x * 2/(time+2);
	newPos.y = newPos.y * 2/(time+2);
	newPos.z = newPos.z * 2/(time+2);
	gl_Position	= mvp * vec4(newPos, 1.0);
	
	
	
}