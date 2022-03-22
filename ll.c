/**
 * C program to delete first node from Singly Linked List by key.
 */
#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node
{
    int data;          // Data
    struct node *next; // Address
} * head;


/* Function declaration */
void createList(int n);
void insertNodeAtBeginning(int data);
void deleteFirstNode();
void deleteFirstByKey(int key);
void displayList();


int main()
{
    int n, key, data, choice;

    // Input node count to create
    printf("Enter number of node to create: ");
    scanf("%d", &n);

    createList(n);

    // Display list
    printf("\nData in list before deletion\n");
    displayList();
    
    printf("\nPress 1 to delete first node: ");
    scanf("%d", &choice);

    /* Delete first node from list */
    if(choice == 1)
        deleteFirstNode();
    
    /*
     * Insert data at the beginning of the singly linked list
     */
    printf("\nEnter data to insert at beginning of the list: ");
    scanf("%d", &data);
    insertNodeAtBeginning(data);

    printf("\nEnter element to delete with key: ");
    scanf("%d", &key);

    // Call function to delete first element by key
    deleteFirstByKey(key);

    // Print final list
    printf("\nData in list after deletion\n");
    displayList();

    return 0;
}

/**
 * Create a list of n nodes
 */
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = malloc(sizeof(struct node));

    /*
     * Unable to allocate memory, hence exit from app.
     */
    if (head == NULL)
    {
        printf("Unable to allocate memory. Exiting from app.");
        exit(0);
    }
    

    /* Input head node data from user */
    printf("Enter data of node 1: ");
    scanf("%d", &data);

    head->data = data; // Link data field with data
    head->next = NULL; // Link address field to NULL

    temp = head;

    /*
     * Create n nodes and add to the list
     */
    for (i = 2; i <= n; i++)
    {
        newNode = malloc(sizeof(struct node));

        /* If memory is not allocated for newNode */
        if (newNode == NULL)
        {
            printf("Unable to allocate memory. Exiting from app.");
            exit(0);
        }

        printf("Enter data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data; // Link data field of newNode
        newNode->next = NULL; // The newNode should point to nothing

        temp->next = newNode; // Link previous node i.e. temp to the newNode
        temp = temp->next;
    }
    
}

/*
 * Deletes the first node of the linked list
 */
void deleteFirstNode()
{
    struct node *toDelete;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        head = head->next;

        printf("\nData deleted = %d\n", toDelete->data);

        /* Clears the memory occupied by first node*/
        free(toDelete);

        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}

/*
 * Create a new node and inserts at the beginning of the linked list.
 */
void insertNodeAtBeginning(int data)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // Link data part
        newNode->next = head; // Link address part

        head = newNode;          // Make newNode as first node

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}

/**
 * Display entire list
 */
void displayList()
{
    struct node *temp;

    /*
     * If the list is empty i.e. head = NULL,
     * dont perform any action and return.
     */
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    
    temp = head;
    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        
        temp = temp->next;  // Move to next node
    }

    printf("\n");
}


/**
 * Delete first node by key from the list.
 */
void deleteFirstByKey(int key)
{
    struct node *prev, *cur;

    /* Check if head node contains key */
    while (head != NULL && head->data == key)
    {
        // Get reference of head node
        prev = head;

        // Adjust head node link
        head = head->next;

        // Delete prev since it contains reference to head node
        free(prev);

        // No need to delete further
        return;
    }

    prev = NULL;
    cur  = head;

    /* For each node in the list */
    while (cur != NULL)
    {
        // Current node contains key
        if (cur->data == key)
        {
            // Adjust links for previous node
            if (prev != NULL) 
                prev->next = cur->next;

            // Delete current node
            free(cur);

            // No need to delete further
            return;
        } 

        prev = cur;
        cur = cur->next;
    }
}
