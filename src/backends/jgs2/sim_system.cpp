#include <sim_system.h>

namespace uipc::backend::jgs2
{
REGISTER_SIM_SYSTEM(SimSystem);

void SimSystem::do_build()
{
    spdlog::info("[NoneEngine] NoneSimSystem call do_build()");
}
}  // namespace uipc::backend::jgs2
