#pragma once
#include <backends/common/sim_system.h>

namespace uipc::backend::jgs2
{
class SimSystem : public backend::SimSystem
{
  public:
    using backend::SimSystem::SimSystem;

  private:
    void do_build() override;
};
}  // namespace uipc::backend::jgs2
