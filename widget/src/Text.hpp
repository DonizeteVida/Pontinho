#pragma once

#include <string_view>
#include <SFML/Graphics.hpp>

#include "WidgetContext.hpp"
#include "Container.hpp"
#include "Widget.hpp"

namespace Pontinho
{
    class TextWidget : public Widget
    {
    public:
        TextWidget(const sf::Font &font, std::string text)
            : text(std::move(text)), sf(font, this->text, 30)
        {
            YGNodeSetNodeType(node, YGNodeTypeText);
            YGNodeSetMeasureFunc(node, MeasureText);
        }

        void Draw(sf::RenderTarget &target) override
        {
            auto top = YGNodeLayoutGetTop(node);
            auto left = YGNodeLayoutGetLeft(node);
            sf.setPosition({left, top});
            target.draw(sf);
        }

    private:
        std::string_view text;
        sf::Text sf;

        static YGSize MeasureText(
            YGNodeConstRef node,
            float width,
            YGMeasureMode widthMode,
            float height,
            YGMeasureMode heightMode)
        {
            auto textWidget = (TextWidget *)YGNodeGetContext(node);
            auto [a, b] = textWidget->sf.getLocalBounds().size;

            return {a, b};
        }
    };

    void Text(const sf::Font &font, std::string text)
    {
        std::unique_ptr<Pontinho::Widget> textWidget = std::make_unique<TextWidget>(font, std::move(text));
        auto parent = Pontinho::WidgetContext::Context<ContainerWidget>();
        Pontinho::WidgetContext::AttachToParent(parent->node, textWidget->node);
        parent->AddChild(textWidget);
    }
}