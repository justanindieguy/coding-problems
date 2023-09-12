class Node:
    data = 0
    next = None

    def __init__(self, data, next=None):
        self.data = data
        self.next = next


class LinkedList:
    head = None

    def insert_node(self, data):
        new_node = Node(data)

        if not self.head:
            self.head = new_node
            return

        temp = self.head
        while temp.next:
            temp = temp.next

        temp.next = new_node

    def print_list(self):
        if not self.head:
            return

        temp = self.head
        while temp:
            if temp.next:
                print(f"{temp.data}, ", end="")
            else:
                print(temp.data, end="")

            temp = temp.next

        print()

    def insertion_sort(self):
        if not self.head or not self.head.next:
            return

        dummy = Node(0, self.head)
        prev, curr = dummy, self.head
        while curr:
            if (curr.next) and (curr.next.data < curr.data):
                while (prev.next) and (prev.next.data < curr.next.data):
                    prev = prev.next

                temp = prev.next
                prev.next = curr.next
                curr.next = curr.next.next
                prev.next.next = temp

                # Start scanning from HEAD again in next iteration
                prev = dummy
            else:
                curr = curr.next

        self.head = dummy.next


def main():
    l = LinkedList()
    l.insert_node(-1)
    l.insert_node(5)
    l.insert_node(3)
    l.insert_node(4)
    l.insert_node(0)

    l.print_list()
    l.insertion_sort()
    l.print_list()


if __name__ == "__main__":
    main()
