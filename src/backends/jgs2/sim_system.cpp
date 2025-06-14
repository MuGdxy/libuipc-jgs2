#include <sim_system.h>

namespace uipc::backend::jgs2
{
REGISTER_SIM_SYSTEM(SimSystem);

void SimSystem::do_build()
{
    spdlog::info("[NoneEngine] NoneSimSystem call do_build()");
}

SimEngine& SimSystem::engine() noexcept
{
    return static_cast<SimEngine&>(Base::engine());
}

WorldVisitor& SimSystem::world() noexcept
{
    return engine().world();
}
}  // namespace uipc::backend::jgs2
