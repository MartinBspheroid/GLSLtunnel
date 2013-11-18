#version 150
uniform mat4 modelViewProjectionMatrix;
uniform vec2 t;
in vec4 position;
in vec2 texcoord;

out vec2 texC;


void main()
	{	
		 gl_Position = modelViewProjectionMatrix * position;
		texC = texcoord;
	}