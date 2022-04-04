#include "library.h"

template <typename T>

uint max (uint x, uint y){ return x > y ? x : y; }

void ArrayList<T>::ResizeCheck (uint target){
	while (target >= currentSize){
		currentSize *= PHI;
		array = reallocarray(array, currentSize, sizeof(T));
	}
	while (target * PHI < currentSize){
		currentSize /= PHI;
		array = reallocarray(array, currentSize, sizeof(T));
	}
}

ArrayList<T>::ArrayList (){ array = (T *)std::calloc(currentSize, sizeof(T)); }

void ArrayList<T>::Free (){ free(array); }

void ArrayList<T>::Free (void (free_func) (void *)){
	for (uint i = 0; i < length; i++){
		free_func(array[i]);
	}
	free(array);
}

uint ArrayList<T>::Length (){ return length; }

T ArrayList<T>::GetAt (uint index){
	assert(0 <= index and index < length);
	return array[index];
}

void ArrayList<T>::SetAt (uint index, T value){
	assert(index >= 0);
	new_length = max(length++, index);
	ResizeCheck(new_length);
	array[index] = value;
	length = new_length;
}

void ArrayList<T>::InsertAt (uint index, T value){
	assert(index >= 0);
	new_length = max(length++, index);
	ResizeCheck(new_length);
	for (uint i = length; i > index; i--){ array[i] = array[i - 1]; }
	SetAt(index, value);
}

void ArrayList<T>::Add (T value){ SetAt(length, value); }

void ArrayList<T>::Remove (){
	length -= 1;
	ResizeCheck();
}

void ArrayList<T>::RemoveAt (uint index){
	for (uint i = index; i > length; i++){ array[i] = array[i + 1]; }
	Remove();
}