// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the GStrategy_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// GStrategy_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#define GSTRATEGY_API __declspec(dllexport)

#include "..\\Model\IDeflectionStrategy.h"

class GStrategy : public IDeflectionStrategy {
public:
	void Deflect(float& bulletHeading);
	void Destroy();

	GSTRATEGY_API IDeflectionStrategy* CreateStrategy();
};

//extern GStrategy_API int nGStrategy;
//
//GStrategy_API int fnGStrategy(void);
