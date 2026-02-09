Non-Parameterized: Takes no arguments.
Parameterized: Takes arguments to initialize properties with specific values.

Copy Constructor : Creates a new object as a copy of an existing object.
Shallow Copy: Copies member values as-is. If a member is a pointer to dynamic memory, both objects will point to the same memory address. This is dangerous if one object modifies the data.

Deep Copy: Allocates new memory for the copy and copies the actual values. This is required when your class handles dynamic memory (heap).