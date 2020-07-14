#ifndef MIMEDOWN_WRAP_H
#define MIMEDOWN_WRAP_H

#include <stdbool.h>
#include <stddef.h>
#include "vendor/queue.h"

struct wordlist_entry
{
	const char *start;
	ptrdiff_t len;

	TAILQ_ENTRY(wordlist_entry) entries;
};
TAILQ_HEAD(wordlist, wordlist_entry);

struct wordlist *wordlist_create(void);
struct wordlist *wordlist_append(struct wordlist *ws, const char *text);
void wordlist_free(struct wordlist *ws);
size_t print_wrapped(const struct wordlist *ws, const char *overhang,
		size_t width, bool flowed);

#endif
