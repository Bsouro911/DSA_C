#include <stdio.h>
#include <stdlib.h>

typedef struct tab
{
    char *url;
    struct tab *next;
    struct tab *previous;
} tab;

typedef struct BrowserHistory
{
    tab *current;
} BrowserHistory;

tab *createTab(char *url)
{
    tab *newTab = malloc(sizeof(tab));

    newTab->url = url;
    newTab->next = NULL;
    newTab->previous = NULL;

    return newTab;
}

BrowserHistory *browserHistoryCreate(char *homepage)
{
    BrowserHistory *history = malloc(sizeof(BrowserHistory));
    history->current = createTab(homepage);

    return history;
}

void browserHistoryVisit(BrowserHistory *obj, char *url)
{
    BrowserHistory history = *obj;

    tab *newTab = createTab(url);
    history.current->next = newTab;
    newTab->previous = history.current;
    history.current = newTab;

    *obj = history;
}

char *browserHistoryBack(BrowserHistory *obj, int steps)
{
    BrowserHistory history = *obj;
    int back = 0;

    while (history.current->previous != NULL && back < steps)
    {
        back++;
        history.current = history.current->previous;
    }

    *obj = history;

    return history.current->url;
}

char *browserHistoryForward(BrowserHistory *obj, int steps)
{
    BrowserHistory history = *obj;
    int forward = 0;

    while (history.current->next != NULL && forward < steps)
    {
        forward++;
        history.current = history.current->next;
    }

    *obj = history;

    return history.current->url;
}

void browserHistoryFree(BrowserHistory *obj)
{
    BrowserHistory history = *obj;

    // Free tab nodes while traversing the next pointers
    while (history.current->next != NULL)
    {
        tab *current = history.current;
        history.current = history.current->next;
        free(current->url); // Free the memory allocated for the URL string
        free(current);
    }

    // Free the last tab node and its URL
    free(history.current->url);
    free(history.current);

    // Free the BrowserHistory object
    free(obj);
}

int main()
{
    BrowserHistory *history = browserHistoryCreate("https://www.example.com");

    browserHistoryVisit(history, "https://www.example.com/page1");
    browserHistoryVisit(history, "https://www.example.com/page2");

    printf("Current URL: %s\n", history->current->url);

    char *previousURL = browserHistoryBack(history, 1);
    printf("Previous URL: %s\n", previousURL);

    char *forwardURL = browserHistoryForward(history, 1);
    printf("Forward URL: %s\n", forwardURL);

    browserHistoryFree(history);

    return 0;
}
