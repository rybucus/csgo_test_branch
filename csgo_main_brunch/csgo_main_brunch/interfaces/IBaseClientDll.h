#pragma once

class IBaseClientDLL {
	virtual int					GetIntersectingSurfaces(
		const void* model,
		const int& vCenter,
		const float radius,
		const bool bOnlyVisibleSurfaces,	// Only return surfaces visible to vCenter.
		void* pInfos,
		const int nMaxInfos) = 0;

};