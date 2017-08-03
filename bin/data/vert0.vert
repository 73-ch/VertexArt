#version 150
uniform mat4 modelViewProjectionMatrix;
uniform float time;
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
    vec3 v_position = vec3(vec2(gl_VertexID / 20. - time * 20., 30. * sin(2 * gl_VertexID + time)), rnd(vec2(gl_VertexID, 0.348)) * 20.);
    gl_Position = modelViewProjectionMatrix * vec4(v_position, 1.);
}