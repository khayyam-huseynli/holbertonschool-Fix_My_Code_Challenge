#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int i;

    if (*head == NULL)
        return (-1);

    current = *head;

    /* Traverse to the node at the specified index */
    for (i = 0; current != NULL && i < index; i++)
    {
        current = current->next;
    }

    /* If the node to delete doesn't exist */
    if (current == NULL)
        return (-1);

    /* If the node to delete is the head node */
    if (current == *head)
    {
        *head = current->next; /* Move head pointer to next node */
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    else
    {
        /* Update the previous node's next pointer */
        if (current->prev != NULL)
            current->prev->next = current->next;
    }

    /* Update the next node's prev pointer */
    if (current->next != NULL)
        current->next->prev = current->prev;

    /* Free the node */
    free(current);
    
    return (1);
}
