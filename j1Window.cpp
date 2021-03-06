#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Window.h"

#include "SDL/include/SDL.h"


j1Window::j1Window() : j1Module()
{
	window = NULL;
	screen_surface = NULL;
	name.create("window");
}

// Destructor
j1Window::~j1Window()
{
}

// Called before render is available
bool j1Window::Awake(pugi::xml_node window_config)
{
	LOG("Init SDL window & surface");
	bool ret = true;


	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		LOG("SDL_VIDEO could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}
	else
	{
		//Create window
		Uint32 flags = SDL_WINDOW_SHOWN;
		width = window_config.child("width").attribute("value").as_int(640);
		height = window_config.child("height").attribute("value").as_int(480);

		scale = window_config.child("scale").attribute("scale").as_int();
		if (scale < 1)
			scale = 1;

		//App->config.child("scale").child_value;

		if (window_config.child("fullscreen").child_value() == "true")
		{
			flags |= SDL_WINDOW_FULLSCREEN;
		}

		if (window_config.child("borderless").child_value() == "true")
		{
			flags |= SDL_WINDOW_BORDERLESS;
		}

		if (window_config.child("resizable").child_value() == "true")
		{
			flags |= SDL_WINDOW_RESIZABLE;
		}

		if (window_config.child("fullscreen_windowed").child_value() == "true")
		{
			flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
		}

		window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);

		if(window == NULL)
		{
			LOG("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			ret = false;
		}
		else
		{
			//Get window surface
			screen_surface = SDL_GetWindowSurface(window);
			SetTitle(window_config.child("name").child_value());
		}
	}

	return ret;
}

// Called before quitting
bool j1Window::CleanUp()
{
	LOG("Destroying SDL window and quitting all SDL systems");

	//Destroy window
	if(window != NULL)
	{
		SDL_DestroyWindow(window);
	}

	//Quit SDL subsystems
	SDL_Quit();
	return true;
}

// Set new window title
void j1Window::SetTitle(const char* new_title)
{
	//title.create(new_title);
	SDL_SetWindowTitle(window, new_title);
}

void j1Window::GetWindowSize(uint& width, uint& height) const
{
	width = this->width;
	height = this->height;
}

uint j1Window::GetScale() const
{
	return scale;
}