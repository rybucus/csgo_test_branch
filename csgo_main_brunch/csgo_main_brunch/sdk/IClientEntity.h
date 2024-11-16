#pragma once
#include "../math/Vector.h"
#include <string>

class IClientEntity
{
public:
	// Delete yourself.
	virtual void			Release(void) = 0;

	// Network origin + angles
	virtual const Vector& GetAbsOrigin(void) const = 0;
	virtual const int& GetAbsAngles(void) const = 0;

	virtual void* GetMouth(void) = 0;

	// Retrieve sound spatialization info for the specified sound on this entity
	// Return false to indicate sound is not audible
	virtual bool			GetSoundSpatialization(int& info) = 0;

	virtual bool			IsBlurred(void) = 0;

	virtual std::string		GetModelName(void) const = 0;

};
