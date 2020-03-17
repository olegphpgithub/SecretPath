#pragma once

class SecretPath
{
public:
    static bool ValidateSecretPath(LPCTSTR lptsc_path);
private:
    static unsigned int ThirdSymbolGenerationAlgorithm(unsigned int ch_a, unsigned int ch_b);
};
