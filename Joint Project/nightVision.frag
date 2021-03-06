uniform sampler2D sceneBuffer;
uniform sampler2D noiseTex; 
uniform sampler2D maskTex; 
uniform float elapsedTime; // seconds
uniform float luminanceThreshold; // 0.2
uniform float colorAmplification; // 4.0
uniform float effectCoverage; // 0.5
void main ()
{
  vec4 finalColor;
  // Set effectCoverage to 1.0 for normal use.  
  if (gl_TexCoord[0].x < effectCoverage) 
  {
    vec2 uv;           
    uv.x = 5.0*sin(elapsedTime*1000.01);                                 
    uv.y = 0.0*cos(elapsedTime*1.0);                                 
    float m = texture2D(maskTex, gl_TexCoord[0].st).r;
    vec3 n = texture2D(noiseTex, 
                 (gl_TexCoord[0].st* 5.5) - uv).rgb;
    vec3 c = texture2D(sceneBuffer, gl_TexCoord[0].st 
                               * (n.xy*0.005)).rgb;
  
    float lum = dot(vec3(0.30, 0.59, 0.11), c);
    if (lum < luminanceThreshold)
      c = colorAmplification; 
  
    vec3 visionColor = vec3(0.1, 0.95, 0.2);
    finalColor.rgb = (c + (n*0.2)) * visionColor * m;
   }
   else
   {
    finalColor = texture2D(sceneBuffer, 
                   gl_TexCoord[0].st);
   }
  gl_FragColor.rgb = finalColor.rgb;
  gl_FragColor.a = 0.05;
}			
