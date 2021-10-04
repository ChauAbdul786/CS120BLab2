# Array of tests to run (in order)
# Each test contains
#   description - 
#   steps - A list of steps to perform, each step can have
#       inputs - A list of tuples for the inputs to apply at that step
#       *time - The time (in ms) to wait before continuing to the next step 
#           and before checking expected values for this step. The time should be a multiple of
#           the period of the system
#       *iterations - The number of clock ticks to wait (periods)
#       expected - The expected value at the end of this step (after the "time" has elapsed.) 
#           If this value is incorrect the test will fail early before completing.
#       * only one of these should be used
#   expected - The expected output (as a list of tuples) at the end of this test
# An example set of tests is shown below. It is important to note that these tests are not "unit tests" in 
# that they are not ran in isolation but in the order shown and the state of the device is not reset or 
# altered in between executions (unless preconditions are used).
tests = [ {'description': 'PINA: 0x00, PINB: 0x00, PINC: 0x00 => PORTD: 0x00 (No Weight)',
	'steps': [ {'inputs': [('PINA',0x00),('PINB',0x00),('PINC',0x00)], 'iterations': 5 } ],
	'expected': [('PORTD',0x00)],
	},
	{'description': 'PINA: 0x21, PINB: 0x1F, PINC: 0x00 => PORTD: 0x10 (Empty SeatC)',
	'steps': [ {'inputs': [('PINA',0x21),('PINB',0x1F),('PINC',0x00)], 'iterations': 5 } ],
	'expected': [('PORTD',0x10)],
	},
	{'description': 'PINA: 0x1E, PINB: 0x00, PINC: 0x0A => PORTD: 0x08 (Empty SeatB)',
	'steps': [ {'inputs': [('PINA',0x1E),('PINB',0x00),('PINC',0x0A)], 'iterations': 5 } ],
	'expected': [('PORTD',0x08)],
	},
	{'description': 'PINA: 0x00, PINB: 0x09, PINC: 0x20 => PORTD: 0x08 (Empty SeatA)',
	'steps': [ {'inputs': [('PINA',0x00),('PINB',0x09),('PINC',0x20)], 'iterations': 5 } ],
	'expected': [('PORTD',0x08)],
	},
	{'description': 'PINA: 0x1E, PINB: 0x10, PINC: 0x21 => PORTD: 0x10 (All Three Seats Occupied)',
	'steps': [ {'inputs': [('PINA',0x1E),('PINB',0x10),('PINC',0x21)], 'iterations': 5 } ],
	'expected': [('PORTD',0x10)],
	},
	{'description': 'PINA: 0x32, PINB: 0x28, PINC: 0x32 => PORTD: 0x20 (Weight Adds Up To 140kg)',
	'steps': [ {'inputs': [('PINA',0x32),('PINB',0x28),('PINC',0x32)], 'iterations': 5 } ],
	'expected': [('PORTD',0x20)],
	},
	{'description': 'PINA: 0xFF, PINB: 0xFF, PINC: 0xFF => PORTD: 0xBD (All Seats Full Weight)',
	'steps': [ {'inputs': [('PINA',0xFF),('PINB',0xFF),('PINC',0xFF)], 'iterations': 5 } ],
	'expected': [('PORTD',0xBD)],
	},
	{'description': 'PINA: 0x00, PINB: 0xFF, PINC: 0x00 => PORTD: 0x16 (Only SeatB Full Weight)',
	'steps': [ {'inputs': [('PINA',0x00),('PINB',0xFF),('PINC',0x00)], 'iterations': 5 } ],
	'expected': [('PORTD',0x3D)],
	},
	{'description': 'PINA: 0x51, PINB: 0x00, PINC: 0x00 => PORTD: 0x16 (Unbalanced Heavy SeatA)',
	'steps': [ {'inputs': [('PINA',0x51),('PINB',0x00),('PINC',0x00)], 'iterations': 5 } ],
	'expected': [('PORTD',0x16)],
	},
	{'description': 'PINA: 0x00, PINB: 0xFF, PINC: 0x51 => PORTD: 0x16 (Unbalanced Heavy SeatC)',
	'steps': [ {'inputs': [('PINA',0x00),('PINB',0x00),('PINC',0x51)], 'iterations': 5 } ],
	'expected': [('PORTD',0x16)],
	},
	{'description': 'PINA: 0xFF, PINB: 0x00, PINC: 0x00 => PORTD: 0x3F (Only SeatA Full Weight)',
	'steps': [ {'inputs': [('PINA',0xFF),('PINB',0x00),('PINC',0x00)], 'iterations': 5 } ],
	'expected': [('PORTD',0x3F)],
	},
	{'description': 'PINA: 0x00, PINB: 0x00, PINC: 0xFF => PORTD: 0x3F (Only SeatC Full Weight)',
	'steps': [ {'inputs': [('PINA',0x00),('PINB',0x00),('PINC',0xFF)], 'iterations': 5 } ],
	'expected': [('PORTD',0x3F)],
	},
	]
#watch = ['PORTC']
