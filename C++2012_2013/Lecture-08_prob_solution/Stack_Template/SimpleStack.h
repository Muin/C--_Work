#ifndef SIMPLESTACK_H
#define SIMPLESTACK_H

#include <vector>

template <class T>
class SimpleStack
    {
        public:
            const T& Top(void) const;
            void Pop(void);
            void Push(const T& x);

        private:
            std::vector<T> m_Array;
    };

#include <Stack.ink>

#endif // SIMPLESTACK_H
