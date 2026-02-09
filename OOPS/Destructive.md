Destructors

Concept: A special method used to deallocate memory when an object is destroyed (e.g., when it goes out of scope).

Syntax: Defined with a tilde ~ before the class name (e.g., ~Student()).

Importance: Crucial for preventing memory leaks, especially if you have allocated dynamic memory (using new) in the constructor; you must release it (using delete) in the destructor