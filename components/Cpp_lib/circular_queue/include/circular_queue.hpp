#include <iostream>

namespace cpp_lib
{
    template <typename T, size_t S>
    class c_que
    {
    private:
        T *_mem{};
        size_t _cap{};

        size_t _head{};
        size_t _tail{};

    public:
        c_que() : _mem(NULL), _cap(S)
        {
            /* allocate the static array */
            _mem = (T *)malloc(sizeof(T) * _cap);
        }

        /**
         * @brief Enqueue data to circular queue 
         */
        void enqueue(const T& data)
        {
            /* if queue is full then throw exception */
            if(_sz == _cap) {
                throw std::out_of_range("Circular queue is full.");
            }

            /* add to buffer */
            

        }

        void dequeue()
        {
        }

        T& peek()
        {

        }
    };
}