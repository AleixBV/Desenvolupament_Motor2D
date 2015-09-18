#ifndef _PHYSFS_
#define _PHYSFS_

#include "j1Module.h"


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
	SDL_RWops* LoadFile(const char* file);
};

#endif