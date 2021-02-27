// 1024 max prescaler
// 0xFFFF maximum number of counts
// 1/8MHz = 1,25*10^-7

// delay max = 1024 * 0xFFFF * 1/8M = 8.38848s
// this delay is half the delay of the square wave, then..
// T = 16.77696s is the period max of the square wave.
// fmin = 1/Tmax = 0.05960555428Hz
// it can be decreased using loops
