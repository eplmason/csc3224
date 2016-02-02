#version 330 core

uniform float time;

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

in Vertex{
	vec4 colour;
	vec2 texCoord;
} IN[];

out Vertex{
	vec4 colour;
	vec2 texCoord;
} OUT;

void main(){
	for(int i = 0; i < gl_in.length(); ++i){
		// This sets the position of the vertices according to the time
		gl_Position = gl_in[i].gl_Position;
		gl_Position.x = gl_in[i].gl_Position.x * (1+(time/500*i));
		gl_Position.y = gl_in[i].gl_Position.y * (1+(time/500*i));
			
		OUT.colour = IN[i].colour;
		OUT.texCoord = IN[i].texCoord;
		EmitVertex();
		
	}
	EndPrimitive();
	
}