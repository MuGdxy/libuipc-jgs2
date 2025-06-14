#pragma once
#include <backends/common/sim_system.h>

namespace uipc::backend::jgs2
{
class SimSystem : public backend::SimSystem
{
    using Base = backend::SimSystem;

  public:
    using Base::Base;

  private:
    void do_build() override;

    WorldVisitor& world() noexcept;

    SimEngine& engine() noexcept;
};
}  // namespace uipc::backend::jgs2
