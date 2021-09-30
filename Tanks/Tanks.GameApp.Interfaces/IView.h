#pragma once

namespace TanksGameAppInterfaces
{
    class IView
    {
    public:
        virtual ~IView() noexcept = default;
        virtual void update() = 0;
    };
}
