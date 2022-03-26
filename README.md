Data Structures for C++<a name="TOP"></a>
=======================
<br/>

# About the project #
This project aims to provide a simplfied way of using data structures in C++. There are in-built data structures like stack and queue data in C++. There are also other great github repos for this use case, but I wanted to create something simple and unique for my own needs.  
<br/>
# Getting Started #

## Usage ##
----
If you simply intend to integrate this into your project, compilation is not required. Simply copy the folders inside src directory to your project workspace and include the relevant header files.  
<br/>
### Instantiation ### 
Data Structures exist as templates, so initialize the instance with required data type.  
**eg:**  
`SinglyLinkedList <int> sIntObj;`  
`SinglyLinkedList <std::string> sStrObj;`  
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
---   
This project uses cmake build environment.  
<br/>

### Pre-requisites: ###  

On Ubuntu or Debian based systems:
```sh
sudo apt install cmake
```

On Fedora:
```sh
sudo dnf install cmake
```

If you use any other Linux distribution, please refer the respective documentation for your OS regarding installation. On most systems, you should be also able to download and install from cmake website.  
[cmake Download](https://cmake.org/download/)  
<br/>

### Build Steps: ###
You would need to do below steps only if you need to run an example executable or unit tests. These steps are not required for integrating to your project. Refer [Usage](#usage "Goto Usage") section.
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
    ```sh
    cmake ..
    ```
5. Build the project
    ```sh
    make
    ```
Binary 'src/datastructures-cpp-example' executes an example executable.  
<br/>

### Unit Testing: ###  
This project uses [googletest](https://github.com/google/googletest) for unit testing. No separate action is required from the user as the project has been designed to clone and use googletest version 1.11.0 at the time of build.  
<br/>

To execute unit test cases after build (step 5 above):
```sh
ctest -V
```
<br/>

To manually execute the test cases after build (step 5 above):
```sh
./test/datastructures-cpp-ut
```
<br/>
For more details regarding usage of googletest, refer their documentation.

<br/>

## TODO ##
---
- [ ] ChangeLog
- [ ] Doubly Linked List
- [ ] Binary Search Tree
- [ ] Improve source code comments

<br/>


## Contributing ##
---
Contributions are one of the key advantages of the open source community. Any contributions you wish to make are more than welcome.  
1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/NewFeature`)
3. Commit your Changes (`git commit -m 'Add some new feature'`)
4. Push to the Branch (`git push origin feature/NewFeature`)
5. Open a Pull Request

<br/>

## References ##
---
1. [cmake Documentation](https://cmake.org/documentation/)
2. [googletest Documentation](https://google.github.io/googletest/)
3. [markdown repo by tchapi](https://github.com/tchapi/markdown-cheatsheet) for easy README template reference
4. [Best-README-Template repo by othneildrew](https://github.com/othneildrew/Best-README-Template) for easy README template reference
5. [StackOverflow community](https://stackoverflow.com/)