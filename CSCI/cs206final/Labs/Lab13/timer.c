/*
 * CSCI 206 Computer Organization & Programming
 * Author: L. Felipe Perrone
 * Date: 2011-11-29
 * Copyright (c) 2011 Bucknell University
 *
 * Permission is hereby granted, free of charge, to any individual or
 * institution obtaining a copy of this software and associated
 * documentation files (the "Software"), to use, copy, modify, and
 * distribute without restriction, provided that this copyright and
 * permission notice is maintained, intact, in all copies and supporting
 * documentation.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL BUCKNELL UNIVERSITY BE LIABLE FOR ANY CLAIM, DAMAGES
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <sys/time.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>

extern char *strsignal(int sig);

void timer_handler(int a)
{
  // handle signal
  printf(">>>> signal caught\n");
  printf(">>>>    int parameter = %s\n", (char*) strsignal(a));
}

int main(int argc, char* argv[])
{
  int retval;
  struct itimerval timerValue;
  struct itimerval oldTimerValue;

  // initialize timer parameters: expires in 5 seconds
  timerValue.it_interval.tv_sec = 5;
  timerValue.it_interval.tv_usec = 0;

	timerValue.it_value.tv_sec = 5;
	timerValue.it_value.tv_usec = 0;

  // initialize the sigaction parameters
  struct sigaction act;
  struct sigaction oldact;

  act.sa_handler = timer_handler;
  
  // install signal handler to catch SIGALRM
  sigaction(SIGALRM, &act, &oldact);
  retval = setitimer(ITIMER_REAL, &timerValue, &oldTimerValue);
 
  if (-1 == retval)
    perror("Could not set timer");
 
  while(1);

  return 0;
}
