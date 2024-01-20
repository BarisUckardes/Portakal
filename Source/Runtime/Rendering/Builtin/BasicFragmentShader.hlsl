struct PS_INPUT
{
    float4 pos : SV_POSITION;
    float2 uv : TEXCOORD0;
};

          
float4 main(PS_INPUT input) : SV_Target
{
    float4 out_col = float4(input.uv,0.0f,1.0f);
    return out_col;
}