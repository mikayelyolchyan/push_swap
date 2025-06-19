<a name="readme-top"></a>
<div align="center">

  <!-- Project Name -->
  <h1>Push-Swap</h1>

  <!-- Short Description -->
  <p align="center">
      <b>Sorting algorithm using two stacks with limited operations</b><br>
  </p>

  <h3>
      <a href="#-about-project">📜 About Project</a>
    <span> · </span>
      <a href="#-operations-list">📑 Operations List</a>
    <span> · </span>
      <a href="#-algorithm">🧮 Algorithm</a>
    <span> · </span>
      <a href="#-bonus-part">🌟 Bonus Part</a>
    <span> · </span>
      <a href="#-usage">👨‍💻 Usage</a>
  </h3>
</div>

---

## 📜 About Project

* This project will make you sort data on a stack, with a limited set of operations, using the lowest possible number of actions.

* The Push_swap project is a very simple and highly effective algorithm project: data will need to be sorted.  
You have at your disposal a set of int values, 2 stacks and a set of operations to manipulate both stacks.  

* The goal is to write a program in C called push_swap which calculates and displays on the standard output the operations that sort the integers received as arguments.

* The learning objectives of this project are rigor, use of C and use of basic algorithms. Especially looking at the complexity of these basic algorithms.

* You are allowed to use the following functions: malloc, free, exit, write, read.

For detailed information, refer to the [**subject of this project**](en.subject.pdf).

> [!NOTE]  
> Because of 42 School norm requirements:
> * Each function can't have more than 25 lines of code.
> * All variables are declared and aligned at the top of each function.
> * Project should be created just with allowed functions otherwise it's cheating.

## 📑 Operations List

The program is only allowed to work with two stacks: stack A and stack B.  
All the numbers are initially added to stack A, and stack B is empty.

The possible operations are:

| Code  | Operations                          | Action                                                 |
|:-----:|:-----------------------------------:|:------------------------------------------------------:|
| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | push a                              | moves the top element of stack b to the top of stack a |
| `pb`  | push b                              | moves the top element of stack a to the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |

## 🦋 Butterfly Algorithm

The **Butterfly** algorithm sorts stack A by splitting it into chunks and gradually moving elements to the auxiliary stack B, then returning them back to stack A in sorted order.

### Steps of the Algorithm

**1. Determining the Chunk Size**  
The chunk size is chosen depending on the total number of elements in stack A. The larger the stack, the larger the chunk size.

**2. Distributing Elements from Stack A to Stack B**  
- Iterate through stack A:
  - If the index of the top element of stack A is less than or equal to the current counter `i`, push it to stack B (`pb`) and increment the counter.
  - If the index of the top element is in the range from `i+1` to `i+chunk_size`, push it to stack B (`pb`), then rotate stack B (`rb`), and increment the counter.
  - If the index is greater than `i+chunk_size`, rotate stack A (`ra`) to bring the needed elements closer to the top.
- Repeat this process until stack A is empty. As a result, stack B contains elements split into chunks, with smaller elements closer to the bottom of stack B and larger ones at the top.

**3. Returning Elements from Stack B to Stack A**  
- While stack B is not empty:
  - Find the position of the maximum index in stack B.
  - If the maximum element is closer to the top (its position ≤ half the size of stack B), rotate stack B up (`rb`) until the maximum is on top.
  - If the maximum is closer to the bottom, rotate stack B down (`rrb`) until it is on top.
  - Then perform `pa` to push the maximum element back to stack A.
- Repeat until stack B is empty.

**Result:**  
After these operations, stack A is sorted in ascending order.

> **Note:**  
> The chunk size should be adjusted depending on the number of elements.  
> Experiment with different chunk sizes to achieve the best operation count.  
> For more information about the algorithm, see [this video](https://www.youtube.com/watch?v=GA9aKzl86nA&ab_channel=Edu_events_mow).  
> You can also visualize the algorithm using [this visualizer](https://push-swap42-visualizer.vercel.app/).

## 🟢 Small Stack Sorting

For a small number of elements (2, 3, 4, or 5), a separate optimized algorithm is used to minimize the number of operations.

### Principle

- **2 elements:**  
  Simply compare the two numbers; if the order is wrong, perform `sa` (swap a).

- **3 elements:**  
  Use a set of conditions to determine the minimal sequence of operations (`sa`, `ra`, `rra`) needed to sort three numbers. All possible combinations are considered to sort the stack in the minimal number of moves.

- **4 elements:**  
  Find the smallest element, move it to the top using rotations (`ra` or `rra`), then push it to stack B (`pb`). Sort the remaining three elements as in the 3-element case, then push the smallest element back to stack A (`pa`).

- **5 elements:**  
  Similar to the 4-element case: the two smallest elements are pushed to stack B one by one, the remaining three are sorted, then the smallest elements are pushed back to stack A.

**Result:**  
This approach allows you to sort a small stack with the minimum number of operations, which is especially important for achieving the best results in the push_swap project.

## 🌟 Bonus Part
* The Bonus exercise was to write a program called 'checker' that can read the operations from stdin and perform them on a stack of numbers.
* Checker will display 'OK' when the given operations will sort the numbers in ascending order. Otherwise it displays 'KO'.
* In case of an error (e.g., operation doesn't exist) it displays 'Error'.

## 👨‍💻 Usage
### Requirements

The program is written in C language and thus needs the **gcc compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the program**

To compile the program, run:

```shell
cd path_to/push_swap && make
```

To compile the checker, run:

```shell
cd path_to/push_swap && make bonus
```

**2. How to run the program**

Run the executable together with the set of numbers separated by a space:
```shell
./push_swap 5 7 10 4 6 8 9 2 1 3
```

To run the checker on push_swap, use the pipe:
```shell
ARG="5 7 10 4 6 8 9 2 1 3"; ./push_swap $ARG | ./checker $ARG
```

Use `make clean` to delete all object files, `make fclean` to remove the executable and all object files, and `make re` to recompile the program:
```shell
make clean
make fclean
make re
```