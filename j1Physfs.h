#ifndef _PHYSFS_
#define _PHYSFS_

#include "j1Module.h"
#include "p2Log.h"


#include "SDL/include/SDL.h"

#include "SDL_image/include/SDL_image.h"
#pragma comment( lib, "SDL_image/libx86/SDL2_image.lib" )
#include "PhysFS/include/physfs.h"
#pragma comment( lib, "PhysFS/libx86/physfs.lib" )


class j1Physfs : public j1Module
{
public:
	j1Physfs();


	// Destructor
	virtual ~j1Physfs();


	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before quitting
	bool CleanUp();
	

	// Called for load files
	bool LoadFile(SDL_RWops* file);
};

#endif