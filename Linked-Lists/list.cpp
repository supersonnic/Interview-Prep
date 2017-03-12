/********************************************************************************
 * Shervin Oloumi
 * list.cpp
 * This file includes the implementation of all the functions declared in list.h
 *******************************************************************************/

/* This program uses code from "Algorithms in C, Third Edition,"
 *               by Robert Sedgewick, Addison-Wesley, 1998.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* This code uses C++ features: function overload by specifying default values 
 * for the last parameter in the function declaration in the header file, list.h:
 *        link newLink(Item value, link next_in = 0)
 */

struct node_struct {
    Item item;
    link next;
};

struct list_struct {
    link first;
    int length;    
};

// ------------- link functions

/* Creates a new link, that contains the value specified in the argument, 
 * and that points to next_in. 
 * C++ feature: because of:  "link next_in = NULL" in the header file,
 * we will be able to call this method both ways:
 *      newLink(5);
 *      newLink(5, some_ptr);
 */
link newLink(Item value, link next_in) {
    link result = (link) malloc(sizeof (struct node_struct));
    result->item = value;
    result->next = next_in;
    return result;
}

void destroyLink(link the_link)  {
    if (the_link != NULL) {
    	
        free(the_link);
        
    }
}

Item getLinkItem(link the_link) {
    if (the_link != NULL) {
        return the_link->item;    
    }
    else {
        printf("\n getLinkItem: Empty link. Returned -1.");
        return -1;    // NOTE: This line can be improved.
    }
}

link getLinkNext(link the_link) {
    if (the_link != NULL) {
        return the_link->next;
    }
    else {
        return NULL;
    }
}

void setLinkItem(link the_link, Item value) {
    if (the_link != NULL) {
        the_link->item = value;
    }
}

void setLinkNext(link the_link, link next) {
    if (the_link != NULL) {
        the_link->next = next;
    }
}


/*    --------  LIST functions    */

int listIsNULL(list the_list) {
    if (the_list == NULL) {
        printf("\nThe list pointer is NULL)\n");
        return 1;
    }     
    else {
        return 0;
    }    
}

/* Creates and returns an empty list. */
list newList() {
    list result = (list) malloc(sizeof (*result));
    result->first = NULL;
    result->length = 0;
    return result;
}

/* Deallocates memory for all nodes in the list and the list object itself. */
void destroyList(list the_list) {
    if (listIsNULL(the_list) == 1) {        
        return;
    }
    
    link current = the_list->first;
    while (1) {
        if (current == NULL) {
            break;
        }

        link next = current->next;
        destroyLink(current);
        current = next;
    }
    free(the_list);
}

link getFirst(list the_list) {
    if (listIsNULL(the_list) == 1) {        
        return NULL;
    }
    
    return the_list->first;
}

int getLength(list the_list) {
    if (listIsNULL(the_list) == 1) {        
        return -1;
    }
    
    return the_list->length;
}

/* Sets the data to empty (first is null, length is 0,...)
 * It does NOT free any memory.
 */ 
void setEmpty(list the_list) {
    the_list->first = NULL;    
    the_list->length = 0;
}

/* Inserts new_link to the specified list, at the position right after
 * the link called "previous". */
void insertLink(list my_list, link previous, link new_link) {
    if (listIsNULL(my_list) == 1) {        
        return;
    }    
    
    /* We need a special case when we want to insert to the beginning.
     * In that case, the previous link is NULL. */
    if (previous == NULL) {
        new_link->next = my_list->first;
        my_list->first = new_link;
    } else {
        new_link->next = previous->next;
        previous->next = new_link;
    }
    
    my_list->length += 1;
}

/* Inserts new_link to the beginning of the list. */
void insertAtBeginning(list my_list, link new_link) {
    setLinkNext(new_link, getFirst(my_list));  // replaces: new_link->next = my_list->first;
    my_list->first = new_link;
    my_list->length += 1;
}

/* Removes from the list and returns the link coming AFTER link x. 
 * This function DOES NOT remove link x itself. 
 */
link removeNext(list my_list, link x) {
    if (listIsNULL(my_list) == 1) {        
        return NULL;
    }     
    
    link temp;
    if (x == NULL) // try to delete the first node
    {
        temp = my_list->first;
        if (my_list->first != NULL) // There is at least one node in the list.
        {
            my_list->first = my_list->first->next;
            my_list->length -= 1;
        }
    } else {
        temp = x->next;
        x->next = x->next->next; 
        my_list->length -= 1;
    }
    return temp;
}

/* Removes from the list and returns the link at the beginning of the list.
It does not free the memory for that node. */
link removeFirst(list my_list) {
    if (listIsNULL(my_list) == 1) {        
        return NULL;
    }    
    
    link first_node = my_list->first;
    if (first_node != NULL) {
        my_list->first = first_node->next;
        my_list->length -= 1;
    }
    return first_node;
}

void reverse(list the_list) {
    if (listIsNULL(the_list) == 1) {        
        return;
    }    
    
    link current = the_list->first;
    link previous = NULL;
    while (current != NULL) {
        link temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }
    the_list->first = previous;
}

void printList(list my_list) {
    if (listIsNULL(my_list) == 1) {        
        return;
    }     
    
    int i = 0;
    int n = my_list->length;
    link curr;    
    printf("\n List length = %d\n List items:\n", my_list->length);
    for (i = 0, curr = my_list->first; (curr != NULL) && (i<n) ; curr = curr->next) {
        printf("item %d: %d\n", i, curr->item);
        i++;
    }
    printf("\n");
}

