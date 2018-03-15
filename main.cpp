#include <iostream>
#include "SalesItem.h"

void example_1_4_1() {
    int sum = 0, val = 1;
    // keep executing the while as long as val is less than or equal to 10
    while (val <= 10) {
        sum += val; // assigns sum + val to sum
        ++val;      // increment val
    }
    std::cout << "The sum of 1 to 10 inclusive is: " << sum << std::endl;
}

void exercise_1_9() {
    int sum = 0, val = 50;
    while (val <= 100) {
        sum += val++;
    }
    std::cout << "the sum of 50 to 100 inclusive is: " << sum << std::endl;
}

void exercise_1_10() {
    int val = 10;
    while (val >= 0) {
        std::cout << "countdown: " << val-- << std::endl;
    }
}

void exercise_1_11() {
    int value1, value2;
    std::cout << "Enter 2 values: " << std::endl;
    std::cin >> value1 >> value2;
    int lowestValue = value2 >= value1 ? value1 : value2;
    int highestValue = lowestValue != value1 ? value1 : value2;
    int currentValue = lowestValue;
    while (currentValue <= highestValue) {
        std::cout << "value in range " << lowestValue << " to " << highestValue << ": " << currentValue++ << std::endl;
    }
}

void example_1_4_2() {
    int sum = 0;
    // sum values from 1 through 10 inclusive
    for (int val = 0; val <= 10; ++val)
        sum += val;
    std::cout << "Sum of 1 through 10 inclusive is " << sum << std::endl;
}

void exercise_1_12() {
    int sum = 0;
    for (int val = -100; val <= 100; ++val)
        sum += val;
    std::cout << "Sum of -100 through 100 inclusive is " << sum << std::endl;
}

void exercise_1_13_1() {
    int sum = 0;
    for (int val = 50; val <= 100; ++val) {
        sum += val;
    }
    std::cout << "Sum of 50 through 100 inclusive is " << sum << std::endl;
}

void exercise_1_13_2() {
    for (int val = 10; val >= 0; --val) {
        std::cout << "countdown: " << val << std::endl;
    }
}

void exercise_1_13_3() {
    std::cout << "Enter 2 numbers:" << std::endl;
    int value1, value2;
    std::cin >> value1 >> value2;
    int lowestValue = value1 <= value2 ? value1 : value2;
    int highestValue = lowestValue != value1 ? value1 : value2;
    for (int val = lowestValue; val <= highestValue; val++) {
        std::cout << "value in range " << lowestValue << " to " << highestValue << ": " << val << std::endl;
    }
}

void example_1_4_3() {
    std::cout << "Enter some values" << std::endl;
    int sum = 0, val = 0;
    // read until end of file, calculating a running total of all values read
    while (std::cin >> val)
        sum += val;
    std::cout << "Sum is: " << sum << std::endl;
}

void exercise_1_16_1() {
    std::cout << "Enter some values, enter '-1' to sum the result:" << std::endl;
    int sum = 0, val = 0;
    while (std::cin >> val) {
        if (val == -1) break;
    }
    std::cout << "Sum is: " << sum << std::endl;
}

void example_1_4_4() {
    // currVal is the value we're counting, read the new values into val
    int currVal = 0, val = 0;
    // read the first number while ensuring we have data to process
    while (std::cin >> currVal) {
        int count = 1; // store the count for the current value we're processing
        while (std::cin >> val) { // read the remaining numbers
            if (val == currVal) // if values are the same
                ++count; // increment count
            else { // otherwise print the count for the previous value
                std::cout << currVal << " occurs " << count << " times" << std::endl;
                currVal = val; // remember the new val
                count = 0; // reset the counter
            }
        }
    }
}

void example_1_5_1() {
    std::cout << "Enter ISBN, count sold then price" << std::endl;
    SalesItem item1, item2;
    std::cin >> item1 >> item2; // read a pair of transactions
    std::cout << item1 + item2 << std::endl; // print their sum
}

void exercise_1_20() {
    SalesItem currentItem;
    do {
        std::cout << currentItem << std::endl;
        std::cout << "Enter ISBN, count sold then price" << std::endl;
    } while (std::cin >> currentItem);
}

