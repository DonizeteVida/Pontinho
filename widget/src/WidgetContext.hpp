#pragma once

#include <vector>

#include <yoga/Yoga.h>

namespace Pontinho
{
    class WidgetContext
    {
    public:
        inline static std::vector<YGNodeRef> stack;

        static YGNodeRef Get()
        {
            return stack.back();
        }

        template <typename T>
        static T *Context()
        {
            return (T *)YGNodeGetContext(stack.back());
        }

        static void PushParent(YGNodeRef node)
        {
            stack.push_back(node);
        }

        static void PopParent()
        {
            stack.pop_back();
        }

        static inline void AttachToParent(YGNodeRef parent, YGNodeRef child)
        {
            YGNodeInsertChild(parent, child, YGNodeGetChildCount(parent));
        }
    };
}