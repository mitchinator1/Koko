#shader vertex
#version 330 core

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec4 inColour;

//uniform mat4 u_Projection;
//uniform mat4 u_View;
//uniform mat4 u_Model;

//out vec3 fragPos;
out vec4 colour;

void main()
{
	//fragPos = vec3(u_Model * vec4(inPosition, 1.0));
	colour = inColour;
    
   //gl_Position = u_Projection * u_View * vec4(fragPos, 1.0);
	gl_Position = vec4(inPosition, 1.0);
}

#shader fragment
#version 330 core

out vec4 fragmentColour;
 
in vec4 colour;

void main()
{
    fragmentColour = colour;
}
