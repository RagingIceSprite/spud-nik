#include "PotatoModule.h"

DEFINE_LOG_CATEGORY(PotatoModule)

#define LOCTEXT_NAMESPACE "FPotatoModule"

void FPotatoModule::StartupModule()
{
	UE_LOG(PotatoModule, Warning, TEXT("CLAY HANDS Potato Module Planted!"))
}

void FPotatoModule::ShutdownModule()
{
	UE_LOG(PotatoModule, Warning, TEXT("CLAY HANDS Potato Module Uprooted."))
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPotatoModule, PotatoModule)