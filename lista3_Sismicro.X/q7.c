Difference between Interrupt and Polling

Interrupt:
Interrupt is a hardware mechanism in which, the device notices the CPU that it requires its attention. Interrupt can take place at any time. So when CPU gets an interrupt signal trough the indication interrupt-request line, CPU stops the current process and respond to the interrupt by passing the control to interrupt handler which services device.

Polling:
In polling is not a hardware mechanism, its a protocol in which CPU steadily checks whether the device needs attention. Wherever device tells process unit that it desires hardware processing, in polling process unit keeps asking the I/O device whether or not it desires CPU processing. The CPU ceaselessly check every and each device hooked up thereto for sleuthing whether or not any device desires hardware attention.

Each device features a command-ready bit that indicates the standing of that device, i.e., whether or not it?s some command to be dead by hardware or not. If command bit is ready one, then it?s some command to be dead else if the bit is zero, then it?s no commands. 
