class Node():
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

class BST():
    def __init__(self):
        self.root = None

    def __insertion(self, key):
        new_node = Node(key)

        if self.root is None:
            self.root = new_node
            return

        queue = [self.root]

        while len(queue) > 0:
            current = queue.pop(0)

            #Testa adicionar na esquerda
            if current.left is None:
                current.left = new_node
                break
            else:
                queue.append(current.left)

            #Testa adicionar na direita
            if current.right is None:
                current.right = new_node
                break
            else:
                queue.append(current.right)
        
    def __pre_order(self, node):
        if node is None:
            return

        print(f' {node.data}', end='')
        self.__pre_order(node.left)
        self.__pre_order(node.right)

    def __in_order(self, node):
        if node is None:
            return

        self.__in_order(node.left)
        print(f' {node.data}', end='')
        self.__in_order(node.right)

    def __post_order(self, node):
        if node is None:
            return

        self.__post_order(node.left)
        self.__post_order(node.right)
        print(f' {node.data}', end='')

    def insert(self, key):
        self.__insertion(key)
        return 

    def print(self):
        print('Pre-order:', end='')
        self.__pre_order(self.root)
        print()
        print('In-order:', end='')
        self.__in_order(self.root)
        print()
        print('Post-order:', end='')
        self.__post_order(self.root)
        print()

num = int(input())
entrada = input().split(' ')
inteiros = []

for value in entrada:
    inteiros.append(int(value))

tree = BST()

for value in inteiros:
    tree.insert(value)

tree.print()