#ifdef GL_ES
precision mediump float;
#endif

#extension GL_OES_standard_derivatives : enable

uniform float time;
uniform vec2 mouse;
uniform vec2 resolution;

float wave(float t, vec2 p, float a, float b, float c)
{
  return clamp(abs(0.005 / (p.y - c * sin(a * p.x + b * t))), 0.0, 1.0);
}

vec4 render(float t, vec2 p)
{
	vec3 color = vec3(0.0);
	float a = wave(t, p, 7.0, 5.0, 0.5);
	float b = wave(t, p, 6.0, 6.0, 0.4);
	float c = wave(t, p, 5.0, 7.0, 0.3);
	float d = wave(t, p, 7.0, 5.0, 0.5);
	float e = wave(t, p, 6.0, 6.0, 0.4);
	float f = wave(t, p, 5.0, 7.0, 0.3);
	
	
	color += vec3(a, 0.0, 0.0);
	color += vec3(0.0, b, 0.0);
	color += vec3(0.0, 0.0, c);
  	return vec4(color, 0.5);
}

void main( void ) {
    vec2 p = 2.0 * (gl_FragCoord.xy / resolution.xy - 0.5) * resolution.xy / resolution.y;
    gl_FragColor = render(time, p);
}