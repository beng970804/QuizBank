//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT list: Link-based implementation.
    Listing 9-2.
    @file LList.h */

#ifndef _LLIST
#define _LLIST

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class LList : public ListInterface<ItemType>
{
private:
   Node<ItemType>* headPtr; // Pointer to first node in the chain;
                            // (contains the first entry in the list)
   int itemCount;           // Current count of list items

   // Locates a specified node in this linked list.
   // @pre  position is the number of the desired node;
   //       position >= 1 and position <= itemCount.
   // @post  The node is found and a pointer to it is returned.
   // @param position  The number of the node to locate.
   // @return  A pointer to the node at the given position.
   Node<ItemType>* getNodeAt(int position) const;

public:
   LList();
   LList(const LList<ItemType>& aList);
   virtual ~LList();

   bool isEmpty() const;
   int getLength() const;
   bool insert(int newPosition, const ItemType& newEntry);
   bool erase(int position);
   void clear();

   /** @throw PrecondViolatedExcep if position < 1 or
                                      position > getLength(). */
   ItemType retrieve(int position) const throw(PrecondViolatedExcep);

   /** @throw PrecondViolatedExcep if position < 1 or
                                      position > getLength(). */
   void setEntry(int position, const ItemType& newEntry)
                               throw(PrecondViolatedExcep);

   /** The following functions are added by Alfred Loo on 10/02/2017*/

       /**Sort insert the given object with descending order*/
       void sortedInsertDesc(const ItemType& newEntry);

       /**Randomize the order of question*/
       void randomize();

   /**edit done*/

}; // end LList

#include "LList.cpp"
#endif
