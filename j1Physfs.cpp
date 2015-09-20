#include "j1Physfs.h"
#include "p2Log.h"


#include "SDL/include/SDL.h"

#include "SDL_image/include/SDL_image.h"
#pragma comment( lib, "SDL_image/libx86/SDL2_image.lib" )
#include "PhysFS/include/physfs.h"
#pragma comment( lib, "PhysFS/libx86/physfs.lib" )


j1Physfs::j1Physfs() : j1Module()
{}

// Destructor
j1Physfs::~j1Physfs()
{}

bool j1Physfs::Awake()
{
	LOG("physfs init");
	PHYSFS_init(NULL);
	

	if (PHYSFS_getLastError() != 0)
	return false;

	return true;
}

bool j1Physfs::Start()
{
	LOG("physfs start");
	return true;
}

bool j1Physfs::CleanUp()
{
	LOG("deinit physfs");
	PHYSFS_deinit();
	return true;
}



/*SDL_RWops* j1Physfs::LoadFile(const char* file)
{
	//IMG_Load_RW(file);

	//return true;
}*/