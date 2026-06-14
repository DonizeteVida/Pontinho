#pragma once

#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

#include "WidgetContext.hpp"
#include "Widget.hpp"

namespace Pontinho
{
    class ContainerWidget : public Widget
    {
    public:
        ContainerWidget(int width = 0, int height = 0)
        {
            YGNodeStyleSetFlexGrow(node, 1.0f);
        }

        void AddChild(std::unique_ptr<Widget> &widget)
        {
            children.push_back(std::move(widget));
        }

        void Draw(sf::RenderTarget &target) override
        {
            for (const auto &child : children)
            {
                child->Draw(target);
            }
        }

        void SetWidth(int width) const
        {
            YGNodeStyleSetWidth(node, width);
        }

        void SetHeight(int height) const
        {
            YGNodeStyleSetHeight(node, height);
        }

    private:
        std::vector<std::unique_ptr<Widget>> children;
    };

    template <typename ContainerType, typename... Args>
    static void CreateContainer(
        std::function<void()> content,
        Args... args)
    {
        std::unique_ptr<Widget> container = std::make_unique<ContainerType>(args...);

        auto parent = Pontinho::WidgetContext::Context<ContainerWidget>();
        Pontinho::WidgetContext::AttachToParent(parent->node, container->node);
        Pontinho::WidgetContext::PushParent(container->node);

        parent->AddChild(container);
        content();
        Pontinho::WidgetContext::PopParent();
    }
};