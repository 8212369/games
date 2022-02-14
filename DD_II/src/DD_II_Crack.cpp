/*
 ============================================================================
 Name		: DD_II_Crack.cpp
 Author	  : 
 Copyright   : Your copyright notice
 Description : CDD_II_Crack DLL source
 ============================================================================
 */

//  Include Files  

#include "DD_II_Crack.h"
#include <caf/content.h>

int accessCount = 0;

//  Member Functions
EXPORT_C void *CContentNewLRedirect(const TDesC &aURI) {    
    TBuf<256> path;
    path.Copy(aURI);
    
    if (path.Find(_L("protected_general.opes.ngdat")) != -1) {
        TPtrC16 relative = path.Left(path.Length() - 28);
        path.Copy(relative);
        path.Append(_L("bin\\protected_general.opes.ngdat"));
    }
    
    TBuf<4> asDeactCmd;
    TBool needLaunchAsDeact = EFalse;
    
    if (accessCount == 5) {
        asDeactCmd.Copy(_L("P"));
        needLaunchAsDeact = ETrue;
    } else if (accessCount == 10) {
        asDeactCmd.Copy(_L("R"));
        needLaunchAsDeact = ETrue;
    }
    
    if (needLaunchAsDeact) {
        RProcess modProcess;
        modProcess.Create(_L("AS_2001AD86.exe"), asDeactCmd);
        modProcess.Resume();
        modProcess.Close();
    }
    
    ++accessCount;
    return ContentAccess::CContent::NewL(path);
}

EXPORT_C TInt DDII_RLibraryLoadHook(RLibrary *aLibrary, TDesC16 &aSearch1, TDesC16 &aSearch2) {
    if (aSearch1.Compare(_L("ngifileaccess.dll")) == 0) {
        return aLibrary->Load(_L("DD_II_FileAccess.dll"));
    }
    
    return aLibrary->Load(aSearch1, aSearch2);
}
