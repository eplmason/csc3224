#version 400 core

uniform float time;

in vec3 position;
in vec2 texCoord;
out Vertex{
	vec2 texCoord;
} OUT;

void main(void){
	gl_Position = vec4(position,1.0);
	vec3 newPos = position;	

	newPos.x = newPos.x * 2/(time/50+2);
	newPos.y = newPos.y * 2/(time/50+2);
	newPos.z = newPos.z * 2/(time/50+2);
	gl_Position	= vec4(newPos, 1.0);

	OUT.texCoord = texCoord;
}