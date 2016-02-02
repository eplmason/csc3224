#version 330 core

uniform float blendTime;

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

	//This shader is almost identical to explodeGeo - however the way the scaling of each position is done is different

	vec4 normal = normalize(gl_in[0].gl_Position);
	float scale = 15f;
	gl_Position = gl_in[0].gl_Position;	
	OUT.colour = vec4(0,1,1,1);
	gl_Position.x -= normal.x* blendTime*scale;
	gl_Position.y -= normal.y* blendTime*scale;
	EmitVertex();
		
	gl_Position = gl_in[1].gl_Position;	
	OUT.colour = vec4(1,0,1,1);
	gl_Position.x -= normal.x* blendTime*scale;
	gl_Position.y -= normal.y* blendTime*scale;
	EmitVertex();

	gl_Position = gl_in[2].gl_Position;	
	OUT.colour = vec4(1,1,0,1);
	gl_Position.x -= normal.x* blendTime*scale;
	gl_Position.y -= normal.y* blendTime*scale;
	EmitVertex();
	
	EndPrimitive();
	
}