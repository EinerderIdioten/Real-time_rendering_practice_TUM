#version 300 es

// For better performance less precision
precision highp float;
out vec4 fragColor;

in vec3 world_normal;
in vec3 world_fragPos;

uniform vec3 lightPos; 
uniform vec3 lightColor;
uniform vec3 objectColor;

// Main program for each fragment = pixel candidate
void main() {
  vec3 norm = normalize(world_normal);
  vec3 light_dir = normalize(lightPos - world_fragPos);

  float diff = max(dot(world_normal, light_dir), 0.0);

  vec3 diffuse = diff * lightColor;

  vec3 result = objectColor * diffuse;

  fragColor = vec4(result, 1.0);
}