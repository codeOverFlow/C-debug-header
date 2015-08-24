# C-debug-header
A little C header to help debugging with some printing or just output error easily

To desactivate the debugging messages compile with -DNDEBUG

# debug(message, ...)
```
int main(int argc, char const *argv[]) {
   // check argc
   // no need to declare any variable named "argerror"
   check(argc >= 3, argerror, "Some text");
   // print: [ERROR] (roms.c:13, main --> errno: NONE): Some text

   // no error
   return 0;

   //error
   argerror:
   return -1;
}

```

# var_val(variable, format)
```
int main(int argc, char const *argv[]) {
   var_val(argc, "%d);
   // print: argc = 1 

   return 0;
}

```

# printbits(variable, size)
```
int main(int argc, char const *argv[]) {
   char c = 5;
   var_val(c, "%d);
   // print: 0000101

   return 0;
}

```
