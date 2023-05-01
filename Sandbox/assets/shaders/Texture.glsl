// Basic Texture Shader

#type vertex
#version 330 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec4 a_Color;
layout(location = 2) in vec2 a_TexCoord;
layout(location = 3) in float a_TexIndex;
layout(location = 4) in float a_TilingFactor;

uniform mat4 u_ViewProjection;
out vec4 v_Color;
out vec2 v_TexCoord;
out float v_TexIndex;
out float v_TilingFactor;

void main()
{
    v_Color = a_Color;
    v_TexCoord = a_TexCoord;
    v_TexIndex = a_TexIndex;
	v_TilingFactor = a_TilingFactor;
    gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
}

#type fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec4 v_Color;
in vec2 v_TexCoord;
in float v_TexIndex;
in float v_TilingFactor;

uniform sampler2D u_Textures[32];


vec4 SampleTexture(int idx, vec2 texCoord)
{
    if (idx == 0) {
        return texture(u_Textures[0], texCoord);
    }
    else if (idx == 1) {
        return texture(u_Textures[1], texCoord);
    }
    else if (idx == 2) {
        return texture(u_Textures[2], texCoord);
    }
    else if (idx == 3) {
        return texture(u_Textures[3], texCoord);
    }
    else if (idx == 4) {
        return texture(u_Textures[4], texCoord);
    }
    else if (idx == 5) {
        return texture(u_Textures[5], texCoord);
    }
    else if (idx == 6) {
        return texture(u_Textures[6], texCoord);
    }
    else if (idx == 7) {
        return texture(u_Textures[7], texCoord);
    }
    else if (idx == 8) {
        return texture(u_Textures[8], texCoord);
    }
    else if (idx == 9) {
        return texture(u_Textures[9], texCoord);
    }
    else if (idx == 10) {
        return texture(u_Textures[10], texCoord);
    }
    else if (idx == 11) {
        return texture(u_Textures[11], texCoord);
    }
    else if (idx == 12) {
        return texture(u_Textures[12], texCoord);
    }
    else if (idx == 13) {
        return texture(u_Textures[13], texCoord);
    }
    else if (idx == 14) {
        return texture(u_Textures[14], texCoord);
    }
    else if (idx == 15) {
        return texture(u_Textures[15], texCoord);
    }
    else if (idx == 16) {
        return texture(u_Textures[16], texCoord);
    }
    else if (idx == 17) {
        return texture(u_Textures[17], texCoord);
    }
    else if (idx == 18) {
        return texture(u_Textures[18], texCoord);
    }
    else if (idx == 19) {
        return texture(u_Textures[19], texCoord);
    }
    else if (idx == 20) {
        return texture(u_Textures[20], texCoord);
    }
    else if (idx == 21) {
        return texture(u_Textures[21], texCoord);
    }
    else if (idx == 22) {
        return texture(u_Textures[22], texCoord);
    }
    else if (idx == 23) {
        return texture(u_Textures[23], texCoord);
    }
    else if (idx == 24) {
        return texture(u_Textures[24], texCoord);
    }
    else if (idx == 25) {
        return texture(u_Textures[25], texCoord);
    }
    else if (idx == 26) {
        return texture(u_Textures[26], texCoord);
    }
    else if (idx == 27) {
        return texture(u_Textures[27], texCoord);
    }
    else if (idx == 28) {
        return texture(u_Textures[28], texCoord);
    }
    else if (idx == 29) {
        return texture(u_Textures[29], texCoord);
    }
    else if (idx == 30) {
        return texture(u_Textures[30], texCoord);
    }
    else if (idx == 31) {
        return texture(u_Textures[31], texCoord);
    }
    else {
        return texture(u_Textures[0], texCoord);
    }
};

void main()
{
    int idx = int(v_TexIndex);
    vec4 texColor = SampleTexture(idx, v_TexCoord * v_TilingFactor) * v_Color;
    color = texColor;
}