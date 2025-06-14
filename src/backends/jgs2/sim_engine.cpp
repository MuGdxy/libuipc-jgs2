#include <sim_engine.h>
#include <backends/common/module.h>
#include <uipc/common/log.h>
#include <sim_system.h>

namespace uipc::backend::jgs2
{
SimEngine::SimEngine(EngineCreateInfo* info)
    : uipc::backend::SimEngine(info)
{
    spdlog::info("[NoneEngine] Constructor called.");
    spdlog::info(R"(Hello, this is the JGS2Engine from libuipc backends.
Now, this engine does nothing, but helps to do the checking of the engine interface.
And it is a good place to print out some debug information during the life cycle of the engine.
)");
}

void SimEngine::do_init(InitInfo& info)
{
    spdlog::info("[NoneEngine] do_init() called.");

    build_systems();

    m_system = &require<SimSystem>();

    dump_system_info();
}

void SimEngine::do_advance()
{
    m_frame++;
    spdlog::info("[NoneEngine] do_advance() called.");
}

void SimEngine::do_sync()
{
    spdlog::info("[NoneEngine] do_sync() called.");
}

void SimEngine::do_retrieve()
{
    spdlog::info("[NoneEngine] do_receive() called.");
}

SimEngine::~SimEngine()
{
    spdlog::info("[NoneEngine] Destructor called.");
}


SizeT SimEngine::get_frame() const
{
    return m_frame;
}
bool SimEngine::do_dump(DumpInfo&)
{
    // Now just do nothing
    return true;
}

void SimEngine::do_backward()
{
    // Do nothing
}

bool SimEngine::do_try_recover(RecoverInfo&)
{
    // Now just do nothing
    return true;
}

void SimEngine::do_apply_recover(RecoverInfo& info)
{
    // If success, set the current frame to the recovered frame
    m_frame = info.frame();
}

void SimEngine::do_clear_recover(RecoverInfo& info)
{
    // If failed, do nothing
}
}  // namespace uipc::backend::jgs2


UIPC_BACKEND_API EngineInterface* uipc_create_engine(EngineCreateInfo* info)
{
    return new uipc::backend::jgs2::SimEngine(info);
}

UIPC_BACKEND_API void uipc_destroy_engine(EngineInterface* engine)
{
    delete engine;
}
