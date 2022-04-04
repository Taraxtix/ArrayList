#ifndef ARRAYLIST_LIBRARY_H
#define ARRAYLIST_LIBRARY_H

#include <stdlib.h>
#include <assert.h>

#define PHI 1.6
typedef unsigned int uint;

uint max(uint x, uint y);

template<typename T>
class ArrayList {
private:
    uint length{0};
    uint currentSize{10};
    T *array;

    void ResizeCheck(uint target);

public:
    /**
     * @brief Create an ArrayList which can store the type given between the angle brackets
     * @details The array need to be freed after it's no longer used, using YourArrayList.Free();
     * or YourArrayList.Free(anyFreeFunction); if you want to use on every element the given
     * function before freeing the array
     */
    ArrayList<T>();

    /**
     * @brief Free the ArrayList
     */
    void Free();

    /**
     * @details free the array but first apply the given free function to the whole list;
     * @param free_func
     */
    void Free(void (free_func)(void *));

    /**
     * @brief Returns the length of the array
     */
    uint Length();

    /**
     * @brief Returns the value at the given index
     */
    T GetAt(uint index);

    /**
     * @brief Set the value at the given index with the given value
     */
    void SetAt(uint index, T value);

    /**
     * @brief Insert the given value at the given index
     * @details Inserting a value will shift all the value at the given index and more to the right
     * @param index The index where the value will be
     * @param value The value you want to put in
     */
    void InsertAt(uint index, T value);

    /**
     * @brief Adds the given value at the end of the list;
     */
    void Add(T value);

    /**
     * @brief Removes the last element of the list
     */
    void Remove();

    /**
     * @brief Remove the value at the given index and shift the rest of the value to the left
     * @param index The index to remove
     */
    void RemoveAt(uint index);

		//TODO: ADD BOTH FREE VERSION OF THE REMOVES FUNCTIONS
};

#endif //ARRAYLIST_LIBRARY_H
