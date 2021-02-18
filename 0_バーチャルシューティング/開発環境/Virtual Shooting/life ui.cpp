//=============================================================================
//
//	ライフui[life ui.cpp]
//	Author:吉田　悠人
//
//=============================================================================

//=============================================================================
// インクルードファイル
//=============================================================================
#include "life ui.h"
#include "renderer.h"
#include "manager.h"
//=============================================================================
// 静的メンバー変数
//=============================================================================
TEXTURE_DATA CLifeUi::m_TextureData = { NULL,	"data/TEXTURE/Life_UI.png", };

//=============================================================================
// コンストラクタ
//=============================================================================
CLifeUi::CLifeUi(int nPriorit) :CScene2d(nPriorit)
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CLifeUi::~CLifeUi()
{
}

//=============================================================================
// テクスチャ読み込み
//=============================================================================
HRESULT CLifeUi::Load(void)
{
	//デバイス取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetObjects();
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		m_TextureData.m_cFileName,
		&m_TextureData.m_Texture);

	return S_OK;
}

//=============================================================================
// テクスチャの破棄
//=============================================================================
void CLifeUi::Unload(void)
{
	//テクスチャの破棄
	if (m_TextureData.m_Texture != NULL)
	{
		m_TextureData.m_Texture->Release();
		m_TextureData.m_Texture = NULL;
	}
}

//=============================================================================
// 生成処理
//=============================================================================
CLifeUi * CLifeUi::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	CLifeUi *pLifeUi;
	pLifeUi = new CLifeUi;

	//位置設定
	pLifeUi->SetPos(D3DXVECTOR3(pos.x, pos.y, pos.z));
	//サイズ設定
	pLifeUi->SetSize(D3DXVECTOR3(size.x, size.y, size.z));
	//テクスチャ設定
	pLifeUi->BindTexture(m_TextureData.m_Texture);
	//初期化処理
	pLifeUi->Init();
	return pLifeUi;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CLifeUi::Init(void)
{
	CScene2d::Init();
	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CLifeUi::Uninit(void)
{
	CScene2d::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CLifeUi::Update(void)
{
	CScene2d::Update();
}

//=============================================================================
// 描画処理
//=============================================================================
void CLifeUi::Draw(void)
{
	CScene2d::Draw();
}
