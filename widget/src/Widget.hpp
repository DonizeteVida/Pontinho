#pragma once

#include <yoga/Yoga.h>

namespace Pontinho
{
    class Widget
    {
    public:
        Widget()
        {
            node = YGNodeNew();
            YGNodeSetContext(node, this);
        }
        ~Widget()
        {
            YGNodeFree(node);
        }

        virtual void Draw(::sf::RenderTarget &target) = 0;
    public:
        YGNodeRef node;
    };
}