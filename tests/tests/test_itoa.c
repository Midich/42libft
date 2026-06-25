#include "../soft_assert.h"
#include "libft.h"
#include <limits.h>
#include <stdlib.h>
#include <string.h>

int main(){
    printf("\n=====ITOA=====\n");

    struct {
        int n;
        const char *expected;
    } cases[] = {
        {0, "0"},
        {1, "1"},
        {-1, "-1"},
        {42, "42"},
        {-42, "-42"},
        {123456, "123456"},
        {-123456, "-123456"},
        {2147483647, "2147483647"},   /* INT_MAX */
        {-2147483648, "-2147483648"}, /* INT_MIN */
        {5, "5"},
        {-5, "-5"},
        {10, "10"},
        {-10, "-10"},
        {100, "100"},
        {-100, "-100"}
    };

    for (size_t i = 0; i < sizeof(cases) / sizeof(cases[0]); i++)
    {
        int n = cases[i].n;
        const char *exp = cases[i].expected;

        char *result = ft_itoa(n);

        /* Ensure result is not NULL (we don't test allocation failure) */
        SOFT_ASSERT(result != NULL, "ft_itoa returned NULL");

        /* Compare with expected string */
        char msg[256];
        snprintf(msg, sizeof(msg), "ft_itoa(%d) mismatch, exp = %s, res = %s", n, exp, result);
        SOFT_ASSERT(strcmp(result, exp) == 0, msg);

        /* Also test using snprintf for additional safety (optional) */
        char buffer[64];
        snprintf(buffer, sizeof(buffer), "%d", n);
        SOFT_ASSERT(strcmp(result, buffer) == 0, "ft_itoa vs snprintf");

        free(result);
    }

    /* Additional edge case: test that the string is properly null-terminated */
    int test_vals[] = {0, -1, INT_MAX, INT_MIN};
    for (size_t i = 0; i < sizeof(test_vals) / sizeof(test_vals[0]); i++)
    {
        char *result = ft_itoa(test_vals[i]);
        SOFT_ASSERT(result != NULL, "ft_itoa returned NULL");
        size_t len = strlen(result);
        /* Check that the last character is '\0' (strlen already does this) */
        SOFT_ASSERT(result[len] == '\0', "ft_itoa missing null terminator");
        free(result);
    }
	print_summary();
}
