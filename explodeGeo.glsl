#version 330 core

uniform float time;

// Layout is triangle-strip, therefore 3 vertices
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

	// normalize returns a vector of length 1 from the parameter
	vec4 normal = normalize(gl_in[0].gl_Position);


	// These take the vertices of the triangles, and changes their position with time
	gl_Position = gl_in[0].gl_Position;	
	OUT.colour = vec4(0,1,1,1);
	gl_Position.x += normal.x* time;
	gl_Position.y += normal.y* time;
	EmitVertex();
		
	gl_Position = gl_in[1].gl_Position;	
	OUT.colour = vec4(1,0,1,1);
	gl_Position.x += normal.x* time;
	gl_Position.y += normal.y* time;
	EmitVertex();

	gl_Position = gl_in[2].gl_Position;	
	OUT.colour = vec4(1,1,0,1);
	gl_Position.x += normal.x* time;
	gl_Position.y += normal.y* time;
	EmitVertex();
	
	EndPrimitive();
	
}