void exercise_1_21() {
    std::cout << "Enter total book pair count: " << std::endl;
    int totalBookPairCount;
    if (std::cin >> totalBookPairCount) {
        for (int pairIndex = 1; pairIndex <= totalBookPairCount; pairIndex++) {
            std::cout << "Enter ISBN, count sold then price for first item of pair " << pairIndex << std::endl;
            SalesItem currentItem1, currentItem2;
            if (!(std::cin >> currentItem1)) break;
            std::cout << "Enter ISBN, count sold then price for second item of pair " << pairIndex << std::endl;
            if (!(std::cin >> currentItem2)) break;
            std::cout << "Sum of book pair " << pairIndex << " is " << currentItem1 + currentItem2 << std::endl;
        }
    }
}

void printEnterSalesItem(int count = 1) {
    std::cout << "Enter " << count << " SalesItem: " << std::endl;
}

void exercise_1_23() {
    SalesItem currentSalesItem, trackedSalesItem;
    bool firstRun = true;
    printEnterSalesItem();
    while (std::cin >> currentSalesItem) {
        if (firstRun) {
            firstRun = false;
            trackedSalesItem = currentSalesItem;
        }
        if (trackedSalesItem.isbn() == currentSalesItem.isbn()) {
            trackedSalesItem += currentSalesItem;
        } else {
            std::cout << "Total of SalesItem: " << trackedSalesItem << std::endl;
            trackedSalesItem = currentSalesItem;
        }
        printEnterSalesItem();
    }
}

int example_1_6() {
    SalesItem total;
    std::cout << " Enter new sales item " << std::endl;
    if (std::cin >> total) {
        SalesItem trans;
        std::cout << "Enter another sales item " << std::endl;
        while (std::cin >> trans) {
            if (total.isbn() == trans.isbn()) {
                total += trans;
                std::cout << "Enter another sales item " << std::endl;
            } else {
                std::cout << "total for sales item is " << total << std::endl;
                total = trans;
                std::cout << "Enter new sales item " << std::endl;
            }
        }
        std::cout << "total for sales item is " << total << std::endl;
    } else {
        std::cerr << "No data!?" << std::endl;
        return -1;
    }
    return 0;
}

void example_2_1_2() {
    bool b = 42;
    std::cout << " b = 42: " << b << std::endl;
    int i = b;
    std::cout << " i = b: " << i << std::endl;
    i = 3.14;
    std::cout << " i = 3.14: " << i << std::endl;
    double pi = i;
    std::cout << " pi = i: " << pi << std::endl;
    unsigned char uc = -2;
    std::cout << " uc = -2: " << uc << std::endl;
    signed char sc = 127;
    std::cout << " sc = 127: " << sc << std::endl;
}

void example_2_1_2_charSet() {
    unsigned char uc = 0;
    do {
        std::cout << (int) uc << " is " << uc++ << std::endl;
    } while (uc != 0);
}

void telugu() {
    auto telugu = "జ్ఞ\u200Cా";
    std::cout << "telugu string: " << telugu << std::endl;
}

void exercise_2_4() {
    unsigned u1 = 10, u2 = 42;
}

void example_2_1_3() {
    std::cout << "20 decimal: " << 20 << std::endl;
    std::cout << "20 binary: " << 0B10100 << std::endl;
    std::cout << "20 hexadecimal: " << 0x14 << std::endl;
    std::cout << "20 octal: " << 024 << std::endl;
    std::cout << "Lorem ipsum dolor sit amet, consectetur adipiscing elit, "
            "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
            "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris "
            "nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in "
            "reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. "
            "Excepteur sint occaecat cupidatat non proident, "
            "sunt in culpa qui officia deserunt mollit anim id est laborum.";

    std::cout << "here is \n a new line" << std::endl;
    std::cout << "here is \v a vertical tab" << std::endl;
    std::cout << "here is \t a horizontal tab" << std::endl;
    std::cout << "here is \\ a backslash" << std::endl;
    std::cout << "here is \r a carriage return" << std::endl;
    std::cout << "here is \b a backspace" << std::endl;
    std::cout << "here is \? a question mark" << std::endl;
    std::cout << "here is \f a formfeed" << std::endl;
    std::cout << "here is \a an alert(bell) (doesn't work)" << std::endl;
    std::cout << "here is \' a single quote" << std::endl;
    std::cout << "here is \" a double quote" << std::endl;
    std::cout << "Hi \x4dO\115!\n";
    std::cout << "wide char literal: " << L'a' << std::endl;
    std::cout << "utf-8 string literal: " << u8"a" << std::endl;
    std::cout << "unsigned long long literal: " << 42ULL << std::endl;
    std::cout << "single precision floating-point literal: " << 1E-3F << std::endl;
}

