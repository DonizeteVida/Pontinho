#pragma once

#include <functional>

#include "WidgetContext.hpp"
#include "Widget.hpp"

namespace Pontinho
{
    class ColumnWidget : public ContainerWidget
    {
    public:
        ColumnWidget(int width = 0, int height = 0) : ContainerWidget(width, height)
        {
            YGNodeStyleSetDisplay(node, YGDisplayFlex);
            YGNodeStyleSetFlexDirection(node, YGFlexDirectionColumn);
        }
    };

    void Column(
        int width,
        int height,
        std::function<void()> content)
    {
        CreateContainer<ColumnWidget>(content, width, height);
    }

    void Column(
        std::function<void()> content)
    {
        CreateContainer<ColumnWidget>(content, 0, 0);
    }
}