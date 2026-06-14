#pragma once

#include <functional>

#include "WidgetContext.hpp"
#include "Widget.hpp"

namespace Pontinho
{
    class RowWidget : public ContainerWidget
    {
    public:
        RowWidget(int width = 0, int height = 0) : ContainerWidget(width, height)
        {
            YGNodeStyleSetDisplay(node, YGDisplayFlex);
            YGNodeStyleSetFlexDirection(node, YGFlexDirectionRow);
        }
    };

    void Row(
        int width,
        int height,
        std::function<void()> content)
    {
        CreateContainer<RowWidget>(content, width, height);
    }

    void Row(
        std::function<void()> content)
    {
        CreateContainer<RowWidget>(content, 0, 0);
    }
}