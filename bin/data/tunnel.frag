
#version 150
    //precision highp float;
    #extension GL_ARB_texture_rectangle: enable    
    #define PI 3.1416

    uniform sampler2DRect tex;
    uniform float timeE;
    uniform vec2 resolution;
    uniform vec2 mouse;
    in vec2 texC;
    out vec4 output;

    void main(){

    vec2 position = 2.0 * (texC.xy/ resolution.xy) -1.0;
    position.x *= resolution.x/resolution.y; 
    float a; 
    if(position.x > 0.0){
    a =  atan(position.x , position.y) / PI;
    }else{
    a = 1.0 - (atan(position.x, position.y) + PI ) / PI;
    }
    float r =  mouse.x / length(position) ;
    float f = r;
    r = mod(r-(timeE*0.5), 1.0);
    vec2 uv = vec2(r, a);
    uv.x *= resolution.x;
    uv.y *= resolution.y;
    vec3 texSample = texture2DRect(tex, uv).xyz;
    //output = vec4(texSample, uv);
    output = vec4(texSample / ((f*f)+0.75), 1.0);
}


/*

............. ALMOST WORKING...............


 

.................................













float t = mouse.x * 100;
float d = mouse.y * 110;
vec2 resolution = vec2(128, 128);
vec2 p = -1 + 2 * texC.xy / resolution.xy;
vec2 g = (((2*texC.xy) / resolution.xy) - 1) * vec2(resolution.x / resolution.y, 1.0);
float a = t*atan(g.x, g.y);
// float c = a/(3.1416);
 float r = 0.01 * sqrt(dot(g, g));
//float r = length(g);
vec2 uv;
// uv.x = (6.28/ r) +timeE ;
uv.y = (.1/r) + timeE;
uv.x = a / (3.1416/2.5);
vec3 col = texture(tex, uv).xyz;

 output = vec4(col, 1);
//output = vec4(gl_FragCoord.x/resolution.x, gl_FragCoord.y/resolution.y, 1.0, 1.0);



*/