void exercise_2_8() {
    std::cout << "\x32\x4D\n" << std::endl;
}

void example_2_2_1() {
    std::string book1 = "book";
    std::string book1Copy = book1;
    std::string book2 = book1 + '2';
    std::string book3 = book2 + '3';

    int unitsSold1 = 0;
    int unitsSold2 = {1};
    int unitsSold3{1};
    int unitsSold4(1);

    long double ld = 3.344444434343434;

    int i1 = ld;
    //  error: type 'long double' cannot be narrowed to 'int' in initializer list
    // int i2 = {ld};
    int i2;
    int i3 = i2;
}

void exercise_2_9() {
    //a. std::cin >> int i;
    {
        int i;
        std::cin >> i;
    }
    //b. int i = { 3.14 };
    {
        int i = 3.14;
    }
    //c. double salary = wage = 9999.9
    {
        double wage = 9999.9, salary = wage;
    }
    //d. int i = 3.14
    {
        double d = 3.14;
    }
}

void example_2_3_1() {
    // A Reference is an Alias
    {
        int val = 1024;
        int &refVal = val; // refVal refers to/is another name for val
        //int &refIval2; // Error: declaration of reference value requires an initializer
        refVal = 2; // same as val = 3
        int val2 = refVal; // same as int val2 = val
        int &refVal2 = refVal; // same as int &refVal2 = val;
    }
    // Reference Definitions
    {
        int val1 = 1024, val2 = 2048; // val1 and val2 are both ints
        int &refVal1 = val1, val3 = val2; // refVal1 is a reference bound to val1, val3 is an int initialised with val2
        //int &refVal4 = 10; // Error: expression must be an lvalue
        double dVal1 = 3.14;
        //int &refVal5 = dVal1; // incompatible types int & and double
    }
}

void exercise_2_15() {
    //a:
    int ival = 1.01; // valid, but precision loss converting from double to int.
    //b:
    //int &rval = 1.01; // Error: expression/initializer must be an lvalue/object.
    //c:
    int &rval2 = ival; // ok because ival is an object of same type
    //d:
    //int &rval; //Error: definition of reference variable requires an initializer.
}

void exercise_2_16() {
    int i = 0, &ri = i;
    double d = 0, &rd = d;
    //a:
    rd = 3.14159; // valid, assigns literal to d;
    //b:
    rd = ri; // valid, takes value of ri (i) assigns to rd (d)
    //c:
    i = rd; // valid, but precision loss as rd (d) is a double, i is a int.
    //d:
    ri = d; // valid, but precision loss as d is a double, ri (i) is a int.
}

void exercise_2_17() {
    int i, &ri = i;
    i = 5, ri = 10;
    std::cout << i << " " << ri << std::endl;
    //prints "10 10"
}

