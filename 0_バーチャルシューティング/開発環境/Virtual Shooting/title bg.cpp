//=============================================================================
//
//	タイトル背景[title bg.cpp]
//	Author:吉田　悠人
//
//=============================================================================

//=============================================================================
// インクルードファイル
//=============================================================================
#include "title bg.h"
#include "manager.h"
#include "renderer.h"

//=============================================================================
// 静的メンバー変数
//=============================================================================
TEXTURE_DATA CTitleBg::m_TextureData = { NULL,"data/TEXTURE/title.png" };

//=============================================================================
// コンストラクタ
//=============================================================================
CTitleBg::CTitleBg(int nPriorit)
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CTitleBg::~CTitleBg()
{
}

//=============================================================================
// テクスチャ読み込み
//=============================================================================
HRESULT CTitleBg::Load(void)
{
	//デバイス取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetObjects();
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
							m_TextureData.m_cFileName, 
							&m_TextureData.m_pTexture);

	return S_OK;
}

//=============================================================================
// テクスチャの破棄
//=============================================================================
void CTitleBg::Unload(void)
{
	//テクスチャの破棄
	if (m_TextureData.m_pTexture != NULL)
	{
		m_TextureData.m_pTexture->Release();
		m_TextureData.m_pTexture = NULL;
	}

}

//=============================================================================
// 生成処理
//=============================================================================
CTitleBg * CTitleBg::Create(void)
{
	CTitleBg *pTitleBg;
	pTitleBg = new CTitleBg;

	//位置設定
	pTitleBg->SetPos(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f));
	//サイズ設定
	pTitleBg->SetSize(D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f));
	//テクスチャ設定
	pTitleBg->BindTexture(m_TextureData.m_pTexture);
	//初期化処理
	pTitleBg->Init();
	return pTitleBg;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CTitleBg::Init(void)
{
	CBgc::Init();
	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CTitleBg::Uninit(void)
{
	CBgc::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CTitleBg::Update(void)
{
	CBgc::Update();
}

//=============================================================================
// 描画処理
//=============================================================================
void CTitleBg::Draw(void)
{
	CBgc::Draw();
}
