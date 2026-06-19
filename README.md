*This project has been created as part of the 42 curriculum by msowinsk*

# Description
Libft is a library made for 42cursus as the first project.  
Libft goal is to reimplement a set of functions from the `libc` and add few useful ones not included in it.

## Functions from libc

### 1. Character classification
| Function | Parameters | Return value | Description |
| -------- | ---------- | ----------- | ----------- |
| **int** ft_isalpha(int **c**) | **c**: char to be tested | 1 if there is match<br>0 if not | Check if given character is an alphabetic character [a-zA-z] |
| **int** ft_isdigit(int **c**) | **c**: char to be tested | 1 if there is match<br>&nbsp;0 if not | Check if given character is a digit [0-9] |
| **int** ft_isalnum(int **c**) | **c**: char to be tested | 1 if there is match<br>0 if not | Check if given character is an alphabetic or digit [a-zA-Z0-9] |
| **int** ft_isascii(int **c**) | **c**: char to be tested | 1 if there is match<br>0 if not | Check if given character in range of standard ascii table |
| **int** ft_isprint(int **c**) | **c**: char to be tested | 1 if there is match<br>0 if not | Check if given character can be printed |

### 2.
| Function | Parameters | Return value | Description |
| -------- | ---------- | ----------- | ----------- |
| **size_t** ft_strlen(const char \***s**) | **s**: | | |
| **void** \*ft_memset(void \***s**, int **c**, size_t **n**) | **s**:<br>**c**:<br>**n** | | |
| **void** ft_bzero(void \***s**, size_t **n**) | **s**:<br>**n** | | |
| **void** \*ft_memcpy(void \***dest**, const void \***src**, size_t **n**) | **dest**:<br>**src**:<br>**n**: | | |
| **void** \*ft_memmove(void \***dest**, const void \***src**, size_t **n**) | **dest**:<br>**src**:<br>**n**: | | |
| **size_t** ft_strlcpy(char \***dst**, const char \***src**, size_t **size**) | **dst**:<br>**src**:<br>**size**: | | |
| **size_t** ft_strlcat(char \***dst**, const char \***src**, size_t **size**) | **dst**:<br>**src**:<br>**size**: | | |
| **int** ft_toupper(int **c**) | **c**: | | |
| **int** ft_tolower(int **c**) | **c**: | | |
| **char** \*ft_strchr(const char \***s**, int **c**) | **s**:<br>**c**: | | |
| **char** \*ft_strrchr(const char \***s**, int **c**) | **s**:<br>**c**: | | |
| **int** ft_strncmp(const char \***s1**, const char \***s2**, size_t **n**) | **s1**:<br>**s2**:<br>**n**: | | |
| **void** \*ft_memchr(const void \***s**, int **c**, size_t **n**) | **s**:<br>**c**:<br>**n**: | | |
| **int** ft_memcmp(const void \***s1**, const void \***s2**, size_t **n**) | **s1**:<br>**s2**:<br>**n**: | | |
| **char** \*ft_strnstr(const char \***big**, const char \***little**, size_t **len**) | **big**:<br> **little**:<br>**len**: | | |
| **int** ft_atoi(const char \***nptr**) | **nptr**: | | |
| **void** \*ft_calloc(size_t **nmemb**, size_t **size**) | **nmemb**:<br>**size**: | | |
| **char** \*ft_strdup(const char \***s**) | **s**: | | |

## Extra functions
Additional functions not found in `libc` or found in different form
| Function | Parameters | Return value | Description |
| -------- | ---------- | ----------- | ----------- |
| **char** \*ft_substr(const char \***s**, unsigned int **start**, size_t **len**) | **s**:<br>**start**:<br>**len**: | | |
| **char** \*ft_strjoin(const char \***s1**, const char \***s2**) | **s1**: <br>**s2**: | | |
| **char** \*ft_strtrim(const char \***s1**, const char \***set**) | **s1**: <br>**set**: | | |
| **char** \*\*ft_split(const char \***s**, char **c**) | **s**: <br>**c**: | | |
| **char** \*ft_itoa(int **n**) | **n**: | | |
| **char** \*ft_strmapi(const char \***s**, char (\***f**)(unsigned int, char)) | **s**:<br>**f**: | | |
| **void** ft_striteri(char \***s**, char (\***f**)(unsigned int, char*)) | **s**:<br>**f**: | | | 
| **void** ft_putchar_fd(char **c**, int **fd**) | **c**:<br>**fd** | | |
| **void** ft_putstr_fd(char \***s**, int **fd**) | **s**:<br>**fd** | | |
| **void** ft_putendl_fd(char \***s**, int **fd**) | **s**:<br>**fd** | | |
| **void** ft_putnbr_fd(int **n**, int **fd**) | **n**:<br>**fd** | | |

## Linked List
| Function | Parameters | Return value | Description |
| -------- | ---------- | ----------- | ----------- |
| **t_list** \*ft_lstnew(void \***content**) | **content**: | | |
| **void** ft_lstadd_front(t_list \*\***lst**, t_list \***new**)| **lst**:<br>**new**: | | |
| **int** ft_lstsize(t_list \***lst**) | **lst**: | | |
| **t_list** \*ft_lstlast(t_list \***lst**) | **lst**: | | |
| **void** ft_lstadd_back(t_list \*\***lst**, t_list \***new**) | **lst**:<br>**new**: | | |
| **void** ft_lstdelone(t_list \***lst**, void (\***del**)(void \*)) | **lst**:<br>**del**: | | |
| **void** ft_lstclear(t_list \*\***lst**, void (\***del**)(void \*)) | **lst**:<br>**del**: | | |
| **void** ft_lstiter(t_list \***lst**, void (\***f**)(void \*)) | **lst**:<br>**f**: | | |
| **t_list** \*ft_lstiter(t_list \***lst**, void \*(\***f**)(void \*), void (\***del**)(void \*)) | **lst**:<br>**f**:<br>**del**: | | |

# Instructions

### 1. Compiling
To build this library use  
```
make
```
command for basic compilation or
```
make re
```
to recompile all source files 

### 2. Cleaning
To delete all work files use
```
make clean
```
or
```
make fclean
```
to delete all work files and created library

### 3. Debugging
Compiling with debuging information enabled can be done using 
```
make debug
```
this will not recompile existing files older than already generated objects, to do that use
```
make redebug
```
# Resources
- [Markdown Guide](https://www.markdownguide.org) for cheatsheet on how to use markdown syntax
- [Makefile Tutorial](https://makefiletutorial.com/) for tutoral on Makefiles and
- [GNU website](https://www.gnu.org/software/make/) for documentation
> AI wasn't used in any way, while making this library
