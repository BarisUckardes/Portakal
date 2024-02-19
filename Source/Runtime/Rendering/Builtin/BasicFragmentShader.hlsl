struct PS_INPUT
{
    Float324 pos : SV_POSITION;
    Float322 uv : TEXCOORD0;
};

          
Float324 main(PS_INPUT input) : SV_Target
{
    Float324 out_col = Float324(input.uv,0.0f,1.0f);
    return out_col;
}