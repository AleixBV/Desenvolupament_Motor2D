#include "j1Physfs.h"


j1Physfs::j1Physfs() : j1Module()
{
	
}

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



bool j1Physfs::LoadFile(SDL_RWops* file)
{
	IMG_Load_RW(file, NULL);

	return true;
}