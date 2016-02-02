#version 330 core
uniform sampler2D tex0;
uniform sampler2D tex1;
uniform float blendTime;

in Vertex	{
	smooth	vec4 colour;
	smooth	vec2 texCoord;
	
} IN;

out vec4 gl_FragColor;

void main(void)	{

	// Set vectors a and b as the textures in
	vec4 a = texture(tex0, IN.texCoord);
	vec4 b = texture(tex1, IN.texCoord);
	
	// Sets the fragment colour of the vertex by scaling down a and scaling up b
	gl_FragColor = (a*(1-blendTime))+(b*blendTime);

}