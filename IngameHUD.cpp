#include "BaseInclude.h"
#include "IngameHUD.h"


CIngameHUD::CIngameHUD()
	: m_pSprite(NULL)
	, m_pTextureUI(NULL)
{
}


CIngameHUD::~CIngameHUD()
{
}

CIngameHUD*	CIngameHUD::Initialize(LPCWSTR nFileName)
{
	D3DXCreateSprite(GetDevice(), &m_pSprite);

	D3DXCreateTextureFromFileEx(
		GetDevice(),
		nFileName,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_DEFAULT,
		0,
		&m_stImageInfo,
		NULL,
		&m_pTextureUI
	);
	return this;
}

void CIngameHUD::Progress()
{
}

void CIngameHUD::Render(D3DXVECTOR3 ImagePos)
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);

	D3DXMATRIXA16 matT, matR, matS, matW;
	D3DXMatrixTranslation(&matT, 0, 0, 0);

	matW = matT;

	m_pSprite->SetTransform(&matT);

	RECT rc;
	SetRect(&rc, 0, 0, m_stImageInfo.Width, m_stImageInfo.Height);

	m_pSprite->Draw(
		m_pTextureUI,
		&rc,
		&D3DXVECTOR3(0, 0, 0),
		&ImagePos,
		D3DCOLOR_ARGB(255, 255, 255, 255)
	);

	m_pSprite->End();
}

void CIngameHUD::Release()
{
	if (m_pSprite)
	{
		m_pSprite->Release();
		m_pSprite = NULL;
	}

	if (m_pTextureUI)
	{
		m_pTextureUI->Release();
		m_pTextureUI = NULL;
	}
}
