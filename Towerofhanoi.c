Aim : To implement the **Tower of Hanoi** using **recursion** 
in order to move a set of disks from a source peg to a destination peg following the defined rules.

Program : 

 #include <stdio.h>

 /**
 * Function to solve Tower of Hanoi problem
 * @param diskNumber: Number of disks to move
 * @param source: Starting rod
 * @param destination: Target rod
 * @param auxiliary: Intermediate rod
 */
  void towerOfHanoi(int diskNumber, char source, char destination, char auxiliary)
 {
