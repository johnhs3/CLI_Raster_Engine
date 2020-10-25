/*First attempt at a vertex shader. I have absolutely no clue what I'm doing, nor a clue
    what I'm getting myself into. lol.

    Anyhow, ca. Oct. 24, 2020. John H. Smith. Independent

    Desc.: ???(later)
*/


#include <vector_types.h>

// Input (vertex) data. Holds position, UV coords, normal vecor, and a vertex id.
struct INPUT {
    float4 position : POSITION;
    float2 uv : TEXCOORD;
    float3 normal : NORMAL;
    uint id : SV_vertexID;
};

// Output (preferably normalized!!!) scaled vertex data. Position, uv, and color.
struct OUTPUT {
    float4 position : SV_POSITION;
    float2 uv : TEXCOORD;
    float3 color : COLOR;
};

//BUFFER!!! We like those around here.
cbuffer Buffer {
    float4x4 matrix;
}

void main(in INPUT input, out OUTPUT output){
    output.position = mul(input.position, matrix);
    output.uv = input.uv;
    output.color = input.normal / input.id;         //THIS IS POINTLESS, just a placeholder for something more reasonable.
}