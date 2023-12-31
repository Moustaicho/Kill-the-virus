#version 330

layout (location = 0) in vec3 vertexPosition;
in vec2 vertexTexCoord;            
in vec4 vertexColor;
out vec2 fragTexCoord;             
out vec4 fragColor;                
uniform mat4 mvp;            
      
void main()                        
{             
    fragTexCoord = vertexTexCoord; 
    fragColor = vertexColor;       
	
    gl_Position = mvp*vec4(vertexPosition.x,vertexPosition.y,vertexPosition.z, 1.0); 
}