void printListHoriz(list my_list) {
    if (listIsNULL(my_list) == 1) {        
        return;
    }     

    int i = 0;
    int n = my_list->length;
    link curr;    
    printf("\n List length = %d\n List items:\n", my_list->length);
    for (i = 0, curr = my_list->first; (curr != NULL) && (i<n) ; curr = curr->next) {
        printf("%d    ", curr->item);
        i++;
    }
    printf("\n");
}

int computeLength(list my_list) {
     if (listIsNULL(my_list) == 1) {        
        return -1;
    }     
    
    int counter = 0;
    link i;
    for (i = my_list->first; i != NULL; i = i->next) {
        counter++;
    }
    return counter;
}

list listDeepCopy(list input) {    
    list result = newList();
    link in = getFirst(input);
    link previous = NULL;
    while (in != NULL) {
        link out = newLink(getLinkItem(in));
        insertLink(result, previous, out);
        previous = out;
        in = getLinkNext(in);
    }

    return result;
}

/* returns a new list that contains all values of input1 and all values 
 * of input2
 */
list concatLists(list input1, list input2) {
    list result = listDeepCopy(input1);
    list temp2 = listDeepCopy(input2);
    concatListsDestructive(result, temp2);
    free(temp2);
    return result;
}

/* Modifies target, by inserting at the end of it all links from source.  */
void concatListsDestructive(list target, list source) {
    link previous = NULL;
    link c;

    /* find the last link of target*/
    for (c = getFirst(target); c != NULL; c = getLinkNext(c)) {
        previous = c;
    }

    /* at this point, previous is the last link of target */
    setLinkNext(previous, getFirst(source));
    target->length = target->length + source->length;  // important      
    
    /* Source should not link to the moved nodes any more (when target and source 
     * lists get destroyed, each of them will attempt to free the nodes in 
     * source).
     */
    setEmpty(source);
}

/********************************************************************************
 * Additionall functions
 * Authored by Shervin Oloumi
 *******************************************************************************/

// This function inserts a node at the specified location
void insertAtPosition(list A, Item P, int pos){
	
	// Making sure list A is not and empty list and the specified position exists       
	if (listIsNULL(A) == 1 || pos >= A->length || pos < 0) {
	
    	return;
	}     
    
    /* This block is for the special case when the value 'P' is being inserted
	at position 0. */
	if (pos == 0){  
		link new_link = newLink(P);
    	insertLink(A, NULL, new_link);
        return;
	}
	
    link current = A->first, new_link;
    int count = 0;
    
    while (current->next != NULL){  // Iterating through list A to find the specified position
        
       	count++; // Utilizing the 'count' variable to keep track of the current position in list
			
        if (count == pos){ 
        	link new_link = newLink(P);  // Creating the new link with the specified value
       	    insertLink(A, current, new_link);  // Using the 'insertLink' function to insert the new_link
           	return;
		}
		current = current->next;
	}
}

// This function deletes nodes at the specified locations
void deleteOccurrences(list A, Item V) {
	
	if (listIsNULL(A) == 1) {  // Making sure that the list is not NULL
        return;
    }  
	
	/* This block is for the special case when the first element of 
	the link contains the value V. It works by deleting (and freeing) 
	the first link, as long as it's value is V */
	while (A->first->item == V){  
			removeFirst(A);
			destroyLink(A->first);
	}
	
	link current = A->first, temp;  // Setting the current link as the first link
		
	while (current->next != NULL){  // Iterating through the list (Skipping the first node)
	
		/* Following block compares the value of the next item with V
		and in case of a match, corrects the link by bypassing the next item
		and frees the next link by calling the destroyLink function for it */
		if (current->next->item == V){  
				
			temp = current->next;
			current->next = current->next->next;
			destroyLink(temp);
			A->length -= 1;  // Updating the lenght
		}
		current = current->next;
	}
	return;
}

// This function creates a sublist containing the specified items form the list
list sublist(list A, list pos_list) {
	
	     if (listIsNULL(A) == 1) {  // Making sure list A is not and empty list        
        return NULL;
    }     
    
    list sub_list = newList(); // Creating a new list to store the results in
    link i, j, current_link = NULL;
    int current;
    
    for (i = pos_list->first; i != NULL; i = i->next) {  // Iterating through the position list
    
    	current = -1;  // This resets the 'current' variable in preparation for the next loop
    	
        for (j = A->first; j != NULL; j = j->next){  // Iterating through list A to find specified positions
        
        	current++; // Utilizing the 'current' variable to keep track of the current position in list
        	
        	 /* The following checks to see if the current position in 'list A' (current) matches the current item in
        	 the position list (i->item). If so, it will create a new link with the value of the current item
        	 in list A and will add that link to the subList. Changes in 'list A' does not affect subList as
        	 it is being created independently. In addition the nodes will be naturally added in order.*/
			
        	if (i->item == current){ 
        		link next_item = newLink(j->item);
         	    insertLink(sub_list, current_link, next_item);
            	current_link = next_item;
			}
		}
    }
    
	return sub_list; // Returning the results
}

// This function moves the maximum numbers in the list to the end of the list
void moveAllMaxAtEnd(list A) {
	
	if (listIsNULL(A) == 1) {  // Making sure list A is not and empty list        
        return;
    }
	
	list max_list = newList();
	link current = A->first, i;
    int count = -1, max;
    bool is_max;
    
    while (current != NULL){  // Iterating through list A to find the specified position
    
    	count++;
    	is_max = true;
    	
    	
    	for (i = A->first; i != NULL; i = i->next){
    		
    		if (current->item < i->item){
    			is_max = false;
    			continue;
			}
    		//printf("comparing %d to %d\n",current->item,i->item);
		}
        if (is_max == true){
        	max = current->item;
        	insertLink(max_list, NULL, newLink(current->item));
		}
       	current = current->next;
       }
       deleteOccurrences(A, max);
       concatListsDestructive(A, max_list);

	return;
}

