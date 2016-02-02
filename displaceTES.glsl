# version 400 core

layout ( triangles , equal_spacing , ccw ) in ;

uniform mat4 modelMatrix ;
uniform mat4 viewMatrix ;
uniform mat4 projMatrix ;

void main () {
	// Sets the position of each part of the vertex of a triangle
	vec3 p0 = gl_TessCoord.x * gl_in [0].gl_Position.xyz ;
	vec3 p1 = gl_TessCoord.y * gl_in [1].gl_Position.xyz ;
	vec3 p2 = gl_TessCoord.z * gl_in [2].gl_Position.xyz ;

	// Sets the combined position of the triangle
	vec3 combinedPos = p0 + p1 + p2 ;

	// These set the actual position of the triangles
	vec4 worldPos = modelMatrix * vec4 ( combinedPos , 1);
	gl_Position = projMatrix * viewMatrix * worldPos ;
}