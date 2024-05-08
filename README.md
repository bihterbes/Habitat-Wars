# Habitat-Wars
This C language project is designed to determine the survivor among creatures on a grid as they eat each other.
# Usage
- Firstly, there should be a matrix containing the numerical values of the creatures in the Data.txt file. There should be a space between each value.
- When you run the program, the matrix will be read, and an object will be created for each number representing a creature. The status of these objects will be printed to the screen initially.
- Then, the process of creatures eating each other will begin. It will progress from left to right and top to bottom.
- At each step, the matrix will be updated based on the creatures eating each other, and the updated status will be printed to the screen.
- Finally, the surviving creature and its position will be printed to the screen.

# Number ID 
These numbers express the value of living things. 
According to the limit values ​​given below, it can be understood whether the numerical value is a plant or an insect.

- Plant: 1-9
- Insect: 10-20
- Fly: 21-50
- Flea: 51-99

# Example
Assuming the Data.txt file is as follows:
```
10 2 5 4 7
21 6 1 25 8
11 64 33 41 47
8 1 9 5 23

```
In this case, starting from position (0,0), the process will proceed as follows:

- At position (0,0), the Bug (C) will consume the Plant (B), and the Plant will die.
- At position (1,0), the Bug (C) will consume the Fly (S), and the Bug will die.
- At position (2,0), the Fly (S) will consume the Bug (C), and the Bug will die.
- At position (2,1), the Fly (S) will consume the Bug (C), and the Bug will die.
- At position (3,0), the Plant (B) will consume the Fly (S), and the Fly will die.
- As a result, the surviving creature will be the Plant (B) at position (3,2).

# Inheritance Hierarchy
The project is developed using the following inheritance hierarchy:

       Canli
      /     \
    Bitki   Bocek
             /  \
         Sinek   Pire

      Creature
      /     \
    Plant   Bug
            /  \
         Fly   Flea
         
The following letters will be used when writing living creatures on the screen.
- Plant: B
- Insect: C
- Fly: S
- Flea:P
  
# Interactions between Creatures
The relationships between creatures are as follows:

- Plant → Flea
- Bug → Plant
- Fly → Flea
- Plant → Fly
- Fly → Bug
- Bug → Flea

