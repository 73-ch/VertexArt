#version 150

#define PI 3.141592653589793
#define PI_2 6.2831853072

uniform mat4 modelViewProjectionMatrix;
uniform float time;
uniform int vertex_num;
uniform vec3 r_seed;
in vec4 position;


vec3 rnd(float n, vec3 s){
    return vec3((fract(sin(dot(vec2(n, s.x), vec2(12.9898, 4.1414))) * 43758.5453) - 0.5) * 20.,
                (fract(sin(dot(vec2(n, s.y), vec2(12.9898, 4.1414))) * 43758.5453) - 0.5) * 20.,
                (fract(sin(dot(vec2(n, s.z), vec2(12.9898, 4.1414))) * 43758.5453) - 0.5) * 20.);
}

float rnd(vec2 n){
    return fract(sin(dot(n, vec2(12.9898, 4.1414))) * 43758.5453);
}

void main() {
    int gid = floor(gl_VertexID / 100);
    int cid = gl_VertexID % 100;
    
    vec3 g_pos = rnd(gid, r_seed);
    vec3 g_vel = rnd(gid + vertex_num, r_seed);
    
}