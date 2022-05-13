Data Structures for C++
=======================  
  
# About the project #
This project intends to provide a simple way of using data structures in C++. There are in-built data structures like stack and queue in C++. There are also other great github repos for this use case, but I wanted to create something simple and unique.  
<br/>  
  
# Getting Started #

## Usage ##
Compilation is not required to integrate this into another project. Simply copy the folders inside src directory to your project workspace and include the relevant header files in your source file(s).  
<br/>  

### Instantiation ### 
Data Structures exist as templates, so initialize the instance with required data type.  
**eg:**  
`SinglyLinkedList <int> sIntObj; //initialize singly linked list of type int`  
`SinglyLinkedList <std::string> sStrObj; //initialize singly linked list of type string`  
`DoublyLinkedList <int> dIntObj; //initialize doubly linked list of type int`  
`DoublyLinkedList <int> dStrObj; //initialize doubly linked list of type string`  
<br/>  

### Insert At Head ###
`InsertAtHead()` can be used to insert new data at the head of your data structure.
**eg:**  
`sIntObj.InsertAtHead(5);`  
`sStrObj.InsertAtHead("Hello");`  
<br/>  

### Insert At Tail ###  
`InsertAtTail()` can be used to insert new data at the tail of your data structure.  
**eg:**  
`sIntObj.InsertAtTail(4);`  
`sStrObj.InsertAtTail("World");`  
<br/>  

### Display the data structure ###  
`Display()` can be used to display the contents of your data structure.  
**eg:**  
`std::cout << sIntObj.Display(); << '\n'` prints:  
```sh  
5 -> 4
```  
`std::cout << sStrObj.Display(); << '\n'` prints:  
```sh  
Hello -> World
```  
__Note:__ If data structure is empty, nothing will be printed.  
<br/>  

### Display the data structure in Reverse (for Doubly Linked List) ### 
`DisplayReverse()` can be used to display the contents of your doubly linked list from tail to head.  
**eg:**  
`dIntObj.InsertAtHead(1);`  
`dIntObj.InsertAtTail(2);`  
`dIntObj.InsertAtTail(3);`  
`std::cout << sIntObj.DisplayReverse(); << '\n'` prints:  
```sh
3 <- 2 <- 1
```

__Note:__ If data structure is empty, nothing will be printed.  
<br/>  

### Delete Node containing data ###  
`Delete()` can be used to delete node(s) containing a particular data from your data.  
**eg:**  
`sIntObj.Delete(5);` deletes 5 from your data structure.  
`sStrObj.Delete("World");` deletes "World" from your data structure.  
<br/>  

If there are multiple instances of data, all nodes containing data will be deleted.  
**Before:**  
```sh
5 -> 1 -> 2 -> 1 -> 4
```
**After sIntObj.Delete(1):**  
```sh
5 -> 2 -> 4
```  
<br/>  

## Compilation  ##   
This project uses cmake build environment.  
<br/>  

### Pre-requisites: ###  
  
1. cmake
2. GNU C/C++ compiler  
  
Most linux distributions provide cmake in their own repositories. Package manager of the distro can be used for installation in most cases.  
  
On Ubuntu or Debian based systems:
```sh
sudo apt install cmake
```

On Fedora:
```sh
sudo dnf install cmake
```

On Windows:  
1. Download from website directly. [cmake Download](https://cmake.org/download/)  
2. Refer installation instructions. [cmake Install](https://cmake.org/install/)  
<br/>  

### Build Steps: ###
Below steps are required to be done only for developement purposes or to run executable or unit tests. These steps are not required for integrating to another project. Refer [Usage](#usage "Goto Usage") section.
1. Clone the repository
    ```sh
    git clone https://github.com/balanarayank/simple-cpp-datastructures.git
    ```
2. Go to the project directory
    ```sh
    cd simple-cpp-datastructures
    ```
3. Make a separate build directory for cmake
    ```sh
    mkdir build
    ```
4. Execute cmake  
On Linux:  
    ```sh
    cmake ..
    ```  
    On Windows:  
    ```sh
    cmake -G "Unix Makefiles" ..
    ```  

5. Build the project
    ```sh
    make
    ```
Binary 'src/datastructures-cpp-example' executes an example executable.   
<br/>  

### Unit Testing: ###  
This project uses [googletest](https://github.com/google/googletest) for unit testing. Project has been designed to clone and use googletest version 1.11.0 at the time of compilation.  
  
To execute unit test cases after build (step 5 above):
```sh
ctest -V
```  
  
To manually execute the test cases after build (step 5 above):
```sh
./test/datastructures-cpp-ut
```  
  
For more details regarding usage, refer googletest [documentation](https://google.github.io/googletest/).  
<br/>  

## TODO ##
- [ ] ChangeLog
- [x] Doubly Linked List
- [ ] Binary Search Tree
- [x] Improve source code comments  
<br/>  

## Contributing ##
Contributions are one of the key advantages of the open source community. Any contributions you wish to make are more than welcome.  
1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/NewFeature`)
3. Commit your Changes (`git commit -m 'Add some new feature'`)
4. Push to the Branch (`git push origin feature/NewFeature`)
5. Open a Pull Request  
<br/>  

## References ##
1. [cmake Documentation](https://cmake.org/documentation/)
2. [googletest Documentation](https://google.github.io/googletest/)
3. [markdown repo by tchapi](https://github.com/tchapi/markdown-cheatsheet) for easy README template reference
4. [Best-README-Template repo by othneildrew](https://github.com/othneildrew/Best-README-Template) for easy README template reference
5. [StackOverflow community](https://stackoverflow.com/)
