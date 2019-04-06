# coding=utf-8
#!/usr/bin/env python
from distutils.core import setup, Extension

levenshtein_module = Extension('_levenshtein',
        language='c++',
        include_dirs=['.'],
        extra_compile_args=['-O3', '-std=c++11'],
        sources=['levenshtein_wrap.cxx', 'levenshtein.cc'],
        )

setup(name = 'levenshtein',
        version = '0.0.1',
        author      = "pingfengluo@gmail.com",
        description = """edit distance (levenshtein distance)""",
        ext_modules = [levenshtein_module],
        py_modules = ["levenshtein"],
        )
