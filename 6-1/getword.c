#include <stdio.h>

static int isletter(char);

/*
 * isletter: return 1 if c is a letter as defined by Appendix A, A.2.3, The C
 *           Programming Language, 2nd Edition, otherwise return 0
 */
static int isletter(char c) {
    /* NB: underscore(_) is a letter according to Appendix A, A.2.3 */
    return c == '_' || isalpha(c);
}

/* getword: get next word. */
int getword(char *word, int lim) {
    int c;

    c = getchar();

    /* handle EOF */
    if(c == EOF) {
	*word = EOF;
	return *word;
    }

    /* skip preprocessor directives */
    /* NB: this must be before skipping whitespace */
    if(c == '\n') {
	char next_c;

	next_c = getchar();
	if(next_c == '#') { /* inside preprocessor directive */
	    while((next_c = getchar()) != EOF && next_c != '\n');
	    return getword(word, lim);
	} else { /* not inside preprocessor directive */
	    ungetc(next_c, stdin);
	}
    }

    /* skip whitespace */
    if(isspace(c)) {
	/* skip one char */
	/* NB: it must be only one for preprocessor directive skipping to work */
	return getword(word, lim);
    }

    /* skip comment */
    if(c == '/') {
	char next_c = getchar();

	if(next_c == '*') {
	    /* inside a comment */

	    while((c = getchar()) != EOF) {
		if(c == '*') {
		    next_c = getchar();
		    if(next_c == '/') {
			break; /* end of comment */
		    } else {
			ungetc(next_c, stdin);
		    }
		}
	    }

	    /* skip comment */
	    return getword(word, lim);
	} else { /* not inside a comment */
	    ungetc(next_c, stdin);
	}
    }

    /* skip char literal */
    /* this is required so that '"' is not interpreted as a string opener */
    if(c == '\'') {
	while((c = getchar()) != EOF) {
	    if(c == '\'') break;
	    if(c == '\\') getchar(); /* discard the next char */
	}

	return getword(word, lim);
    }

    /* skip string literal */
    if(c == '"') {
	while((c = getchar()) != EOF) {
	    if(c == '"') break;
	    if(c == '\\') getchar(); /* discard the next char*/
	}

	return getword(word, lim);
    }


    /* read word */
    if(isletter(c)) {
	int i;

	word[0] = c;
	for(i = 1; isletter(c = getchar()) || isdigit(c);) {
	    if(i < lim - 1) {
		word[i] = c;
		i++;
	    }
	}
	word[i] = '\0';

	ungetc(c, stdin); /* put back the char that is not part of our word */

	return word[0];
    } else {
	/* continue parsing from the next char */
	return getword(word, lim);
    }
}
