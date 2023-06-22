#pragma comment(lib, "../SDK/lib/bedrock_server_api.lib")
#pragma comment(lib, "../SDK/lib/bedrock_server_var.lib")
#pragma comment(lib, "../SDK/lib/SymDBHelper.lib")
#pragma comment(lib, "../SDK/lib/LiteLoader.lib")

#include <llapi/HookAPI.h>
#include <llapi/mc/Mob.hpp>
#include <llapi/mc/ActorDamageSource.hpp>
#include <llapi/mc/Actor.hpp>
#include <llapi/mc/Vec3.hpp>
#include <llapi/mc/ExperienceOrb.hpp>

TInstanceHook(void, "?die@Mob@@UEAAXAEBVActorDamageSource@@@Z", Mob, ActorDamageSource const& a2) {
    original(this, a2);
    if (getIsExperienceDropEnabled())
    {
        int v5 = hasCategory(ActorCategory::Player) + 2;
        int v6 = getOnDeathExperience();
        Vec3 v7 = getPos();
        BlockSource* DimensionBlockSourceConst = getBlockSource();
        ExperienceOrb::spawnOrbs(*DimensionBlockSourceConst, v7, v6, (ExperienceOrb::DropType)v5, nullptr);
        setIsExperienceDropEnabled(false);
    }
}
