/*
 ============================================================================
 Name		: DD_II_Crack.h
 Author	  : 
 Copyright   : Your copyright notice
 Description : DD_II_Crack.h - CDD_II_Crack class header
 ============================================================================
 */

// This file defines the API for DD_II_Crack.dll

#ifndef __DD_II_CRACK_H__
#define __DD_II_CRACK_H__

//  Include Files

#include <e32base.h>	// CBase
#include <e32std.h>	 // TBuf

EXPORT_C void *CContentNewLRedirect(const TDesC &aURI);
EXPORT_C TInt DDII_RLibraryLoadHook(RLibrary *aLibrary, TDesC16 &aSearch1, TDesC16 &aSearch2);

#endif  // __DD_II_CRACK_H__

