//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class LList.
 @file LList.cpp */

#include "LList.h"  // Header file
#include <cassert>
#include <ctime>
#include <cstdlib>

template<class ItemType>
LList<ItemType>::LList() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LList<ItemType>::LList(const LList<ItemType>& aList) : itemCount(aList.itemCount)
{
   Node<ItemType>* origChainPtr = aList.headPtr;  // Points to nodes in original chain

   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original list is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());

      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();

         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);

         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();

         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while

      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LList<ItemType>::~LList()
{
   clear();
}  // end destructor

template<class ItemType>
bool LList<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LList<ItemType>::getLength() const
{
   return itemCount;
}  // end getLength

template<class ItemType>
bool LList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
   if (ableToInsert)
   {
      // Create a new node containing the new entry
      Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

      // Attach new node to chain
      if (newPosition == 1)
      {
         // Insert new node at beginning of chain
         newNodePtr->setNext(headPtr);
         headPtr = newNodePtr;
      }
      else
      {
         // Find node that will be before new node
         Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

         // Insert new node after node to which prevPtr points
         newNodePtr->setNext(prevPtr->getNext());
         prevPtr->setNext(newNodePtr);
      }  // end if

      itemCount++;  // Increase count of entries
   }  // end if

   return ableToInsert;
}  // end insert

template<class ItemType>
bool LList<ItemType>::erase(int position)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
   {
      Node<ItemType>* curPtr = nullptr;
      if (position == 1)
      {
         // Remove the first node in the chain
         curPtr = headPtr; // Save pointer to node
         headPtr = headPtr->getNext();
      }
      else
      {
         // Find node that is before the one to delete
         Node<ItemType>* prevPtr = getNodeAt(position - 1);

         // Point to node to delete
         curPtr = prevPtr->getNext();

         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prevPtr->setNext(curPtr->getNext());
      }  // end if

      // Return node to system
      curPtr->setNext(nullptr);
      delete curPtr;
      curPtr = nullptr;

      itemCount--;  // Decrease count of entries
   }  // end if

   return ableToRemove;
}  // end remove

template<class ItemType>
void LList<ItemType>::clear()
{
   while (!isEmpty())
      erase(1);
}  // end clear

template<class ItemType>
ItemType LList<ItemType>::retrieve(int position) const throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
   else
   {
      string message = "retrieve() called with an empty list or ";
      message  = message + "invalid position.";
      throw(PrecondViolatedExcep(message));
   }  // end if
}  // end getEntry

template<class ItemType>
void LList<ItemType>::setEntry(int position, const ItemType& newEntry) throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToSet = (position >= 1) && (position <= itemCount);
   if (ableToSet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
      nodePtr->setItem(newEntry);
   }
   else
   {
      string message = "setEntry() called with an invalid position.";
      throw(PrecondViolatedExcep(message));
   }  // end if
}  // end setEntry

template<class ItemType>
Node<ItemType>* LList<ItemType>::getNodeAt(int position) const
{
   // Debugging check of precondition
   assert( (position >= 1) && (position <= itemCount) );

   // Count from the beginning of the chain
   Node<ItemType>* curPtr = headPtr;
   for (int skip = 1; skip < position; skip++)
      curPtr = curPtr->getNext();

   return curPtr;
}  // end getNodeAt

/** The following functions are added by Alfred Loo on 10/02/2017*/
    template<class ItemType>
    void LList<ItemType>::sortedInsertDesc(const ItemType& newEntry)
    {
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
        if(itemCount==0)
        {
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
            itemCount++;
        }
        else{
            Node<ItemType>* curPtr;
            Node<ItemType>* prevPtr = headPtr;
            int counter =1;
            while(counter<=itemCount)
            {
                curPtr=prevPtr->getNext();
                if(newEntry>=headPtr->getItem())
                {
                    newNodePtr->setNext(headPtr);
                    headPtr = newNodePtr;
                    itemCount++;
                    break;
                }
                else if(curPtr!=nullptr)
                {
                    if(newEntry<=prevPtr->getItem()&&newEntry>=curPtr->getItem())
                    {
                        newNodePtr->setNext(curPtr);
                        prevPtr->setNext(newNodePtr);
                        itemCount++;
                        break;
                    }
                }
                else if(curPtr==nullptr){
                    if(newEntry<=prevPtr->getItem())
                    {
                        prevPtr->setNext(newNodePtr);
                        newNodePtr->setNext(nullptr);
                        itemCount++;
                        break;
                    }
                }
                prevPtr = prevPtr->getNext();
                counter++;
            }
        }
    }

    template<class ItemType>
    void LList<ItemType>::randomize()
    {
        srand(time(NULL));
        int counter = 0;
        while (counter < itemCount)
        {
            int initialPos = counter + 1;
            Node<ItemType>* temp = getNodeAt(initialPos);
            Node<ItemType>* nodeToInsert = new Node<ItemType>(temp->getItem());
            int rand_pos = rand() %(itemCount) + 1;
            erase(initialPos);
            insert(rand_pos,nodeToInsert->getItem());
            counter++;
        }
    }
/**edit done*/
//  End of implementation file.
