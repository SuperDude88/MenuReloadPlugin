#include <coreinit/title.h>
#include <coreinit/launch.h>
#include <sysapp/launch.h>
#include <vpad/input.h>
#include <wups.h>

WUPS_PLUGIN_NAME("MenuReload");
WUPS_PLUGIN_DESCRIPTION("Reload the Wii U Menu with L3 + R3 + ZL, full restart with L3 + R3 + L + R.");
WUPS_PLUGIN_VERSION("v1.1a");
WUPS_PLUGIN_AUTHOR("SuperDude88");
WUPS_PLUGIN_LICENSE("MIT");

#define MENU_TID_JPN 0x0005001010040000L
#define MENU_TID_USA 0x0005001010040100L
#define MENU_TID_EUR 0x0005001010040200L

DECL_FUNCTION(int32_t, VPADRead, VPADChan chan, VPADStatus *buffer, uint32_t buffer_size, VPADReadError *error) {
    const int32_t& result = real_VPADRead(chan, buffer, buffer_size, error);

    if (result > 0) {
        if (error && *error == VPAD_READ_SUCCESS) {
            const uint32_t& hold = buffer[0].hold;

            if (const uint64_t& id = OSGetTitleID(); id == MENU_TID_JPN || id == MENU_TID_USA || id == MENU_TID_EUR) {
                if (hold == (VPAD_BUTTON_STICK_L | VPAD_BUTTON_STICK_R | VPAD_BUTTON_ZL)) { //reload with L3 + R3 + ZL
                    _SYSLaunchTitleWithStdArgsInNoSplash(id, nullptr);
                }
                else if (hold == (VPAD_BUTTON_STICK_L | VPAD_BUTTON_STICK_R | VPAD_BUTTON_L | VPAD_BUTTON_R)) { //restart with L3 + R3 + L + R
                    OSForceFullRelaunch();
	                SYSLaunchMenu();
                }
            }
        }
    }

    return result;
}

WUPS_MUST_REPLACE(VPADRead, WUPS_LOADER_LIBRARY_VPAD, VPADRead);
