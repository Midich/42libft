#include "libft.h"
#include "tests/soft_assert.h"
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

static int create_temp_file(char *name)
{
    static const char template[] = "/tmp/libft_test_XXXXXX";
    strcpy(name, template);
    int fd = mkstemp(name);
    if (fd == -1)
    {
        perror("mkstemp");
        exit(EXIT_FAILURE);
    }
    return (fd);
}

//read entire content of a file into a newly allocated string.
static char *read_temp_file(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return (NULL);
    }
    off_t size = lseek(fd, 0, SEEK_END);
    if (size == -1)
    {
        perror("lseek");
        close(fd);
        return (NULL);
    }
    lseek(fd, 0, SEEK_SET);
    char *buf = malloc(size + 1);
    if (!buf)
    {
        close(fd);
        return (NULL);
    }
    ssize_t bytes = read(fd, buf, size);
    if (bytes != size)
    {
        free(buf);
        close(fd);
        return (NULL);
    }
    buf[size] = '\0';
    close(fd);
    unlink(filename);
    return (buf);
}

static void test_putchar_fd(void)
{
    printf("\n=====PUTCHAR_FD=====\n");
    char filename[64];
    int fd = create_temp_file(filename);

    /* Write a single character */
    ft_putchar_fd('A', fd);
    close(fd);

    char *content = read_temp_file(filename);
    SOFT_ASSERT(content != NULL, "read_temp_file failed");
    SOFT_ASSERT(strcmp(content, "A") == 0, "ft_putchar_fd('A') failed");
	free(content);
	
    /* Test newline and other chars */
    fd = create_temp_file(filename);
    ft_putchar_fd('\n', fd);
    ft_putchar_fd('B', fd);
    ft_putchar_fd('\0', fd);
    ft_putchar_fd('C', fd);
    close(fd);

    content = read_temp_file(filename);
    SOFT_ASSERT(content != NULL, "read_temp_file failed");
    size_t expected_len = 2; /* newline, 'B', '\0', 'C' */
    SOFT_ASSERT(strlen(content) == expected_len, "ft_putchar_fd length mismatch");
    SOFT_ASSERT(content[0] == '\n' && content[1] == 'B' && content[2] == '\0' && content[3] == 'C',
                "ft_putchar_fd multi-char failed");
    free(content);
}

static void test_putstr_fd(void)
{
    printf("\n=====PUTSTR_FD=====\n");
    char filename[64];
    int fd = create_temp_file(filename);

    /* Empty string */
    ft_putstr_fd("", fd);
    close(fd);
    char *content = read_temp_file(filename);
    SOFT_ASSERT(content != NULL, "read_temp_file failed");
    SOFT_ASSERT(strcmp(content, "") == 0, "ft_putstr_fd empty string failed");
    free(content);

    /* Normal string */
    fd = create_temp_file(filename);
    ft_putstr_fd("Hello, World!", fd);
    close(fd);
    content = read_temp_file(filename);
    SOFT_ASSERT(content != NULL, "read_temp_file failed");
    SOFT_ASSERT(strcmp(content, "Hello, World!") == 0,
                "ft_putstr_fd 'Hello, World!' failed");
    free(content);

    /* String with newline and null byte  */
    fd = create_temp_file(filename);
    ft_putstr_fd("abc\0def", fd);  /* writes only "abc" */
    close(fd);
    content = read_temp_file(filename);
    SOFT_ASSERT(content != NULL, "read_temp_file failed");
    SOFT_ASSERT(strcmp(content, "abc") == 0,
                "ft_putstr_fd with embedded null failed");
    free(content);

    /* Long string */
    char long_str[512];
    memset(long_str, 'X', sizeof(long_str) - 1);
    long_str[sizeof(long_str) - 1] = '\0';
    fd = create_temp_file(filename);
    ft_putstr_fd(long_str, fd);
    close(fd);
    content = read_temp_file(filename);
    SOFT_ASSERT(content != NULL, "read_temp_file failed");
    SOFT_ASSERT(strcmp(content, long_str) == 0,
                "ft_putstr_fd long string failed");
    free(content);
}

static void test_putendl_fd(void)
{
    printf("\n=====PUTENDL_FD=====\n");
    char filename[64];
    int fd = create_temp_file(filename);

    /* Empty string */
    ft_putendl_fd("", fd);
    close(fd);
    char *content = read_temp_file(filename);
    SOFT_ASSERT(content != NULL, "read_temp_file failed");
    SOFT_ASSERT(strcmp(content, "\n") == 0,
                "ft_putendl_fd empty string failed (should output newline)");
    free(content);

    /* Normal string */
    fd = create_temp_file(filename);
    ft_putendl_fd("Hello", fd);
    close(fd);
    content = read_temp_file(filename);
    SOFT_ASSERT(content != NULL, "read_temp_file failed");
    SOFT_ASSERT(strcmp(content, "Hello\n") == 0,
                "ft_putendl_fd 'Hello' failed");
    free(content);

    /* String with newline already (should output extra newline) */
    fd = create_temp_file(filename);
    ft_putendl_fd("Hi\n", fd);
    close(fd);
    content = read_temp_file(filename);
    SOFT_ASSERT(content != NULL, "read_temp_file failed");
    SOFT_ASSERT(strcmp(content, "Hi\n\n") == 0,
                "ft_putendl_fd with existing newline failed");
    free(content);
}

static void test_putnbr_fd(void)
{
    printf("\n=====PUTNBR_FD=====\n");
    char filename[64];
    int fd;

    /* Test zero */
    fd = create_temp_file(filename);
    ft_putnbr_fd(0, fd);
    close(fd);
    char *content = read_temp_file(filename);
    SOFT_ASSERT(content != NULL, "read_temp_file failed");
    SOFT_ASSERT(strcmp(content, "0") == 0,
                "ft_putnbr_fd(0) failed");
    free(content);

    /* Positive numbers */
    int nums[] = {1, 42, 1234567, 2147483647};
    for (size_t i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
    {
        fd = create_temp_file(filename);
        ft_putnbr_fd(nums[i], fd);
        close(fd);
        content = read_temp_file(filename);
        SOFT_ASSERT(content != NULL, "read_temp_file failed");
        char expected[32];
        snprintf(expected, sizeof(expected), "%d", nums[i]);
        SOFT_ASSERT(strcmp(content, expected) == 0,
                    "ft_putnbr_fd positive mismatch");
        free(content);
    }

    /* Negative numbers */
    int neg_nums[] = {-1, -42, -1234567, -2147483648};
    for (size_t i = 0; i < sizeof(neg_nums) / sizeof(neg_nums[0]); i++)
    {
        fd = create_temp_file(filename);
        ft_putnbr_fd(neg_nums[i], fd);
        close(fd);
        content = read_temp_file(filename);
        SOFT_ASSERT(content != NULL, "read_temp_file failed");
        char expected[32];
        snprintf(expected, sizeof(expected), "%d", neg_nums[i]);
        SOFT_ASSERT(strcmp(content, expected) == 0,
                    "ft_putnbr_fd negative mismatch");
        free(content);
    }
}

int main()
{
	test_putchar_fd();
	test_putstr_fd();
	test_putendl_fd();
	test_putnbr_fd();
	print_summary();
}
