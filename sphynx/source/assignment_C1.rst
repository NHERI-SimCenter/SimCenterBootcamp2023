C: Assignments Day 1
====================

Today we have three problems for you to tackle. 


.. warning::

   In this part of the bootcamp we will only be providing you with a minimal number of example files. You will in a hurry have to learn some **emacs**, basic **git** and **linux** commands. The sidebar on the left contains some basic instruction on these (enough to get you through this part of the bootcamp). The training wheels have been removed!

   
Problem 1: Solve the Quadratic
------------------------------
We wish to solve the quadratic equations, i.e. given **a**, **b**, and **c**, solve the following equation for **x**. 

.. math::

   ax^2+bx+c=0

The solution from your high school days is the legendary formula:

.. math::

    x = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}

We want you to write an application developed in  **C** to solve this equation.

To start you off, we have provided a file **solveQuadratic.c** in **/assignments/C-Day1/**. The contents of this file are shown below.

.. literalinclude:: ./assignments/c1/solveQuadratic.c
   :language: c
   :linenos:
		
.. note::

   When compiling because you will be using functions from the **C** math library you will need to include the math library when you compile and link your code, i.e.

   .. code::
      
      gcc solveQuadratic.c -lm

      
Problem 2: Stress Transformations
---------------------------------

To transform stress to a rotated coordinate system one can use the formula shown in the figure. We would ask you to write code that will take as input **4** values  sigmaXX, sigmaYY, tauXY, and **theta** compute the stress in the transformed coordinate system. We would ask you to perform that transformation computation in a function other than **main** and to complicate things, but demonstrate you understand passing of arrays, pass the input and output stresses to this new function in fixed length arrays.

**Theory**: Stress transformation

.. math::
    \sigma_x' = \sigma_x \cos^2\theta + \sigma_y \sin^2\theta + 2 \tau_{xy} \sin\theta \cos\theta \\
    \sigma_y' = \sigma_x \sin^2\theta + \sigma_y \cos^2\theta - 2 \tau_{xy} \sin\theta \cos\theta \\
    \tau_{xy}' = ( \sigma_y - \sigma_x ) \sin\theta \cos\theta + \tau_{xy} ( \cos^2\theta - \sin^2\theta ) 

To start you off, we have provided a file **transformStress.c** in **/assignments/C-Day1/**. You are to modify it to print out the transformed stresses. The contents of this file are shown below.

.. literalinclude:: ./assignments/c1/transformStress.c
   :language: c
   :linenos:
    
.. note::

   If you need something extra work, write to a file the results of this transformation from **0** through **360** degrees in increments of 10

      To send you data to a file named **results.out**, start the application as follows:   

   .. code::

      ./appName 1.0 100.0 0.01 1 > results.out

Problem 3: Compute PI numerically
_________________________________

The figure below shows an method to compute **pi** by numerical integration. We would like you to implement that computation in a **C** program. The program should take as **input** an **integer value specyfying the number of intervals**.

   .. figure:: figures/pi.png
           :align: center
           :figclass: align-center

           Computation of pi numerically

To start you off, we have provided a file **transformStress.c** in **/assignments/C-Day1/**. You are to modify it to print out the transformed stresses. The contents of this file are shown below.

.. literalinclude:: ./assignments/c1/pi.c
   :language: c
   :linenos:	   

.. note::

   You will be using your solution on Day 4 as part of the parallel exercises.
   
