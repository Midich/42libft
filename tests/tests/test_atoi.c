#include "../soft_assert.h"
#include "libft.h"
#include <stdlib.h>

int main(){
    printf("\n=====ATOI=====\n");
    const char *test_cases[] = {
        "0", "1", "-1", "+1", "  -123", "  456", "123abc", "abc",
        "\t\n\v\f\r  -789", "2147483647", "-2147483648",
        "999999999999", "-999999999999", "", "   +  123"
    };
    for (size_t i = 0; i < sizeof(test_cases)/sizeof(test_cases[0]); i++) {
        const char *s = test_cases[i];
        int exp = atoi(s);
        int got = ft_atoi(s);
        SOFT_ASSERT(got == exp, "ft_atoi mismatch for input");
    }
    print_summary();
}
