#version 330 core
uniform sampler2D tex0;
uniform float blendTime;

in Vertex	{
	smooth	vec4 colour;
	smooth	vec2 texCoord;
	
} IN;

out vec4 gl_FragColor;

void main(void)	{

	vec4 a = texture(tex0, IN.texCoord);
	
	gl_FragColor = vec4(a.rgb,a.w);

	// a is the alpha component, aka the transparency
	gl_FragColor.a = 1-blendTime;

}