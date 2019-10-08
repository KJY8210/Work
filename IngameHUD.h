#pragma once
class CIngameHUD
{
public:
	CIngameHUD();
	~CIngameHUD();

public:
	CIngameHUD* Initialize(LPCWSTR nFileName);
	void Progress();
	void Render(D3DXVECTOR3 ImagePos);
	void Release();

private:
	LPD3DXSPRITE m_pSprite;
	D3DXIMAGE_INFO m_stImageInfo;
	LPDIRECT3DTEXTURE9 m_pTextureUI;
};

