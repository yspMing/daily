#pragma once

#include<iostream>
using namespace std;

// Define the structure of a GPTNode in a singly linked list
struct GPTNode {
    int data;
    GPTNode* next;
    GPTNode(int x) : data(x), next(NULL) {}
};

// Function to reverse a linked list and return the new head
GPTNode* reverseLinkedList(GPTNode* head) {
    GPTNode* prev = NULL;
    GPTNode* current = head;
    GPTNode* next = NULL;

    while (current != NULL) {
        next = current->next;  // Store next
        current->next = prev;  // Reverse current GPTNode's pointer
        prev = current;        // Move pointers one position ahead
        current = next;
    }
    return prev;  // New head
}

// Function to divide and reverse the linked list
GPTNode* divideAndReverse(GPTNode* head, int N, int M) {
    GPTNode* current = head;
    GPTNode* prevTail = NULL;
    GPTNode* newHead = NULL;

    for (int m = 0; m < M; ++m) {
        GPTNode* partHead = current;
        GPTNode* partTail = current;

        // Move to the end of the current part
        for (int n = 1; n < N && current; ++n) {
            current = current->next;
        }

        // Prepare for the next part
        if (current) {
            GPTNode* nextPart = current->next;
            current->next = NULL;  // Break the link
            current = nextPart;    // Move current to the start of the next part
        }

        // Reverse the current part
        GPTNode* reversedPartHead = reverseLinkedList(partHead);

        // If this is the first part, it will become the new head of the final list
        if (m == 0) newHead = reversedPartHead;

        // Link the previous part with the reversed current part
        if (prevTail) prevTail->next = reversedPartHead;

        // Update the previous part's tail for the next iteration
        prevTail = partTail;
    }

    return newHead;  // Return the head of the newly arranged list
}

// Helper function to print the list
void printList(GPTNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

GPTNode* constructLinkedListGPT(int* arr, int length)
{
    if (length < 1)
        return nullptr;
    GPTNode* head = new GPTNode(arr[0]);
    GPTNode* curr = head;
    for (int i = 1; i < length; i++)
    {
        curr->next = new GPTNode(arr[i]);
        curr = curr->next;
    }
    std::cout << "construct a linked list of " << length << " GPTNodes." << std::endl;
    return head;
}

// Main Function
int mainGPT() {
    int arr[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };

    GPTNode* head = constructLinkedListGPT(arr, 15);

    int N = 5;  // Number of GPTNodes in each part
    int M = 3;  // Number of parts

    GPTNode* newHead = divideAndReverse(head, N, M);
    printList(newHead);

    // Free the allocated memory (not shown here, but should be done in real scenarios)
    return 0;
}