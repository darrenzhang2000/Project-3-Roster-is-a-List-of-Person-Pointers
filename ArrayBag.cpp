//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

//  Modified by Tiziana Ligorio for CSCI 235 Hunter college 2019

/** Implementation file for the class ArrayBag.
 @file ArrayBag.cpp */

#include "ArrayBag.hpp"
#include <iostream>

/** default constructor**/
template<class T>
ArrayBag<T>::ArrayBag(): item_count_(0)
{
}  // end default constructor


/**
 @return item_count_ : the current size of the bag
 **/
template<class T>
int ArrayBag<T>::getCurrentSize() const
{
	return item_count_;
}  // end getCurrentSize


/**
 @return true if item_count_ == 0, false otherwise
 **/
template<class T>
bool ArrayBag<T>::isEmpty() const
{
	return item_count_ == 0;
}  // end isEmpty




/**
 @return true if an_etry was successfully removed from items_, false otherwise
 **/
template<class T>
bool ArrayBag<T>::remove(const T& an_entry)
{
   int found_index = getIndexOf(an_entry);
	bool can_remove = !isEmpty() && (found_index > -1);
	if (can_remove)
	{
		item_count_--;
		items_[found_index] = items_[item_count_];
	}  // end if
    
	return can_remove;
}  // end remove


/**
 @post item_count_ == 0
 **/
template<class T>
void ArrayBag<T>::clear()
{
	item_count_ = 0;
}  // end clear


/**
 @return the number of times an_entry is found in items_
 **/
template<class T>
int ArrayBag<T>::getFrequencyOf(const T& an_entry) const
{
   int frequency = 0;
   int cun_index = 0;       // Current array index
   while (cun_index < item_count_)
   {
      if (items_[cun_index] == an_entry)
      {
         frequency++;
      }  // end if
      
      cun_index++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf


/**
 @return true if an_etry is found in items_, false otherwise
 **/
template<class T>
bool ArrayBag<T>::contains(const T& an_entry) const
{
	return getIndexOf(an_entry) > -1;
}  // end contains


/**
 @return a vector having the same cotntents as items_
 **/
template<class T>
std::vector<T> ArrayBag<T>::toVector() const
{
   std::vector<T> bag_contents;
	for (int i = 0; i < item_count_; i++)
		bag_contents.push_back(items_[i]);
      
   return bag_contents;
}  // end toVector



template<class T>
void ArrayBag<T>::display() const{
	for(int i=0; i< item_count_; i++){
		std::cout << items_[i] << ", ";
	}
	std::cout << std::endl;
}

/**
 @return true if new_etry was successfully added to items_, false otherwise
 	 if there is a duplicate, new_entry is not added

 **/
template<class T>
bool ArrayBag<T>::add(const T& new_entry)
{
	bool has_room = (item_count_ < DEFAULT_CAPACITY);
	bool has_duplicate = false;
	for(int i=0; i<getCurrentSize() && !has_duplicate; i++){ //checks to see new_entry isn't duplicated and there is room to add 
		if(new_entry == items_[i]) {  //if new_entry is already in array
			has_duplicate = true; 
		}
	}	
	if (has_room && !has_duplicate) 
	{
		items_[item_count_] = new_entry; //sets new_entry as the last element in the array
		item_count_++;
        return true;
	}  // end if
    
	return false;
}  // end add


	/**
	@param a_bag an object of class type ArrayBag 
	@post concatenates the nonduplicate entries in a_bag to the items_ array / implicit parameter
	**/
template<class T>
void ArrayBag<T>::operator+=(const ArrayBag<T>& a_bag){ //set union
		for(int i=0; i<a_bag.getCurrentSize() && item_count_<DEFAULT_CAPACITY; i++){ //loops through every element in the second bag, and add the non duplicates
			add(a_bag.items_[i]);  
		}
}

	/**
	@param a_bag an object of class type ArrayBag
	@post removes the duplicate entries in the implicit parameter that is also in a_bag
	**/
template<class T>
void ArrayBag<T>::operator-=(const ArrayBag<T>& a_bag){ //set intersection
		for(int i=0; i<a_bag.getCurrentSize() && item_count_<DEFAULT_CAPACITY; i++){ //loops through every element in the second bag, remove the non duplicates
			if(contains(a_bag.items_[i])){
				remove(a_bag.items_[i]);
			}
		}
}


// ********* PRIVATE METHODS **************//

/**
 @param target to be found in items_
 @return either the index target in the array items_ or -1,
 if the array does not containthe target.
 **/
template<class T>
int ArrayBag<T>::	getIndexOf(const T& target) const
{
	bool found = false;
   int result = -1;
   int search_index = 0;
   
   // If the bag is empty, item_count_ is zero, so loop is skipped
   while (!found && (search_index < item_count_))
   {
      if (items_[search_index] == target)
      {
         found = true;
         result = search_index;
      } 
      else
      {
         search_index++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf