
#pragma once

#include "scene/SceneRendering.h"
#include "basic/GlobalInstance.h"
#include "graphics/Renderer.h"
#include "entity/SceneEntitySprite.h"

#include "OuterTotalisticCA.h"
#include "GenerationOuterTotalisticCA.h"

namespace BCA = BitboardCA;

class InnerCAForStarwars
	: public BCA::OuterTotalisticCA
{
public:
	InnerCAForStarwars(std::size_t size_x, std::size_t size_y)
		: OuterTotalisticCA(size_x, size_y)
	{
	}

protected:
	BCA::Bitboard Rule(
		BCA::Bitboard board,
		BCA::Bitboard s0, BCA::Bitboard s1, BCA::Bitboard s2,
		BCA::Bitboard s3, BCA::Bitboard s4, BCA::Bitboard s5,
		BCA::Bitboard s6, BCA::Bitboard s7, BCA::Bitboard s8 )
	{
		return ( board & ( s3 | s4 | s5 ) ) | ( ~board & s2 );
	}
};

class StarwarsCA
	: public BCA::GenerationOuterTotalisticCA
	, public entity::SceneEntitySprite
{
public:
	StarwarsCA()
		: SceneEntitySprite("resource/master/reversi/white.tga")
		, GenerationOuterTotalisticCA(100, 70, 4)
		, m_Starwars(GetSizeX(), GetSizeY())
	{
		//EnableAlphatest();
		EnableAlphablending();
		SetRect(utility::Rect<float>(0, 0, 8, 8));

		SetInnerCAInstance(&m_Starwars);
	}

	void Draw()
	{
		for ( int y = 0 ; y < (int)GetSizeY() ; y ++ )
			for ( int x = 0 ; x < (int)GetSizeX() ; x ++ )
			{
				std::size_t state = GetCellState(x, y);
				if ( state > 0 )
				{
					utility::Color color(255, state * 50, state * 50, state * 50);
					GetGlobalInstance()->GetRenderer()->DrawRect(
						utility::Rect<float>(x * width, y * height, width, height),
						GetUV(), color, GetTexture(), IsEnableAlphatest(), IsEnableAlphablending());
				}
			}
	}

private:
	InnerCAForStarwars m_Starwars;
};

class SceneCA
	: public SceneRendering
{
private:
	StarwarsCA m_CA;

public:
	SceneCA(SceneID scene_id);

	void Initialize();
	void Finalize();
	void Update(unsigned int elapsed_time);

};
