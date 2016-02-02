#version 330 core
uniform sampler2D tex;

in Vertex	{
	smooth	vec4 colour;
	smooth	vec2 texCoord;
	
} IN;

out vec4 gl_FragColor;

void main(void)	{	
	gl_FragColor = IN.colour * texture(tex,IN.texCoord);
}