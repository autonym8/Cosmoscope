/// @file Brushes.h
/// @brief Contains all functions related to brushes to display the Cosmoscope using SDL2.0.
///
/// @author Alice Rixte
/// @date 05/04/2022
#pragma once

#include<SDL.h>
#include <cmath>
#include "CSC_CoorSystemSDL.h"

namespace draw_SDL {

	// this is probably not optimal, maybe using a texture would be better but the color constantly changes.

	/// @brief  Draws an ellipse directly on the renderer that fits the given rectangle, with a gradient toward transparency
	/// @param renderer The SDL_Renderer to draws on
	/// @param ellipseRect The rectangle the ellipse must fit
	/// @param color The color of the ellipse.
	/// @param plainPercent Describes when the gradient towards transparency starts : if the plain percentage is 1.0, then there is now gradient,
	/// if it's 0.0, the gradients immediately applies as the points move away from the focuses. 
	/// @return 0 if everything went fine
	int DrawEllipse(SDL_Renderer* renderer, const cosmoscopeSDL::Point& pos, double width, double weight,
		const SDL_Color& color, double plainRatio = 1.0, float grad_steepness=1.0);


	/// @brief  Draws an ellipse directly on the renderer that fits the given rectangle, with a gradient toward transparency
	/// @param renderer The SDL_Renderer to draws on
	/// @param ellipseRect The rectangle the ellipse must fit
	/// @param color The color of the ellipse.
	/// @param plainPercent Describes when the gradient towards transparency starts : if the plain percentage is 1.0, then there is now gradient,
	/// if it's 0.0, the gradients immediately applies as the points move away from the focuses. 
	/// @return 0 if everything went fine
	int DrawCircle(SDL_Renderer* renderer, const cosmoscopeSDL::Point& pos, double radius,
		const SDL_Color& color, double plainRatio = 1.0, float grad_steepness = 1.0);

}