void example_2_3_2() {

    // Taking the address of an object
    {
        int i = 42;
        int *pI = &i; // initializer is the address of an int
        int &refI = *pI;

        double d;
        double *pD = &d;    // initializer is address of a double
        double *pD2 = pD;   // initializer is pointer to a double
        //int *pI2 = pD;    // error: types of pI2 and pD differ
        //int *pI3 = &d;    // error: cannot use address of double as initializer for pointer to int
    }
    // Using a Pointer to access an Object
    {
        int i = 42;
        int *pI = &i; // pI holds the address of I, pI is a pointer to I
        std::cout << "*pI: " << *pI << std::endl; // dereference pI then print
    }
    // Some symbols have multiple meanings
    {
        int i = 42;
        int &r = i; // & follows a type and it's part of a declaration, r is a reference
        int *p;     // * follows a type and it's part of a declaration, p is a pointer
        p = &i;     // & is used as part of an expression, & is the address-of operator
        *p = i;     // * is used as part of an expression, * is the dereference operator
    }
    // Null pointers
    {
        int *pI1 = nullptr; // equivalent to int *pI = 0; nullptr is new in C++11
        int *pI2 = 0;       // directly initialises pI2 from literal constant 0
        int pI3 = NULL;    // equivalent to int *pI = 0; NULL is a preprocessor directive where NULL is converted to literal constant 0
        // This is the old C way and should not be used in modern C++11+ applications

        int zero = 0;
        // int *pI4 = zero; // error: cannot assign an int to a pointer, not equivalent to literal constant 0
    }
    // Assignments and Pointers
    {
        int i1 = 42;
        int *pi1 = 0;   // pi1 is initialized but addresses no object
        int *pi2 = &i1; // pi2 is initialized to hold the address of i1
        int *pi3;       // as pi3 is defined in block scope, pi3 is uninitialized
        pi3 = pi2;      // pi3 now points to the same object that pi2 points to - i1
        pi2 = 0;        // pi2 now points to/addresses no object
    }
    // Other Pointer Operations
    {
        // A pointer can be used as part of a condition (yields boolean value)
        int i1 = 1024;
        int *pi1 = 0;   // pi1 is a valid pointer, that points to/addresses no object (null pointer)
        int *pi2 = &i1; // pi2 is a valid pointer, that points to/address i1
        if (pi1) {      // pi1 points to/address no object (null pointer), condition is false
            // do something with valid pointer
        }
        if (pi2) {      // pi2 points to/address i1, condition is true
            // do something with valid pointer
        }
    }
    // Void Pointers
    {
        auto obj = 3.14, *pd = &obj;
        // void pointer can point to / hold the address of any data pointer type
        void *pv = &obj;    // obj can be of any type.
        pv = pd;            // pv can be set with a pointer to any type.
    }
    // Playground
    {
        // try to initialize pointers when object it initially points to exists
        int i1 = 1337;
        int *pi1 = &i1;

        // otherwise always initialize to nullptr
        int *pi2 = nullptr;

        // and never leave a block-scoped pointer uninitialised
        int *pi3; // behaviour when accessed is undefined

        int i2 = 1337;
        int *pi4 = &i1;
        int *pi5 = &i2;
        std::cout << "pi4 == pi5 = " << ((pi4 == pi5) ? "true" : "false") << std::endl;
        std::cout << "*pi4 == *pi5 = " << ((*pi4 == *pi5) ? "true" : "false") << std::endl;

        int *pi6 = pi2 ?: pi5;
        std::cout << "pi6 == pi2 = " << ((pi6 == pi5) ? "true" : "false") << std::endl;

        int *i = new int(1); // hey look, I'm a Java developer!!
    }
}

void exercise_2_18() {
    // initialize to nullptr
    int *ip = nullptr;
    {
        int i1 = 1, i2 = 2;
        // change value of ip to address of i1
        ip = &i1;

        // change value of ip to address of i2
        ip = &i2;

        // change value of object that ip addresses/points to (i2)
        *ip = 21;
    }
}

void exercise_2_19() {
    // Pointers and references are similar in the sense that they both allow indirect access to some object.
    int i = 1;
    int &iref = i;  // reference to i
    int *iptr = &i; // pointer to i
    // However pointers are objects themselves, where as references are not.
    // References must be initialized on declaration and cannot change the object to which they refer:
    //int &iref2; // error: declaration or reference requires an initializer.
    // Where as pointers can be declared without an initializer
    int *iptr2;
    // However uninitialized pointers at block scope yield undefined behaviour when accessed and should be initialized with
    // the object to which it will be initially bound or to the literal nullptr.
    // Pointers, unlike references can change the object to which they reference/address/point to.
    // When a pointer is initialized or given a new non-null value, it can be initialized with another pointer of the
    // same type or with the address on an object of the correct type, for example:
    iptr2 = &i; // now addresses/points to i
    int *iptr3 = iptr2; // declared and initialized with iptr2 - iptr3 points to i.
    // but when a reference in declared and initialized, the address-of operator is not required:
    int &iref2 = i;
    // Because references are not objects, you cannot have a pointer to a reference (can only point to objects):
    int *iptr4 = &iref; // << legal but points to object in which iref references, which is i;
    // You may have a pointer to a pointer:
    int **ipptr = &iptr;
}

void exercise_2_20() {
    int i = 42;     // declares int and initializes with literal 42
    int *pi = &i;   // declares int * and initializes with address of i
    *pi = *pi * *pi; // dereferences pi *(to access i), muliplies it by again, dereferencing pi (to access i)
    // then gives result to dereference pi (i)
    // essentially it's: i = i * i;
}

