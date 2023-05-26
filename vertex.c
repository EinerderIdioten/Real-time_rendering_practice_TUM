#version 300 es

// Vertex position in object space coordinates
in vec3 vertexPosition;
// Surface normal at the vertex in object space coordinates
in vec3 vertexNormal;
// Texture coordinates at that vertex
in vec2 vertexTextureCoordinates;

out vec3 world_normal;
out vec3 world_fragPos;

// Model matrix
uniform mat4 mMatrix;
// View matrix
uniform mat4 vMatrix;
// Projection matrix
uniform mat4 pMatrix;

// Main program for each vertex
void main() {
  world_fragPos = vec3(mMatrix * vec4(vertexPosition, 1.0));
  world_normal = mat3(transpose(inverse(mMatrix))) * vertexNormal;
  gl_Position = pMatrix * vMatrix * vec4(world_fragPos, 1.0);  
}