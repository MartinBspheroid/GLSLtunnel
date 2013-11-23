#version 150
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
    
    output = vec4(texSample / ((f*f)+0.75), 1.0);
}
