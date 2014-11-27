# **Table of Context**
## `ListNode` struct

- `T` `ListNode::data` - The object data

- `ListNode<T>` `*next` - Pointer to the next Node

## `LinkedList` class

**`boolean` methods returns if succeeded**

- `LinkedList<T>::LinkedList()` - Constructor.

- `LinkedList<T>::~LinkedList()` - Destructor. Clear Nodes to minimize memory. Does not free pointer memory.

- `int` `LinkedList<T>::size()` - Returns the current size of the list.

- `bool` `LinkedList<T>::add(T)` - Add element T at the END of the list.

- `bool` `LinkedList<T>::add(int index, T)` - Add element T at `index` of the list.

- `bool` `LinkedList<T>::unshift(T)` - Add element T at the BEGINNING of the list.

- `bool` `LinkedList<T>::set(int index, T)` - Set the element at `index` to T.

- `T` `LinkedList<T>::remove(int index)` - Remove element at `index`. Return the removed element.

- `T` `LinkedList<T>::pop()` - Remove the LAST element. Return the removed element.

- `T` `LinkedList<T>::shift()` - Remove the FIRST element. Return the removed element.

- `T` `LinkedList<T>::get(int index)` - Return the element at `index`.

- `void` `LinkedList<T>::clear()` - Removes all elements. Does not free pointer memory.

- **protected** `int` `LinkedList<T>::_size` - Holds the cached size of the list.

- **protected** `ListNode<T>` `LinkedList<T>::*root` - Holds the root node of the list.

- **protected** `ListNode<T>` `LinkedList<T>::*last` - Holds the last node of the list.

- **protected** `ListNode<T>*` `LinkedList<T>::getNode(int index)` - Returns the `index` node of the list.
## **ID Class**
### Data Types
	- `String IDNumber` - ID number
	- `String IDOwner`  - The Owner of the ID
	
### Class methods
#### Constructors
	- `ID()` 										- Default Constructor
	- `ID(String arg_IDNumber, String arg_IDOwner)` - Constructor
	- `ID(String arg_IDNumber)` 					- Another Constructor only with ID 
			
#### Functions
	- `String getID()`										- Return ID
	- `String getOwner()`										- Return Owner
	- `void editID(String arg_IDNumber, String arg_IDOwner)`					- Edit ID/ Owner
	- `bool isIDBlank()`										- Check to see if ID is blank
	- `bool isOwnerBlank()`										- Check to see name(Owner) is blank
	- `void printID(HardwareSerial *serIn)` 					- Print ID/ Owner 
				
	
## **IDDatabase**
### Data Types
	- `LinkedList<ID> database` - Importing ID class to template-based linked list
	- `HardwareSerial *_Serial` - Serial/ baud rate of 
		
### Class Methods
#### Constructor
	- `IDDatabase(HardwareSerial *serIn)` 					- Serial initialization
#### Functions	
	- `void addID(String arg_IDNumber, String arg_IDOwner)` 							- Push ID/Owner
	- `ID eraseID(String arg_IDNumber)` 												- Erasing by iteration 
	- `ID eraseID(int arg_index)`														- Erasing by index
	- `void editID(string arg_searchCriteria, string arg_IDNumber, string arg_IDOwner)` - Edit ID/Owner
	- `int getSize()`																	- Size of Database
	- `bool isEmpty()`																	- Bool size
	- `void print()` 																  	- Printing All users
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
