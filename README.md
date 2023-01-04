# Advanced-Programming-Project
<h1>EX2 IS IN BRANCH: "MAIN_EX2"</h1>
<h1>EX3 IS IN BRANCH: "ex3"</h1>
<h2>About The Project</h2>
<p>This project was made by Omer Bar and Shilo Padael in our second year of our Computer Science B.A. This project was written in C++ language, this course is all about "Advanced-Porigramming" through out this course we learn new stuff, such as: C++ language syntax, Socket, Procceing, MultiThreading -- for now --</p>

<h2>How To Run On Bar-Ilan Server?</h2>
<h4>TO RUN THIS PROJECT ON BIU SERVER:</h4>
<p>The Makefile is inside the folder "build-for-linux", Before executing the command "make" make sure you are inside the desired folder.</p>
<ol>
  <li>Pull the git repository to a local folder.</li>
  <li>Open terminal in the project folder.</li>
  <li>Run the following commands: (without the '$' and the comments)</li>
 </ol>
<pre><code>$ cd build-for-linux                       // Moving to the desired folder.
$ make                                     // Compiling the project.
$ ./a.out                                  // Executing the program.</code></pre>

<h2><i>-------------------------Milestone 1 - Part B - 15.12.2022-------------------------</i></h2>
<h4>Reading from a CSV files of data, Knn Algorithim, Machine Learning</h4>
<p>In this part of the project, We implemented the Knn algorithim, to explain the Knn algorithim we define a few things:</p>
<ol>
  <li>An std::vector called the "input_vector"</li>
  <li>Data_files that include in each row: a few floating points number and a classified tag to describe the vector values.</li>
</ol>

<p>To explain the Knn we will start in an example, How can we make a computer to tell if a picture has a cat in it?
well we can "teach" the computer how a cat looks like. We can show the computer alot of images of cats (a.k.a Data_files) and given an image that 
we want the computer to recognize, we calculate the distance betweeen all the images sets, then we define an Integer K 
that will be the K nearset images to the input image (a.k.a input_vector)' finally we will define the image class by the tag
that appeared the most.</p>

<h4>Structs</h4>
<p>We used struct database to hold the information together, 2 structs that defines in a single header file called CSVStruct.h: DistanceVec, VectorCSV</p>
<pre><code>DistanceVec:
std::vector&#60double&#62 vData             // holds the distance between the input_vector and some vector in data_files.
std::string className                 // holds the classified the vector had in data_files.
VectorCSV:
std::vector&#60double&#62 id                // holds the vector elemetns from the data_files.
std::string className                 // holds the classified tag of the vector information.
</code></pre>

<h4>Read From Files</h4>
<p>The ReadCSV class takes an CSV file and return an std::vector&#60VectorCSV&#62 that hold all the information from the files vectors.
using the fstream libaray</p>

<h4>Knn Algorithim</h4>
<p>This class does all the magic, the constructor gets an: std::vector&#60double&#62 input_vector, Integer k, std::vector&#60VectorCSV&#62 data_files, Distance* distance. By using Distance as pointer we make use of polymorphism we can implement the design of the Knn algorithim without knowing which distance to calculate (Incapsulate). after calculating the distances we save it in std::vector&#60DistanceVec&#62 and initilizing the Select algorithim to calculate the K element
in the vector. Why using select? well it is more efficient, the time complexity is O(n) whereas for sorting is O(nlog(n)).
Once a Knn class was created it is not fixed, you can change all the parameters by bunch of sets function, the function getClassified() returns the result of the last time the function calculate() was called. (The first time happend in the constructor, no need to call calculate() after constructor)</p>
<p><b>Important: to avoid segmentaion fault you cannot delete the distance pointer that use the Knn algorithim, only after you changed the Knn distance you can do so.</b></p>


<h2><i>-------------------------Milestone 1 - Part A - 24.11.2022-------------------------</i></h2>
<h4>Creating different algorithm to calculate the distance between 2 vectors</h4>
<p>We implement it using an abstract class called Distance that implements 2 functions and another virtual function.
For each algorithm that inheritance the Distance class it should only implements the virtual function. In this project
we didnt implement a Vector class, We use the std vector class.</p>

<h4>How to calculate the distance?</h4>
<ol>
  <li>Creating an instance of the algorithm.</li>
  <li>Applying the operator () on the instance and saving the value.</li>
</ol>
<p>Let's calculate the Euclidean distance for example:</p> 
<pre><code>// creating the vectors
std::vector v1 = {1, 2, 3};
std::vector v2 = {3, 2, 1};
Euclidean euclidean; // Creating instance of Euclidean algorithem.
double result = euclidean(v1, v2) // Returning the distance between v1 and v2.
</code></pre>

<p>By using an abstract class we can make use of polymorphism</p>
<pre><code>Euclidean euclidean;
Distance* pDistance = &euclidean;
double result = (*pDistance)(v1, v2); // Returning the distance between v1 and v2.
</code></pre>

<h4>How to add another distance algorithm?</h4>
<ol>
  <li>Creating a new class by the name of the algorithm inside folder calculate.</li>
  <li>Inheritance the Distance class (after including it).</li>
  <li>Override the virtual function in Distance class named: operator().</li>
</ol>
<h2>How To Run?</h2>
<h4>----------------------------------------To Create A Makefile For A Specifc Machine----------------------------------------</h4>
<h4>To compile the project for a desired machine, you need to install cmake: https://cmake.org/download/ and follow the tutorial:</h4>
<h4>For Linux:</h4>
<ol>
  <li>Download the zip file of the project, and exctract the zip.</li>
  <li>Open terminal in the project folder.</li>
  <li>Run the following commands: (without the '$' and the comments)</li>
 </ol>
  <pre><code>$ mkdir build                              // Creating a folder for the build files.
$ cd build                                 // Moving to the build folder path.
$ cmake -S ../                             // -S flag for the source CMakeList.txt file.
$ make                                     // Compiling the project. make sure you inside the folder 'build'.
$ ./a.out                                  // Executing the program.</code></pre>

<h4>For Windows:</h4>
<ol>
  <li>Download the zip file of the project</li>
  <li>Extract the zip file in an ASCII supported path. (for example 'D:\test' only english is good)</li>
  <li>Open the cmd inside the folder project.</li>
  <li>Run the following commands: (without the comments)</li>
</ol>
 <pre><code> mkdir build                                // creating a folder for the build files.
 cd build                                   // moving to the build folder path.
 cmake -S ../ -G"MinGW Makefiles"           // -S flag for the source CMakeList.txt file, and -G for the windows default compilor.
 make                                       // Compiling the project. make sure you inside the folder 'build'.
 start a.out                                // Executing the program.</code></pre>

