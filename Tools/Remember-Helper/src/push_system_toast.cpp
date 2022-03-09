#ifndef PSToast_H_
#define PSToast_H_
#if defined(_WIN32) && defined(_USE_TOAST)
#include "push_system.hpp"

void EW_Show(EnglishWord &data, PushSystem &PS)
{
}

void CP_Show(ChinesePoem &data, PushSystem &PS)
{
}

void NONE_Show(RememberData &data, PushSystem &PS)
{
}

void ERROR_Show(std::string &message, PushSystem &PS)
{
}

#endif
#endif