## About

This repository is for first phase of the "Operating System" course project at Amirkabir University of Technology in Fall 2022

The project has 3 phases:

#####  _⤷  [_phase1](https://github.com/mahlashrifi/xv6_New_SystemCall/blob/master/README)

#####  _⤷  [_phase2](https://github.com/mahlashrifi/xv6_Thread_Implementation)

#####  _⤷  [_phase3](https://github.com/mahlashrifi/xv6_Cpu_Scheduling)



## Overview

XV6 is a simple Unix-like teaching operating system that serves as a reference to better understand the concepts of operating systems.

In this phase, we have extended the xv6 operating system to support thread 



## Implemented features

- Add thread implementation to the xv6 operating system and the 3 following system calls to support it:

  1. The ```thread_create``` system call allows the user to create a new thread which uses the same address space as its parent.
    
  2. The ```thread_id``` system call returns the tid (thread id) of the new thread.
    
  3. The ```thread_join``` system call makes the thread's parent wait for it until it finishes its job.

  The functionality of these parts can be tested using ```threadTest``` command.
