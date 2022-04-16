#include "WindowManager.h"

#include "Brushes.h"
#include <cmath>


WindowManager::WindowManager(const char* window_name, int width, int height, const cosmoscope::FuncTree* func_tree) : 
    m_cosmosDrawer(func_tree,sqrt(width*width + height*height)/2.0,floatpix::Position{static_cast<float>(width/2.0),static_cast<float>(height/2.0)}),
    m_isWindowOpen(true),
    m_window(NULL), m_renderer(NULL), t(0), m_altKeyDown(false)
{

    //SDL initialisation
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
    }
    //main window  and renderer creation
    else if (SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_RESIZABLE, &m_window, &m_renderer) < 0) {
        printf("Error in window/renderer creation: %s", SDL_GetError());
    }
    else {
        SDL_SetWindowTitle(m_window, "Cosmoscope");
        SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
    }
}


int WindowManager::ProcessEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_WINDOWEVENT:
            if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
                m_isWindowOpen = false; //window closing
            }
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_LALT) {
                m_altKeyDown = true;
            }
            else if (event.key.keysym.sym == SDLK_s && m_altKeyDown) {
                TakeScreenshot();
            }
            break;
        case SDL_KEYUP:
            if (event.key.keysym.sym == SDLK_LALT) {
                m_altKeyDown = false;
            }
        }
    }
    return 0;
}

int WindowManager::UpdateFrame() {
    m_cosmosDrawer.DrawSnap(t, m_renderer);
    SDL_RenderPresent(m_renderer);
    SDL_Delay(1);
    t++;

    return 0;
}


bool WindowManager::IsWindowOpen() const {
    return m_isWindowOpen;
}

int WindowManager::TakeScreenshot() const {
    int w, h = 0;
    SDL_GetWindowSize(m_window,&w,&h);
    SDL_Surface* sshot = SDL_CreateRGBSurface(0, w, h, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    SDL_RenderReadPixels(m_renderer, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
    SDL_SavePNG(sshot, "screenshots/cosmoscope.png");
    SDL_FreeSurface(sshot);
    return 0;
}

WindowManager::~WindowManager() {
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();
}


