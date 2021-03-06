/// @file CosmosDrawerSDL.h
/// @brief This class allows to draw a Tree snapshot on a given renderer.
/// 
/// @author Alice Rixte
/// @date 07/04/2022
/// 
#pragma once

#include "CSC_FuncTree.h"
#include "CSC_CosmovertorSDL.h"

namespace cosmoscopeSDL {
	class CosmosDrawerSDL {
	public:
		CosmosDrawerSDL(const SDL_Rect& draw_area);

		void DrawSnap(const SnapQueueSDL& snap_queue, SDL_Renderer* renderer) const ;


	private:
		int m_minX;
		int m_maxX;
		int m_minY;
		int m_maxY;
	};
}



