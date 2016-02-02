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

	mat4 mvp	= projMatrix * viewMatrix * modelMatrix;
	vec3 newPos = position;	

	OUT.texCoord	= texCoord;
	OUT.colour = colour;
	//gl_Position = mvp * vec4(position,1.0f);
	//OUT.colour = vec4 (0.5f,0.5f,0.5f,1.0);
		
	
	gl_Position	= mvp * vec4(newPos, 1.0);
	newPos.x = newPos.x * 2/time;
	newPos.y = newPos.y * 2/time;
	newPos.z = newPos.z * 2/time;
	gl_Position	= mvp * vec4(newPos, 1.0);
	
	
	
}