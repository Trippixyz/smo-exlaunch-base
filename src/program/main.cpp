#include "al/Library/Controller/JoyPadUtil.h"
#include "al/Library/Memory/MemorySystem.h"
#include "al/Library/Sequence/Sequence.h"
#include "diag/assert.hpp"
#include "heap/seadExpHeap.h"
#include "heap/seadHeapMgr.h"
#include "hook/trampoline.hpp"
#include "imgui.h"
#include "lib.hpp"
#include "nn/fs.h"
#include "program/imgui_nvn.h"
#include <sead/filedevice/seadFileDeviceMgr.h>

static void drawDbgGui()
{
    ImGui::GetIO().FontGlobalScale = .5;

    ImGui::Text("Hello World!");
}

HOOK_DEFINE_REPLACE(DisableATrigger) {
    static bool Callback(s32 port) {
        return false;
    }
};

extern "C" void exl_main(void* x0, void* x1)
{
    exl::hook::Initialize();

    nvnImGui::InstallHooks();
    nvnImGui::addDrawFunc(drawDbgGui);
}

extern "C" NORETURN void exl_exception_entry()
{
    /* TODO: exception handling */
    EXL_ABORT(0x420);
}
