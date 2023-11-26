
#include <stdio.h>
#include "sample_mm.h"

SH_DECL_HOOK4(IPluginHelpersCheck, CreateMessage, SH_NOATTRIB, 0, bool, const char*, edict_t*, DIALOG_TYPE, KeyValues*)

UnlockMenusPlugin g_Plugin;
IPluginHelpersCheck* check = NULL;

PLUGIN_EXPOSE(UnlockMenusPlugin, g_Plugin);
bool UnlockMenusPlugin::Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late)
{
	PLUGIN_SAVEVARS();
	GET_V_IFACE_ANY(GetServerFactory, check, IPluginHelpersCheck, INTERFACEVERSION_PLUGINHELPERSCHECK);
	if (!check) {
		META_LOG(g_PLAPI, "Couldn't get interface. Exiting!");
		return false;
	}
	SH_ADD_HOOK(IPluginHelpersCheck, CreateMessage, check, SH_MEMBER(this, &UnlockMenusPlugin::Hook_CreateMessage), false);
	return true;
}

bool UnlockMenusPlugin::Hook_CreateMessage(const char* plugin, edict_t* pEntity, DIALOG_TYPE type, KeyValues* data) {
	RETURN_META_VALUE(MRES_SUPERCEDE, true);
}

bool UnlockMenusPlugin::Unload(char *error, size_t maxlen)
{
	SH_REMOVE_HOOK(IPluginHelpersCheck, CreateMessage, check, SH_MEMBER(this, &UnlockMenusPlugin::Hook_CreateMessage), false);
	return true;
}

bool UnlockMenusPlugin::Pause(char *error, size_t maxlen)
{
	return true;
}

bool UnlockMenusPlugin::Unpause(char *error, size_t maxlen)
{
	return true;
}

const char *UnlockMenusPlugin::GetLicense()
{
	return "";
}

const char *UnlockMenusPlugin::GetVersion()
{
	return "1.0.0.0";
}

const char *UnlockMenusPlugin::GetDate()
{
	return __DATE__;
}

const char *UnlockMenusPlugin::GetLogTag()
{
	return "MENUS";
}

const char *UnlockMenusPlugin::GetAuthor()
{
	return "bt";
}

const char *UnlockMenusPlugin::GetDescription()
{
	return "Unlocks \"Valve Style\" menus for ep1/sdk2004 mods.";
}

const char *UnlockMenusPlugin::GetName()
{
	return "Menu Patch";
}

const char *UnlockMenusPlugin::GetURL()
{
	return "https://gmod9.com";
}
