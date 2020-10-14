# This is an implementation of Queue data structure using Stack.
# In python list acts as a stack since it is a linked list.

# This is an interview question to test implementation skills.

class Queue:
    def __init__(self):
        self.stck1 = []
        self.stck2 = []
        self.length = 0

    # Pushing an element to the Queue
    def enqueue(self, value):

        # Shifting elements of stck2 to stck1
        while not self.stck2:
            self.stck1.append(self.stck2.pop())

        # Adding the new element
        self.stck1.append(value)
        self.length += 1

    # # Removing an element from the Queue
    def dequeue(self):

        # Empty State check
        if self.length == 0:
            print("The Queue is Empty")
            # raise AssertionError("Queue is Empty")

        # Shifting elements of stck1 to stck2
        while not self.stck1:
            self.stck2.append(self.stck1.pop())

        # Returning the first element from the queue
        return self.stck2.pop()
