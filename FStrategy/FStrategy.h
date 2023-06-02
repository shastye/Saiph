// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the FStrategy_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// FStrategy_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#define FSTRATEGY_API __declspec(dllexport)

#include "..\\Model\IDeflectionStrategy.h"

class FStrategy : public IDeflectionStrategy {
public:
	void Deflect(float& bulletHeading);
	void Destroy();

	FSTRATEGY_API IDeflectionStrategy* CreateStrategy();
};

//extern FStrategy_API int nFStrategy;
//
//FStrategy_API int fnFStrategy(void);
