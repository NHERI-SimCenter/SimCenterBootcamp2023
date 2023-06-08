C: Assignments Day 4
====================

Problem 1: Parallelize **pi.c** using **MPI**
---------------------------------------------

Today we are going to parallelize the **pi.c** code you developed for day 1. to run at TACC you will need to use either **idev** or **sbatch**.

The figure below shows an method to compute **pi** by numerical integration. We would like you to implement that computation in a **C** program.

   .. figure:: figures/pi.png
           :align: center
           :figclass: align-center

           Computation of pi numerically

	   
The solution `pi.c' is in the solitions/C-Day1/pi folder. The contents of that file is presented here:

.. literalinclude:: ./assignments/c4/pi.c
  :language: c
  :linenos:

.. note::

   1. When compiling at TACC if you wish to use **gcc** as I have done, issue the following command when you login.

   .. code::

      module load gcc         

   2. When building and testing that the application works, use **idev**, as I have been showing in the videos.

   3. When launchig the job to test the performance you will need to use **sbatch** and place your job in the queue. To do this you need to create a script that will be launched when the job runs. I have placed two scripts in each of the file folders. The script informs the system how many nodes and cores per node, what the expected run time is, and how to run the jib. Once the executable exists, the job is launched using the following command issued from a **login** node:

      
   .. code::

      sbatch submit.sh   

  Full documentation on submitting scripts for **OpenMP** and **MPI** can be found `online at TACC <https://frontera-portal.tacc.utexas.edu/user-guide/scripts/>`_
     
.. warning::

   Our solution of **pi.c** as written as a loop dependency which may need to revise for tomorrows OpenMPI problem.
   

You are to modify the **pi.c** application and run it to use mpi. I have included a few files in code/parallel/ExercisesDay4/ex1 to help you. They include **pi.c** above, gather1.c and a submit.sh script. **gather1.c** was presented in the video, and us shown below:

.. literalinclude:: ./assignments/c4/gather1.c
  :language: c
  :linenos:

The submit script is as shown below.

.. literalinclude:: ./assignments/c4/submit.sh
  :linenos:


Problem 2: Compute the Norm of a vector using **MPI**
-----------------------------------------------------

Given what you just did with **pi** can you now write a program to compute the norm of  avector. In the **ex2** directory I have placed a file **scatterArray.c**. This file will use MPI_Scatter to send components of the vector to the different processes in the running parallel application.


.. literalinclude:: ./assignments/c4/scatterArray.c
  :language: c		    
  :linenos:
     
.. note::

   The vector size may not always be divisible by the number of processes. In such a case there will be additional terms not sent. Don;t forget to include them in the computation!
  

Problem 3: Bonus Parallelize your **matMul** solution using **MPI**
-------------------------------------------------------------------

If you want a more complicated problem to parallelize, I suggest parallelizing you matMul application from Day 2.

     
