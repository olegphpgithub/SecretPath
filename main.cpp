#include "stdafx.h"
#include "SecretPath.h"


int _tmain(int argc, _TCHAR* argv[])
{
    TCHAR lptsc_path[MAX_PATH];
    if( GetModuleFileName(NULL, lptsc_path, MAX_PATH) ) {

        bool ok = SecretPath::ValidateSecretPath(lptsc_path);
        if(ok) {
            _tprintf_s(TEXT("valid\n"));
        } else {
            _tprintf_s(TEXT("is not valid\n"));
        }

    }

    return 0;
}
