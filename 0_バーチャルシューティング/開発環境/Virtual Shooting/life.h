#ifndef _LIFE_H_
#define _LIFE_H_
//----------------------------------------------
//ヘッダーファイル
//----------------------------------------------
#include "main.h"
#include "scene.h"
//----------------------------------------------
//マクロ定義
//----------------------------------------------
#define MAX_LIFE 8
#define PRIORIT_LIFE 5
//=============================================================================
//前方宣言
//=============================================================================
class CScene2d;
class CUi;
class CLifeUi;
//------------------------------------
//クラス処理
//------------------------------------
class CLife :public CScene
{
public:
	CLife(int nPriorit= 3);							//コンストラクタ
	~CLife();							//デストラクタ

	static CLife*	Create(D3DXVECTOR3 pos);	//生成処理

	HRESULT			Init(void);		//初期化処理
	void			Uninit(void);	//終了処理
	void			Update(void);	//更新処理
	void			Draw(void);		//描画処理
	void			SetLife(int nLifeNumber);	//ライフセット
	void			SetPos(D3DXVECTOR3 Lifepos);//ライフ位置
	void			DownLife(int nLifeDown);	//ダメージを受けた時
private:
	static LPDIRECT3DTEXTURE9	m_apTexture;				//テクスチャへのポインタ
	CUi							*m_Ui;						//UIクラス
	CLifeUi						*m_LifeUi[MAX_LIFE];					//ライフUI
	int							nLife;						//ライフ量
	D3DXVECTOR3					pos;						//位置
};



#endif