void exercise_2_21() {
    int i = 0;
    // a:
    // double* dp = &i; // error, initializing double * with address of an int instead of the address of a double

    // b:
    //int *ip = i; //error, requires the address-of operator (&)

    //c:
    int *p = &i; // legal as the type to which p points is the type of i (int),
    // address-of operator initializes p with the address of i.
}

void exercise_2_22() {
    int i = 0;
    int *p = &i;

    // p evaluates to true or false if it is valid pointer i.e:
    //  - it points to an object
    //  - it points to the location just immediately past the end of an object
    //  - it points to nullptr/0/NULL
    // It will evaluate to true in the first 2 cases, it will evaluate to false in the third case (nullptr).
    // If p were not initialized, the behaviour of the expression is undefined as the pointer is declared at block scope.
    if (p) { // will evaluate to true as it is a valid pointer that points to/addresses i.
    }
    // Here the pointer is de-referenced, where the result is the object to which it points.
    // Just like when using an integer as a boolean expression, it will evaluate to true if the int to
    // which it points is non-zero, otherwise zero.
    // However the behaviour of de-referencing the pointer is undefined if the pointer does not point to an object, so when:
    //  - it points to the location just immediately past the end of the object
    //  - it points to nullptr/0/NULL
    //  - it is an uninitialized pointer declared at block scope
    // As the behaviour is undefined in these cases, the program may crash.
    if (*p) { // will evaluate to false as pointer points to an int with value zero.
    }
}

void exercise_2_23() {
    // There is no way to determine if a pointer is valid, such as:
    int *p;
    // p is invalid as it is a pointer declared without an initializer, accessing it will cause undefined behaviour.
    // So the following results in undefined behaviour:
    if (p) { // program may crash as p is an uninitialized pointer declared at block scope.

    }
    // If we know/assume that a pointer is valid, we can however determine whether the pointer points to a valid object or not:
    int i = 1;
    int *p2 = &i, *p3 = nullptr;
    // we can check it's validity simply by:
    if (p2) { // evaluates as true as it points to a valid int object.

    }
    if (p3) { // evaluates as false as it points no no object.

    }
}

void exercise_2_24() {
    int i = 42;
    int *p = &i;    // legal as p is a pointer to an int object, and the value given is the address of an int object.
    //long *lp = &i;  // illegal as lp is a pointer to a long object, and the value given is the address of an int object.
}


void example_2_3_3() {
    // Understanding Compound type declarators
    {
        // i is an int, p is a pointer to an int, r is a reference to an int
        int i = 1024, *p = &i, &r = i;
    }
    // Defining multiple variables
    {
        /*
        int* p;         legal but might be misleading
        int* p1, p2;    p1 is a pointer to an int, p2 is an int
        int *p1, *p2;   both are pointers to int - emphasises compound type of each declarator
        int* p1;
        int* p2;        // emphasises declaration defines the compound type;
         */
    }
    // Pointers to Pointers
    {
        int i = 1024;
        int *pi = &i;       // pi is a pointer to an int
        int **ppi = &pi;   // ppi is a pointer to a pointer to an int

        using namespace std;
        cout << "The value of i:\n"
             << "Direct value: " << i
             << "\nIndirect value: " << *pi
             << "\nDoubly indirect value: " << **ppi
             << endl;
    }
    // References to Pointers
    {
        int i = 42;
        int *pi;            // pi is a pointer to an int
        int *&rpi = pi;     // rpi is a reference to a pointer to an int

        rpi = &i;           // assigning &i makes pi point to i
        *rpi = 0;           // dereferencing rpi yields the object to which pi points to - i. Assigning 0 changes i
    }
}

int main() {
//    example_1_4_1();
//    exercise_1_9();
//    exercise_1_10();
//    exercise_1_11();
//    example_1_4_2();
//    exercise_1_12();
//    exercise_1_13_1();
//    exercise_1_13_2();
//    exercise_1_13_3();
//    example_1_4_3();
//    exercise_1_16_1();
//    example_1_4_4();
//    example_1_5_1();
//    exercise_1_20();
//    exercise_1_21();
//    exercise_1_22();
//    example_1_6();
//    example_2_1_2();
//    example_2_1_2_charSet();
//    telugu();
//    example_2_1_3();
//    exercise_2_8();
    //example_2_2_1();
//    example_2_3_1();
//    exercise_2_15();
//    exercise_2_16();
//    exercise_2_17();
    example_2_3_2();
    example_2_3_3();
}
