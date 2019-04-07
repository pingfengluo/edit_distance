# Editdistance

Implementation of the edit distance [Levenshtein distance](http://en.wikipedia.org/wiki/Levenshtein_distance),  support C/C++ && Python interface.

## Install
```
    make
```

## Usage

Python interface
```
    import levenshtein
    levenshtein.levenshtein_distance("abcde", 5, "ab2efg", 6)
```

C/C++ interface
```
    const char str1[] = "abcde";
    const char str2[] = "ab2efg";
    int dist = levenshtein_distance(str1, strlen(str1), str2, strlen(str2));
```

## License

It is released under the MIT license.
